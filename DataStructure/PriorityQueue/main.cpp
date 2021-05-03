#include <iostream>
#include "Heap.h"

using namespace std;

int main() {
    Heap h(3);
    h.insert(12);
    h.insert(87);
    h.insert(111);
    h.insert(34);
    h.insert(16);
    h.insert(75);

    h.printNodes();

    for(int i = 0; i < 6; ++i) {
        h.deleteMin();
        h.printNodes();
    }
    
    return 0;
}