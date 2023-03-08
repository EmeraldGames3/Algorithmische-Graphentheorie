#include "Graph.h"
#include "GraphAdjazenztlist.h"
#include<iostream>

using namespace std;

int main() {

    Graph g;
    cout << g.isEdge(0, 1) << endl;

    cout << endl;
    g.printGraph();

    cout << endl;
    g.printList();

    cout << endl;
    cout << "Max : " << g.maxDegree() << " Min: " << g.minDegree() << endl;

    cout << endl;
    GraphAdj g2;
    g2.printGraph();
}