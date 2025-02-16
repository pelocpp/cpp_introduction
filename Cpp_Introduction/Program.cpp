
// =====================================================================================
// Cpp Introduction
// Program.cpp
// Entry Point for all Examples
// 
// https://github.com/pelocpp
// https://peterloos.de
// =====================================================================================

#pragma message("Collection of introductory C++ Code Examples - Copyright (C) 2019-2025 Peter Loos")

#include <iostream>

// function prototypes
extern void main_HelloWorld();
extern void main_ClassesObjects();
extern void main_ProceduralVsOOProgramming();
extern void main_ClassesObjectsImproved();
extern void main_Constructors();
extern void main_Static();
extern void main_References();
extern void main_ParameterPassing();
extern void main_ClassTimeParameterPassing();
extern void main_OperatorsOverloading();
extern void main_MemoryManagement();
extern void main_DynamicMemory();
extern void main_RuleOfThree();
extern void main_Namespaces();
extern void main_Templates();
extern void main_Strings();
extern void main_Exceptions();
extern void main_Streams();
extern void main_Inheritance();
extern void main_MoreInheritance();
extern void main_STL();

extern void main_Exercises();

// entry point
int main()
{
    std::cout << "[Collection of introductory C++ Code Examples - Copyright (C) 2019-2025 Peter Loos]" << std::endl;

    // main entry points code examples
    try
    {
        //main_HelloWorld();
        //main_ClassesObjects();
        //main_ProceduralVsOOProgramming();
        //main_ClassesObjectsImproved();
        //main_Constructors();
        //main_Static();
        //main_References();
        //main_ParameterPassing();
        //main_ClassTimeParameterPassing(); 
        //main_OperatorsOverloading();
        //main_MemoryManagement();
        //main_DynamicMemory();
        //main_RuleOfThree();
        //main_Namespaces();
        //main_Templates();
        //main_Strings();
        //main_Exceptions();
        //main_Streams();
        //main_Inheritance();
        //main_MoreInheritance();
        //main_STL();

        //main_Exercises();
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
