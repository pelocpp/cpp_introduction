// ===============================================================================
// Rectangle.h
// ===============================================================================

#pragma once

#include <iostream>

#include "Point.h"

namespace Rectangle {

    class Rectangle
    {
    private:
        double m_x;
        double m_y;
        double m_width;
        double m_height;

    public:
        // c'tors
        Rectangle();
        Rectangle(double x, double left, double width, double height);

        // getter/setter
        double getX();
        double getY();
        double getWidth();
        double getHeight();

        void setX(double x);
        void setY(double y);
        void setWidth(double width);
        void setHeight(double height);

        // public interface // methods
        double circumference();
        double diagonal();
        double area();
        bool isSquare();
        void moveTo(double, double);
        bool equals(Rectangle other);
        Point center();
        Rectangle intersection(Rectangle other);
        void print();
    };
}

// ===============================================================================
// End-of-File
// ===============================================================================
