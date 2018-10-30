#include "month.h"

#include <utility>
#include <vector>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace wildland_firesim;

TEST_CASE("Month is parsed", "[month]")
{
    static std::vector<std::pair<std::string, Month>> months {
        { "JAN", Month::January },
        { "FEB", Month::February },
        { "MAR", Month::March },
        { "APR", Month::April },
        { "MAY", Month::May },
        { "JUN", Month::June },
        { "JUL", Month::July },
        { "AUG", Month::August },
        { "SEP", Month::September },
        { "OCT", Month::October },
        { "NOV", Month::November },
        { "DEC", Month::December }
    };

    for (const auto &p : months) {
        REQUIRE(stringToMonth(p.first) == p.second);
    }
}
