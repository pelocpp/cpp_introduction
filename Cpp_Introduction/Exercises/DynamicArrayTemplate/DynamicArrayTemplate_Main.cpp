// ===========================================================================
// DynamicArrayTemplate_Main.cpp
// ===========================================================================

#include "DynamicArrayTemplate.h"

void exerciseDynamicArrayTemplate01()
{
    DynamicArrayTemplate<int> da;
    da.print();

    da.fill(123);
    da.print();

    da.resize(8);
    da.print();
}


void exerciseDynamicArrayTemplate02()
{
    DynamicArrayTemplate<double> da(7);

    da.fill(5.55);
    da.print();

    da.resize(12);
    da.print();
}

void exerciseDynamicArrayTemplate03()
{
    DynamicArrayTemplate<std::string> da(5);

    da.fill(std::string("<empty>"));
    da.print();

    da.resize(8);
    da.print();
}

void exerciseDynamicArrayTemplate04()
{
    DynamicArrayTemplate<std::string> array(3);
    array[0] = "one";
    array[1] = "two";
    array[2] = "three";
    array.print();
}

void exerciseDynamicArrayTemplate05()
{
    DynamicArrayTemplate<std::string> array(3);

    array.fill("<empty>");
    array.print();

    array.release();
    array.print();
}

void exerciseDynamicArrayTemplate06()
{
    DynamicArrayTemplate<std::string> array(3);
    array[0] = "one";
    array[1] = "two";
    array[2] = "three";
    array.print();

    array.resize(6);
    array.print();

    array[3] = "four";
    array[4] = "five";
    array[5] = "six";
    array.print();

    array.resize(2);
    array.print();
}

void exerciseDynamicArrayTemplate07()
{
    DynamicArrayTemplate<std::string> array1(3);
    array1.fill("<empty>");

    DynamicArrayTemplate<std::string> array2(5);
    array2.fill("<EMPTY>");

    array1.print();
    array2.print();

    array1 = array2;
    array1.print();
}

void exerciseDynamicArrayTemplate08()
{
    DynamicArrayTemplate<std::string> array1(3);
    array1.fill("<empty>");

    DynamicArrayTemplate<std::string> array2(array1);
    array1.print();
    array2.print();
}

void exerciseDynamicArrayTemplate09()
{
    DynamicArrayTemplate<std::string> array1(3);
    array1.fill("<empty>");

    DynamicArrayTemplate<std::string> array2(array1);
    std::cout << std::boolalpha << (array1 == array2) << std::endl;

    array1[1] = "<EMPTY>";
    std::cout << std::boolalpha << (array1 == array2) << std::endl;
}

void exerciseDynamicArrayTemplate()
{
    exerciseDynamicArrayTemplate01();
    exerciseDynamicArrayTemplate02();
    exerciseDynamicArrayTemplate03();
    exerciseDynamicArrayTemplate04();
    exerciseDynamicArrayTemplate05();
    exerciseDynamicArrayTemplate06();
    exerciseDynamicArrayTemplate07();
    exerciseDynamicArrayTemplate08();
    exerciseDynamicArrayTemplate09();
}

// ===========================================================================
// End-of-File
// ===========================================================================
