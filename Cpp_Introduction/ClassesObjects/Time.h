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
        int m_seconds;
        int m_minutes;
        int m_hours;

        // public interface / methods
        void reset();
        void increment();
        void print();
    };
}

// ===========================================================================
// End-of-File
// ===========================================================================
