#include <iostream>
#include <string>
#include <map>
#include <tuple>
#include <algorithm>
#include <forward_list>

#include "PhoneBookEx.h"

namespace PhoneBookMapBased
{
    bool PhoneBookComparator::operator()(const std::string& left, const std::string& right) const
    {
        //const auto& [first1, last1] = PhoneBook::getNamesFromKey(left);
        //const auto& [first2, last2] = PhoneBook::getNamesFromKey(right);

        const std::pair<std::string, std::string> last1 = PhoneBook::getNamesFromKey(left);
        const std::pair<std::string, std::string> last2 = PhoneBook::getNamesFromKey(right);

        return (last1 < last2);
    }

    std::pair<std::string, std::string> PhoneBook::getNamesFromKey(const std::string& key)
    {
        size_t pos = key.find("_");

        std::string first = key.substr(0, pos);
        std::string last = key.substr(pos + 1, key.size() - (pos + 1));

        return { first, last };
    }

    std::string PhoneBook::getKeyFromNames(const std::string& first, const std::string& last)
    {
        return { first + "_" + last };  // "Hubert", "Mueller" ==> "Hubert_Mueller"
    }

    bool PhoneBook::insert(const std::string& first, const std::string& last, long number)
    {
        //std::string key = getKeyFromNames(first, last);

        //auto position = m_map.find(key);

        //if (position != m_map.end()) {
        //    return false;
        //}

        //m_map.emplace(key, number);

        return true;
    }

    bool PhoneBook::update(const std::string& first, const std::string& last, long number)
    {
        // TO BE DONE
        return true;
    }

    bool PhoneBook::search(const std::string& first, const std::string& last, long& number)
    {
        //std::string key = getKeyFromNames(first, last);

        //std::unordered_map<std::string, long>::iterator pos = m_map.find(key);

        //// auto result = m_map.find(key);

        //if (pos == m_map.end()) {
        //    std::cout << "Key" + key << " not found";
        //    return false;
        //}
        //else {
        //    std::pair<std::string, long> entry = *pos;
        //    number = entry.second;
        //    std::cout << "At Key " + key << " found number: " << number;
        //    return true;
        //}

        // TO BE DONE
        return true;
    }

    bool PhoneBook::contains(const std::string& first, const std::string& last)
    {
        //std::string key = getKeyFromNames(first, last);
        //auto result = m_map.find(key);
        //return (result == m_map.end()) ? false : true;

        // TO BE DONE
        return true;
    }

    bool PhoneBook::remove(const std::string& first, const std::string& last)
    {
        std::string key = getKeyFromNames(first, last);

        // komische Fehlermedlung
        // size_t numErased = m_map.erase(key);
        // return (numErased == 1) ? true : false;

        // TO BE DONE
        return true;
    }

    //std::ostream& operator << (std::ostream& os, const PhoneBook& book)
    //{
    //    for (int i = 1; const auto& [first, last, number] : book) {
    //        os
    //            << i << ": "
    //            << "First Name: " << first
    //            << ", Last Name: " << last
    //            << ", Phone: " << number
    //            << std::endl;

    //        ++i;
    //    }

    //    return os;
    //}

    //std::ostream& operator << (std::ostream& os, const PhoneBook& book)
    //{
    //    for (int i = 1; const auto& entry : book.m_map)
    //    {
    //        const auto& [key, number] = entry;

    //        const auto& [first, last] = PhoneBook::getNamesFromKey(key);
    //        //size_t pos = key.find("_");

    //        //// substr : sub string == Teil Zeichenkette
    //        //std::string first = key.substr(0, pos);
    //        //std::string last = key.substr(pos + 1, key.size() - (pos + 1));

    //        os
    //            << i << ": "
    //            << "First Name: " << first
    //            << ", Last Name: " << last
    //            << ", Phone: " << number
    //            << std::endl;

    //        ++i;
    //    }

    //    return os;
    //}


    std::forward_list<std::string> PhoneBook::getNames()
    {
        std::forward_list<std::string> result;

        std::transform(
            m_map.begin(),
            m_map.end(),
            std::front_insert_iterator<std::forward_list<std::string>>(result),
            [this](const auto& entry) {
                std::string key = entry.first;
                std::pair<std::string, std::string> names = getNamesFromKey(key);
                std::string name{ names.first + " " + names.second };
                return name;
            }
        );

        return result;
    }

    void PhoneBook::sort()
    {
        // already sorted ;)
    }
}


