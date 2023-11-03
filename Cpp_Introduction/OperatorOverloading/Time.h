// ===========================================================================
// Time.h // Operator Overloading
// ===========================================================================

#pragma once

#include <iostream>
#include <iomanip>
#include <cstdio>

namespace OperatorOverloading
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
        Time(int hours, int minutes, int seconds);

        // getter // setter
        int getSeconds() const { return m_seconds; }
        int getMinutes() const { return m_minutes; }
        int getHours() const { return m_hours; }
        void setSeconds(int seconds);
        void setMinutes(int minutes);
        void setHours(int hours);

        // comparison operators: as member methods
        //bool operator== (const Time& other);
        //bool operator!= (const Time& other);
        //bool operator<= (const Time& other);
        //bool operator<  (const Time& other);
        //bool operator>= (const Time& other);
        //bool operator>  (const Time& other);

        // comparison operators - global methods declared as friends
        friend bool operator== (const Time& left, const Time& right);
        friend bool operator!= (const Time& left, const Time& right);
        friend bool operator<= (const Time& left, const Time& right);
        friend bool operator<  (const Time& left, const Time& right);
        friend bool operator>= (const Time& left, const Time& right);
        friend bool operator>  (const Time& left, const Time& right);

        // public interface
        void print();
    };

    // or as global methods
    //bool operator== (const Time& left, const Time& right);
    //bool operator!= (const Time& left, const Time& right);
    //bool operator<= (const Time& left, const Time& right);
    //bool operator<  (const Time& left, const Time& right);
    //bool operator>= (const Time& left, const Time& right);
    //bool operator>  (const Time& left, const Time& right);
}

// ===========================================================================
// End-of-File
// ===========================================================================
