// ===============================================================================
// IPhoneBook.h
// ===============================================================================

#include <iostream>
#include <string>
#include <map>
#include <algorithm>

#include <iostream>
#include <string>
#include <map>
#include <tuple>
#include <algorithm>
#include <forward_list>


#include "PhoneBookMap.h"

namespace PhoneBookMapBased
{
    std::pair<std::string, std::string> PhoneBook::getNamesFromKey(const std::string& key)
    {
        size_t pos = key.find("_");

        // substr : sub string == Teil Zeichenkette
        std::string first = key.substr(0, pos);
        std::string last = key.substr(pos + 1, key.size() - (pos + 1));

        // short version of returning a std::pair<>  // man kann den Typ weglassen
        return std::pair<std::string, std::string>{ first, last };

        // long version of returning a std::pair<>
        // return std::pair<std::string, std::string> { first, last };
    }

    std::string PhoneBook::getKeyFromNames(const std::string& first, const std::string& last)
    {
        return { first + "_" + last };  // "Hubert", "Mueller" ==> "Hubert_Mueller"
    }

    bool PhoneBook::insert(const std::string& first, const std::string& last, long number)
    {
        // bauen Schlüssel ( "Hubert", "Mueller" ==> "Hubert Mueller" )

        std::string key = first + "_" + last;  //   "Hubert", "Mueller" ==> "Hubert Mueller"

        // a) Nicht so kurz, aber exakt und besser verständlicher:
        std::pair<std::string, long> entry{ key, number };

        m_map.insert(entry);

        // oder

        // a) Die kürzeste und eleganteste
        // m_map[key] = number;

        return true;
    }

    bool PhoneBook::search(const std::string& first, const std::string& last, long& number)
    {
        // a) we need at first the key

        std::string key = first + "_" + last;  //   "Hubert", "Mueller" ==> "Hubert Mueller"

        std::unordered_map<std::string, long>::iterator result = m_map.find(key);

        //auto result = m_map.find(key);

        if (result == m_map.end()) {
            std::cout << "Key" + key << " not found";
            return false;
        }
        else {
            std::pair<std::string, long> entry = *result;

            long tmp = entry.second;

            number = tmp;

            std::cout << "At Key " + key << " found number: " << number;

            return true;
        }
    }

    // 1. Realisierung
    std::ostream& operator << (std::ostream& os, const PhoneBook& pb)
    {
        // Range-Based Loop:  Mit Index ergänzt
        int i = 0; 
        for (  const std::pair<std::string, long>& entry : pb.m_map)
        {
            std::string key = entry.first;
            long number = entry.second;

            // Hans_Mueller  ===> "Hans",  "Mueller" 
            // find und subtring

            size_t pos = key.find("_");

            // substr : sub string == Teil Zeichenkette
            std::string first = key.substr(0, pos);
            std::string last = key.substr(pos + 1, key.size() - (pos+1));

            os << "Eintrag " << i << ": " 
            << first << " " << last 
            << ": " << number << '\n';

             ++i;
        }

        return os;
    }

    bool PhoneBook::contains(const std::string& first, const std::string& last)
    {
        std::string key{ first + "_" + last };

        auto result = m_map.find(key);   // result ist ein Iterator

        return (result == m_map.end()) ? false : true;
    }

    bool PhoneBook::remove(const std::string& first, const std::string& last)
    {
        std::string key{ first + "_" + last };

        //size_t numErased = m_map.erase(key);

        //return (numErased == 1) ? true : false;

        return true;
    }

    std::forward_list<std::string> PhoneBook::getNames()
    {
        std::forward_list<std::string> result;

        // von Quelle zu Ziel: 
        // Lambda erhält einen PhoneBook Entry, berechnet Name
        // Achtung: transform greift auf das ZIEL mit [index] zu
        // Geht NICHT bei einer Liste --- deshalb ein dazwischen geschalteter inserter
        std::transform(
            m_map.begin(),
            m_map.end(),

            std::front_insert_iterator<std::forward_list<std::string>>(result),

            [this](const auto& entry) {

                std::string key = entry.first;  // std::pair

                // structured binding
          //      const auto& [vorname, nachname] = getNamesFromKey(key);

                std::pair<std::string, std::string> names = getNamesFromKey(key);
                std::string name{ names.first + " " + names.second };

//                std::string name{ vorname + " " + nachname };

                return name;
            }
        );

        return result;
    }

    // virtual std::forward_list<std::string> getNames() override;
    //std::forward_list<std::string> PhoneBook::getNames()
    //{
    //    std::forward_list<std::string> result;

    //    std::transform(

    //        m_map.begin(),
    //        m_map.end(),

    //        std::back_inserter(result),  // Es wird ein LEERER Vektor mit push_back gefüllt

    //        [this](const auto& entry) {

    //            std::string key = entry.first;  // std::pair

    //            // structured binding
    //            const auto& [vorname, nachname] = getNamesFromKey(key);

    //            std::string name{ vorname + " " + nachname };

    //            return name;
    //        }
    //    );

    //    return result;
    //}

    //bool PhoneBookComparator::operator()(const std::string& left, const std::string& right) const
    //{
    //    //const auto& [first1, last1] = PhoneBook::getNamesFromKey(left);
    //    //const auto& [first2, last2] = PhoneBook::getNamesFromKey(right);

    //    const std::pair<std::string, std::string> last1 = PhoneBook::getNamesFromKey(left);
    //    const std::pair<std::string, std::string> last2 = PhoneBook::getNamesFromKey(right);

    //    return (last1 < last2);
    //}

    void PhoneBook::sort()
    {
        throw std::exception("Sorting not supported");
    }

}

