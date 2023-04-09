#include <iostream>
#include "Graph.h"

int main() {
    Graph graph("input.txt");
    graph.printGraph();

    graph.BFS(1);
    graph.BFS(4);

    std::cout << "\n";

    graph.printConexComponent();
    return 0;
}
