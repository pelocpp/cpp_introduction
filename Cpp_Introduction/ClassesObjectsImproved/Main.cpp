// ===========================================================================
// Main.cpp // Classes and Objects Improved
// ===========================================================================

#include "Time.h"

namespace Classes_Objects_Motivating_This
{
    class Time
    {
    private:
        int seconds;
        int minutes;
        int hours;

    public:
        // getter // setter
        void setHours(int hours);
    };

    void Time::setHours(int hours)
    {
        if (0 <= hours && hours < 24) {
            hours = hours;          // wrong !!!
            // vs
            this->hours = hours;    // correct !!!
        }
        else {
            // some error handling ...
        }
    }
}

static void classesObjectsImproved()
{
    using namespace Classes_Objects_Improved;

    Time now;
    now.setHours(10);
    now.setMinutes(20);
    now.setSeconds(30);
    now.print();

    // now.m_hours = 9999;   // doesn't compile

    now.increment();
    now.print();

    now.decrement();
    now.print();

    Time what;
    what.setHours(9999);
    what.print();            // watch output carefully
}

void main_ClassesObjectsImproved()
{
    classesObjectsImproved();
}

// ===========================================================================
// End-of-File
// ===========================================================================
