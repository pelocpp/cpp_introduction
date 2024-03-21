#include <algorithm> 

#include "PhoneBook.h"

namespace PhoneBookVectorBased
{
    bool PhoneBook::insert(const std::string& first, const std::string& last, long number)
    {
        if (contains(first, last)) {
            return false;
        }

        m_entries.push_back(Entry (first, last, number));
        // m_entries.emplace_back(first, last, number); 
        return true;
    }

    bool PhoneBook::update(const std::string& first, const std::string& last, long number)
    {
        auto position = std::find_if(
            m_entries.begin(),
            m_entries.end(),
            [&](Entry e) {
                return (e.m_first == first && e.m_last == last) ? true : false;
            }
        );

        if (position == m_entries.end()) {
            return false;
        }
        else {
            (*position).m_number = number;
            return true;
        }
    }

    bool PhoneBook::search(const std::string& first, const std::string& last, long& number)
    {
        number = 0;

        auto result = std::find_if(
            m_entries.begin(), 
            m_entries.end(), 
            [&](Entry e) {
                return (e.m_first == first && e.m_last == last) ? true : false;
            }
        );

        if (result == m_entries.end()) {
            return false;
        }
        else {
            Entry gefunden = *result;
            number = gefunden.m_number;
            return true;
        }
    }

    bool PhoneBook::contains(const std::string& first, const std::string& last)
    {
        auto result = std::find_if(
            m_entries.begin(), 
            m_entries.end(),
            [&](Entry e) {
                return (e.m_first == first && e.m_last == last) ? true : false;
            }
        );

        return (result == m_entries.end()) ? false : true;
    }

    bool PhoneBook::remove(const std::string& first, const std::string& last)
    {
        auto result = std::remove_if(
            m_entries.begin(),
            m_entries.end(), 
            [&](Entry e) {
                return (e.m_first == first && e.m_last == last) ? true : false;
            }
        );

        if (result == m_entries.end()) {
            return false;
        }
        else {
            m_entries.erase(result, m_entries.end());
            return true;
        }
    }

    std::forward_list<std::string> PhoneBook::getNames()
    {
        std::forward_list<std::string> result;

        std::transform( 
            m_entries.begin(),
            m_entries.end(), 
            std::front_insert_iterator<std::forward_list<std::string>>(result),
            [] (const auto& entry) {
                std::string name{ entry.m_first + " " + entry.m_last };
                return name;
            }
        );

        return result;
    }

    //std::vector<PhoneBook::Entry>::iterator PhoneBook::begin()
    //{
    //    return m_entries.begin();
    //}

    //std::vector<PhoneBook::Entry>::iterator PhoneBook::end()
    //{
    //    return m_entries.end();
    //}

    //std::vector<PhoneBook::Entry>::const_iterator PhoneBook::begin() const
    //{
    //    return m_entries.begin();
    //}

    //std::vector<PhoneBook::Entry>::const_iterator PhoneBook::end() const
    //{
    //    return m_entries.end();
    //}

    bool operator< (const PhoneBook::Entry& entry1, const PhoneBook::Entry& entry2)
    {
        // sorting according to last name
        return (entry1.m_last < entry2.m_last) ? true : false;
    }

    void PhoneBook::sort()
    {
        std::sort (
            m_entries.begin(), 
            m_entries.end()
        );
    }

    // ?????????????????????????????????????????????????????????????????????
    //std::ostream& PhoneBook::operator () (std::ostream& os)
    //{
    //    os << *this;
    //    return os;
    //}

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
}

