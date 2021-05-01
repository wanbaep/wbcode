#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "Vertex.h"

class Graph
{
public:
    Graph()
        :vertexCount(0), vertices(NULL)
    {
    }
    ~Graph() {};
    void addVertex(Vertex* newVertex)
    {
        if(NULL == vertices)
        {
            vertices = newVertex;
        }
        else
        {
            Vertex* pCur = vertices;
            while(NULL != pCur->pNext)
            {
                pCur = pCur->pNext;
            }
            pCur->pNext = newVertex;
        }
    }
    void printGraph()
    {
        Vertex* pVertex = vertices;

        while(NULL != pVertex)
        {
            Edge* pEdge = pVertex->pAdjacency;
            printf("%d : ", pVertex->data);
            while(NULL != pEdge)
            {
                if(NULL != pEdge->m_pTarget)
                {
                    printf("%d[%d] ", pEdge->m_pTarget->data, pEdge->m_weight);
                }
                pEdge = pEdge->pNext;
            }
            printf("\n");
            pVertex = pVertex->pNext;
        }
    }
private:
    int vertexCount;
    Vertex* vertices;
};


#endif /* _GRAPH_H_ */