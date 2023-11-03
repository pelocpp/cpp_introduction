// =====================================================================================
// BigData.h // "Rule of Three"
// =====================================================================================

#pragma once

#include <iostream>
#include <cstdio>

namespace Rule_Of_Three {

    class BigData
    {
    private:
        // private member data
        int m_size;   // current number of elements
        int* m_data;  // dynamically allocated array of elements

    public:
        // c'tors and d'tor
        BigData();
        BigData(int size);
        ~BigData();

        // getter
        int size() const;
        bool isEmpty() const;

        // copy semantics
        BigData(const BigData&); // copy c'tor
        BigData& operator= (const BigData&);  // copy assignment

        // public interface
        void print();
    };
}

// =====================================================================================
// End-of-File
// =====================================================================================
