#ifndef DOORSYSTEM_H
#define DOORSYSTEM_H

class DoorSystem
{
private:
    int m_year{};
    int m_month{};
    int m_day{};

public:
    DoorSystem();

    void SetDate(int year, int month, int day);

    int getYear() const { return m_year; }
    int getMonth() const { return m_month; }
    int getDay() const { return m_day; }
};

#endif