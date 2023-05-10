#include "Graph.h"

#include <fstream>
#include <iostream>
#include <limits>

Graph::Graph(const string &fileName) {
    std::ifstream fin(fileName);
    string line;
    Edge e;

    std::set<string> s;
    while (fin >> e.city1 >> e.city2 >> e.weight){
        edgeList.push_back(e);
        s.insert(e.city1);
        s.insert(e.city2);
    }
    fin.close();
    nodes = static_cast<int>(s.size());
    edges = static_cast<int>(edgeList.size());
}

void Graph::printGraph() const {
    std::cout << nodes << '\n';
    std::cout << edges << '\n';
    for (const auto &edge: edgeList)
        std::cout << edge.city1 << " " << edge.city2 << " " << edge.weight << '\n';
}

//Djikstra
/*
void Graph::shortestPath(const string& city1, const string& city2) {
    // Create a set to store visited nodes
    std::set<string> visitedNodes;

    // Create a map to store the shortest distance from the starting city
    std::map<string, int> shortestDistance;

    // Create a map to store the previous city in the shortest path
    std::map<string, string> previousCity;

    // Initialize the distances and previous city for all cities
    for (const auto& edge : edgeList) {
        shortestDistance[edge.city1] = INT16_MAX;
        shortestDistance[edge.city2] = INT16_MAX;
        previousCity[edge.city1] = "";
        previousCity[edge.city2] = "";
    }

    // Set the distance of the starting city to 0
    shortestDistance[city1] = 0;

    // Loop until all cities have been visited
    while (visitedNodes.size() < nodes) {
        // Find the city with the minimum distance that hasn't been visited
        string currentCity;
        int minDistance = INT16_MAX;
        for (const auto& distance : shortestDistance) {
            if (visitedNodes.find(distance.first) == visitedNodes.end() && distance.second < minDistance) {
                minDistance = distance.second;
                currentCity = distance.first;
            }
        }

        // Mark the current city as visited
        visitedNodes.insert(currentCity);

        // Update the distances of the neighboring cities
        for (const auto& edge : edgeList) {
            if (edge.city1 == currentCity) {
                int newDistance = shortestDistance[currentCity] + edge.weight;
                if (newDistance < shortestDistance[edge.city2]) {
                    shortestDistance[edge.city2] = newDistance;
                    previousCity[edge.city2] = currentCity;
                }
            }
            else if (edge.city2 == currentCity) {
                int newDistance = shortestDistance[currentCity] + edge.weight;
                if (newDistance < shortestDistance[edge.city1]) {
                    shortestDistance[edge.city1] = newDistance;
                    previousCity[edge.city1] = currentCity;
                }
            }
        }
    }

    // Check if a path exists between the two cities
    if (previousCity[city2].empty()) {
        std::cout << "No path exists between " << city1 << " and " << city2 << std::endl;
        return;
    }

    // Backtrack from the destination city to the starting city to find the shortest path
    std::deque<string> path;
    string currentCity = city2;
    while (!currentCity.empty()) {
        path.push_front(currentCity);
        currentCity = previousCity[currentCity];
    }

    // Print the shortest path
    std::cout << "Shortest path from " << city1 << " to " << city2 << ": ";
    for (const auto &city : path) {
        std::cout << city << " ";
    }
    std::cout << '\n';
}*/

//Bellman-Ford //TODO: not working
void Graph::shortestPath(const string& source, const string& destination) {
    const int INF = std::numeric_limits<int>::max();
    vector<int> distance(nodes, INF);
    vector<int> predecessor(nodes, -1);

    int sourceIndex = stoi(source);
    distance[sourceIndex] = 0;

    // Relax edges repeatedly |V| - 1 times
    for (int i = 0; i < nodes - 1; ++i) {
        for (const auto& edge : edgeList) {
            int u = stoi(edge.city1);
            int v = stoi(edge.city2);
            int weight = edge.weight;
            if (distance[u] != INF && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                predecessor[v] = u;
            }
        }
    }

    // Check for negative-weight cycles
    for (const auto& edge : edgeList) {
        int u = stoi(edge.city1);
        int v = stoi(edge.city2);
        int weight = edge.weight;
        if (distance[u] != INF && distance[u] + weight < distance[v]) {
            std::cout << "Graph contains a negative-weight cycle\n";
            return;
        }
    }

    // Print the shortest path
    int destinationIndex = stoi(destination);
    if (distance[destinationIndex] == INF) {
        std::cout << "There is no path from " << source << " to " << destination << "\n";
        return;
    }

    std::cout << "Shortest path from " << source << " to " << destination << ":\n";
    std::cout << source << " ";
    int current = destinationIndex;
    while (current != sourceIndex) {
        std::cout << predecessor[current] << " ";
        current = predecessor[current];
    }
    std::cout << "\n";
    std::cout << "Weight: " << distance[destinationIndex] << "\n";
}