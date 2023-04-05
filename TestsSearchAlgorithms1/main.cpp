#include <iostream>
#include "Graph.h"

int main() {
    Graph g = Graph();
    g.printGraph();

    Graph graph("input.txt");
    graph.printGraph();

    graph.BFS(0);
}
