#include <iostream>
#include <ctime>

using namespace std;

struct Date
{
    int year;
    int month;
    int day;
};

Date getTodaysDateFromSystem()
{
    Date todaysDate;
    time_t now = time(0);
    tm* localTime = localtime(&now);
    todaysDate.year = 1900 + localTime->tm_year;
    todaysDate.month = localTime->tm_mon;
    todaysDate.day = localTime->tm_mday;
    return todaysDate;
}


int main()
{
    Date todaysDate = getTodaysDateFromSystem();
    cout << todaysDate.year << "-" << todaysDate.month << "-" << todaysDate.day << endl;
    return 0;
}
