/*
    // Four time-related types in std libary <ctime>:
    clock_t, time_t, size_t, tm

    struct tm
    {
        int tm_sec; // seconds of minutes from 0 to 61
        int tm_min; // minutes of hour from 0 to 59
        int tm_hour; // hours of day from 0 to 24
        int tm_mday; // day of month from 1 to 31
        int tm_mon; // month of year from 0 to 11
        int tm_year; // year since 1900
        int tm_wday; // days since Sunday
        int tm_yday; // days since Jan 1
        int tm_isdst; // hours of daylight savings time
    }

*/

#include <iostream>
#include <ctime>

using namespace std;

int main ()
{
    // current date/time based on current system
    time_t now = time(0);

    // convert to string form
    char* dt = ctime(&now);

    cout << "The local date and time is: " << dt << endl;

    // convert to tm struct for UTC
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
    cout << "The UTC date and time is: " << dt << endl;

    cout << "Number of sec since Jan 1, 1970: " << now << endl;
    tm * ltm = localtime(&now);

    // print various components of tm structure
    cout << "Year: " << 1970 + ltm->tm_year << endl;
    cout << "Month: " << 1 + ltm->tm_mon << endl;
    cout << "Day: " << 1 + ltm->tm_mday << endl;
    cout << "Time: " << 1 + ltm->tm_hour << ":";
    cout << 1 + ltm->tm_min << ":";
    cout << 1 + ltm->tm_sec << endl;

    return 0;
}