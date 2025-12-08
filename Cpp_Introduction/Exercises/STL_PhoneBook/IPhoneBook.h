// ===============================================================================
// IPhoneBook.h
// ===============================================================================

#pragma once

#include <cstddef>
#include <forward_list>
#include <iostream>
#include <string>

namespace PhoneBook
{
    class IPhoneBook
    {
    public:
        virtual std::size_t size() = 0;
        virtual bool insert(const std::string& first, const std::string& last, std::size_t number) = 0;
        virtual bool update(const std::string& first, const std::string& last, std::size_t number) = 0;
        virtual bool search(const std::string& first, const std::string& last, std::size_t& number) = 0;
        virtual bool remove(const std::string& first, const std::string& last) = 0;
        virtual bool contains(const std::string& first, const std::string& last) = 0;
        virtual std::forward_list<std::string> getNames() = 0;
        virtual std::string toString() = 0;
        virtual void print() = 0;
    };
}

// ===============================================================================
// End-of-File
// ===============================================================================
