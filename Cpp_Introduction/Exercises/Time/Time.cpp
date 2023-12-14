// ===========================================================================
// Time.cpp
// ===========================================================================

#include <iostream>
#include <iomanip>

#include "Time.h"

// c'tors
Time::Time() : m_seconds(0), m_minutes(0), m_hours(0) {}  // default c'tor

Time::Time(int seconds, int minutes, int hours)  // user-defined c'tor
{
    m_seconds = (0 <= seconds && seconds < 60) ? seconds : 0;
    m_minutes = (0 <= minutes && minutes < 60) ? minutes : 0;
    m_hours = (0 <= hours && hours < 24) ? hours : 0;
}

Time::Time(const char* s)  // user-defined c'tor
{
    // expecting format "hh:mm:ss" - don't expect wrong input (!)
    int hours = 10 * (s[0] - '0') + (s[1] - '0');
    m_hours = (0 <= hours && hours < 24) ? hours : 0;
    s += 3;  // skip hours and colon
    int minutes = 10 * (s[0] - '0') + (s[1] - '0');
    m_minutes = (0 <= minutes && minutes < 60) ? minutes : 0;
    s += 3;  // skip minutes and colon
    int seconds = 10 * (s[0] - '0') + (s[1] - '0');
    m_seconds = (0 <= seconds && seconds < 60) ? seconds : 0;
}

Time::Time(int seconds)     // conversion c'tor
{
    if (0 <= seconds && seconds <= 24 * 60 * 60)
    {
        secondsToTime(seconds);
    }
    else
    {
        m_seconds = m_minutes = m_hours = 0;
    }
}

// getter // setter
void Time::setSeconds(int seconds)
{
    m_seconds = (0 <= seconds && seconds < 60) ? seconds : 0;
}

void Time::setMinutes(int minutes)
{
    m_minutes = (0 <= minutes && minutes < 60) ? minutes : 0;
}

void Time::setHours(int hours)
{
    m_hours = (0 <= hours && hours < 24) ? hours : 0;
}

// public interface
void Time::reset()
{
    m_seconds = 0;
    m_minutes = 0;
    m_hours = 0;
}

void Time::add(const Time & t)
{
    m_seconds += t.m_seconds;
    m_minutes += t.m_minutes;
    m_hours += t.m_hours;

    // normalize object
    m_minutes += m_seconds / 60;
    m_hours += m_minutes / 60;
    m_seconds = m_seconds % 60;
    m_minutes = m_minutes % 60;
    m_hours = m_hours % 24;
}

void Time::sub(const Time& t)
{
    int seconds =
        (m_hours * 3600 + m_minutes * 60 + m_seconds) -
        (t.m_hours * 3600 + t.m_minutes * 60 + t.m_seconds);

    if (seconds < 0)
        seconds += 24 * 60 * 60;

    // transform total seconds into hours, minutes and seconds
    secondsToTime(seconds);
}

Time Time::diff(const Time& t) const
{
    Time tmp;
    if (*this <= t)
        tmp = t - *this;
    else
        tmp = *this - t;

    return tmp;
}

void Time::increment()
{
    m_seconds++;
    if (m_seconds >= 60)
    {
        m_seconds = 0;
        m_minutes++;
        if (m_minutes >= 60)
        {
            m_minutes = 0;
            m_hours++;
            if (m_hours >= 24)
            {
                m_hours = 0;
            }
        }
    }
}

void Time::decrement()
{
    m_seconds--;
    if (m_seconds < 0)
    {
        m_seconds = 59;
        m_minutes--;
        if (m_minutes < 0)
        {
            m_minutes = 59;
            m_hours--;
            if (m_hours < 0)
            {
                m_hours = 23;
            }
        }
    }
}

// arithmetic operators
Time Time::operator+ (const Time & t) const
{
    Time tmp(*this);
    tmp.add(t);
    return tmp;
}

Time Time::operator- (const Time & t) const
{
    Time tmp(*this);
    tmp.sub(t);
    return tmp;
}

Time Time::operator+= (const Time & t)
{
    add(t);
    return *this;
}

Time Time::operator-= (const Time & t)
{
    sub(t);
    return *this;
}

Time Time::operator+= (int seconds)
{
    for (int i = 0; i < seconds; i++)
        increment();

    return *this;
}

Time Time::operator-= (int seconds)
{
    for (int i = 0; i < seconds; i++)
        decrement();

    return *this;
}

// increment operator: prefix version
Time & operator++ (Time & t)
{
    t += 1;
    return t;
}

// decrement operator: prefix version
Time & operator-- (Time & t)
{
    t -= 1;
    return t;
}

// increment operator: postfix version
const Time operator++ (Time & t, int)
{
    Time tmp(t);  // construct a copy
    ++t;          // increment number
    return tmp;   // return the copy
}

// decrement operator: postfix version
const Time operator-- (Time & t, int)
{
    Time tmp(t);  // construct a copy
    --t;          // decrement number
    return tmp;   // return the copy
}

// comparison operators
bool operator== (const Time & t1, const Time & t2)
{
    return
        t1.m_seconds == t2.m_seconds &&
        t1.m_minutes == t2.m_minutes &&
        t1.m_hours == t2.m_hours;
}

bool operator!= (const Time & t1, const Time & t2)
{
    return !(t1 == t2);
}

bool operator<= (const Time & t1, const Time & t2)
{
    return t1 < t2 || t1 == t2;
}

bool operator<  (const Time & t1, const Time & t2)
{
    if (t1.m_hours < t2.m_hours)
        return true;

    if (t1.m_hours == t2.m_hours && t1.m_minutes < t2.m_minutes)
        return true;

    if (t1.m_hours == t2.m_hours && t1.m_minutes == t2.m_minutes && t1.m_seconds < t2.m_seconds)
        return true;

    return false;
}

bool operator>= (const Time & t1, const Time & t2)
{
    return !(t1 < t2);
}

bool operator>  (const Time & t1, const Time & t2)
{
    return !(t1 <= t2);
}

// conversion operator
Time::operator int()
{
    return timeToSeconds();
}

// input / output
std::istream & operator>> (std::istream & is, Time & t)
{
    std::cout << "Hours [hh]: ";
    is >> t.m_hours;
    std::cout << "Minutes [mm]: ";
    is >> t.m_minutes;
    std::cout << "Seconds [ss]: ";
    is >> t.m_seconds;

    return is;
}

std::ostream & operator<< (std::ostream & os, const Time & t)
{
    os << std::setw(2) << std::setfill('0') << t.m_hours << ":";
    os << std::setw(2) << std::setfill('0') << t.m_minutes << ":";
    os << std::setw(2) << std::setfill('0') << t.m_seconds;

    return os;
}

// helper methods
int Time::timeToSeconds()
{
    return m_hours * 3600 + m_minutes * 60 + m_seconds;
}

void Time::secondsToTime(int seconds)
{
    m_hours = seconds / 3600;
    seconds = seconds % 3600;
    m_minutes = seconds / 60;
    m_seconds = seconds % 60;
}

// ===========================================================================
// End-of-File
// ===========================================================================
