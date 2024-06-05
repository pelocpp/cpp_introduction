// ===========================================================================
// Example_Procedural_Programming.cpp /
// Comparison OO versus Procedural Programming
// ===========================================================================

#include <iostream>

namespace Procedural_Versus_OO_Programming {

    const double Pi = 3.14159265358979323846;

    // several functions (also called procedures)
    static double circumferenceCircle(double radius)
    {
        return 2 * Pi * radius;
    }

    static double areaCircle(double radius)
    {
        return Pi * radius * radius;
    }

    static double circumferenceSquare(double length)
    {
        return 4 * length;
    }

    static double areaSquare(double length)
    {
        return length * length;
    }
}

void comparisonProcedural()
{
    using namespace Procedural_Versus_OO_Programming;

    double radius;
    double seite;

    std::cout << "Enter a Radius: ";
    std::cin >> radius;

    std::cout << "Circumference: " << circumferenceCircle(radius) << std::endl;
    std::cout << "Area: " << areaCircle(radius) << std::endl << std::endl;

    std::cout << "Enter Length: ";
    std::cin >> seite;

    std::cout << "Circumference: " << circumferenceSquare(seite) << std::endl;
    std::cout << "Area: " << areaSquare(seite) << std::endl;
}

// ===========================================================================
// End-of-File
// ===========================================================================
