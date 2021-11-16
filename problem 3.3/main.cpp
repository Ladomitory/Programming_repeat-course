//
//Problem 3.3
//by Ladomitory from 13/10/2021
//

//ПРОБЛЕМА КОДА//
//остался какой-то косяк, более правильно считать если мы высчитываем года с предыдущего,
//но такое решение на проходит тест 4.Но если считать не уменьшая год, то ломается тест 12

#include <iostream>
#include <map>
#include <cmath>

using namespace std;

bool LeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    return false;
}

class Date {
public:
    int day = 1;
    int month = 1;
    int year = 1;
    Date (int day, int month, int year) {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    bool DataErrorChek() {
        if ((year < 0)
            || (month > 12 || month < 1)
            || (day > DaysInMonth[month].first)
            || (day < 0)) {
            return true;
        }
        return false;
    }

    int DaysAfterNullYear() {
        int ans = 0;
        int y = year - 1;
        ans += 365 * y + (y / 4 - y / 100 + y / 400);
        ans += DaysInMonth[month - 1].second;
        ans += day - 1;
        if (LeapYear(year) && month > 2) {
            ans += 1;
        }
        return ans;
    }



    map <int, pair <int, int>> DaysInMonth = {{1, {31, 31}},
                                              {2, {28, 59}},
                                              {3, {31, 90}},
                                              {4, {30, 120}},
                                              {5, {31, 151}},
                                              {6, {30, 181}},
                                              {7, {31, 212}},
                                              {8, {31, 243}},
                                              {9, {30, 273}},
                                              {10, {31, 304}},
                                              {11, {30, 334}},
                                              {12, {31, 365}}};
};

int main() {
    int d, m, y;
    cin >> d >> m >> y;
    Date * D1 = new Date(d, m, y);
    cin >> d >> m >> y;
    Date * D2 = new Date(d, m, y);

    if (D1->DataErrorChek() || D2->DataErrorChek()) {
        cout << "ERROR";
        return 0;
    }

    int ans = abs(D1->DaysAfterNullYear() - D2->DaysAfterNullYear());

    cout << ans << '\n';
    return 0;
}