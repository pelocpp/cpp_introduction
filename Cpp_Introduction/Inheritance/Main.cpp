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
        int getX() const { return m_x; }
        int getY() const { return m_y; }
        int getWidth() const { return m_width; }
        int getHeight() const { return m_height; }

        // setter
        void setX(int x) { m_x = x; }
        void setY(int y) { m_y = y; }
        void setWidth(int width) { m_width = width; }
        void setHeight(int height) { m_height = height; }

        // public interface
        void eraseBackground()
        {
            std::cout << "  Rectangle::eraseBackground" << std::endl;
        }

        void draw() {

            std::cout
                << "Rectangle::draw [x=" << m_x
                << ", y=" << m_y << "]" << std::endl;

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
        double m_opacity;  // representing some transparency model

    public:
        // c'tor(s)
        TransparentRectangle()
            : TransparentRectangle(0, 0, 0, 0, 0.0)
        {}

        TransparentRectangle(int x, int y, int width, int height, double opacity)
            : Rectangle(x, y, width, height), m_opacity(123.45)
        {}

        void draw() {

            Rectangle::draw();

            std::cout
                << "  ColoredRectangle::draw [opacity = " << m_opacity << "]" << std::endl;
        }
    };
}

void main_Inheritance()
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
