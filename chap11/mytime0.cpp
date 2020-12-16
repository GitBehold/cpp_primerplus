#include <iostream>
#include "mytime0.h"
Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h ,int m)
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::Reset(int h ,int m)
{
    hours = h;
    minutes = m;
}

Time Time::Sum(const Time &t) const //参数传引用,目的是为了提高效率,实现效果与按值传递一致
{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours +t.hours + sum.minutes/60;
    sum.minutes %= 60;
    return sum;
}

void Time::Show() const
{
    std::cout << hours << "hours, " << minutes << " minutes";
}

