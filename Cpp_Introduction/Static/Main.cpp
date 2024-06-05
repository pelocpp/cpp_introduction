// ===========================================================================
// Main.cpp // Keyword 'static'
// ===========================================================================

#include <iostream>

namespace Violating_Static
{
    class Math
    {
    private:
        double m_pi;

    public:
        Math()
        {
            m_pi = 3.14159265358979323846;
        }

        double Pi() { return m_pi; }
    };

    void violatingStatic01()
    {
        Math math;

        double radius = math.Pi() * 2.0 * 2.0;
    }

    class Calculator
    {
    public:
        int add(int x, int y) { return x + y; }
        int sub(int x, int y) { return x + y; }
        int mul(int x, int y) { return x + y; }
        int div(int x, int y) { return x + y; }
    };

    static void violatingStatic02()
    {
        Calculator calc;

        int sum = calc.add(123, 456);
    }
}

namespace Motivating_Static
{
    class Math
    {
    public:
        static const double Pi;
    };

    double const Math::Pi = 3.14159265358979323846;

    void motivatingStatic01()
    {
        double radius = Math::Pi * 2.0 * 2.0;
    }

    class Calculator
    {
    public:
        static int add(int x, int y) { return x + y; }
        static int sub(int x, int y) { return x + y; }
        static int mul(int x, int y) { return x + y; }
        static int div(int x, int y) { return x + y; }
    };

    static void motivatingStatic02()
    {
        int sum = Calculator::add(123, 456);
    }
}


void main_Static()
{
    using namespace Violating_Static;
    using namespace Motivating_Static;

    violatingStatic01();
    violatingStatic02();
    motivatingStatic01();
    motivatingStatic02();
}

// ===========================================================================
// End-of-File
// ===========================================================================
