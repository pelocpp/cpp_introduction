// ===========================================================================
// DynamicArrayTemplate.h
// ===========================================================================

#pragma once

#include <iostream>
#include <string>

template <typename T>
class DynamicArrayTemplate
{
private:
    size_t m_size;
    T* m_data;

public:
    // c'tor(s) / d'tor
    DynamicArrayTemplate() {

        m_size = 0;
        m_data = nullptr;
    }
    
    DynamicArrayTemplate(size_t size) {

        m_size = size;
        m_data = new T[size];

        // initialize buffer with default values
        for (int i = 0; i < m_size; ++i) {
            m_data[i] = T();
        }
    }
    
    ~DynamicArrayTemplate() {
        delete[] m_data;
    }

    // getter / setter
    size_t size() const { return m_size; }

    T& at(size_t index) {

        // bounds checking
        if (index >= m_size) {

            std::string msg = "Wrong Index: " + std::to_string(index);
            throw std::out_of_range(msg);
        }

        return m_data[index];
    }

    // public interface
    void fill(T value) {

        for (int i = 0; i < m_size; ++i) {
            m_data[i] = value;
        }
    }
    
    void resize(size_t newSize) {
    
        // allocate new buffer
        T* data = new T[newSize];

        size_t minSize = (newSize <= m_size) ? newSize : m_size;

        // copy old buffer into new one
        for (size_t i = 0; i < minSize; ++i) {
            data[i] = m_data[i];
        }

        // initialize rest of buffer, if any, with default values
        for (size_t i = m_size; i < newSize; ++i) {
            data[i] = T();
        }

        // release old buffer
        delete[] m_data;

        // switch to new buffer
        m_size = newSize;
        m_data = data;
    }
    
    void release() {
    
        delete[] m_data;
        m_data = nullptr;
        m_size = 0;
    }
    
    void print() {

        for (size_t i = 0; i < m_size; ++i) {
            std::cout << m_data[i] << ' ';
        }
        std::cout << "[Length: " << m_size << ']' << std::endl;
    }

    // operators
    T& operator[] (size_t index) {

        // no bounds checking - intentionally !!!
        return m_data[index];
    }

    // copy semantics - copy constructor
    DynamicArrayTemplate(const DynamicArrayTemplate& other) {

        // allocate buffer
        m_size = other.m_size;
        m_data = new T[m_size];

        // copy object
        for (size_t i = 0; i < other.m_size; ++i) {
            m_data[i] = other.m_data[i];
        }
    }

    // copy semantics - assignment operator
    DynamicArrayTemplate& operator= (const DynamicArrayTemplate& other) {

        // prevent self-assignment
        if (this == &other)
            return *this;

        // delete old buffer
        delete[] m_data;

        // allocate a new buffer
        m_size = other.m_size;
        m_data = new T[m_size];

        // copy buffer
        for (size_t i = 0; i < other.m_size; ++i) {
            m_data[i] = other.m_data[i];
        }

        return *this;
    }

    // comparison operators
    friend bool operator== (const DynamicArrayTemplate& left, DynamicArrayTemplate right) {

        if (left.m_size != right.m_size) {
            return false;
        }

        for (int i = 0; i < left.m_size; ++i) {

            if (left.m_data[i] != right.m_data[i]) {
                return false;
            }
        }

        return true;
    }

    friend bool operator!= (const DynamicArrayTemplate& left, DynamicArrayTemplate right) {

        return !(left == right);
    }
};

// ===========================================================================
// End-of-File
// ===========================================================================
