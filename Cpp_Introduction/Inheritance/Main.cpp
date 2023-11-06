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
        void drawBorder()
        {
            std::cout
                << "  Rectangle::drawBorder: width=" << m_width
                << ", height: " << m_height << std::endl;
        }

        void eraseBackground()
        {
            std::cout << "  Rectangle::eraseBackground" << std::endl;
        }
    };

    // =======================================================================

    class ColoredRectangle : public Rectangle
    {
    private:
        double m_hsv;  // hue, saturation, value

    public:
        // c'tor(s)
        ColoredRectangle() : ColoredRectangle(0, 0, 0, 0, 0.0) {}

        ColoredRectangle(int x, int y, int width, int height, double color)
            : Rectangle(x, y, width, height), m_hsv(123)
        {}

        // public interface
        void draw() {

            eraseBackground();
            drawBorder();
            std::cout
                << "ColoredRectangle::draw [x=" << getX()
                << ", y=" << getY() << "]" << std::endl;
        }
    };

    // =======================================================================

    class TransparentRectangle : public Rectangle
    {
    private:
        int m_opaque;  // transparency value

    public:
        // c'tor(s)
        TransparentRectangle() 
            : TransparentRectangle(0, 0, 0, 0, 0.0)
        {}

        TransparentRectangle(int x, int y, int width, int height, double color)
            : Rectangle(x, y, width, height), m_opaque(123) 
        {}

        // public interface
        void draw()
        {
            eraseBackground();
            drawBorder();

            std::cout
                << "TransparentRectangle::draw [x=" 
                << getX() << ", y=" << getY() << "]" << std::endl;
        }
    };
}

void testInheritance()
{
    using namespace Inheritance;

    ColoredRectangle cr(1, 1, 20, 30, 255);
    TransparentRectangle tr(2, 2, 30, 40, 111.0);

    cr.draw();
    tr.draw();
}

// ===========================================================================
// End-of-File
// ===========================================================================
