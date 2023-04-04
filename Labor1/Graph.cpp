#include "Graph.h"
#include <fstream>
#include <iostream>

using namespace std;

Graph::Graph() {
    ifstream f;
    f.open("data.in");
    f >> n;
    f >> m;
    int x, y;
    for (int i = 0; i < m; i++) {
        f >> x >> y;
        addEdge(x, y);
    }

    makeList();
}

void Graph::addEdge(int x, int y) {
    matrix[x][y] = 1;
    matrix[y][x] = 1;
}

bool Graph::isEdge(int x, int y) {
    return matrix[x][y] == 1;
}

void Graph::printGraph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void Graph::printList() {
    for (int i = 0; i < adjacencyList.size(); i++) {
        cout << i << ": ";
        for (int j: adjacencyList[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void Graph::makeList() {
    adjacencyList.resize(n);
    for (int i = 0; i < n / 2 + 1; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1 && j > i) {
                adjacencyList[i].push_back(j);
            }
        }
    }
}

int Graph::maxDegree() {
    int max = 0;
    for (int i = 0; i < adjacencyList.size(); i++) {
        if (adjacencyList[i].size() > max)
            max = adjacencyList[i].size();
    }

    return max;
}

int Graph::minDegree() {
    int min = INT16_MAX;

    for (int i = 0; i < adjacencyList.size(); i++) {
        if (adjacencyList[i].size() < min)
            min = adjacencyList[i].size();
    }

    return min;
}