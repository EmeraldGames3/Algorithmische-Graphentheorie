#include "Graph.h"
#include <fstream>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <deque>

Graph::Graph(const string &fileName) {
    edges = 0;
    head = nullptr;

    Node *current = head;

    std::ifstream fin(fileName);
    string line;
    Edge e;

    std::set<string> s;

    while (fin >> e.city1 >> e.city2 >> e.weight) {
        edges++;
        Node *newNode = new Node(e);

        s.insert(e.city1);
        s.insert(e.city2);

        if (current == nullptr) {
            head = newNode;
            current = newNode;
            continue;
        }

        current->next = newNode;
        current = newNode;
    }

    nodes = static_cast<int>(s.size());
}

void Graph::printGraph() const {
    std::cout << nodes << ' ' << edges << '\n';
    Node *currentNode = head;
    while (currentNode != nullptr) {
        Node *nextNode = currentNode->next;

        std::cout << currentNode->edge.city1 << ' '
                  << currentNode->edge.city2 << ' '
                  << currentNode->edge.weight << '\n';

        currentNode = nextNode;
    }
}

Graph::~Graph() {
    Node *currentNode = head;
    while (currentNode != nullptr) {
        Node *nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
    head = nullptr;
}

using std::set, std::map, std::cout, std::deque;

//void Graph::shortestPath(const std::string &city1, const std::string &city2) {
//    std::set<std::string> visitedNodes;
//    std::map<std::string, int> shortestDistance;
//    std::map<std::string, std::string> previousCity;
//
//    // Initialize the distances and previous city for all cities
//    Node* currentNode = head;
//    while (currentNode != nullptr) {
//        const Edge& edge = currentNode->edge;
//        shortestDistance[edge.city1] = INT32_MAX;
//        shortestDistance[edge.city2] = INT32_MAX;
//        previousCity[edge.city1] = "";
//        previousCity[edge.city2] = "";
//        currentNode = currentNode->next;
//    }
//
//    shortestDistance[city1] = 0;
//
//    // Enqueue the first node as the one that needs to be visited
//    std::deque<std::string> nodesToVisit;
//    nodesToVisit.push_back(city1);
//
//    while (!nodesToVisit.empty()) {
//        std::string currentCity = nodesToVisit.front();
//        nodesToVisit.pop_front();
//
//        // Update the distances of the neighboring cities
//        currentNode = head;
//        while (currentNode != nullptr) {
//            const Edge& edge = currentNode->edge;
//            if (edge.city1 == currentCity) {
//                int newDistance = shortestDistance[currentCity] + edge.weight;
//                if (newDistance < shortestDistance[edge.city2]) {
//                    shortestDistance[edge.city2] = newDistance;
//                    previousCity[edge.city2] = currentCity;
//                }
//            } else if (edge.city2 == currentCity) {
//                int newDistance = shortestDistance[currentCity] + edge.weight;
//                if (newDistance < shortestDistance[edge.city1]) {
//                    shortestDistance[edge.city1] = newDistance;
//                    previousCity[edge.city1] = currentCity;
//                }
//            }
//            currentNode = currentNode->next;
//
//            // Enqueue neighboring city if not visited
//            if (visitedNodes.find(edge.city2) == visitedNodes.end()) {
//                nodesToVisit.push_back(edge.city2);
//            }
//        }
//
//        // Mark the current city as visited
//        visitedNodes.insert(currentCity);
//    }
//
//    // Check if a path exists between the two cities
//    if (previousCity[city2].empty()) {
//        std::cout << "No path exists between " << city1 << " and " << city2 << std::endl;
//        return;
//    }
//
//    // Backtrack from the destination city to the starting city to find the shortest path
//    std::deque<std::string> path;
//    std::string currentCity = city2;
//    while (!currentCity.empty()) {
//        path.push_front(currentCity);
//        currentCity = previousCity[currentCity];
//    }
//
//    // Print the shortest path
//    std::cout << "Shortest path from " << city1 << " to " << city2 << ": ";
//    for (const auto& city : path) {
//        std::cout << city << " ";
//    }
//    std::cout << '\n';
//}

void Graph::shortestPath(const string &city1, const string &city2) {
    // Create a set to store visited nodes
    std::set<string> visitedNodes;

    // Create a map to store the shortest distance from the starting city
    std::map<string, int> shortestDistance;

    // Create a map to store the previous city in the shortest path
    std::map<string, string> previousCity;

    // Initialize the distances and previous city for all cities
    Node *currentNode = head;
    while (currentNode != nullptr) {
        Edge edge = currentNode->edge;
        shortestDistance[edge.city1] = INT32_MAX;
        shortestDistance[edge.city2] = INT32_MAX;
        previousCity[edge.city1] = "";
        previousCity[edge.city2] = "";
        currentNode = currentNode->next;
    }

    // Set the distance of the starting city to 0
    shortestDistance[city1] = 0;

    // Loop until all cities have been visited
    while (visitedNodes.size() < nodes) {
        // Find the city with the minimum distance that hasn't been visited
        string currentCity;
        int minDistance = INT32_MAX;
        for (const auto &distance: shortestDistance) {
            if (visitedNodes.find(distance.first) == visitedNodes.end() && distance.second < minDistance) {
                minDistance = distance.second;
                currentCity = distance.first;
            }
        }

        // Mark the current city as visited
        visitedNodes.insert(currentCity);

        // Update the distances of the neighboring cities
        currentNode = head;
        while (currentNode != nullptr) {
            const Edge &edge = currentNode->edge;
            if (edge.city1 == currentCity) {
                int newDistance = shortestDistance[currentCity] + edge.weight;
                if (newDistance < shortestDistance[edge.city2]) {
                    shortestDistance[edge.city2] = newDistance;
                    previousCity[edge.city2] = currentCity;
                }
            } else if (edge.city2 == currentCity) {
                int newDistance = shortestDistance[currentCity] + edge.weight;
                if (newDistance < shortestDistance[edge.city1]) {
                    shortestDistance[edge.city1] = newDistance;
                    previousCity[edge.city1] = currentCity;
                }
            }
            currentNode = currentNode->next;
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
    for (const auto &city: path) {
        std::cout << city << " ";
    }
    std::cout << '\n';
}