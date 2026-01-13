// ===========================================================================
// STL_Main.cpp // Introductionary Examples for STL
// ===========================================================================

#include <algorithm>
#include <iostream>
#include <vector>

// ===========================================================================
// Simple Devils sequence

static void printToConsole(int value) {
    std::cout << ">: " << value << std::endl;
}

static void testDevilsSequence()
{
    std::vector<int> devilsSequence;

    int start = 7;

    devilsSequence.push_back(start);

    while (start != 1)
    {
        // compute numbers of sequence
        start = (start % 2 == 0) ? (start / 2) : (start * 3 + 1);

        devilsSequence.push_back(start);
    }

    // read-only traversal
    std::for_each(
        devilsSequence.begin(),
        devilsSequence.end(),
        printToConsole
    );
}

// ===========================================================================
// Devils sequence with callable object

class DevilsSequence
{
private:
    int m_start;

public:
    DevilsSequence() {
        m_start = 7;
    }

    DevilsSequence(int start) {
        m_start = start;
    }

    int operator() () {
        if (m_start != 1) {
            m_start = (m_start % 2 == 0) ? (m_start / 2) : (m_start * 3 + 1);
            return m_start;
        }
        else {
            return 0;
        }
    }
};


static void testDevilsSequenceAdvanced()
{
    std::vector<int> devilsSequence;
    devilsSequence.resize(30);

    // set start value
    const int Start = 7;
    devilsSequence[0] = Start;
    DevilsSequence sequenceGenerator(Start);

    std::generate(
        std::next(devilsSequence.begin()),
        devilsSequence.end(),
        sequenceGenerator
    );

    // read-only traversal
    std::for_each(
        devilsSequence.begin(),
        devilsSequence.end(),
        printToConsole
    );
}

// ===========================================================================
// Fibonacci sequence with callable object

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

// ===========================================================================

void exerciseSTL()
{
    testDevilsSequence();
    testDevilsSequenceAdvanced();
    testFibonacci();
}

// ===========================================================================
// End-of-File
// ===========================================================================
