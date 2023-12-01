// ===========================================================================
// DynamicArray_Main.cpp
// ===========================================================================

#include "DynamicArray.h"

void exerciseDynamicArray01()
{
    DynamicArray array(3);
    array.print();
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array.print();
}

void exerciseDynamicArray02()
{
    DynamicArray array(3);
    array.print();

    array.fill(123);
    array.print();

    array.release();
    array.print();
}

void exerciseDynamicArray03()
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

void exerciseDynamicArray04()
{
    DynamicArray array1(3);
    DynamicArray array2(5);
    array1.print();
    array2.print();

    array1 = array2;
    array1.print();
}

void exerciseDynamicArray05()
{
    DynamicArray array1(3);
    DynamicArray array2(array1);
    array1.print();
    array2.print();
}

void exerciseDynamicArray()
{
    exerciseDynamicArray01();
    exerciseDynamicArray02();
    exerciseDynamicArray03();
    exerciseDynamicArray04();
    exerciseDynamicArray05();
}

// ===========================================================================
// End-of-File
// ===========================================================================
