#include <iostream>
#include <string>
#include <iostream>
#include <cassert>

using namespace std;

class Date {

    public:
    // inicializace
//        Date()
//            : day(1), month(1), year(1970)
//        {
//
//        };

        Date(int day, int month, int year)
            : day(day), month(month), year(year)
        {

        };

        Date(const string& date)
            : day(stoi(date.substr(0, 2))),
            month(stoi(date.substr(3, 2))),
            year(stoi(date.substr(6, 4))){

        }

        bool lessThan(Date other)
        void print(const ostream& os);
        int compare(Date other);

    private:
    // kontrolujeme, jestli je datum správné, chceme to privátní, protože jinak si do toho pak omylem šahnem
        bool validate(){
            return day > 0 && day <= 31;
        }
        int day, month, year;
            // int day, ...
};

int main(){
    Date d1 = Date(29, 2, 2024);
    Date d2 = Date(1, 1, 1993);
    Date d3 = Date(28, 10, 1918);

    assert(d1.compare(d2) > 0);
    assert(d2.compare(d1) == 0);
    assert(!d1.lessThan(d3));
}