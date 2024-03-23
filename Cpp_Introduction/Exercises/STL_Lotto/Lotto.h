// ===========================================================================
// String.h
// ===========================================================================

#pragma once

#include <iostream>
#include <vector>
#include <random>

class Lotto
{
private:
    std::vector<int> m_numbers;

    std::default_random_engine m_random_engine;
    std::uniform_int_distribution<int> m_dist;

public:
    // c'tors
    Lotto();
    Lotto(int seed);

    // getter
    size_t drawnNumbers() const;

    // public interface
    int genNextNumber();
    void drawNextNumber(int zahl);
    void play();
    void playEx();
    void print();
    static void printNumber(int number);

    // make Lotto a callable object
    int operator() ();

private:
    bool numberAlreadyDrawn(int zahl);
    void verifyNumbers();
};

class IterableLotto
{
private:
    std::vector<int> m_numbers;

    std::default_random_engine m_random_engine;
    std::uniform_int_distribution<int> m_dist;

private:

    // TODO Der Name der Klasse ist schwach ..........
    class Position
    {
    private:
        int m_drawnNumbers;

        // need back reference
        IterableLotto& m_outer;

    public:
        Position(IterableLotto& outer, int drawnNumbers)
            : m_outer{ outer }, m_drawnNumbers{ drawnNumbers } {}

        bool operator != (const Position& other) {
            return m_drawnNumbers != other.m_drawnNumbers;
        }

        void operator++ () {

            m_drawnNumbers++;
            if (m_drawnNumbers == 6) {
                m_drawnNumbers = -1;
            }
        }

        int operator* () {

            int number = m_outer.m_numbers[drawnNumbers];
            return number;

         //   return -1; // Fehlerfall // Wird das erreicht ????

            //if (m_position == 0) {
            //    return m_outer.m_wert1;
            //}
            //else if (m_position == 1) {
            //    return m_outer.m_wert2;
            //}
            //else if (m_position == 2) {
            //    return m_outer.m_wert3;
            //}
            //else {
            //    return -1; // Fehlerfall // Wird das erreicht ????
            //}
        }
    };

public:
    using iterator = Position;


    Position begin() { return Position(*this, 0); };
    Position end() { return Position(*this, -1); };

public:
    // c'tors
    IterableLotto();
    IterableLotto(int seed);

    // getter
    size_t drawnNumbers() const;

    // public interface
    int genNextNumber();
    void drawNextNumber(int zahl);
    void play();
    void playEx();
    void print();
    static void printNumber(int number);

    // make Lotto a callable object
    int operator() ();

private:
    bool numberAlreadyDrawn(int zahl);
    void verifyNumbers();
};



// ===========================================================================
// End-of-File
// ===========================================================================
