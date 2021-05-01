#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
    Graph graph;
    Vertex* v1 = new Vertex(1);
    Vertex* v2 = new Vertex(2);
    Vertex* v3 = new Vertex(3);
    Vertex* v4 = new Vertex(4);
    Vertex* v5 = new Vertex(5);

    graph.addVertex(v1);
    graph.addVertex(v2);
    graph.addVertex(v3);
    graph.addVertex(v4);
    graph.addVertex(v5);

    v1->addEdge(new Edge(v2, 0));
    v1->addEdge(new Edge(v3, 0));
    v1->addEdge(new Edge(v4, 0));
    v1->addEdge(new Edge(v5, 0));

    v2->addEdge(new Edge(v1, 0));
    v2->addEdge(new Edge(v3, 0));
    v2->addEdge(new Edge(v5, 0));

    v3->addEdge(new Edge(v1, 0));
    v3->addEdge(new Edge(v2, 0));

    v4->addEdge(new Edge(v1, 0));
    v4->addEdge(new Edge(v5, 0));

    v5->addEdge(new Edge(v1, 0));
    v5->addEdge(new Edge(v2, 0));
    v5->addEdge(new Edge(v4, 0));

    graph.printGraph();

    return 0;
}