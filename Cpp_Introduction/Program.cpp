// =====================================================================================
// https://github.com/pelocpp // https://peterloos.de
// =====================================================================================

#pragma message("Collection of introductionary C++ Code Examples - Copyright (C) 2019-2023 Peter Loos")

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

  //  std::cout << "[Collection of introductionary C++ Code Examples - Copyright (C) 2019-2023 Peter Loos]" << std::endl;

    // main entry points code examples
    try
    {
        //testHelloWorld();
        //testClassesObjects();
        //testProceduralVsOOProgramming();
        //testClassesObjectsImproved();
        //testConstructors();
        //testReferences();
        //testParameterPassing();
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

        testExercises();
    }
    catch (const std::exception& ex) {
        std::cout << "Exception: " << ex.what() << std::endl;
    }

    std::cout << "[Done.]" << std::endl;
    return 0;
}

// =====================================================================================
// End-of-File
// =====================================================================================
