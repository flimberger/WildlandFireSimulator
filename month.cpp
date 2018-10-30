#include "month.h"

#include <algorithm>
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
        { "jan", Month::January },
        { "feb", Month::February },
        { "mar", Month::March },
        { "apr", Month::April },
        { "may", Month::May },
        { "jun", Month::June },
        { "jul", Month::July },
        { "aug", Month::August },
        { "sep", Month::September },
        { "oct", Month::October },
        { "nov", Month::November },
        { "dec", Month::December }
    };

    // convert the month name to lower space
    auto lowerCaseName = m;

    std::for_each(std::begin(lowerCaseName), std::end(lowerCaseName), [](char &c){
        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));;
    });

    Month month;

    for (const auto &mapping : months) {
        if (lowerCaseName == mapping.name) {
            month = mapping.month;
        }
    }

    return month; //warning if used uninitialized?!
}

}  // namespace wildland_firesim
