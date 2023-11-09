#include "Rectangle.h"

namespace Rectangle {

    void exercise01_ctors()
    {
        Rectangle rect1;
        rect1.print();
        Rectangle rect2(3, 3, 5, 5);
        rect2.print();
        Rectangle rect3(3, 3, 5, 1);
        rect3.print();
        Rectangle rect4(3, 3, 1, 1);
        rect4.print();
        Rectangle rect5(3, 3, 1, 5);
        rect5.print();
    }

    void exercise02_methods()
    {
        Rectangle rect(3, 4, 9, 10);
        rect.print();
        std::cout << "Circumference: " << rect.circumference() << std::endl;
        std::cout << "Diagonal:      " << rect.diagonal() << std::endl;
        std::cout << "Area:          " << rect.area() << std::endl;
        std::cout << "IsSquare:      " << rect.isSquare() << std::endl;
    }

    void exercise03_center()
    {
        Rectangle rect1(1, 3, 3, 1);
        rect1.print();
        Point p = rect1.center();
        std::cout << "Center: (" << p.getX() << "," << p.getY() << ')' << std::endl;

        Rectangle rect2(1, 4, 4, 1);
        rect2.print();
        p = rect2.center();
        std::cout << "Center: (" << p.getX() << "," << p.getY() << ')' << std::endl;
    }

    void exercise04_move()
    {
        Rectangle rect(1, 1, 4, 5);
        rect.print();
        rect.moveTo(5, -5);
        rect.print();
    }

    void exercise05_intersection()
    {
        Rectangle rect1(4, 8, 9, 5);
        Rectangle rect2(2, 10, 8, 6);
        Rectangle rect = rect1.intersection(rect2);

        rect1.print();
        rect2.print();
        rect.print();

        Rectangle rect3(7, 9, 9, 4);
        rect = rect1.intersection(rect3);
        rect.print();

        rect = rect3.intersection(rect3);
        rect.print();

        Rectangle rect4(6, 7, 10, 5);
        rect = rect1.intersection(rect4);
        rect.print();
    }

    void exercise06_equals()
    {
        Rectangle rect1(1, 1, 4, 5);
        Rectangle rect2(1, 1, 4, 5);
        bool equals = rect1.equals(rect2);
        std::cout << equals << std::endl;
        rect2.setX(10);
        equals = rect1.equals(rect2);
        std::cout << equals << std::endl;
    }

    void test_version_03() {
        exercise01_ctors();
        exercise02_methods();
        exercise03_center();
        exercise04_move();
        exercise05_intersection();
        exercise06_equals();
    }
}

void exerciseRectangle()
{
    using namespace Rectangle;

    exercise01_ctors();
    exercise02_methods();
    exercise03_center();
    exercise04_move();
    exercise05_intersection();
    exercise06_equals();
}

// ===========================================================================
// End-of-File
// ===========================================================================
