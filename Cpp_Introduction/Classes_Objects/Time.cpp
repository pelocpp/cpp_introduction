// ===========================================================================
// Time.cpp
// ===========================================================================

#include <iostream>
#include <iomanip>

#include "Time.h"

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

void Time::print()
{
    std::cout<< std::setw(2) << std::setfill('0') << m_hours << ":";
    std::cout<< std::setw(2) << std::setfill('0') << m_minutes << ":";
    std::cout<< std::setw(2) << std::setfill('0') << m_seconds;
}

// ===========================================================================
// End-of-File
// ===========================================================================
