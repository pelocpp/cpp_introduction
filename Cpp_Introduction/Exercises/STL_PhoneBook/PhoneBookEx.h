// ===============================================================================
// PhoneBook.h // Using std::unordered_map
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

    private:
        std::unordered_map<std::string, long, PhoneBookComparator> m_map;

    private:

        //class PhoneBookIterator
        //{
        //private:
        //    std::map<std::string, long, PhoneBookComparator>::iterator m_position;
        //    PhoneBook& m_outer;  // back reference

        //public:
        //    PhoneBookIterator(PhoneBook& outer, std::map<std::string, long, PhoneBookComparator>::iterator position)
        //        : m_outer{ outer } , m_position{ position } {}

        //    bool operator != (const PhoneBookIterator& other) {
        //        return m_position != other.m_position;
        //    }

        //    void operator++ () {
        //        m_position++;
        //    }

        //    std::tuple<std::string, std::string, long> operator* () {

        //        const auto& [key, number] = *m_position;
        //        const auto& [first, last] = PhoneBook::getNamesFromKey(key);
        //        return { first, last, number };
        //    }
        //};

        //class ConstPhoneBookIterator
        //{
        //private:
        //    std::map<std::string, long, PhoneBookComparator>::const_iterator m_position;

        //    const PhoneBook& m_outer;  // back reference

        //public:
        //    ConstPhoneBookIterator(const PhoneBook& outer, std::map<std::string, long, PhoneBookComparator>::const_iterator position)
        //        : m_outer{ outer }, m_position{ position } {}

        //    bool operator != (const ConstPhoneBookIterator& other) {
        //        return m_position != other.m_position;
        //    }

        //    void operator++ () {
        //        m_position++;
        //    }

        //    const std::tuple<std::string, std::string, long> operator* () const {

        //        const auto& [key, number] = *m_position;
        //        const auto& [first, last] = PhoneBook::getNamesFromKey(key);
        //        return { first, last, number };
        //    }
        //};

        //using iterator = class PhoneBookIterator;
        //using const_iterator = class ConstPhoneBookIterator;


    public:
        // public interface
        virtual bool insert(const std::string& first, const std::string& last, long number) override;
        virtual bool update(const std::string& first, const std::string& last, long number) override;
        virtual bool search(const std::string& first, const std::string& last, long& number) override;
        virtual bool contains(const std::string& first, const std::string& last) override;
        virtual bool remove(const std::string& first, const std::string& last) override;
        virtual std::forward_list<std::string> getNames() override;
        virtual void sort() override;

        // iterator support
        //PhoneBookIterator begin() { return PhoneBookIterator{ *this, m_map.begin() }; }
        //PhoneBookIterator end() { return PhoneBookIterator{ *this, m_map.end() }; }
        //ConstPhoneBookIterator begin() const { return ConstPhoneBookIterator(*this, m_map.begin() ); }
        //ConstPhoneBookIterator end() const { return ConstPhoneBookIterator{ *this, m_map.end() }; }

     //   friend std::ostream& operator<< (std::ostream& os, const PhoneBook& pb);

    private:
        static std::pair<std::string, std::string> getNamesFromKey(const std::string&);
        static std::string getKeyFromNames(const std::string&, const std::string&);
    };
}

