// ===========================================================================
// Main.cpp  // Templates
// ===========================================================================

#include <iostream>

namespace Templates {

    // implementation of two very similar calculator classes
    class IntCalculator
    {
    public:
        static int add(int x, int y) { return x + y; }
        static int sub(int x, int y) { return x - y; }
        static int mul(int x, int y) { return x * y; }
        static int div(int x, int y) { return x / y; }
    };

    class DoubleCalculator
    {
    public:
        static double add(double x, double y) { return x + y; }
        static double sub(double x, double y) { return x - y; }
        static double mul(double x, double y) { return x * y; }
        static double div(double x, double y) { return x / y; }
    };

    // implementation of a SINGLE calculator class - using templates technique
    template <typename T>
    class Calculator
    {
    public:
        static T add(T x, T y) { return x + y; }
        static T sub(T x, T y) { return x - y; }
        static T mul(T x, T y) { return x * y; }
        static T div(T x, T y) { return x / y; }
    };
}

void testTemplates01()
{
    using namespace Templates;

    int result = IntCalculator::add(123, 456);
    std::cout << "IntCalculator: " << result << std::endl;

    double x = 123.456;
    double y = 654.321;
    double dresult = DoubleCalculator::add(x, y);
    std::cout << "DoubleCalculator: " << dresult << std::endl;
}

void testTemplates02()
{
    using namespace Templates;

    int result = Calculator<int>::add(123, 456);
    std::cout << "Calculator<int>: " << result << std::endl;

    double x = 123.456;
    double y = 654.321;
    double dresult = Calculator<double>::add(x, y);
    std::cout << "Calculator<double>: " << dresult << std::endl;
}

void testTemplates()
{
    using namespace Templates;

    testTemplates01();
    testTemplates02();
}


// ===========================================================================
// End-of-File
// ===========================================================================
