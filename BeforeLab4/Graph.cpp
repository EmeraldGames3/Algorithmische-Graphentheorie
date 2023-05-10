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
    for (const auto& city : path) {
        std::cout << city << " ";
    }
    std::cout << std::endl;
}