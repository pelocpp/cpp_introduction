// ===========================================================================
// Wallet_Main.cpp
// ===========================================================================

#include <iostream>

#include "Wallet.h"

static void test_01_ctors()
{
    Wallet empty;
    empty.print();

    Wallet wallet(123, 45);
    wallet.print();
}

static void test_02_ctors()
{
    try
    {
        Wallet wallet("123", "45");
        //Wallet wallet("ABC", "45");
        //Wallet wallet("123", "DE");
        //Wallet wallet("123DE", "45");
        //Wallet wallet("123", "45DE");
        //Wallet wallet("-123", "45");
        //Wallet wallet("123", "-45");
        wallet.print();
    }
    catch (const std::exception& ex)
    {
        std::cout << "Wrong parameters: " << ex.what() << std::endl;
    }
}

static void test_03_toString()
{
    Wallet empty;
    std::cout << empty.to_string() << std::endl;

    Wallet wallet(123, 55);
    std::cout << wallet.to_string() << std::endl;
}

static void test_04_add()
{
    Wallet wallet1(123, 45);
    Wallet wallet2(3, 30);
    Wallet wallet3(3, 30);
    Wallet wallet4(3, 30);
    Wallet wallet5(3, 30);

    wallet1.add(wallet2);
    std::cout << wallet1 << std::endl;
    wallet1.add(wallet3);
    std::cout << wallet1 << std::endl;
    wallet1.add(wallet4);
    std::cout << wallet1 << std::endl;
    wallet1.add(wallet5);
    std::cout << wallet1 << std::endl;
}

static void test_05_sub()
{
    Wallet wallet1(0, 3);
    Wallet wallet2(0, 1);
    wallet1.sub(wallet2);
    std::cout << wallet1 << std::endl;
    wallet1.sub(wallet2);
    std::cout << wallet1 << std::endl;
    wallet1.sub(wallet2);
    std::cout << wallet1 << std::endl;

    try
    {
        wallet1.sub(wallet2);
    }
    catch (const std::invalid_argument& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

static void test_06_add_sub_euros()
{
    Wallet wallet(5);
    wallet.add(5);
    std::cout << wallet<< std::endl;
    wallet.sub(10);
    std::cout << wallet << std::endl;
}

static void test_07_comparision()
{
    Wallet wallet1(10, 20);
    Wallet wallet2(20, 10);

    std::cout << std::boolalpha << (wallet1 == wallet1) << std::endl;
    std::cout << std::boolalpha << (wallet1 == wallet2) << std::endl;
    std::cout << std::boolalpha << (wallet1 != wallet2) << std::endl;

    std::cout << std::boolalpha << (wallet1  < wallet2) << std::endl;
    std::cout << std::boolalpha << (wallet1 <= wallet2) << std::endl;
    std::cout << std::boolalpha << (wallet1  > wallet2) << std::endl;
    std::cout << std::boolalpha << (wallet1 >= wallet2) << std::endl;
}

static void test_08_arithmetic_increment_operators()
{
    Wallet wallet1(123, 45);
    Wallet wallet2(26, 55);

    wallet1 += wallet2;
    std::cout << wallet1 << std::endl;
    wallet1 += 50;
    std::cout << wallet1 << std::endl;

    wallet1 -= wallet2;
    std::cout << wallet1 << std::endl;
    wallet1 -= 73;
    std::cout << wallet1 << std::endl;
}

static void test_09_increment_operators()
{
    Wallet wallet(10);
    Wallet wallet1;

    std::cout << wallet << std::endl;

    wallet1 = ++wallet;
    std::cout << wallet1 << std::endl;

    wallet1 = --wallet;
    std::cout << wallet1 << std::endl;

    wallet1 = wallet--;
    std::cout << wallet1 << std::endl;
    std::cout << wallet << std::endl;

    wallet1 = wallet++;
    std::cout << wallet1 << std::endl;
    std::cout << wallet << std::endl;
}

static void test_10_example_tutorial()
{
    Wallet wallet(2, 50);
    std::cout << wallet << std::endl;

    std::cout << "Wallet contains " << wallet.getEuros() << " euros." << std::endl;
    std::cout << "Wallet contains " << wallet.getCent() << " cent." << std::endl;
}

static void test_11_example_tutorial()
{
    Wallet wallet(2, 50);
    std::cout << wallet << std::endl;

    wallet.add(5);
    std::cout << wallet << std::endl;

    wallet.sub(7);
    std::cout << wallet << std::endl;
}

static void test_12_example_tutorial()
{
    Wallet wallet(2, 50);
    std::cout << wallet << std::endl;

    try
    {
        wallet.sub(3);
    }
    catch (const std::invalid_argument& ex)
    {
        std::cout << ex.what() << std::endl;
    }

    std::cout << wallet << std::endl;
}

static void test_13_example_tutorial()
{
    Wallet wallet(2, 50);
    std::cout << wallet << std::endl;

    wallet += 3;
    std::cout << wallet << std::endl;
}

static void test_14_example_tutorial()
{
    Wallet wallet1(2, 50);
    std::cout << wallet1 << std::endl;

    Wallet wallet2(3, 75);
    std::cout << wallet2 << std::endl;

    if (wallet1 < wallet2) {
        std::cout << "Wallet 1 contains less money than Wallet 2" << std::endl;
    }

    wallet1 = wallet2;
    std::cout << wallet1 << std::endl;
    std::cout << wallet1 << std::endl;

    if (wallet1 == wallet2) {
        std::cout << "Wallet 1 contains the same amount of money as Wallet 2." << std::endl;
    }
}

void exerciseWallet()
{
    test_01_ctors();
    test_02_ctors();
    test_03_toString();
    test_04_add();
    test_05_sub();
    test_06_add_sub_euros();
    test_07_comparision();
    test_08_arithmetic_increment_operators();
    test_09_increment_operators();

    test_10_example_tutorial();
    test_11_example_tutorial();
    test_12_example_tutorial();
    test_13_example_tutorial();
    test_14_example_tutorial();
}

// ===========================================================================
// End-of-File
// ===========================================================================
