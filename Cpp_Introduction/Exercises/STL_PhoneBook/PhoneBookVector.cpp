// ===============================================================================
// PhoneBookVector.h
// ===============================================================================

#include "PhoneBookVector.h"

#include <algorithm> 
#include <iomanip>
#include <iostream>
#include <numeric> 
#include <sstream> 

namespace PhoneBook
{
    // getter
    std::size_t PhoneBookVector::size()
    {
        return m_entries.size();
    }

    // public interface
    bool PhoneBookVector::insert(const std::string& first, const std::string& last, std::size_t number)
    {
        if (contains(first, last)) {
            return false;
        }

        Entry entry(first, last, number);
        m_entries.push_back(entry);

        return true;
    }

    bool PhoneBookVector::update(const std::string& first, const std::string& last, std::size_t number)
    {
        MatchName name(first, last);

        std::vector<Entry>::iterator pos = std::find_if(
            m_entries.begin(),
            m_entries.end(),
            name
        );

        if (pos == m_entries.end()) {
            return false;
        }
        else {
            (*pos).m_number = number;
            return true;
        }

        return true;
    }

    bool PhoneBookVector::search(const std::string& first, const std::string& last, std::size_t& number)
    {
        MatchName name(first, last);

        std::vector<Entry>::iterator pos = std::find_if(
            m_entries.begin(),
            m_entries.end(),
            name
        );

        if (pos == m_entries.end()) {
            return false;
        }
        else {
            const Entry& result = *pos;
            number = result.m_number;
            return true;
        }
    }

    bool PhoneBookVector::contains(const std::string& first, const std::string& last)
    {
        MatchName name(first, last);

        std::vector<Entry>::iterator pos = std::find_if(
            m_entries.begin(),
            m_entries.end(),
            name
        );

        return pos != m_entries.end();
    }

    bool PhoneBookVector::remove(const std::string& first, const std::string& last)
    {
        MatchName name(first, last);

        std::vector<Entry>::iterator pos = std::find_if(
            m_entries.begin(),
            m_entries.end(),
            name
        );

        if (pos == m_entries.end()) {
            return false;
        }
        else {
            m_entries.erase(pos);
            return true;
        }
    }

    // ---------------------------------------------------------------------------

    std::string PhoneBookVector::entryToString(const Entry& entry)
    {
        return entry.m_first + " " + entry.m_last;
    }

    std::forward_list<std::string> PhoneBookVector::getNames()
    {
        std::forward_list<std::string> list;

        std::transform( 
            m_entries.begin(),
            m_entries.end(), 
            std::front_insert_iterator<std::forward_list<std::string>>(list),
            entryToString
        );

        return list;
    }

    // ---------------------------------------------------------------------------

    std::string PhoneBookVector::append(const std::string& first, const Entry& next)
    {
        static int counter = 0;
        counter++;

        std::string name = next.m_first + " " + next.m_last;

        std::ostringstream ss;
        ss << std::setfill('0') << std::setw(2) << counter
           << ": " << std::setfill(' ') << std::setw(16) << std::left << name << " Phone: "
           << next.m_number << std::endl;

        return first + ss.str();
    }

    std::string PhoneBookVector::toString() {

        std::string s = std::accumulate(
            m_entries.begin(),
            m_entries.end(),
            std::string(),
            append
        );

        return s;
    };

    // ---------------------------------------------------------------------------

    void PhoneBookVector::printEntry(const Entry& entry)
    {
        std::cout << entry.m_first << " " << entry.m_last << ": " << entry.m_number << std::endl;
    }

    void PhoneBookVector::print()
    {
        std::for_each(
            m_entries.begin(),
            m_entries.end(),
            printEntry
        );
    }
}

// ===============================================================================
// End-of-File
// ===============================================================================
