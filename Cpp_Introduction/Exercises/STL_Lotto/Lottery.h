// ===========================================================================
// Lottery.h
// ===========================================================================

#pragma once

#include <iostream>
#include <vector>
#include <random>

class Lottery
{
private:
    std::vector<int> m_numbers;

    mutable std::default_random_engine m_random_engine;
    mutable std::uniform_int_distribution<int> m_dist;

    // ----------------------------------------------------------
    // iterator support

    class DrawPosition
    {
    private:
        size_t m_drawnNumbers;

        // need back reference
        Lottery& m_outer;

    public:
        DrawPosition(Lottery& outer, size_t drawnNumbers)
            : m_outer{ outer }, m_drawnNumbers{ drawnNumbers }
        {
            // need to draw first number
            if (m_drawnNumbers == 1) {

                int number = m_outer.drawNextNumber();
                m_outer.setNextNumber(number);
            }
        }

        bool operator != (const DrawPosition& other) {
            return m_drawnNumbers != other.m_drawnNumbers;
        }

        void operator++ () {

            m_drawnNumbers++;

            if (m_drawnNumbers == 7) {
                // drawing of lottery numbers is complete
                m_drawnNumbers = 0;
            }
            else {
                // draw next number
                int number = m_outer.drawNextNumber();
                m_outer.setNextNumber(number);
            }
        }

        int operator* () {
            size_t currentIndex = m_drawnNumbers - 1;
            return m_outer.m_numbers[currentIndex];
        }
    };

public:
    using iterator = DrawPosition;

    DrawPosition begin() { return DrawPosition(*this, 1); };
    DrawPosition end() { return DrawPosition(*this, 0); };

    // end of iterator support
    // ----------------------------------------------------------

public:
    // c'tors
    Lottery();
    Lottery(int seed);

    // getter
    size_t getDrawnNumbers() const;

    // public interface
    void play();
    void print();

private:
    // private helper methods
    int nextRandomNumber() const;
    bool numberAlreadyDrawn(int number) const;
    int drawNextNumber() const;
    void setNextNumber(int number);
    void verifyNumbers() const;

    // private class method
    static void printNumber(int number);
};

// ===========================================================================
// End-of-File
// ===========================================================================
