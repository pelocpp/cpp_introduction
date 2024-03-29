// ===========================================================================
// Time.h // Classes and Objects Improved
// ===========================================================================

#pragma once

#include <iostream>
#include <cstdio>

namespace Classes_Objects_Improved
{
    class Time
    {
    private:
        int m_hours;
        int m_minutes;
        int m_seconds;

    public:
        // getter // setter
        int getHours() { return m_hours; }
        int getMinutes() { return m_minutes; }
        int getSeconds() { return m_seconds; }
        void setHours(int hours);
        void setMinutes(int minutes);
        void setSeconds(int seconds);

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
