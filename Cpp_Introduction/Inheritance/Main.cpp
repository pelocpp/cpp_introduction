// ===========================================================================
// Main.cpp // Inheritance
// ===========================================================================

#include <iostream>

namespace Inheritance
{
    class Rectangle
    {
    private:
        int m_x;
        int m_y;
        int m_width;
        int m_height;

    public:
        // c'tor(s)
        Rectangle() : Rectangle(0, 0, 0, 0) {}

        Rectangle(int x, int y, int width, int height)
            : m_x(x), m_y(y), m_width(width), m_height(height)
        {}

        // getter
        int getX() { return m_x; }
        int getY() { return m_y; }
        int getWidth() { return m_width; }
        int getHeight() { return m_height; }

        // public interface
        void eraseBackground()
        {
            std::cout << "  Rectangle::eraseBackground" << std::endl;
        }

        void draw() {

            std::cout
                << "Rectangle::draw [x=" << getX()
                << ", y=" << getY() << "]" << std::endl;

            eraseBackground();
        }
    };

    // =======================================================================

    class ColoredRectangle : public Rectangle
    {
    private:
        int m_color;  // representing some color model

    public:
        // c'tor(s)
        ColoredRectangle() : ColoredRectangle(0, 0, 0, 0, 0) {}

        ColoredRectangle(int x, int y, int width, int height, int color)
            : Rectangle(x, y, width, height), m_color(123)
        {}
    };

    // =======================================================================

    class TransparentRectangle : public Rectangle
    {
    private:
        double m_opaque;  // representing some transparency model

    public:
        // c'tor(s)
        TransparentRectangle() 
            : TransparentRectangle(0, 0, 0, 0, 0.0)
        {}

        TransparentRectangle(int x, int y, int width, int height, double transparency)
            : Rectangle(x, y, width, height), m_opaque(transparency)
        {}
    };
}

// ===========================================================================

namespace InheritanceImproved
{
    class Rectangle
    {
    private:
        int m_x;
        int m_y;
        int m_width;
        int m_height;

    public:
        // c'tor(s)
        Rectangle() : Rectangle(0, 0, 0, 0) {}

        Rectangle(int x, int y, int width, int height)
            : m_x(x), m_y(y), m_width(width), m_height(height)
        {}

        // getter
        int getX() { return m_x; }
        int getY() { return m_y; }
        int getWidth() { return m_width; }
        int getHeight() { return m_height; }

        // public interface
        void eraseBackground()
        {
            std::cout << "  Rectangle::eraseBackground" << std::endl;
        }

        void draw() {

            std::cout
                << "Rectangle::draw [x=" << getX()
                << ", y=" << getY() << "]" << std::endl;

            eraseBackground();
        }
    };

    // =======================================================================

    class ColoredRectangle : public Rectangle
    {
    private:
        int m_color;   // representing some color model

    public:
        // c'tor(s)
        ColoredRectangle() : ColoredRectangle(0, 0, 0, 0, 0) {}

        ColoredRectangle(int x, int y, int width, int height, int color)
            : Rectangle(x, y, width, height), m_color(123)
        {}

        void draw() {

            Rectangle::draw();

            std::cout
                << "  ColoredRectangle::draw [color = " << m_color << "]" << std::endl;
        }
    };

    // =======================================================================

    class TransparentRectangle : public Rectangle
    {
    private:
        int m_opaque;  // representing some transparency model

    public:
        // c'tor(s)
        TransparentRectangle()
            : TransparentRectangle(0, 0, 0, 0, 0.0)
        {}

        TransparentRectangle(int x, int y, int width, int height, double color)
            : Rectangle(x, y, width, height), m_opaque(123)
        {}

        void draw() {

            Rectangle::draw();

            std::cout
                << "  ColoredRectangle::draw [transparency = " << m_opaque << "]" << std::endl;
        }
    };
}

void testInheritance()
{
    using namespace Inheritance;
    // vs
    // using namespace InheritanceImproved;


    ColoredRectangle cr(1, 1, 20, 30, 255);
    TransparentRectangle tr(2, 2, 30, 40, 111.0);

    cr.draw();
    tr.draw();
}

// ===========================================================================
// End-of-File
// ===========================================================================
