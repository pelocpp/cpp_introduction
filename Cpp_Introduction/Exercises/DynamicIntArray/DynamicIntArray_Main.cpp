// ===========================================================================
// DynamicIntArray_Main.cpp
// ===========================================================================

#include "DynamicIntArray.h"

static void testDynamicIntArray01()
{
    DynamicIntArray array(3);
    array.print();
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array.print();
}

static void testDynamicIntArray02()
{
    DynamicIntArray array(3);
    array.print();

    array.fill(123);
    array.print();

    array.release();
    array.print();
}

static void testDynamicIntArray03()
{
    DynamicIntArray array(3);
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

static void testDynamicIntArray04()
{
    DynamicIntArray array1(3);
    DynamicIntArray array2(5);
    array1.print();
    array2.print();

    array1 = array2;
    array1.print();
}

static void testDynamicIntArray05()
{
    DynamicIntArray array1(3);
    DynamicIntArray array2(array1);
    array1.print();
    array2.print();
}

void exerciseDynamicIntArray()
{
    testDynamicIntArray01();
    testDynamicIntArray02();
    testDynamicIntArray03();
    testDynamicIntArray04();
    testDynamicIntArray05();
}

// ===========================================================================
// End-of-File
// ===========================================================================
