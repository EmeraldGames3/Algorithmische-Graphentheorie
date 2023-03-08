#include "GraphAdjazenztlist.h"
#include <fstream>
#include <iostream>

using namespace std;

GraphAdj::GraphAdj() {
    ifstream f;
    f.open("data.in");
    f >> n;
    f >> m;

    adjacencyList.resize(n);

    int x, y;
    for (int i = 0; i < m; i++) {
        f >> x >> y;
        adjacencyList[x].push_back(y);
        adjacencyList[y].push_back(x);
    }
}

void GraphAdj::printGraph() {
    for (int i = 0; i < adjacencyList.size(); i++) {
        cout << i << ": ";
        for (int j: adjacencyList[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int GraphAdj::maxDegree() {
    int max = 0;

    for (int i = 0; i < adjacencyList.size(); i++) {
        if (adjacencyList[i].size() > max)
            max = adjacencyList[i].size();
    }

    return max;
}

int GraphAdj::minDegree() {
    int min = INT16_MAX;

    for (int i = 0; i < adjacencyList.size(); i++) {
        if (adjacencyList[i].size() < min)
            min = adjacencyList[i].size();
    }

    return min;
}

