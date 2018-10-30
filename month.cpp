#include "month.h"

#include <vector>

namespace wildland_firesim {

Month
stringToMonth(const std::string &m)
{
    struct NameMapping {
        std::string name;
        Month month;
    };

    static std::vector<NameMapping> months {
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

    Month month;

    for (const auto &mapping : months) {
        if (m == mapping.name) {
            month = mapping.month;
        }
    }

    return month; //warning if used uninitialized?!
}

}  // namespace wildland_firesim
