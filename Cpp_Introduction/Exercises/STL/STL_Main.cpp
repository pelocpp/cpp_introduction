// ===========================================================================
// STL_Main.cpp // Introductionary Examples for STL
// ===========================================================================

#include <iostream>
#include <algorithm>
#include <vector>

static void printToConsole(int value) {
    std::cout << ">: " << value << std::endl;
}

static void testDevilsSequence()
{
    std::vector<int> devilsSequenceFolge;

    int start = 7;

    devilsSequenceFolge.push_back(start);

    while (start != 1)
    {
        // compute numbers of sequence
        start = (start % 2 == 0) ? (start / 2) : (start * 3 + 1);

        devilsSequenceFolge.push_back(start);
    }

    // read-only traversal
    std::for_each(
        devilsSequenceFolge.begin(),
        devilsSequenceFolge.end(),
        printToConsole
    );
}

// ===========================================================================

// Callable Object
class FibonacciSequence
{
private:
    int m_first;
    int m_second;

public:
    FibonacciSequence() : m_first(0), m_second(1) {}

    int operator() ()
    {
        // store current Fibonacci number
        int last = m_first;

        // calculate next pair
        int tmp = m_first + m_second;
        m_first = m_second;
        m_second = tmp;

        return last;
    }

    void operator() (int elem)
    {
        std::cout << ">: " << elem << std::endl;
    }
};

static void testFibonacci()
{
    std::vector<int> sequence(20);

    FibonacciSequence fibonacci;

    std::generate(
        sequence.begin(),
        sequence.end(),
        fibonacci
    );

    std::for_each(
        sequence.begin(),
        sequence.end(),
        fibonacci
    );
}

void exerciseSTL()
{
    testDevilsSequence();
    testFibonacci();
}

// ===========================================================================
// End-of-File
// ===========================================================================
