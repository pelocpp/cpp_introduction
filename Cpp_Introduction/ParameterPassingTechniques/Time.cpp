// ===========================================================================
// Time.cpp // Classes and Objects Improved
// ===========================================================================

//#include <iostream>
//#include <iomanip>

#include "Time.h"

namespace Classes_Objects_Improved_Parameter_Passing
{
    // c'tors
    Time::Time() : m_seconds(0), m_minutes(0), m_hours(0) {}

    Time::Time(int seconds, int minutes, int hours)
    {
        m_seconds = (0 <= seconds && seconds < 60) ? seconds : 0;
        m_minutes = (0 <= minutes && minutes < 60) ? minutes : 0;
        m_hours = (0 <= hours && hours < 24) ? hours : 0;
    }

    // public interface
    void Time::add(const Time& t)
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

    Time Time::diff(const Time& other) const
    {
        Time result;

        int thisSeconds = timeToSeconds();
        int otherSeconds = other.timeToSeconds();

        if (thisSeconds <= otherSeconds) {
            result.secondsToTime(otherSeconds - thisSeconds);
        }
        else {
            result.secondsToTime(thisSeconds - otherSeconds);
        }

        return result;
    }

    void Time::print()
    {
        std::printf("%02d:%02d:%02d\n", m_hours, m_minutes, m_seconds);
    }

    // helper methods
    int Time::timeToSeconds() const
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
}

// ===========================================================================
// End-of-File
// ===========================================================================
