#include "Graph.h"
#include <iostream>
#include <cassert>

int main() {
    Graph g1{};
    assert(g1.isEmptyGraph());

    Graph g2(g1);
    assert(g2.isEmptyGraph());

    std::string fileName = "data.in";

    Graph g3(fileName);
    assert(!g3.isEmptyGraph());
    g3.printKantenList();
    std::cout << '\n';

    Graph g4(g3);
    assert(!g4.isEmptyGraph());
    g3.printKantenList();
    std::cout << '\n';

    g3.printGraphAndKomplement();
}