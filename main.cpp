#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

struct Date
{
    int year;
    int month;
    int day;
};

Date setDate(int givenYear, int givenMonth, int givenDay)
{
    Date givenDate;
    givenDate.year = givenYear;
    givenDate.month = givenMonth;
    givenDate.day = givenDay;
    return givenDate;
}

void displayDate(Date givenDate)
{
    cout << givenDate.year << "-" << setw(2) << setfill('0') << givenDate.month << "-" << setw(2) << setfill('0') << givenDate.day << endl;
}

Date getTodaysDateFromSystem()
{
    Date todaysDate;
    time_t now = time(0);
    tm* localTime = localtime(&now);
    todaysDate.year = 1900 + localTime->tm_year;
    todaysDate.month = 1 + localTime->tm_mon;
    todaysDate.day = localTime->tm_mday;
    return todaysDate;
}

bool isDateGreater(Date checkedDate, Date referenceDate)
{
    bool answer = false;
    if (checkedDate.year > referenceDate.year)
    {
        answer = true;
    }
    else if (checkedDate.year == referenceDate.year)
    {
        if (checkedDate.month > referenceDate.month)
        {
            answer = true;
        }
        else if (checkedDate.month == referenceDate.month)
        {
            if (checkedDate.day > referenceDate.day)
            {
                answer = true;
            }

        }
    }
    return answer;
}

bool isYearLeap(int  year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    else
        return false;
}

int numberOfDaysInMonth(int month, int year)
{
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else if (month == 2)
        {
            if (isYearLeap(year))
                return 29;
            else
                return 28;
        }
    else
        return 31;
}

int main()
{
    Date todaysDate = getTodaysDateFromSystem();
    cout << "Today's date: ";
    displayDate(todaysDate);

    Date someDate = setDate(1900,3,31);
    cout << "Some date: ";
    displayDate(someDate);


    cout << endl << endl << "***dates comparison***" << endl;
    displayDate(someDate);
    if (isDateGreater(someDate,todaysDate))
    {
        cout << "is greater than" << endl;
    }
    else
    {
        cout << "is not greater than" << endl;
    }
    displayDate(todaysDate);

    cout << endl;

    cout << someDate.year;

    if (isYearLeap(someDate.year))
    {
        cout << " is leap year" << endl;
    }
    else
    {
        cout << " is not leap year" << endl;
    }
    cout << "month " << setw(2) << setfill('0') << someDate.month << " of year " << someDate.year;
    cout << " has " << numberOfDaysInMonth (someDate.month,someDate.year) << " days";

    return 0;
}
