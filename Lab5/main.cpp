#include <iostream>

#include "Graph.h"

int main() {
    Graph graph("cities.txt");
//    graph.printGraph();

    graph.shortestPath("Tacoma", "SaltLakeCity");
    graph.shortestPath("Savannah", "Sacramento");
}