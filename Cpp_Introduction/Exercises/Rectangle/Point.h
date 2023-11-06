// ===========================================================================
// Point.h
// ===========================================================================

#pragma once

#include <iostream>

namespace Rectangle {

    class Point
    {
    private:
        double m_x;
        double m_y;

    public:
        // c'tor(s)
        Point();
        Point(double, double);

        // getter/setter
        double getX();
        double getY();
        void setX(double);
        void setY(double);
    };
}

// ===========================================================================
// End-of-File
// ===========================================================================
