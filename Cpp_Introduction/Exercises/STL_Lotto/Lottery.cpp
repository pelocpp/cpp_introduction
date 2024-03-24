// ===========================================================================
// Lottery.cpp
// ===========================================================================

#include "Lottery.h"

// c'tors
Lottery::Lottery() : m_random_engine(123), m_dist(1, 49) {}

Lottery::Lottery(int seed) : m_random_engine(seed), m_dist(1, 49) {}

// getter
size_t Lottery::drawnNumbers() const { return m_numbers.size(); }

// public interface
int Lottery::nextRandomNumber()
{
    int number = m_dist(m_random_engine);
    return number;
}

bool Lottery::numberAlreadyDrawn(int number)
{
    std::vector<int>::iterator pos = std::find(
        m_numbers.begin(),
        m_numbers.end(),
        number
    );

    return pos != m_numbers.end();
};

void Lottery::setNextNumber(int number)
{
    m_numbers.push_back(number);
}

int Lottery::drawNextNumber()
{
    int number;
    do {
        number = nextRandomNumber();
    } while (numberAlreadyDrawn(number));

    return number;
}

void Lottery::play()
{
    for (int i = 0; i < 6; ++i) {

        int number = drawNextNumber();
        setNextNumber(number);
        verifyNumbers();
    }
}

void Lottery::verifyNumbers()
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

void Lottery::printNumber(int number) {
    std::cout << number << ", ";
}

void Lottery::print()
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



// ===========================================================================
// End-of-File
// ===========================================================================
