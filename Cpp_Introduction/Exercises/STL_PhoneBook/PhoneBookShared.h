#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
#include <memory>

namespace PhoneBookVectorShared
{
    class PhoneBook
    {
    private:
        // private Hilfsstruktur // private Hilfsklasse
        // In einer Struktur ist automatisch alles 'public'
        struct Entry
        {
            std::string m_first;
            std::string m_last;
            long        m_number;
        };

    private:
        std::vector< std::shared_ptr< Entry >> m_entries;

    public:
        void insert(const std::string& first, const std::string& last, long number);
        bool search(const std::string& first, const std::string& last, long& number);

        bool contains(const std::string& first, const std::string& last);
        bool remove(const std::string& first, const std::string& last);

        std::forward_list<std::string> getNames();
        std::vector<std::string> getNamesEx();

        void sort();

        friend bool operator< (const std::shared_ptr<Entry>& entry1, const std::shared_ptr<Entry>& entry2);

        // Ausgabe auf der Konsole: Gehört zum "guten Stil"
        friend std::ostream& operator << (std::ostream& os, const PhoneBook& pb);

        size_t vectorsizeof()
        {
            return sizeof(std::shared_ptr<Entry>) * m_entries.size();
        }
    };

    bool operator< (const std::shared_ptr<PhoneBook::Entry>& entry1, const std::shared_ptr<PhoneBook::Entry>& entry2);

    // Ausgabe auf der Konsole: Gehört zum "guten Stil"
    // Globale Funktion
    std::ostream& operator<< (std::ostream& os, const PhoneBook& pb);
}
