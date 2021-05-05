#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

#include <stdio.h>
#include <string>

typedef struct
{
    int priority;
    void* data;
}HeapNode;

class PriorityQueue
{

public:
    PriorityQueue(int size) {
        usedSize = 0;
        capacity = size;
        heap = (HeapNode*) malloc(sizeof(HeapNode) * capacity);
    };
    ~PriorityQueue() {
        free(heap);
    };
    bool isEmpty() {
        if(usedSize == 0) {
            return true;
        } else {
            return false;
        }
    }
    void enqueue(HeapNode newData) {
        int currentPosition = usedSize;
        int parentPosition = getParent(currentPosition);
        if(usedSize == capacity) {
            increaseCapacity();
        }
        heap[currentPosition] = newData;
        
        while(currentPosition > 0 && heap[currentPosition].priority < heap[parentPosition].priority) {
            //swap
            HeapNode tmp = heap[currentPosition];
            heap[currentPosition] = heap[parentPosition];
            heap[parentPosition] = tmp;

            currentPosition = parentPosition;
            parentPosition = getParent(currentPosition);
        }
        ++usedSize;
    }

    HeapNode dequeue() {
        HeapNode pPop;
        pPop.priority = heap[0].priority;
        pPop.data = heap[0].data;

        --usedSize;
        heap[0] = heap[usedSize];

        int parent = 0;

        while(1) {
            int selectedChild = 0;
            //left child check
            int leftChild = getLeftChild(parent);
            int rightChild = leftChild + 1;
            if(leftChild >= usedSize) break;
            if(rightChild >= usedSize) {
                selectedChild = leftChild;
            }
            else {
                if(heap[leftChild].priority < heap[rightChild].priority) {
                    selectedChild = leftChild;
                } else {
                    selectedChild = rightChild;
                }
            }
            //swap
            if(heap[parent].priority > heap[selectedChild].priority) {
                HeapNode tmp = heap[selectedChild];
                heap[selectedChild] = heap[parent];
                heap[parent] = tmp;
                parent = selectedChild;
            } else {
                break;
            }
        }
        if(usedSize < (capacity/2)) {
            decreaseCapacity();
        }
        return pPop;
    }
    void printNodes() {
        for(int i = 0; i < usedSize; ++i) {
            printf("%d:%s ", heap[i].priority, (char*)heap[i].data);
        }
        printf("\n");
    }

    void increaseCapacity() {
        capacity *= 2;
        heap = (HeapNode*)realloc(heap, sizeof(HeapNode) * capacity);
    }
    void decreaseCapacity() {
        capacity /= 2;
        heap = (HeapNode*)realloc(heap, sizeof(HeapNode) * capacity);
    }
    
    int getParent(int child) {
        return (int) ((child - 1) / 2);
    }
    int getLeftChild(int parent) {
        return (parent * 2) + 1;
    }
    int getUsedSize() {
        return usedSize;
    }
private:
    int usedSize;
    int capacity;
    HeapNode* heap;
};


#endif /* _PRIORITY_QUEUE_H_ */