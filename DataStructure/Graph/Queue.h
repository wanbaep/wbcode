#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "Vertex.h"

class Queue
{
public:
    Queue() {
        pHead = NULL;
        pTail = NULL;
    };
    ~Queue() {};

    bool isEmpty() {
        if(pHead == NULL && pTail == NULL) {
            return true;
        } else {
            return false;
        }
    }

    void enqueue(Vertex* newNode) {
        if(NULL == pHead) {
            pHead = newNode;
            pTail = newNode;
        }
        else {
            newNode->qNext = pHead;
            pHead = newNode;
        }
    }

    Vertex* dequeue() {
        if(NULL == pTail) {
            return NULL;
        }
        else {
            Vertex* pTarget = pTail;
            if(pHead == pTail) {
                pHead = NULL;
                pTail = NULL;
            }
            else {
                Vertex* pCur = pHead;
                while(pTail != pCur->qNext) {
                    pCur = pCur->qNext;
                }
                pTail = pCur;
                pTail->qNext = NULL;
            }
            return pTarget;
        }
    }

private:
    Vertex* pHead;
    Vertex* pTail;
};


#endif /* _QUEUE_H_ */