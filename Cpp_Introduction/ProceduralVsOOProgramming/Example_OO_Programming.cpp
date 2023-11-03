// ===========================================================================
// Example_OO_Programming.cpp // Comparison OO versus Procedural Programming
// ===========================================================================

#include <iostream>

namespace Procedural_Versus_OO_Programming {

    const double Pi = 3.14159265358979323846;

    class Circle
    {
    public:
        double m_radius;

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
    public:
        double m_length;

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
    std::cin >> circle.m_radius;
    
    std::cout << "Circumference of Circle: " << circle.circumference() << std::endl;
    std::cout << "Area of Circle: " << circle.area() << std::endl;
    
    std::cout << std::endl << "Enter Side Length of Square: ";
    std::cin >> square.m_length;
    
    std::cout << "Circumference of Square: " << square.circumference() << std::endl;
    std::cout << "Area of Square: " << square.area() << std::endl;
}

// ===========================================================================
// End-of-File
// ===========================================================================
