#include "Rectangle.h"

static void test01_ctors()
{
    using namespace Rectangles;

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

static void test02_methods()
{
    using namespace Rectangles;

    Rectangle rect(3, 4, 9, 10);
    rect.print();
    std::cout << "Circumference: " << rect.circumference() << std::endl;
    std::cout << "Diagonal:      " << rect.diagonal() << std::endl;
    std::cout << "Area:          " << rect.area() << std::endl;
    std::cout << "IsSquare:      " << rect.isSquare() << std::endl;
}

static void test03_center()
{
    using namespace Rectangles;

    Rectangle rect1(1, 3, 3, 1);
    rect1.print();
    Point p = rect1.center();
    std::cout << "Center: (" << p.getX() << "," << p.getY() << ')' << std::endl;

    Rectangle rect2(1, 4, 4, 1);
    rect2.print();
    p = rect2.center();
    std::cout << "Center: (" << p.getX() << "," << p.getY() << ')' << std::endl;
}

static void test04_move()
{
    using namespace Rectangles;

    Rectangle rect(1, 1, 4, 5);
    rect.print();
    rect.moveTo(5, -5);
    rect.print();
}

static void test05_intersection()
{
    using namespace Rectangles;

    Rectangle center(30, 30, 10, 10);

    Rectangle upperLeft(10, 10, 10, 10);
    Rectangle upperRight(50, 10, 10, 10);
    Rectangle lowerLeft(10, 50, 10, 10);
    Rectangle lowerRight(50, 50, 10, 10);

    Rectangle intersection;

    intersection = center.intersection(upperLeft);
    intersection.print();
    intersection = center.intersection(upperRight);
    intersection.print();
    intersection = center.intersection(lowerLeft);
    intersection.print();
    intersection = center.intersection(lowerRight);
    intersection.print();
}

static void test06_intersection()
{
    using namespace Rectangles;

    Rectangle center(20, 20, 30, 30);

    Rectangle upperLeft(10, 10, 20, 20);
    Rectangle upperRight(40, 10, 20, 20);
    Rectangle lowerLeft(10, 40, 20, 20);
    Rectangle lowerRight(40, 40, 20, 20);

    Rectangle intersection;

    intersection = center.intersection(upperLeft);
    intersection.print();
    intersection = center.intersection(upperRight);
    intersection.print();
    intersection = center.intersection(lowerLeft);
    intersection.print();
    intersection = center.intersection(lowerRight);
    intersection.print();
}

static void test07_equals()
{
    using namespace Rectangles;

    Rectangle rect1(1, 1, 4, 5);
    Rectangle rect2(1, 1, 4, 5);
    bool equals = rect1.equals(rect2);
    std::cout << equals << std::endl;
    rect2.setX(10);
    equals = rect1.equals(rect2);
    std::cout << equals << std::endl;
}

void exerciseRectangle()
{
    using namespace Rectangles;

    test01_ctors();
    test02_methods();
    test03_center();
    test04_move();
    test05_intersection();
    test06_intersection();
    test07_equals();
}

// ===========================================================================
// End-of-File
// ===========================================================================
