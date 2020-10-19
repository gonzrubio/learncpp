#pragma once
#ifndef DATE_H
#define DATE_H

class Date {
private:
    int m_day;
    int m_month;
    int m_year;

public:
    Date(const int day, const int month, const int year);
    void setDate(const int day, const int month, const int year);
    // These are all made const since they do not change the state of the class object.
    int getDay() const;
    int getMonth() const;
    int getYear() const;
};

#endif // !DATE_H

