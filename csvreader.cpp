#include "csvreader.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

namespace wildland_firesim {
namespace csv {
namespace {

enum class State {
    StartRecord,
    StartField,
    InField,
    InComment
};

}  // namespace

Reader::Reader(char delimiter, char comment)
    : m_comment{comment}, m_delimiter{delimiter}
{}

std::vector<std::vector<std::string>>
Reader::parse(const std::string &fileName)
{
    auto result = std::vector<std::vector<std::string>>{};
    auto input_stream = std::ifstream{fileName};

    if (!input_stream.is_open()) {
        std::cerr << "failed to open file \"" << fileName << '\"' << std::endl;
        return result;
    }

    auto logbuf = std::stringstream{};
    auto buf = std::stringstream{};
    const int eof = std::ifstream::traits_type::eof();
    auto  state = State::StartRecord;

    for (int c = input_stream.get(); c != eof; c = input_stream.get()) {
        switch (state) {
        case State::StartRecord:
            if (c == m_comment) {
                state = State::InComment;
                break;
            }
            result.emplace_back();
            state = State::StartField;
            [[clang::fallthrough]];
        case State::StartField:
            if (c == '\n') {
                // empty field; empty row
                result.back().emplace_back();
                state = State::StartRecord;
            } else if (c == m_delimiter) {
                // empty field again
                result.back().emplace_back();
            } else {
                buf << static_cast<char>(c);
                state = State::InField;
            }
            break;
        case State::InComment:
            if (c == '\n') {
                state = State::StartRecord;
            }
            break;
        case State::InField:
            if (c == '\n') {
                result.back().emplace_back(buf.str());
                buf = std::stringstream{};
                state = State::StartRecord;
            } else if (c == m_delimiter) {
                result.back().emplace_back(buf.str());
                buf = std::stringstream{};
                state = State::StartField;
            } else {
                buf << static_cast<char>(c);
            }
            break;
        }
    }

    return result;
}

}  // namespace csv
}  // namespace wildland_firesim
