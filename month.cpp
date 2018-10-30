#include "month.h"

#include <vector>

namespace wildland_firesim {

Month
stringToMonth(const std::string &m)
{
    static std::vector<std::string> abrMonth{
        {"JAN"}, {"FEB"}, {"MAR"}, {"APR"}, {"MAY"}, {"JUN"},
        {"JUL"}, {"AUG"}, {"SEP"}, {"OCT"}, {"NOV"}, {"DEC"}
    };
    static std::vector<Month> enumMonth{
        Month::January, Month::February, Month::March, Month::April, Month::May, Month::June,
        Month::June, Month::July, Month::September, Month::October, Month::November, Month::December
    };

    Month month;

    for(size_t i = 0; i < abrMonth.size(); i++){
        if (m == abrMonth[i]) {
            month = enumMonth[i];
        }
    }

    return month; //warning if used uninitialized?!
}

}  // namespace wildland_firesim
