#ifndef _OPEN_ADDRESS_HASH_H_
#define _OPEN_ADDRESS_HASH_H_

#include "Hash.h"

class OpenAddressHash : public Hash
{
public:
    OpenAddressHash(int tableSize)
    {
        occupiedCount = 0;
        m_tableSize = tableSize;
        m_table = new Node[m_tableSize];
    }
    ~OpenAddressHash()
    {
        delete[] m_table;
        m_table = NULL;
    }
    //1. set
    void set(const string& key, const string& value)
    {
        double usage = (double)occupiedCount / m_tableSize;
        if(usage > 0.5)
        {
            rehash();
        }
        int address = hash(key);
        int stepSize = hashForStep(key);
        while(EMPTY != m_table[address].m_state && m_table[address].getKey() != key)
        {
            printf("Collision occured! : Key(%s), Address(%d), stepSize(%d)\n", key.c_str(), address, stepSize);
            address = (address + stepSize) % m_tableSize;
        }
        m_table[address].setKey(key);
        m_table[address].setValue(value);
        m_table[address].m_state = OCCUPIED;
        ++occupiedCount;
        printf("Key(%s) entered at address(%d)\n", key.c_str(), address);
    }
    //2. get
    string get(const string& key)
    {
        int address = hash(key);
        int stepSize = hashForStep(key);
        while(EMPTY != m_table[address].m_state && m_table[address].getKey() != key)
        {
            address = (address + stepSize) % m_tableSize;
        }
        return m_table[address].getValue();
    }
    //3. hash
    int hash(const string& key)
    {
        int hashValue = 0;
        for(int i = 0; i < key.size(); ++i)
        {
            hashValue = (hashValue << 3) + key[i];
        }
        return hashValue % m_tableSize;
    }
    //4. hash2
    int hashForStep(const string& key)
    {
        int hashValue = 0;
        for(int i = 0; i < key.size(); ++i)
        {
            hashValue = (hashValue << 2) + key[i];
        }
        return hashValue % (m_tableSize - 3) - 1;
    }
    //5. rehash

private:
    //prevent default consturctor
    OpenAddressHash() {};
    void rehash()
    {
        Node* oldTable = m_table;
        int oldTableSize = m_tableSize;
        m_tableSize *= 2;
        Node* newTable = new Node[m_tableSize];
        m_table = newTable;
        printf("\nRehashed. New table size is : %d\n\n", m_tableSize);
        for(int i = 0; i < oldTableSize; ++i)
        {
            if(OCCUPIED == oldTable[i].m_state)
            {
                set(oldTable[i].getKey(), oldTable[i].getValue());
            }
        }
        delete[] oldTable;
    };

    int occupiedCount;
};

#endif /* _OPEN_ADDRESS_HASH_H_ */