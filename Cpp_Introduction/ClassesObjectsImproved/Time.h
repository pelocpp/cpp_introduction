// ===========================================================================
// Time.h // Classes and Objects Improved
// ===========================================================================

#pragma once

#include <iostream>
// #include <iomanip>
#include <cstdio>

namespace Classes_Objects_Improved
{
    class Time
    {
    private:
        int m_seconds;
        int m_minutes;
        int m_hours;

    public:
        // getter // setter
        int getSeconds() { return m_seconds; }
        int getMinutes() { return m_minutes; }
        int getHours() { return m_hours; }
        void setSeconds(int seconds);
        void setMinutes(int minutes);
        void setHours(int hours);

        // public interface
        void reset();
        void increment();
        void decrement();
        void print();
    };
}

// ===========================================================================
// End-of-File
// ===========================================================================
