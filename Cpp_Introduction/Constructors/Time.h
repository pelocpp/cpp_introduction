// ===========================================================================
// Time.h // Constructors
// ===========================================================================

#pragma once

#include <iostream>
#include <cstdio>

namespace Classes_Objects_Constructors
{
    class Time
    {
    private:
        int m_hours;
        int m_minutes;
        int m_seconds;

    public:
        // c'tors
        Time();
        Time(int hours, int minutes, int seconds);
        Time(int hours, int minutes);
        Time(int seconds);  // conversion c'tor
        Time(const char*);  // conversion c'tor

        // public interface
        void print();

    private:
        // helper method(s)
        void secondsToTime(int seconds);
    };
}

// ===========================================================================
// End-of-File
// ===========================================================================
