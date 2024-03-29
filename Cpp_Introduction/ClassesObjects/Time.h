// ===========================================================================
// Time.h // Classes and Objects
// ===========================================================================

#pragma once

#include <iostream>
#include <iomanip>
#include <cstdio>

namespace Classes_Objects
{
    class Time
    {
    public:
        // member data / instance variables
        int m_hours;
        int m_minutes;
        int m_seconds;

        // public interface / methods
        void reset();
        void increment();
        void print();
    };
}

// ===========================================================================
// End-of-File
// ===========================================================================
