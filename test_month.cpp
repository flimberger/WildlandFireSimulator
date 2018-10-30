#include "month.h"

#include "catch.hpp"

using namespace wildland_firesim;

TEST_CASE("Valid month names are parsed correctly", "[month]")
{
    static constexpr struct TestMapEntry {
        const char *upperCaseName;
        const char *lowerCaseName;
        Month month;
    } months[] {
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
