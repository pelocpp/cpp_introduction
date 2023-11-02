// ===========================================================================
// Time.h
// ===========================================================================

#pragma once

#include <iostream>

class Time
{
public:
    // instance variables
    int m_seconds;
    int m_minutes;
    int m_hours;

public:
    // public interface / methods
    void reset();
    void increment();
    void print();



    // conversion operator
    operator int();

    // input / output
    friend std::ostream & operator<< (std::ostream&, const Time&);
    friend std::istream & operator>> (std::istream&, Time&);

private:
    // helper methods
    int timeToSeconds();
    void secondsToTime(int seconds);
};

// ===========================================================================
// End-of-File
// ===========================================================================
