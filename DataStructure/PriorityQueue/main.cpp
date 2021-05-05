#include <iostream>
// #include "Heap.h"
#include "PriorityQueue.h"

using namespace std;
void printJob(HeapNode node) {
    printf("{priority: %d} %s \n", node.priority, (char*)node.data);
}
int main() {
    PriorityQueue queue(3);
    
    HeapNode nodes[7] = {
        {34, (void*)"코딩"},
        {12, (void*)"고객미팅"},
        {87, (void*)"커피타기"},
        {45, (void*)"문서작성"},
        {35, (void*)"디버깅"},
        {66, (void*)"이닦기"}
    };

    for(int i = 0; i < 6; ++i) {
        queue.enqueue(nodes[i]);
    }
    queue.printNodes();
    printf("Left jobs in queue: %d\n", queue.getUsedSize());
    
    HeapNode popped;
    while(!queue.isEmpty()) {
        popped = queue.dequeue();
        printJob(popped);
    }
    return 0;
}