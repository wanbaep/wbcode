#ifndef _VERTEX_H_
#define _VERTEX_H_

#include "Edge.h"

class Edge; //전방선언

typedef int ElementType;

enum VisitMode
{
    VISITED     = 0,
    NOT_VISITED = 1,
};

class Vertex
{
public:
    Vertex(int inputData)
        : data(inputData), visited(NOT_VISITED), index(-1), pNext(NULL), pAdjacency(NULL)
    {
    }
    ~Vertex();
    void addEdge(Edge* newEdge)
    {
        if(NULL == pAdjacency)
        {
            pAdjacency = newEdge;
        }
        else
        {
            Edge* pCur = pAdjacency;
            while(NULL != pCur->pNext)
            {
                pCur = pCur->pNext;
            }
            pCur->pNext = newEdge;
        }
    }

    ElementType data;
    int visited;
    int index;
    Vertex* pNext;
    Edge* pAdjacency;
    Vertex* qNext;
private:
    
};

#endif /* _VERTEX_H_ */