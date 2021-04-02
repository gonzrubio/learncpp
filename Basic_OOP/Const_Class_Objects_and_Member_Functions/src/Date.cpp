#include "Date.h"

Date::Date(const int day, const int month, const int year) {
    setDate(day, month, year);
}

void Date::setDate(const int day, const int month, const int year) {
    m_day = day;
    m_month = month;
    m_year = year;
}

int Date::getDay() const { return m_day; }
int Date::getMonth() const { return m_month; }
int Date::getYear() const { return m_year; }