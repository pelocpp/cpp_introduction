#include <algorithm> 
#include <memory> 

#include "PhoneBookShared.h"

namespace PhoneBookVectorShared
{
    // Telefonbuch

    // ====================================================
    // Realisierung der Methoden ... typischerweise in einer .cpp Datei

    std::ostream& operator << (std::ostream& os, const PhoneBook& pb)
    {
        for (size_t i = 0; i != pb.m_entries.size(); i++) {

            std::shared_ptr<PhoneBook::Entry> tmp = pb.m_entries[i];

            os << "Eintrag " << i << ": "
                << tmp->m_first << " " << tmp->m_last
                << ": " << tmp->m_number << '\n';
        }

        return os;
    }


    void PhoneBook::insert(const std::string& first, const std::string& last, long number)
    {
        // Ein Eintrag wird am Heap angelegt
        // std::make_shared: Ist "etwas" schneller
        std::shared_ptr<Entry> entry 
            = std::make_shared<Entry>(first, last, number);
        
        // ODER
        
        // std::shared_ptr<Entry> entry1 = 
        //    std::shared_ptr<Entry>( new Entry { first, last, number });

        m_entries.push_back(entry);
    }

    // Stilistik: C ++
    bool PhoneBook::search(const std::string& first, const std::string& last, long& number)
    {

        // Es werden shared_ptr an den Lambda übergeben
        auto lambdaFunktion = [&] (const std::shared_ptr<Entry>& e) { 
        
            if (e->m_first == first && e->m_last == last) {
                return true;
            }
            else {
                return false;
            }
        };
    
        auto result = std::find_if( 
            m_entries.begin(), 
            m_entries.end(),
            lambdaFunktion
        );
    
        if (result == m_entries.end()) {
    
            std::cout << "... nicht gefunden ...." << std::endl;
    
            return false;
        }
        else {
            std::cout << "... Gefunden ...." << std::endl;
    
            std::shared_ptr<Entry> gefunden = *result;
    
            number = gefunden->m_number;
    
            std::cout << "... Nummer =  " << gefunden->m_number << std::endl;
    
            return true;
        }
    
    
        return false;  // Minimalanweisung, um übersetzen zu können
    }



    bool PhoneBook::contains(const std::string& first, const std::string& last)
    {

        auto iter = std::find_if(
            m_entries.begin(),      // Anfang vom Bereich
            m_entries.end(),        // Ende vom Bereich
            [&](const std::shared_ptr<Entry>& element) {

                if (element->m_first == first && element->m_last == last) {
                    return true;
                }
                else {
                    return false;
                }
            }
        );

        // ternäre Operator
        return (iter == m_entries.end()) ? false : true;
    }

    bool PhoneBook::remove(const std::string& first, const std::string& last)
    {
        auto pos = std::remove_if(
            m_entries.begin(),
            m_entries.end(),
            [&](const auto& entry) {

                if (entry->m_first == first && entry->m_last == last) {
                    return true;
                }
                else {
                    return false;
                }
            }
        );

        if (pos == m_entries.end()) {
            return false;
        }
        else {
            // Achtung: Resultat 'pos'
            // Welche Elemente nicht mehr zum Container gehören,
            // wird durch den Rückgabewert 'pos ' der Methode std::remove_if zum Ausdruck gebracht:
            // Dies ist ein Iterator-Objekt, das auf das erste, nicht mehr dazugehörige Element
            // im Container zeigt.

            // 2. Schritt: std::erase: Geht von Position 'pos' bis zum Ende des Containers
            // Hier wird jetzt tatsächlich gelöscht
            m_entries.erase(pos, m_entries.end());
            return true;
        }
    }

    std::forward_list<std::string> PhoneBook::getNames()
    {
        std::forward_list<std::string> result;

        // von Quelle zu Ziel: 
        // Lambda erhält einen PhoneBook Entry, berechnet Name
        // Achtung: transform greift auf das ZIEL mit [index] zu
        // Geht NICHT bei einer Liste --- deshalb ein dazwischen geschalteter inserter
        std::transform(

            m_entries.begin(),
            m_entries.end(),

            std::front_insert_iterator(result),

            [](const auto& entry) {

                std::string name{ entry->m_first + " " + entry->m_last };

                return name;
            }
        );

        return result;
    }


    std::vector<std::string> PhoneBook::getNamesEx()
    {
        std::vector<std::string> result(m_entries.size());

        std::transform(
            m_entries.begin(),
            m_entries.end(),

            result.begin(),    // DIESER VEKTOR MUSS EINE ENTSPRECHENDE GROESSE HABEN
            // wird mit [ index ] gefüllt

            [](const auto& entry) {

                std::string name{ entry->m_first + " " + entry->m_last };

                return name;
            }
        );

        return result;
    }

    bool operator< (const std::shared_ptr<PhoneBook::Entry>& entry1, const std::shared_ptr<PhoneBook::Entry>& entry2)
    {
        // Sortierkriterium
        // a) Nachname
        //std::cout << "   Vergleiche " << entry1.m_last << " mit " << entry2.m_last << std::endl;
        //return (entry1.m_last < entry2.m_last) ? true : false ;

        // Sortierkriterium
        // a) Tel.Nummer
        std::cout << "   Vergleiche " << entry1->m_number << " mit " << entry2->m_number << std::endl;
        return (entry1->m_number < entry2->m_number) ? true : false;
    }

    // ???????????????????????????????????????????
    // Wertden hier ZEIGER oder Werte sortiert ???
    void PhoneBook::sort()
    {
        std::sort(
            m_entries.begin(),
            m_entries.end()
        );
    }
}

