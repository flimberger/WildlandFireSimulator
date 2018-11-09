#ifndef WILDLAND_FIRESIM_CSVREADER_H
#define WILDLAND_FIRESIM_CSVREADER_H

#include <string>
#include <vector>

namespace wildland_firesim {
namespace csv {

class StatePrivate;

/*!
 * \brief The Reader class
 * Class containing the parser for csv-files.
 */
class Reader{

public:
    Reader(char delimiter, char comment);

    /*!
     * \brief parse
     * Function to parse .csv-files.
     * \param fileName
     * \return
     */
    std::vector<std::vector<std::string>> parse(const std::string &fileName);

private:
    // dialect specification
    char m_comment;
    char m_delimiter;
};

} //namespace wildland_firesim
} //namespace csv


#endif // WILDLAND_FIRESIM_CSVREADER_H
