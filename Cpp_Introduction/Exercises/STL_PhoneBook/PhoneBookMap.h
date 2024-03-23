// ===============================================================================
// PhoneBookMap.h // Using std::unordered_map
// ===============================================================================

#pragma once

#include "IPhoneBook.h"

#include <iostream>
#include <string>
#include <unordered_map>
#include <forward_list>

namespace PhoneBook
{
    class PhoneBookMap : public IPhoneBook
    {
    private:
        std::unordered_map<std::string, size_t> m_map;

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
        std::string toString() override;
        void print() override;

    private:
        // helper methods
        static std::pair<std::string, std::string> getNamesFromKey(const std::string&);
        static std::string getKeyFromNames(const std::string&, const std::string&);

        static void printEntry(const std::pair<std::string, size_t>&);
        static std::string transformToName(const std::pair<std::string, size_t>&);
        static std::string append(const std::string&, const std::pair<std::string, size_t>&);
    };
}

// ===============================================================================
// End-of-File
// ===============================================================================
