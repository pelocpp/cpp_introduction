// ===============================================================================
// PhoneBookMap.h // Using std::unordered_map
// ===============================================================================

#pragma once

#include "IPhoneBook.h"

#include <cstddef>
#include <string>
#include <unordered_map>
#include <forward_list>

namespace PhoneBook
{
    class PhoneBookMap : public IPhoneBook
    {
    private:
        std::unordered_map<std::string, std::size_t> m_map;

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
        // helper methods
        static std::pair<std::string, std::string> getNameFromKey(const std::string&);
        static std::string getKeyFromName(const std::string&, const std::string&);

        static void printEntry(const std::pair<std::string, std::size_t>&);
        static std::string pairToString(const std::pair<std::string, std::size_t>&);
        static std::string append(const std::string&, const std::pair<std::string, std::size_t>&);
    };
}

// ===============================================================================
// End-of-File
// ===============================================================================
