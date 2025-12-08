// ===============================================================================
// PhoneBookVector.h // Using std::vector
// ===============================================================================

#pragma once

#include "IPhoneBook.h"

#include <cstddef>
#include <string>
#include <vector>
#include <forward_list>

namespace PhoneBook
{
    class PhoneBookVector : public IPhoneBook
    {
    private:
        // private helper classes
        class Entry
        {
        public:
            std::string m_first;
            std::string m_last;
            std::size_t m_number;

            Entry() : m_number(0) {}

            Entry(const std::string& first, const std::string& last, std::size_t number)
                : m_first(first), m_last(last), m_number(number)
            {}
        };

        class MatchName
        {
        public:
            const std::string& first;
            const std::string& last;
            
            MatchName(const std::string& first, const std::string& last)
                : first(first), last(last)
            {}

            bool operator() (const Entry& other) const {
                return other.m_first == first && other.m_last == last;
            }
        };

        // member data
        std::vector<Entry> m_vec;

    public:
        // public interface
        std::size_t size() override;
        bool insert(const std::string& first, const std::string& last, std::size_t number) override;
        bool update(const std::string& first, const std::string& last, std::size_t number) override;
        bool search(const std::string& first, const std::string& last, std::size_t& number) override;
        bool remove(const std::string& first, const std::string& last) override;
        bool contains(const std::string& first, const std::string& last) override;
        std::forward_list<std::string> getNames() override;
        std::string toString() override;
        void print() override;

    private:
        // private helper methods
        static void printEntry             (const Entry&);
        static std::string entryToString   (const Entry&);
        static std::string append          (const std::string&, const Entry&);
    };
}

// ===============================================================================
// End-of-File
// ===============================================================================
