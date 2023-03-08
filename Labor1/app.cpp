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
    cout << "Max : " << g.maxDegree() << " Min: " << g.minDegree() << endl;

    cout << endl;
    GraphAdj g2;
    g2.printGraph();
    cout << "Max : " << g2.maxDegree() << " Min: " << g2.minDegree() << endl;
}