// ===============================================================================
// PhoneBookEx.h // Using std::unordered_map
// ===============================================================================

#pragma once

#include "IPhoneBook.h"

#include <iostream>
#include <string>
#include <unordered_map>
#include <forward_list>

namespace PhoneBook
{
    //struct PhoneBookComparator
    //{
    //    bool operator()(const std::string& left, const std::string& right) const;
    //};

    class PhoneBookMap : public IPhoneBook
    {
        //friend struct PhoneBookComparator;
        //friend std::ostream& operator << (std::ostream& os, const PhoneBookMap& pb);

    private:
       // std::unordered_map<std::string, size_t, PhoneBookComparator> m_map;
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
        void print() override;

    private:
        static std::pair<std::string, std::string> getNamesFromKey(const std::string&);
        static std::string getKeyFromNames(const std::string&, const std::string&);
    };
}

// ===============================================================================
// End-of-File
// ===============================================================================
