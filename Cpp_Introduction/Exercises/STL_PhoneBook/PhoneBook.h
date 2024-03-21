#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
#include <tuple>

#include "IPhoneBook.h"

namespace PhoneBookVectorBased
{
    using namespace PhoneBookRequirements;

    class PhoneBook : public IPhoneBook
    {
    private:
        struct Entry
        {
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

     //   virtual std::ostream& operator () (std::ostream& os) override;  // ???

        // iterator support
        std::vector<Entry>::iterator begin();
        std::vector<Entry>::iterator end();
        std::vector<Entry>::const_iterator begin() const;
        std::vector<Entry>::const_iterator end() const;

        friend std::ostream& operator << (std::ostream& os, const PhoneBook& book);
        friend bool operator< (const Entry& entry1, const Entry& entry2);

        size_t vectorsizeof()
        {
            return sizeof(Entry) * m_entries.size();
        }
    };

    //bool operator< (const PhoneBook::Entry& entry1, const PhoneBook::Entry& entry2);
    //std::ostream& operator<< (std::ostream& os, const PhoneBook& book);
}
