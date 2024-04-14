// ===========================================================================
// DynamicIntArray.h
// ===========================================================================

#pragma once

#include <iostream>

class DynamicIntArray
{
private:
    int* m_data;
    size_t m_size;

public:
    // c'tor(s) / d'tor
    DynamicIntArray();
    DynamicIntArray(size_t size);
    DynamicIntArray(int* values, size_t count);
    ~DynamicIntArray();

    // getter / setter
    size_t size() const;
    int& at(size_t index);

    // public interface
    void fill(int value);
    void resize(size_t newSize);
    void shrinkToFit();
    int  minimum() const;
    int  maximum() const;
    int  indexOf(int value) const;
    bool contains(int value) const;
    void release();
    void print() const;

    // operators
    int& operator[] (size_t index);

    // copy semantics
    DynamicIntArray(const DynamicIntArray&); // copy c'tor
    DynamicIntArray& operator= (const DynamicIntArray&);  // copy assignment

    // comparison operators
    friend bool operator== (const DynamicIntArray& left, DynamicIntArray right);
    friend bool operator!= (const DynamicIntArray& left, DynamicIntArray right);
};

// ===========================================================================
// End-of-File
// ===========================================================================
