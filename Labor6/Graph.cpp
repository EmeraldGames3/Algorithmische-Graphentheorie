#include "Graph.h"
#include <fstream>
#include <iostream>
#include <deque>
#include <set>

Graph::Graph(const string &fileName) {
    ifstream file(fileName);

    if (!file.is_open()) {
        throw invalid_argument("Cannot open file");
    }

    m = 0;
    n = 0;
    matrix = vector<vector<bool>>();

    file >> n >> m;
    matrix.resize(n);
    for (int i = 0; i < n; i++) {
        matrix[i].resize(n);
    }

    int node1, node2;
    while (file >> node1 >> node2) {
        matrix[node1][node2] = true;
        matrix[node2][node1] = true;
    }
}

void Graph::printGraph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
}

void Graph::isBipartite() {
    set<int> partition1;
    set<int> partition2;

    //BFS
    int startNode = 0;
    deque<int> queue;
    vector<int> distance(n, -1);

    queue.push_back(startNode);
    distance[startNode] = 0;
    partition1.insert(startNode);

    while (!queue.empty()) {
        int current = queue.front();
        queue.pop_back();

        for (int neighbor = 0; neighbor < n; neighbor++) {
            if (matrix[current][neighbor] && distance[neighbor] == -1) {
                distance[neighbor] = distance[current] + 1;
                queue.push_back(neighbor);

                //Partition the nodes
                if (distance[neighbor] % 2 == 0) {
                    partition1.insert(neighbor);
                } else {
                    partition2.insert(neighbor);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] && (
                    partition1.contains(i) && partition1.contains(j) ||
                    partition2.contains(i) && partition2.contains(j))) {
                cout << "Graph is not bipartite\n";
                return;
            }
        }
    }

    cout << "Partition1: ";
    for (auto it: partition1) {
        cout << to_string(it) << ' ';
    }
    cout << '\n';

    cout << "Partition2: ";
    for (auto it: partition2) {
        cout << to_string(it) << ' ';
    }
    cout << '\n';
}