#ifndef _HASH_H_
#define _HASH_H_

#include <stdio.h>
#include <string>

using namespace std;

enum NodeState
{
    EMPTY    = 0,
    OCCUPIED = 1
};

class Node
{
public:
    Node() { pNext = NULL; };
    Node(const string& key, const string& value)
    {
        m_key = key;
        m_value = value;
        pNext = NULL;
        m_state = EMPTY;
    }
    ~Node() {};
    void setKey(const string& key) { m_key = key; };
    void setValue(const string& value) { m_value = value; };
    string getKey() { return m_key; };
    string getValue() { return m_value; };

    Node* pNext;
    NodeState m_state;

private:
    string m_key;
    string m_value;
};

class Hash
{
public:
    //1. create hash table -> constructor
    Hash() {
        m_tableSize = 0;
        m_table = NULL;
    };
    //2. Destroy hash table -> destructor
    virtual ~Hash() {};
    //3. set(key, value)
    virtual void set(const string& key, const string& value) = 0;
    //4. get(key)
    virtual string get(const string& key) = 0;
    //5. hash
    virtual int hash(const string& key) = 0;

    //member variable
    int m_tableSize;
    Node* m_table;

private:

};

#endif /* _HASH_H_ */