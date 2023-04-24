
#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <deque>

using std::vector, std::string;

class Graph{
private:
    int nodes{};
    int edges{};
    vector<vector<int>> adjacencyList;

public:
    //Default constructor
    Graph();

    //Constructor with 1 parameter
    explicit Graph(int edges);

    //Copy constructor
    Graph(const Graph &other);

    void addEdge(int u, int v);

    vector<int> getNeighbors(int v);

    int getNumVertices();

    //Print the graph on the screen
    void text();

    //BFS algorithm
    void BFS(int start);

    //Find the way between two nodes
    int weg(int start, int stop);
};