#include "month.h"

#include <utility>
#include <vector>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace wildland_firesim;

TEST_CASE("Month is parsed", "[month]")
{
    struct TestMapEntry {
        std::string upperCaseName;
        std::string lowerCaseName;
        Month month;
    };

    static std::vector<TestMapEntry> months {
        { "JAN", "jan", Month::January },
        { "FEB", "feb", Month::February },
        { "MAR", "mar", Month::March },
        { "APR", "apr", Month::April },
        { "MAY", "may", Month::May },
        { "JUN", "jun", Month::June },
        { "JUL", "jul", Month::July },
        { "AUG", "aug", Month::August },
        { "SEP", "sep", Month::September },
        { "OCT", "oct", Month::October },
        { "NOV", "nov", Month::November },
        { "DEC", "dec", Month::December }
    };

    for (const auto &mapping : months) {
        REQUIRE(stringToMonth(mapping.upperCaseName) == mapping.month);
        REQUIRE(stringToMonth(mapping.lowerCaseName) == mapping.month);
    }
}
