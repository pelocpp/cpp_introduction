// ===========================================================================
// DynamicIntArray.cpp
// ===========================================================================

#include <string>
#include <stdexcept>

#include "DynamicIntArray.h"

// c'tor(s) / d'tor
DynamicIntArray::DynamicIntArray()
{
    m_size = 0;
    m_data = nullptr;
}

DynamicIntArray::DynamicIntArray(size_t size)
{
    m_size = size;
    m_data = new int[size];

    // initialize buffer with default values
    for (int i = 0; i < m_size; ++i) {
        m_data[i] = 0;
    }
}

DynamicIntArray::DynamicIntArray(int* values, size_t count)
{
    m_size = count;
    m_data = new int[count];

    // initialize buffer with provided values
    for (int i = 0; i < m_size; ++i) {
        m_data[i] = values[i];
    }
}

DynamicIntArray::~DynamicIntArray()
{
    delete[] m_data;
}

// getter / setter
size_t DynamicIntArray::size() const
{
    return m_size;
}

int& DynamicIntArray::at(size_t index)
{
    // bounds checking
    if (index >= m_size) {

        std::string msg = "Wrong Index: " + std::to_string(index);
        throw std::out_of_range(msg);
    }

    return m_data[index];
}

// public interface
void DynamicIntArray::fill(int value)
{
    for (int i = 0; i < m_size; ++i) {
        m_data[i] = value;
    }
}

void DynamicIntArray::resize(size_t newSize)
{
    if (newSize <= m_size)
    {
        // just shorten length, keep buffer
        m_size = newSize;
    }
    else
    {
        // allocate new (temporary) buffer
        int* data = new int[newSize];

        // copy current buffer into new one
        for (size_t i = 0; i < m_size; ++i) {
            data[i] = m_data[i];
        }

        // initialize rest of buffer with default values
        for (size_t i = m_size; i < newSize; ++i) {
            data[i] = 0;
        }

        // release old buffer
        delete[] m_data;

        // switch to new buffer
        m_size = newSize;
        m_data = data;
    }
}

void DynamicIntArray::shrinkToFit()
{
    // allocate new - temporary and fitting - buffer
    int* data = new int[m_size];

    // copy current buffer into new one
    for (size_t i = 0; i < m_size; ++i) {
        data[i] = m_data[i];
    }

    // release old buffer
    delete[] m_data;

    // switch to new buffer
    m_data = data;
}

int DynamicIntArray::minimum() const
{
    if (m_size == 0) {
        return 0;
    }

    int min = m_data[0];

    for (int i = 1; i < m_size; i++) {

        if (min > m_data[i]) {
            min = m_data[i];
        }
    }

    return min;
}

int DynamicIntArray::maximum() const
{
    if (m_size == 0) {
        return 0;
    }

    int max = m_data[0];

    for (int i = 1; i < m_size; i++) {

        if (max < m_data[i]) {
            max = m_data[i];
        }
    }

    return max;
}

int DynamicIntArray::indexOf(int value)  const
{
    // perform a linear search
    for (int i = 0; i < m_size; i++) {
        if (m_data[i] == value) {
            return i;
        }
    }

    return -1;
}

bool DynamicIntArray::contains(int value) const
{
    for (int i = 0; i < m_size; i++) {

        if (m_data[i] == value) {
            return 1;
        }
    }

    return 0;
}

void DynamicIntArray::release() {

    if (m_data != nullptr) {

        delete[] m_data;
        m_data = nullptr;
        m_size = 0;
    }
}

void DynamicIntArray::print() const
{
    for (size_t i = 0; i < m_size; ++i) {
        std::cout << m_data[i] << ' ';
    }
    std::cout << "[Length: " << m_size << ']' << std::endl;
}

// operators
int& DynamicIntArray::operator[] (size_t index)
{
    // no bounds checking - intentionally !!!
    return m_data[index];
}

// copy semantics - copy constructor
DynamicIntArray::DynamicIntArray(const DynamicIntArray& data) {

    // allocate buffer
    m_size = data.m_size;
    m_data = new int[m_size];

    // copy object
    for (size_t i = 0; i < data.m_size; ++i) {
        m_data[i] = data.m_data[i];
    }
}

// copy semantics - assignment operator
DynamicIntArray& DynamicIntArray::operator= (const DynamicIntArray& data) {

    // prevent self-assignment
    if (this == &data)
        return *this;

    // delete old buffer
    delete[] m_data;

    // allocate a new buffer
    m_size = data.m_size;
    m_data = new int[m_size];

    // copy buffer
    for (size_t i = 0; i < data.m_size; ++i) {
        m_data[i] = data.m_data[i];
    }

    return *this;
}

// comparison operators
bool operator== (const DynamicIntArray& left, DynamicIntArray right)
{
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

bool operator!= (const DynamicIntArray& left, DynamicIntArray right)
{
    return ! (left == right);
}

// ===========================================================================
// End-of-File
// ===========================================================================
