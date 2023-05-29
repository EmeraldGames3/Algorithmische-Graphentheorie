#include "Graph.h"
#include <iostream>
#include <deque>
#include <set>

Graph::Graph(const string &fileName) {
    nodes = 0;
    vertices = 0;
    matrix = vector<vector<int>>();
    cities = vector<string>();

    ifstream file(fileName);

    if (!file.is_open()) {
        throw invalid_argument("File not found");
    }

    string city1;
    string city2;
    int value;
    while (file >> city1 >> city2 >> value) {
        vertices++;

        bool city1Exists = false;
        bool city2Exists = false;
        int indexCity1 = 0;
        int indexCity2 = 0;

        for (int i = 0; i < cities.size(); i++) {
            if (cities[i] == city1) {
                city1Exists = true;
                indexCity1 = i;
            }
            if (cities[i] == city2) {
                city2Exists = true;
                indexCity2 = i;
            }
        }

        if (!city2Exists) {
            indexCity2 = static_cast<int>(cities.size());
            cities.push_back(city2);
        }

        if (!city1Exists) {
            indexCity1 = static_cast<int>(cities.size());
            cities.push_back(city1);
        }

        // Resize the matrix if necessary
        if (indexCity1 >= matrix.size() || indexCity2 >= matrix.size()) {
            int newSize = std::max(indexCity2, indexCity1) + 1;
            matrix.resize(newSize, std::vector<int>(newSize, 0));
        }

        matrix[indexCity1][indexCity2] = value;
        matrix[indexCity2][indexCity1] = value;
    }
    nodes = static_cast<int>(cities.size());

    file.close();
}

void Graph::printGraph() {
    cout << "\t";
    for (const auto &it: cities) {
        cout << it << ' ';
    }

    cout << '\n';

    for (int i = 0; i < matrix.size(); i++) {
        cout << cities[i] << ' ';
        for (int j = 0; j < matrix.size(); j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
}

void Graph::isBipartite() {
    // Create two sets to represent the two partitions
    std::set<int> partitionEven; // Nodes with even distances
    std::set<int> partitionOdd;  // Nodes with odd distances

    // Perform breadth-first search (BFS) from an arbitrary starting node
    int startNode = 0; // Choose the starting node as desired
    std::deque<int> queue;
    std::vector<int> distance(nodes, -1); // Initialize distances to -1 (unvisited)

    queue.push_back(startNode);
    distance[startNode] = 0;
    partitionEven.insert(startNode); // Add the starting node to the even distance set

    while (!queue.empty()) {
        int current = queue.front();
        queue.pop_front();

        // Traverse the neighbors of the current node
        for (int neighbor = 0; neighbor < nodes; ++neighbor) {
            if (matrix[current][neighbor] != 0 && distance[neighbor] == -1) {
                distance[neighbor] = distance[current] + 1;
                queue.push_back(neighbor);

                // Assign the neighbor to the appropriate partition based on the distance parity
                if (distance[neighbor] % 2 == 0) {
                    partitionEven.insert(neighbor);
                } else {
                    partitionOdd.insert(neighbor);
                }
            }
        }
    }

    // Check if any edge violates the bipartite property
    for (int u = 0; u < nodes; ++u) {
        for (int v = 0; v < nodes; ++v) {
            if (matrix[u][v] != 0 && ((partitionOdd.count(u) && partitionOdd.count(v)) ||
                                      (partitionEven.count(u) && partitionEven.count(v)))) {
                std::cout << "Error: G is not bipartite." << std::endl;
                return;
            }
        }
    }

    // The graph is bipartite. Output the two partitions.
    std::cout << "Node partition V = partitionEven U partitionOdd: ";
    std::cout << "partitionEven = { ";
    for (const auto &node: partitionEven) {
        std::cout << cities[node] << " ";
    }
    std::cout << "} \npartitionOdd = { ";
    for (const auto &node: partitionOdd) {
        std::cout << cities[node] << " ";
    }
    std::cout << "}" << std::endl;
}