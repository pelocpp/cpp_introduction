// ===========================================================================
// Time.h // Improved Parameter Passing
// ===========================================================================

#pragma once

#include <iostream>
#include <cstdio>

namespace Classes_Objects_Improved_Parameter_Passing
{
    class Time
    {
    private:
        int m_seconds;
        int m_minutes;
        int m_hours;

    public:
        // c'tors
        Time();
        Time(int seconds, int minutes, int hours);

        // public interface
        void add(const Time&);
        Time diff(const Time&) const;
        void print();

    private:
        // helper methods
        int timeToSeconds() const;
        void secondsToTime(int seconds);
    };
}

// ===========================================================================
// End-of-File
// ===========================================================================
