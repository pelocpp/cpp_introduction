// ===========================================================================
// DynamicArray_Main.cpp
// ===========================================================================

#include "DynamicArray.h"

void testDynamicArray01()
{
    DynamicArray array(3);
    array.print();
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array.print();
}

void testDynamicArray02()
{
    DynamicArray array(3);
    array.print();
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array.print();

    array.resize(6);
    array.print();

    array[3] = 3;
    array[4] = 4;
    array[5] = 5;
    array.print();

    array.resize(2);
    array.print();
}

void testDynamicArray03()
{
    DynamicArray array1(3);
    DynamicArray array2(5);
    array1.print();
    array2.print();

    array1 = array2;
    array1.print();
}

void testDynamicArray04()
{
    DynamicArray array1(3);
    DynamicArray array2(array1);
    array1.print();
    array2.print();
}

void testDynamicArray()
{
    testDynamicArray01();
    testDynamicArray02();
    testDynamicArray03();
    testDynamicArray04();
}

// ===========================================================================
// End-of-File
// ===========================================================================
