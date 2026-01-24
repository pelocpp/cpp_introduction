// ===============================================================================
// PhoneBookVector.h // Using std::vector
// ===============================================================================

#pragma once

#include "IPhoneBook.h"

#include <cstddef>
#include <forward_list>
#include <string>
#include <vector>

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
        std::vector<Entry> m_entries;

    public:
        // public interface
        std::size_t size() const override;
        bool insert(const std::string& first, const std::string& last, std::size_t number) override;
        bool update(const std::string& first, const std::string& last, std::size_t number) override;
        bool search(const std::string& first, const std::string& last, std::size_t& number) const override;
        bool remove(const std::string& first, const std::string& last) override;
        bool contains(const std::string& first, const std::string& last) const override;
        std::forward_list<std::string> getNames() const override;
        std::string toString() const override;
        void print() const override;

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
