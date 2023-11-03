// ===========================================================================
// Time.cpp // Classes and Objects Improved
// ===========================================================================

//#include <iostream>
//#include <iomanip>

#include "Time.h"

namespace Classes_Objects_Improved
{
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

    // public interface
    void Time::reset()
    {
        m_seconds = 0;
        m_minutes = 0;
        m_hours = 0;
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

    void Time::print()
    {
        std::printf("%02d:%02d:%02d\n", m_hours, m_minutes, m_seconds);
    }
}

// ===========================================================================
// End-of-File
// ===========================================================================
