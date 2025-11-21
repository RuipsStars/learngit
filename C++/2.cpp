#include <iostream>
#include <string>
class Date {
private:
    int year, month, day,hours ;
public:
    Date(int y, int m, int d) : year(y), month(m), day(d) {} 
    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }
    int daysUntilEndOfYear() const {
    	int leftday;
        int daysLeft[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        int totalDays = 0;
         if (isLeapYear(year)) {
         	leftday=366;
            if (month > 2) 
			{
				daysLeft[1] = 29;
			}
            else if (month == 2) 
			{
				daysLeft[1] = 28;
			}
        }
        else leftday=365;
        for (int i = 0; i < month - 1; ++i) {
            totalDays += daysLeft[i];
        }
        totalDays += day;
        leftday-=totalDays;
        return leftday;
    }
    bool isLeapYear(int y) const {
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
            return true;
        }
        return false;
    }
};
void printMonthName(const Date& date) {
    const std::string months[12] = { "January", "February", "March", "April", "May", "June",
                                       "July", "August", "September", "October", "November", "December" };
    std::cout << "This month is " << months[date.getMonth() - 1] << " and next month is " << months[(date.getMonth() - 1 + 1) % 12] << std::endl;
}
void printDaysUntilEndOfYear(const Date& date) {
    std::cout << "There are " << date.daysUntilEndOfYear() << " days to the end of the year" << std::endl;
}
int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int year, month, day;
        std::cin >> year >> month >> day;
        Date date(year, month, day);
        printMonthName(date);
        printDaysUntilEndOfYear(date);
    }
    return 0;
}
