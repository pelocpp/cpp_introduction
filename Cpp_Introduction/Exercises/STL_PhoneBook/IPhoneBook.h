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
        virtual std::size_t size() const = 0;
        virtual bool insert(const std::string& first, const std::string& last, std::size_t number) = 0;
        virtual bool update(const std::string& first, const std::string& last, std::size_t number) = 0;
        virtual bool search(const std::string& first, const std::string& last, std::size_t& number) const = 0;
        virtual bool remove(const std::string& first, const std::string& last) = 0;
        virtual bool contains(const std::string& first, const std::string& last) const = 0;
        virtual std::forward_list<std::string> getNames() const = 0;
        virtual std::string toString() const = 0;
        virtual void print() const = 0;
    };
}

// ===============================================================================
// End-of-File
// ===============================================================================
