// ===============================================================================
// PhoneBookMap.h
// ===============================================================================

#include "PhoneBookMap.h"

#include <iostream>
#include <algorithm>

namespace PhoneBook
{
    // ---------------------------------------------------------------------------

    size_t PhoneBookMap::size()
    {
        return m_map.size();
    }
    
    // ---------------------------------------------------------------------------

    bool PhoneBookMap::insert(const std::string& first, const std::string& last, size_t number)
    {
        std::string key = getKeyFromNames(first, last);

        std::pair<std::string, size_t> entry(key, number);

        std::pair<std::unordered_map<std::string, size_t>::iterator, bool> result = m_map.insert(entry);

        // returns a bool value set to true if and only if the insertion took place
        bool insertionSucceeded = result.second;

        return insertionSucceeded;
    }

    // ---------------------------------------------------------------------------

    bool PhoneBookMap::update(const std::string& first, const std::string& last, size_t number)
    {
        std::string key = getKeyFromNames(first, last);

        std::unordered_map<std::string, size_t>::iterator pos = m_map.find(key);

        if (pos == m_map.end()) {
            return false;
        }
        else {
            (*pos).second = number;
            return true;
        }
    }

    // ---------------------------------------------------------------------------

    bool PhoneBookMap::search(const std::string& first, const std::string& last, size_t& number)
    {
        std::string key = getKeyFromNames(first, last);

        std::unordered_map<std::string, size_t>::iterator pos = m_map.find(key);

        if (pos == m_map.end()) {

            std::cout << first << " " << last << " not found!" << std::endl;
            return false;
        }
        else {
            std::pair<std::string, size_t> result = *pos;
            number = result.second;
            return true;
        }
    }

    // ---------------------------------------------------------------------------

    bool PhoneBookMap::contains(const std::string& first, const std::string& last)
    {
        std::string key = getKeyFromNames(first, last);
        std::unordered_map<std::string, size_t>::iterator pos = m_map.find(key);
        return pos != m_map.end();
    }

    // ---------------------------------------------------------------------------

    bool PhoneBookMap::remove(const std::string& first, const std::string& last)
    {
        std::string key = getKeyFromNames(first, last);
        size_t numErased = m_map.erase(key);
        return numErased == 1;
    }

    // ---------------------------------------------------------------------------

    std::string PhoneBookMap::transformToName(const std::pair<std::string, size_t>& entry)
    {
        std::string key = entry.first;

        std::pair<std::string, std::string> names = getNamesFromKey(key);

        std::string name(names.first + " " + names.second);

        return name;
    }

    std::forward_list<std::string> PhoneBookMap::getNames()
    {
        std::forward_list<std::string> list;

        std::transform(
            m_map.begin(),
            m_map.end(),
            std::front_insert_iterator<std::forward_list<std::string>>(list),
            transformToName
        );

        return list;
    }

    // ---------------------------------------------------------------------------

    void PhoneBookMap::printEntry(const std::pair<std::string, size_t>& entry)
    {
        std::string key = entry.first;
        std::pair<std::string, std::string> name = getNamesFromKey(key);
        size_t number = entry.second;
        std::cout << name.first << " " << name.second << ": " << number << std::endl;
    }

    void PhoneBookMap::print()
    {
        std::for_each(
            m_map.begin(),
            m_map.end(),
            printEntry
        );
    }


    // ---------------------------------------------------------------------------

    void PhoneBookMap::sort()
    {
        throw std::exception("Sorting not supported");
    }

    // ---------------------------------------------------------------------------

    // 1. Realisierung
    std::ostream& operator << (std::ostream& os, const PhoneBookMap& pb)
    {
        //// Range-Based Loop:  Mit Index ergänzt
        //int i = 0;
        //for (const std::pair<std::string, long>& entry : pb.m_map)
        //{
        //    std::string key = entry.first;
        //    size_t number = entry.second;

        //    // Hans_Mueller  ===> "Hans",  "Mueller" 
        //    // find und subtring

        //    size_t pos = key.find("_");

        //    // substr : sub string == Teil Zeichenkette
        //    std::string first = key.substr(0, pos);
        //    std::string last = key.substr(pos + 1, key.size() - (pos + 1));

        //    os << "Eintrag " << i << ": "
        //        << first << " " << last
        //        << ": " << number << '\n';

        //    ++i;
        //}

        return os;
    }


    // ---------------------------------------------------------------------------

    std::pair<std::string, std::string> PhoneBookMap::getNamesFromKey(const std::string& key)
    {
        size_t pos = key.find("_");

        std::string first = key.substr(0, pos);
        std::string last = key.substr(pos + 1);

        return std::pair<std::string, std::string>(first, last);
    }

    std::string PhoneBookMap::getKeyFromNames(const std::string& first, const std::string& last)
    {
        return first + "_" + last;   // "Hubert", "Mueller" ==> "Hubert_Mueller"
    }
}

// ===============================================================================
// End-of-File
// ===============================================================================


