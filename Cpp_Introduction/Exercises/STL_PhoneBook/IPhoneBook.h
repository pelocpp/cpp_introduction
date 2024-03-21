#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
#include <tuple>

namespace PhoneBookRequirements
{
    class IPhoneBook
    {
    public:
        virtual bool insert(const std::string& first, const std::string& last, long number) = 0;
        virtual bool update(const std::string& first, const std::string& last, long number) = 0;
        virtual bool search(const std::string& first, const std::string& last, long& number) = 0;
        virtual bool contains(const std::string& first, const std::string& last) = 0;
        virtual bool remove(const std::string& first, const std::string& last) = 0;
        virtual void sort() = 0;
        virtual std::forward_list<std::string> getNames() = 0;

        // Aufruf Operator // General Purpose Operator
       // virtual std::ostream& operator() (std::ostream& os) = 0;    // ?????
    };
}
