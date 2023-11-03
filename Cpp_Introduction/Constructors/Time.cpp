// ===========================================================================
// Time.cpp // Constructors
// ===========================================================================

//#include <iostream>
//#include <iomanip>

#include "Time.h"

namespace Classes_Objects_Constructors
{
    // c'tors
    Time::Time() : m_seconds(0), m_minutes(0), m_hours(0) {}  // default c'tor

    Time::Time(int hours, int minutes, int seconds)   // user-defined c'tor
    {
        m_hours = (0 <= hours && hours < 24) ? hours : 0;
        m_minutes = (0 <= minutes && minutes < 60) ? minutes : 0;
        m_seconds = (0 <= seconds && seconds < 60) ? seconds : 0;
    }

    Time::Time(int hours, int minutes)   // user-defined c'tor
    {
        m_hours = (0 <= hours && hours < 24) ? hours : 0;
        m_minutes = (0 <= minutes && minutes < 60) ? minutes : 0;
        m_seconds = 0;
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

    // public interface
    void Time::print()
    {
        std::printf("%02d:%02d:%02d\n", m_hours, m_minutes, m_seconds);
    }

    // private interface
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
