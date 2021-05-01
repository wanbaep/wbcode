#ifndef _LINKED_HASH_H_
#define _LINKED_HASH_H_

#include "Hash.h"

class LinkedHash : public Hash
{
public:
    LinkedHash(int tableSize)
    {
        m_tableSize = tableSize;
        m_table = new Node[m_tableSize];
    };
    ~LinkedHash()
    {
        if(NULL != m_table)
        {
            for(int i = 0; i < m_tableSize; ++ i)
            {
                Node* pCur = m_table[i].pNext;
                while(NULL != pCur)
                {
                    Node* pDel = pCur;
                    pCur = pCur->pNext;
                    pDel->pNext = NULL;
                    delete pDel;
                }
            }
            delete[] m_table;
        }
    }
    //get
    string get(const string& key)
    {
        int address = hash(key);
        Node* pCur = m_table[address].pNext;
        while(NULL != pCur)
        {
            if(pCur->getKey() == key)
            {
                return pCur->getValue();
            }
            pCur = pCur->pNext;
        }
        return "";
    }
    //set
    void set(const string& key, const string& value)
    {
        int address = hash(key);
        Node* newNode = new Node(key, value);

        if(NULL == m_table[address].pNext)
        {
            m_table[address].pNext = newNode;
        }
        else
        {
            //중복 check
            
            if("" != get(key))
            {
                printf("already inserted data value: %s\n", get(key).c_str());
                changeKeyValue(key, value);
            }
            else
            {
                Node* tmp = m_table[address].pNext;
                m_table[address].pNext = newNode;
                newNode->pNext = tmp;

                printf("Collision occured : Key(%s), Address(%d) \n", key.c_str(), address);
            }
            
        }
    }
    //hash
    int hash(const string& key)
    {
        int hashValue = 0;
        for(int i = 0; i < key.size(); ++i)
        {
            hashValue = (hashValue << 3) + key[i];
        }
        return hashValue % m_tableSize;
    }
    
private:
    //prevent default constructor
    LinkedHash() {};

    void changeKeyValue(const string& key, const string& value)
    {
        int address = hash(key);
        string preValue = "";
        Node* pCur = m_table[address].pNext;
        while(NULL != pCur)
        {
            if(pCur->getKey() == key)
            {
                preValue = pCur->getValue();
                break;
            }
            pCur = pCur->pNext;
        }
        pCur->setValue(value);
        printf("change Key Value prev:%s, next:%s\n", preValue.c_str(), value.c_str());
    }
    
};


#endif /* _LINKED_HASH_H_ */