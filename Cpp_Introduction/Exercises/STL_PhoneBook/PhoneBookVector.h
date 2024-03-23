// ===============================================================================
// PhoneBookVector.h // Using std::vector
// ===============================================================================

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <forward_list>

#include "IPhoneBook.h"

namespace PhoneBook
{
    class PhoneBookVector : public IPhoneBook
    {
    private:
        // private helper classes
        class Entry
        {
        public:
            std::string first;
            std::string last;
            size_t number;

            Entry(const std::string& first, const std::string& last, size_t number)
                : first(first), last(last), number(number)
            {}
        };

        class MatchNames
        {
        public:
            const std::string& first;
            const std::string& last;
            
            MatchNames(const std::string& first, const std::string& last)
                : first(first), last(last)
            {}

            bool operator() (const Entry& entry) const {

                return entry.first == first && entry.last == last;
            }
        };

        // member data
        std::vector<Entry> m_vec;

    public:
        // public interface
        size_t size() override;
        bool insert(const std::string& first, const std::string& last, size_t number) override;
        bool update(const std::string& first, const std::string& last, size_t number) override;
        bool search(const std::string& first, const std::string& last, size_t& number) override;
        bool remove(const std::string& first, const std::string& last) override;
        bool contains(const std::string& first, const std::string& last) override;
        std::forward_list<std::string> getNames() override;
        void sort() override;
        void print() override;

       // friend std::ostream& operator << (std::ostream& os, const PhoneBook& book);

        friend bool operator< (const Entry&, const Entry&);

    private:
        // private helper methods
        static void printEntry(const Entry&);
        static std::string transformToName(const Entry&);
    };

    //std::ostream& operator<< (std::ostream& os, const PhoneBook& book);


}

// ===============================================================================
// End-of-File
// ===============================================================================
