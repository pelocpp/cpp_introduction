// ===========================================================================
// Time.cpp // Operator Overloading
// ===========================================================================

#include "Time.h"

// implementation
namespace OperatorOverloading
{
    // c'tors
    Time::Time() : m_seconds(0), m_minutes(0), m_hours(0) {}  // default c'tor

    Time::Time(int hours, int minutes, int seconds)   // user-defined c'tor
    {
        m_hours = (0 <= hours && hours < 24) ? hours : 0;
        m_minutes = (0 <= minutes && minutes < 60) ? minutes : 0;
        m_seconds = (0 <= seconds && seconds < 60) ? seconds : 0;
    }

    // setter
    void Time::setHours(int hours)
    {
        m_hours = (0 <= hours && hours < 24) ? hours : 0;

        if (0 <= hours && hours < 24) {
            m_hours = hours;
        }
        else {
            // we don't modify the current value of 'm_hours'
            std::cout << "Wrong value for hours: " << hours << std::endl;
        }
    }

    void Time::setMinutes(int minutes)
    {
        if (0 <= minutes && minutes < 60) {
            m_minutes = minutes;
        }
        else {
            // we don't modify the current value of 'm_minutes'
            std::cout << "Wrong value for minutes: " << minutes << std::endl;
        }
    }

    void Time::setSeconds(int seconds)
    {
        if (0 <= seconds && seconds < 60) {
            m_seconds = seconds;
        }
        else {
            // we don't modify the current value of 'm_seconds'
            std::cout << "Wrong value for seconds: " << seconds << std::endl;
        }
    }

    void Time::print()
    {
        std::printf("%02d:%02d:%02d\n", m_hours, m_minutes, m_seconds);
    }

    // =======================================================================

    // comparison operators - implemented as member methods
    //bool Time::operator== (const Time& other) {
    //    return
    //        m_seconds == other.m_seconds &&
    //        m_minutes == other.m_minutes &&
    //        m_hours == other.m_hours;
    //}
    //
    //bool Time::operator!= (const Time& other) {
    //    return ! (*this == other);
    //}
    //
    //bool Time::operator<  (const Time& other) {
    //    if (m_hours < other.m_hours)
    //        return true;

    //    if (m_hours == other.m_hours && m_minutes < other.m_minutes)
    //        return true;

    //    if (m_hours == other.m_hours && m_minutes == other.m_minutes && m_seconds < other.m_seconds)
    //        return true;

    //    return false;
    //}

    //bool Time::operator<= (const Time& other) {
    //    return *this < other || *this == other;
    //}
    //
    //bool Time::operator>  (const Time& other) {
    //    return !(*this <= other);
    //}

    //bool Time::operator>= (const Time& other) {
    //    return !(*this < other);
    //}

    // =======================================================================

    // comparison operators as global methods -  NO 'friendship'
    //bool operator== (const Time& left, const Time& right)
    //{
    //    return
    //        left.getSeconds() == right.getSeconds() &&
    //        left.getMinutes() == right.getMinutes() &&
    //        left.getHours() == right.getHours();
    //}

    //bool operator!= (const Time& left, const Time& right)
    //{
    //    return !(left == right);
    //}

    //bool operator<= (const Time& left, const Time& right)
    //{
    //    return left < right || left == right;
    //}

    //bool operator< (const Time& left, const Time& right)
    //{
    //    if (left.getHours() < right.getHours())
    //        return true;

    //    if (left.getHours() == right.getHours() && left.getMinutes() < right.getMinutes())
    //        return true;

    //    if (left.getHours() == right.getHours() && left.getMinutes() == right.getMinutes() && left.getSeconds() < right.getSeconds())
    //        return true;

    //    return false;
    //}

    //bool operator>= (const Time& left, const Time& right)
    //{
    //    return !(left < right);
    //}

    //bool operator>  (const Time& left, const Time& right)
    //{
    //    return !(left <= right);
    //}

    // =======================================================================

    // comparison operators as global methods -  using 'friendship'
    bool operator== (const Time& left, const Time& right)
    {
        return
            left.m_seconds == right.m_seconds &&
            left.m_minutes == right.m_minutes &&
            left.m_hours == right.m_hours;
    }

    bool operator!= (const Time& left, const Time& right)
    {
        return !(left == right);
    }

    bool operator<= (const Time& left, const Time& right)
    {
        return left < right || left == right;
    }

    bool operator<  (const Time& left, const Time& right)
    {
        if (left.m_hours < right.m_hours)
            return true;

        if (left.m_hours == right.m_hours && left.m_minutes < right.m_minutes)
            return true;

        if (left.m_hours == right.m_hours && left.m_minutes == right.m_minutes && left.m_seconds < right.m_seconds)
            return true;

        return false;
    }

    bool operator>= (const Time& left, const Time& right)
    {
        return !(left < right);
    }

    bool operator>  (const Time& left, const Time& right)
    {
        return !(left <= right);
    }
}

// ===========================================================================
// End-of-File
// ===========================================================================
