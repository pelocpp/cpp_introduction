// ===============================================================================
// PhoneBookVector.h
// ===============================================================================

#include "PhoneBookVector.h"

#include <iostream>
#include <algorithm> 

namespace PhoneBook
{
    // ---------------------------------------------------------------------------

    size_t PhoneBookVector::size()
    {
        return m_vec.size();
    }

    // ---------------------------------------------------------------------------

    bool PhoneBookVector::insert(const std::string& first, const std::string& last, size_t number)
    {
        if (contains(first, last)) {
            return false;
        }

        Entry entry(first, last, number);
        m_vec.push_back(entry);

        return true;
    }

    // ---------------------------------------------------------------------------

    bool PhoneBookVector::update(const std::string& first, const std::string& last, size_t number)
    {
        MatchNames matchNames(first, last);

        std::vector<Entry>::iterator pos = std::find_if(
            m_vec.begin(),
            m_vec.end(),
            matchNames
        );

        if (pos == m_vec.end()) {
            return false;
        }
        else {
            (*pos).number = number;
            return true;
        }
    }

    // ---------------------------------------------------------------------------

    bool PhoneBookVector::search(const std::string& first, const std::string& last, size_t& number)
    {
        MatchNames matchNames(first, last);

        std::vector<Entry>::iterator pos = std::find_if(
            m_vec.begin(),
            m_vec.end(),
            matchNames
        );

        if (pos == m_vec.end()) {

       //     std::cout << first << " " << last << " not found!" << std::endl;

            return false;
        }
        else {

            const Entry& result = *pos;

            number = result.number;

   //         std::cout << first << " " << last << " has number " << number << std::endl;

            return true;
        }
    }

    // ---------------------------------------------------------------------------

    bool PhoneBookVector::contains(const std::string& first, const std::string& last)
    {
        MatchNames matchNames(first, last);

        std::vector<Entry>::iterator pos = std::find_if(
            m_vec.begin(),
            m_vec.end(),
            matchNames
        );

        return pos != m_vec.end();
    }


    // ---------------------------------------------------------------------------

    bool PhoneBookVector::remove(const std::string& first, const std::string& last)
    {
        MatchNames matchNames(first, last);

        std::vector<Entry>::iterator pos = std::find_if(
            m_vec.begin(),
            m_vec.end(),
            matchNames
        );

        if (pos == m_vec.end()) {

         //   std::cout << first << " " << last << " not found!" << std::endl;
            return false;
        }
        else {

            m_vec.erase(pos);
            return true;
        }
    }


    // ---------------------------------------------------------------------------

    std::string PhoneBookVector::transformToName(const Entry& entry)
    {
        return entry.first + " " + entry.last;
    }

    std::forward_list<std::string> PhoneBookVector::getNames()
    {
        std::forward_list<std::string> list;

        std::transform( 
            m_vec.begin(),
            m_vec.end(), 
            std::front_insert_iterator<std::forward_list<std::string>>(list),
            transformToName
        );

        return list;
    }

    // ---------------------------------------------------------------------------

    void PhoneBookVector::printEntry(const Entry& entry)
    {
        std::cout << entry.first << " " << entry.last << ": " << entry.number << std::endl;
    }

    void PhoneBookVector::print()
    {
        std::for_each(
            m_vec.begin(),
            m_vec.end(),
            printEntry
        );
    }

    // ---------------------------------------------------------------------------

    // sorting according to last name
    bool operator< (const PhoneBookVector::Entry& entry1, const PhoneBookVector::Entry& entry2)
    {
        return entry1.last < entry2.last;
    }

    void PhoneBookVector::sort()
    {
        std::sort(
            m_vec.begin(),
            m_vec.end()
        );
    }
}

// ===============================================================================
// End-of-File
// ===============================================================================
