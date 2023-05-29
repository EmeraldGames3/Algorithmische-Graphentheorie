#include <iostream>
#include "Graph.h"

int main() {
    Graph graph("Land2.txt");
    graph.printGraph();

    graph.isBipartite();
    return 0;
}