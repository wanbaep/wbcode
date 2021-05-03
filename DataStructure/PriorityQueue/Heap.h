#ifndef _HEAP_H_
#define _HEAP_H_

#include <stdio.h>
#include <string>

typedef struct {
    int data;
} HeapNode;

class Heap
{
public:
    Heap(int size) {
        usedSize = 0;
        capacity = size;
        // heap = new HeapNode[capacity];
        heap = (HeapNode*) malloc(capacity * sizeof(HeapNode));
    };
    ~Heap() {
        free(heap);
    };

    void insert(int newData) {
        int currentPosition = usedSize;
        int parentPosition = getParent(currentPosition);

        if(usedSize == capacity) {
            increaseCapacity();
        }
        heap[currentPosition].data = newData;

        while(currentPosition > 0 && heap[currentPosition].data < heap[parentPosition].data) {
            //swap
            HeapNode tmp = heap[currentPosition];
            heap[currentPosition] = heap[parentPosition];
            heap[parentPosition] = tmp;
            currentPosition = parentPosition;
            parentPosition = getParent(currentPosition);
        }
        ++usedSize;
    }

    void deleteMin() {
        int parentPosition = 0;
        int leftPosition = 0;
        int rightPosition = 0;
        HeapNode root = heap[parentPosition];

        --usedSize;
        heap[0] = heap[usedSize];

        while( 1 ) {
            int selectedChild = 0;
            leftPosition = getLeftChild(parentPosition);
            rightPosition = leftPosition + 1;

            if(leftPosition >= usedSize) break;
            if(rightPosition >= usedSize) {
                selectedChild = leftPosition;
            }
            else {
                if(heap[leftPosition].data < heap[rightPosition].data) {
                    selectedChild = leftPosition;
                } else {
                    selectedChild = rightPosition;
                }
            }

            if(heap[selectedChild].data < heap[parentPosition].data) {
                HeapNode tmp = heap[parentPosition];
                heap[parentPosition] = heap[selectedChild];
                heap[selectedChild] = tmp;
                parentPosition = selectedChild;
            } else {
                break;
            }

            if(usedSize < (capacity/2)) {
                //decreaseCapacity
                decreaseCapacity();
            }
        }
    }

    int getParent(int child) {
        return (int) ((child - 1) /2);
    }
    int getLeftChild(int index) {
        return (2 * index) + 1;
    }
    void printNodes() {
        for(int i = 0; i < usedSize; ++i) {
            printf("%d ", heap[i].data);
        }
        printf("\n");
    }
private:
    void decreaseCapacity() {
        // HeapNode* temporalHeap = heap;
        // heap = new HeapNode[capacity / 2];
        // //copy memory
        // for(int i = 0; i < usedSize; ++i) {
        //     heap[i].data = temporalHeap[i].data;
        // }
        capacity /= 2;
        // delete [] temporalHeap;
        heap = (HeapNode*) realloc(heap, capacity * sizeof(HeapNode));
    }

    void increaseCapacity() {
        // HeapNode* temporalHeap = heap;
        // heap = new HeapNode[capacity * 2];
        // //copy memory
        // for(int i = 0; i < usedSize; ++i) {
        //     heap[i].data = temporalHeap[i].data;
        // }
        capacity *= 2;
        heap = (HeapNode*) realloc(heap, capacity * sizeof(HeapNode));
        // delete [] temporalHeap;
    }

    HeapNode* heap;
    int capacity;
    int usedSize;
};

#endif /* _HEAP_H_ */