// =====================================================================================
// BigData.cpp // "Rule of Three"
// =====================================================================================

#include "BigData.h"

namespace Rule_Of_Three {

    // c'tors and d'tor
    BigData::BigData() {

        // empty buffer
        m_size = 0;
        m_data = nullptr;
    }

    BigData::BigData(int size) {

        // create buffer
        m_size = size;
        m_data = new int[m_size];

        // initialize buffer
        for (int i = 0; i < m_size; ++i) {
            m_data[i] = 0;
        }
    }

    BigData::~BigData() {
        delete[] m_data;
    }

    // ===================================================================
    // getter

    int BigData::size() const {
        return m_size;
    }

    bool BigData::isEmpty() const {
        return m_size == 0;
    }

    // ===================================================================
    // copy semantics: copy constructor and assignment operator 

#if defined (IsCorrect)

    BigData::BigData(const BigData& data) {

        // allocate buffer
        m_size = data.m_size;
        m_data = new int[m_size];

        // copy object
        for (int i = 0; i < m_size; ++i) {
            m_data[i] = data.m_data[i];
        }
    }

    BigData& BigData::operator= (const BigData& data) {

        // prevent self-assignment
        if (this == &data)
            return *this;

        // delete old buffer
        delete[] m_data;

        // allocate a new buffer
        m_size = data.m_size;
        m_data = new int[m_size];

        // copy buffer
        for (int i = 0; i < m_size; ++i) {
            m_data[i] = data.m_data[i];
        }

        return *this;
    }

#endif

    // ===================================================================
    // public interface

    void BigData::print() {
        std::printf("Data: Starting at %08p\n", m_data);
        std::printf("Size: %d\n", m_size);
    }
}

// =====================================================================================
// End-of-File
// =====================================================================================
