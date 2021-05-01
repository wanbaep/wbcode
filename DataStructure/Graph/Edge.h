#ifndef _EDGE_H_
#define _EDGE_H_

#include "Vertex.h"
#include <stdio.h>

class Vertex; //전방 선언

class Edge
{
public:
    Edge(Vertex* pTarget, int weight)
        : m_weight(weight), pNext(NULL), m_pTarget(pTarget)
    {
    }
    ~Edge();

    int m_weight;
    Edge* pNext;
    Vertex* m_pTarget;
private:
    
};

#endif /* _EDGE_H_ */