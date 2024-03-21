#include <iostream> 
#include <algorithm> 

// Header / Klassendefinition
class WichtigeDaten
{
private:
    int m_wert1;
    int m_wert2;
    int m_wert3;

private:
    // Dies ist eine Iterator-Klasse
    class Position
    {
    private:
        int m_position;  // 0 == m_wert1, 1 == m_wert2, 2 == M-wert3, -1 für das Ende

        // need back reference
        WichtigeDaten& m_outer;

    public:
        Position(WichtigeDaten& outer, int position)
            : m_outer{outer}, m_position { position } {}

        bool operator != (const Position& other) {
            return m_position != other.m_position;
        }

        void operator++ () {

            if (m_position == 0) {
                m_position = 1;
            }
            else if (m_position == 1) {
                m_position = 2;
            }
            else if (m_position == 2) {
                m_position = -1;
            }
        }

        int operator* () {

            if (m_position == 0) {
                return m_outer.m_wert1;
            }
            else if (m_position == 1) {
                return m_outer.m_wert2;
            }
            else if (m_position == 2) {
                return m_outer.m_wert3;
            }
            else {
                return -1; // Fehlerfall // Wird das erreicht ????
            }
        }
    };

public:

    using iterator = Position;

    // Konstruktor
    WichtigeDaten();
    WichtigeDaten(int wert1, int wert2, int wert3 );

    Position begin() { return Position(*this,  0); };
    Position end() { return Position(*this, -1); };
};



// Realisierung
WichtigeDaten::WichtigeDaten() 
    : m_wert1{ 0 }, m_wert2{ 0 }, m_wert3{ 0 } {}

WichtigeDaten::WichtigeDaten(int wert1, int wert2, int wert3)
    : m_wert1{ wert1 }, m_wert2{ wert2 }, m_wert3{ wert3 } {}


// Hauptprogramm
void main_iterator()
{
    WichtigeDaten meineDaten{ 1, 2, 3 };

    // Range-Based Loop
    // Setzt auf dem Iteratoren-Konzept auf !!!
    for (auto element : meineDaten)
    {
        std::cout << " naechstes Element: " << element << std::endl;
    }

    // STL Algorithmus
    std::for_each (
        meineDaten.begin(),
        meineDaten.end(),
        [] (auto element) {
            std::cout << " naechstes Element: " << element << std::endl;
        }
    );
}