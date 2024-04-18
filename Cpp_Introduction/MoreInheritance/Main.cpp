// ===========================================================================
// Main.cpp // More Inheritance
// ===========================================================================

#include <iostream>

namespace MoreInheritance
{
    // interfaces
    class IRectangle
    {
    public:
        virtual void draw() = 0;
        virtual void drawForeground() = 0;
        virtual void eraseBackground() = 0;
    };

    class IPersistence
    {
    public:
        virtual void save() = 0;
    };

    // =======================================================================

    // abstract base class
    class Rectangle : public IRectangle
    {
    protected:
        int m_x;
        int m_y;
        int m_width;
        int m_height;

    public:
        Rectangle() 
            : Rectangle(0, 0, 0, 0)
        {}

        Rectangle(int x, int y, int width, int height)
            : m_x(x), m_y(y), m_width(width), m_height(height)
        {}

        virtual void eraseBackground() override final {
            std::cout << "  Rectangle::eraseBackground" << std::endl;
        }

        virtual void draw() override final {
            std::cout << "Rectangle::draw [x=" << m_x << ", y=" << m_y << "]" << std::endl;
            eraseBackground();
            drawForeground();
        }
    };

    // =======================================================================

    class ColoredRectangle : public Rectangle
    {
    private:
        int m_color;  // representing some color model

    public:
        ColoredRectangle()
            : ColoredRectangle(0, 0, 0, 0, 0)
        {}

        ColoredRectangle(int x, int y, int width, int height, int color)
            : Rectangle(x, y, width, height), m_color(123)
        {}

        void paint() {
            std::cout
                << "  ColoredRectangle::paint: width=" << m_width
                << ", height: " << m_height << std::endl;
        }

        virtual void drawForeground() override {
            std::cout << "  ColoredRectangle::drawForeground" << std::endl;
        }
    };

    // =======================================================================

    class TransparentRectangle : public Rectangle
    {
    private:
        double m_opacity;   // representing some transparency model
    
    public:
        TransparentRectangle() 
            : TransparentRectangle(0, 0, 0, 0, 0.0)
        {}

        TransparentRectangle(int x, int y, int width, int height, double opacity)
            : Rectangle(x, y, width, height), m_opacity(opacity)
        {}

        virtual void drawForeground() override {
            std::cout << "  TransparentRectangle::drawForeground" << std::endl;
        }
    };

    // =======================================================================

    class HatchedColoredRectangle : public ColoredRectangle
    {
    public:
        HatchedColoredRectangle() 
            : HatchedColoredRectangle(0, 0, 0, 0, 0, 0.0)
        {}

        HatchedColoredRectangle(int x, int y, int width, int height, int color, double strokeThickness)
            : ColoredRectangle(x, y, width, height, color), m_strokeThickness(strokeThickness)
        {}

        void paint() {
            std::cout
                << "  HatchedColoredRectangle::paint: width=" << m_width
                << ", height: " << m_height << std::endl;
        }

        virtual void drawForeground() override {
            std::cout << "  HatchedColoredRectangle::drawForeground" << std::endl;
        }

    private:
        double m_strokeThickness;
    };
}

static void testMoreInheritance01()
{
    using namespace MoreInheritance;

    // Rectangle is an abstract base class
    // Rectangle rect;   // does not compile!

    HatchedColoredRectangle hcr;
    ColoredRectangle& crRef = hcr;
  
    // paint is not virtual
    crRef.paint();
}

static void testMoreInheritance02()
{
    using namespace MoreInheritance;

    HatchedColoredRectangle hcr;

    ColoredRectangle& crRef(hcr);
    // or
    // ColoredRectangle* crPtr(&hcr);

    crRef.draw();
    // or
    // crPtr->draw();
}

static void testMoreInheritance03()
{
    using namespace MoreInheritance;

    ColoredRectangle cr1(1, 1, 20, 30, 255);
    TransparentRectangle tr(2, 2, 30, 40, 111.0);
    ColoredRectangle cr3(3, 3, 50, 60, 127);

    IRectangle* rects[]{ &cr1, &tr, &cr3 };

    for (int i = 0; i < 3; ++i) {
        rects[i]->draw();
    }
}

void testMoreInheritance()
{
    testMoreInheritance01();
    testMoreInheritance02();
    testMoreInheritance03();
}

// ===========================================================================
// End-of-File
// ===========================================================================
