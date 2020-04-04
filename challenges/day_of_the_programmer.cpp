#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

std::string
doIt(int year)
{
    std::string julian_leap  = "12.09.";
    std::string julian_nleap = "13.09.";
    std::string greg_leap    = "12.09.";
    std::string greg_nleap   = "13.09.";
    std::string spec_case    = "26.09.1918";

    if (year < 1918)
    {
        if (year % 4 == 0)
            return julian_leap + std::to_string(year);    
        return julian_nleap + std::to_string(year);
    }

    if (year == 1918)
        return spec_case;

    if ( year % 400 == 0 ||
            ((year% 4    == 0) && (year % 100 != 0)) )
            return greg_leap + std::to_string(year);

    return greg_nleap + std::to_string(year);
}

int main() {
    int year;
    cin >> year;
    
    std::string date = doIt(year);
    
    std::cout << date << std::endl;
    
    return 0;
}
