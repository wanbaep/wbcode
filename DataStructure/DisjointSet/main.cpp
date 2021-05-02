#include <iostream>
#include "DisjointSet.h"

using namespace std;

int main() {
    DisjointSet disjointSet;
    Node* set1 = new Node(1);
    Node* set2 = new Node(2);
    Node* set3 = new Node(3);
    Node* set4 = new Node(4);

    printf("set1 == set2 : %d\n", disjointSet.findSet(set1) == disjointSet.findSet(set2));

    disjointSet.unionSet(set1, set3);
    printf("set1 == set3 : %d\n", disjointSet.findSet(set1) == disjointSet.findSet(set3));
    disjointSet.unionSet(set3, set4);
    printf("set3 == set4 : %d\n", disjointSet.findSet(set3) == disjointSet.findSet(set4));

    return 0;
}