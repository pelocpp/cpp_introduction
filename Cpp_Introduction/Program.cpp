// =====================================================================================
// Cpp Introduction
// Program.cpp
// Entry Point for all Examples
// 
// https://github.com/pelocpp
// https://peterloos.de
// =====================================================================================

#pragma message("Collection of introductory C++ Code Examples - Copyright (C) 2019-2024 Peter Loos")

#include <iostream>

// function prototypes
extern void testHelloWorld();
extern void testClassesObjects();
extern void testProceduralVsOOProgramming();
extern void testClassesObjectsImproved();
extern void testConstructors();
extern void testStatic();
extern void testReferences();
extern void testParameterPassing();
extern void testClassTimeParameterPassing();
extern void testOperatorsOverloading();
extern void testDynamicMemoryManagement();
extern void testRuleOfThree();
extern void testNamespaces();
extern void testTemplates();
extern void testStrings();
extern void testExceptions();
extern void testStreams();
extern void testInheritance();
extern void testMoreInheritance();
extern void testSTL();

extern void testExercises();

// entry point
int main()
{
    std::cout << "[Collection of introductory C++ Code Examples - Copyright (C) 2019-2024 Peter Loos]" << std::endl;

    // main entry points code examples
    try
    {
        //testHelloWorld();
        //testClassesObjects();
        //testProceduralVsOOProgramming();
        //testClassesObjectsImproved();
        //testConstructors();
        //testStatic();
        //testReferences();
        //testParameterPassing();
        //testClassTimeParameterPassing(); 
        //testOperatorsOverloading();
        //testDynamicMemoryManagement();
        //testRuleOfThree();
        //testNamespaces();
        //testTemplates();
        //testStrings();
        //testExceptions();
        //testStreams();
        //testInheritance();
        //testMoreInheritance();
        //testSTL();

        //testExercises();
    }
    catch (const std::exception& ex) {
        std::cout << "Exception: " << ex.what() << std::endl;
    }

    std::cout << "[Done]" << std::endl;
    return 0;
}

// =====================================================================================
// End-of-File
// =====================================================================================
