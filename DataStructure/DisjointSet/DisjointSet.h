#ifndef _DISJOINT_SET_H_
#define _DISJOINT_SET_H_

#include <stdio.h>

class Node
{
public:
    int m_data;
    Node* pParent;
    Node(int data) {
        m_data = data;
        pParent = NULL;
    }
};

class DisjointSet
{
public:
    DisjointSet() {};
    ~DisjointSet() {};
    //union
    void unionSet(Node* set1, Node* set2) {
        set2 = findSet(set2);
        set2->pParent = set1;
    }
    //find
    Node* findSet(Node* set) {
        while(NULL != set->pParent) {
            set = set->pParent;
        }
        return set;
    }

private:

};


#endif /* DISJOINT_SET_H_ */