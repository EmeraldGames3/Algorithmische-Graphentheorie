#include <iostream>

#include "Graph.h"

int main() {
    Graph graph("Graph.txt");
    graph.printGraph();

    graph.shortestPath("Sibiu", "Arad");
}
