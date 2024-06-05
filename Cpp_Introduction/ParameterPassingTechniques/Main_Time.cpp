// ===========================================================================
// Main_Time.cpp // Method Signatures
// ===========================================================================

#include <iostream>

#include "Time.h"

static void testClassTimeParameterPassing_01()
{
    using namespace Classes_Objects_Improved_Parameter_Passing;

    {
        // testing 'Add'
        Time t1(0, 0, 12);
        Time t2(50, 30, 3);
        for (int i = 0; i < 5; i++)
        {
            t1.add(t2);
            t1.print();
        }
    }

    {
        // testing 'Diff'
        Time t1;
        Time t2(59, 59, 23);
        Time t3 = t1.diff(t2);
        t3.print();
        t3 = t2.diff(t1);
        t3.print();
    }

}

void main_ClassTimeParameterPassing()
{
    testClassTimeParameterPassing_01();
}

// ===========================================================================
// End-of-File
// ===========================================================================
