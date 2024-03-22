// ===============================================================================
// PhoneBookEx.h // Using std::unordered_map
// ===============================================================================

#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <forward_list>
#include <tuple>

#include "IPhoneBook.h"

namespace PhoneBookMapBased
{
    using namespace PhoneBookRequirements;

    struct PhoneBookComparator
    {
        bool operator()(const std::string& left, const std::string& right) const;
    };

    class PhoneBook : public IPhoneBook
    {
        friend struct PhoneBookComparator;
        friend std::ostream& operator << (std::ostream& os, const PhoneBook& pb);

    private:
        std::unordered_map<std::string, long, PhoneBookComparator> m_map;

    public:
        // public interface
        virtual bool insert(const std::string& first, const std::string& last, long number) override;
        virtual bool update(const std::string& first, const std::string& last, long number) override;
        virtual bool search(const std::string& first, const std::string& last, long& number) override;
        virtual bool contains(const std::string& first, const std::string& last) override;
        virtual bool remove(const std::string& first, const std::string& last) override;
        virtual std::forward_list<std::string> getNames() override;
        virtual void sort() override;
        virtual void print() override;

    private:
        static std::pair<std::string, std::string> getNamesFromKey(const std::string&);
        static std::string getKeyFromNames(const std::string&, const std::string&);
    };
}

