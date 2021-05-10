#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "Vertex.h"
#include "Queue.h"
#include "PriorityQueue.h"

#define USER_INF 999999

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
    void initVisited() {
        Vertex* pCur = vertices;
        while(NULL != pCur) {
            pCur->visited = NOT_VISITED;
            pCur = pCur->pNext;
        }
    }

    void dfs(Vertex* vStart) {
        printf("%d ", vStart->data);
        vStart->visited = VISITED;
        Edge* pEdge = vStart->pAdjacency;
        while(NULL != pEdge) {
            if(NULL != pEdge->m_pTarget && pEdge->m_pTarget->visited == NOT_VISITED) {
                dfs(pEdge->m_pTarget);
            }
            pEdge = pEdge->pNext;
        }
    }

    void bfs(Vertex* vStart) {
        Queue queue;
        printf("%d ", vStart->data);
        vStart->visited = VISITED;
        queue.enqueue(vStart);

        while(!queue.isEmpty()) {
            // printf("queue not empty\n");
            Vertex* pPop = queue.dequeue();
            Edge* pEdge = pPop->pAdjacency;

            while(NULL != pEdge) {
                Vertex* pTemp = pEdge->m_pTarget;
                if(pTemp != NULL && pTemp->visited == NOT_VISITED) {
                    printf("%d ", pTemp->data);
                    pTemp->visited = VISITED;
                    queue.enqueue(pTemp);
                }
                pEdge = pEdge->pNext;
            }
        }
    }

    void prim(Vertex* startNode) {
        printf("prim");
        Vertex* pCur = vertices;
        while(NULL != pCur) {
            pCur->key = USER_INF;
            pCur->parent = NULL;
        }
        PriorityQueue queue(10);
        HeapNode node = {startNode->key, (void*)startNode};
        queue.enqueue(node);
        while(!queue.isEmpty()) {
            HeapNode u = queue.dequeue();
            pCur = (Vertex*) u.data;
            Edge* pEdge = pCur->pAdjacency;
            while(NULL != pEdge) {
                Vertex* pTarget = pEdge->m_pTarget;
                if(pTarget->key > pCur->key + pEdge->m_weight) {
                    pTarget->parent = pCur;
                    pTarget->key = pCur->key + pEdge->m_weight;
                }
            }
        }
    }
private:
    int vertexCount;
    Vertex* vertices;
};


#endif /* _GRAPH_H_ */