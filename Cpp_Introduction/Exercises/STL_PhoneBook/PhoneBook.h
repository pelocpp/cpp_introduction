// ===============================================================================
// PhoneBook.h // Using std::vector
// ===============================================================================

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <forward_list>

#include "IPhoneBook.h"

namespace PhoneBookVectorBased
{
    using namespace PhoneBookRequirements;

    class PhoneBook : public IPhoneBook
    {
    private:
        class Entry
        {
        public:
            Entry(const std::string& first, const std::string& last, long number)
            {
                m_first = first;
                m_last = last;
                m_number = number;
            }

            std::string m_first;
            std::string m_last;
            long        m_number;
        };

        std::vector<Entry> m_entries;

    public:
        // public interface
        virtual bool insert(const std::string& first, const std::string& last, long number) override;
        virtual bool update(const std::string& first, const std::string& last, long number) override;
        virtual bool search(const std::string& first, const std::string& last, long& number) override;
        virtual bool contains(const std::string& first, const std::string& last) override;
        virtual bool remove(const std::string& first, const std::string& last) override;
        virtual std::forward_list<std::string> getNames() override;
        virtual void sort() override;


       // friend std::ostream& operator << (std::ostream& os, const PhoneBook& book);

        friend bool operator< (const Entry& entry1, const Entry& entry2);

        //size_t vectorsizeof()
        //{
        //    return sizeof(Entry) * m_entries.size();
        //}
    };

    //bool operator< (const PhoneBook::Entry& entry1, const PhoneBook::Entry& entry2);
    //std::ostream& operator<< (std::ostream& os, const PhoneBook& book);
}

// ===============================================================================
// End-of-File
// ===============================================================================
