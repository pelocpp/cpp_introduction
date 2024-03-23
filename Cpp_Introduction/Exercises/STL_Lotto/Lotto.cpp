// ===========================================================================
// String.h
// ===========================================================================

#pragma once
#include "Lotto.h"

// c'tors
Lotto::Lotto() : m_random_engine(123), m_dist(1, 49) {}

Lotto::Lotto(int seed) : m_random_engine(seed), m_dist(1, 49) {}

// getter
size_t Lotto::drawnNumbers() const { return m_numbers.size(); }

// public interface
int Lotto::genNextNumber()
{
    int number = m_dist(m_random_engine);
    std::cout << "  ... got " << number << std::endl;
    return number;
}

bool Lotto::numberAlreadyDrawn(int zahl)
{
    std::vector<int>::iterator pos = std::find(
        m_numbers.begin(),
        m_numbers.end(),
        zahl
    );

    return pos != m_numbers.end();
};

void Lotto::drawNextNumber(int zahl)
{
    m_numbers.push_back(zahl);
}

void Lotto::play()
{
    for (int i = 0; i < 6; ++i) {

        int zahl;
        do {
            zahl = genNextNumber();
        } while (numberAlreadyDrawn(zahl));

        drawNextNumber(zahl);
        verifyNumbers();
    }
}

void Lotto::playEx()
{
    m_numbers.resize(6);

    std::generate(
        m_numbers.begin(),
        m_numbers.end(),
        std::ref(*this)
    );
}


int Lotto::operator() ()
{
    int zahl;
    do {
        zahl = genNextNumber();
    } while (numberAlreadyDrawn(zahl));

    return zahl;
}

void Lotto::printNumber(int number) {
    std::cout << number << ", ";
}

void Lotto::print()
{
    std::cout << "\n";
    std::cout << "Ziehung der Lottozahlen:\n";
    std::cout << "========================\n";

    std::for_each(
        m_numbers.begin(),
        std::prev(m_numbers.end()),
        printNumber
    );

    int last = m_numbers.back();
    std::cout << last;

    std::cout << "\n";
}


void Lotto::verifyNumbers()
{
    for (int i = 0; i < m_numbers.size(); ++i) {

        int wert = m_numbers[i];

        for (int k = 0; k < m_numbers.size(); ++k) {

            if (k == i)
                continue;

            if (wert == m_numbers[k]) {

                throw std::exception("Illegal numbers found");
            }
        }
    }
}

// ===========================================================================
// End-of-File
// ===========================================================================
