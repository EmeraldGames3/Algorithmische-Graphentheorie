#include <iostream>
#include "Graph.h"

int main() {
    Graph graph("input.txt");
    graph.printGraph();
    graph.isBipartite();
}
