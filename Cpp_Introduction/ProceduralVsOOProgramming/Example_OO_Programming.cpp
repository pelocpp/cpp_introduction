// ===========================================================================
// Example_OO_Programming.cpp // Comparison OO versus Procedural Programming
// ===========================================================================

#include <iostream>

namespace Procedural_Versus_OO_Programming {

    const double Pi = 3.14159265358979323846;

    class Circle
    {
    private:
        double m_radius;

    public:
        Circle()
        {
            m_radius = 0;
        }

        void setRadius(double radius)
        {
            if (radius > 0) {
                m_radius = radius;
            }
        }

        double circumference()
        {
            return 2 * m_radius * Pi;
        }

        double area()
        {
            return Pi * m_radius * m_radius;
        }
    };

    class Square
    {
    private:
        double m_length;

    public:
        Square()
        {
            m_length = 0;
        }

        void setlength(double length)
        {
            if (length > 0) {
                m_length = length;
            }
        }

        double circumference()
        {
            return 4 * m_length;
        }

        double area()
        {
            return m_length * m_length;
        }
    };
}

void testComparisonOO()
{
    using namespace Procedural_Versus_OO_Programming;

    Circle circle;
    Square square;

    std::cout << "Enter Radius of Circle: ";
    double radius;
    std::cin >> radius;
    circle.setRadius(radius);
    
    std::cout << "Circumference of Circle: " << circle.circumference() << std::endl;
    std::cout << "Area of Circle: " << circle.area() << std::endl;
    
    std::cout << std::endl << "Enter Side Length of Square: ";
    double length;
    std::cin >> length;
    square.setlength(length);
    
    std::cout << "Circumference of Square: " << square.circumference() << std::endl;
    std::cout << "Area of Square: " << square.area() << std::endl;
}

// ===========================================================================
// End-of-File
// ===========================================================================
