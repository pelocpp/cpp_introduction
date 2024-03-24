// ===============================================================================
// PhoneBookMap.h
// ===============================================================================

#include "PhoneBookMap.h"

#include <iostream>
#include <iomanip>
#include <sstream> 
#include <algorithm>
#include <numeric> 

namespace PhoneBook
{
    size_t PhoneBookMap::size()
    {
        return m_map.size();
    }
    
    bool PhoneBookMap::insert(const std::string& first, const std::string& last, size_t number)
    {
        std::string key = getKeyFromNames(first, last);

        std::pair<std::string, size_t> entry(key, number);

        std::pair<std::unordered_map<std::string, size_t>::iterator, bool> result = m_map.insert(entry);

        // returns a bool value set to true if and only if the insertion took place
        bool insertionSucceeded = result.second;

        return insertionSucceeded;
    }

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

    bool PhoneBookMap::contains(const std::string& first, const std::string& last)
    {
        std::string key = getKeyFromNames(first, last);
        std::unordered_map<std::string, size_t>::iterator pos = m_map.find(key);
        return pos != m_map.end();
    }

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

        std::pair<std::string, std::string> fullName = getNamesFromKey(key);

        std::string name(fullName.first + " " + fullName.second);

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

    void PhoneBookMap::sort()
    {
        throw std::exception("Sorting not supported");
    }

    // ---------------------------------------------------------------------------

    std::string PhoneBookMap::append(const std::string& first, const std::pair<std::string, size_t>& next)
    {
        static int counter = 0;
        counter++;

        std::string key = next.first;
        std::pair<std::string, std::string> fullName = getNamesFromKey(key);
        std::string name = fullName.first + " " + fullName.second;

        std::ostringstream ss;
        ss << std::setfill('0') << std::setw(2) << counter
            << ": " << std::setfill(' ') << std::setw(16) << std::left << name << " Phone: "
            << next.second << std::endl;

        return first + ss.str();
    }

    std::string PhoneBookMap::toString() {

        std::string s = std::accumulate(
            m_map.begin(),
            m_map.end(),
            std::string(),
            append
        );

        return s;
    };

    // ---------------------------------------------------------------------------

    void PhoneBookMap::printEntry(const std::pair<std::string, size_t>& entry)
    {
        std::string key = entry.first;
        std::pair<std::string, std::string> fullName = getNamesFromKey(key);
        size_t number = entry.second;
        std::cout << fullName.first << " " << fullName.second << ": " << number << std::endl;
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
