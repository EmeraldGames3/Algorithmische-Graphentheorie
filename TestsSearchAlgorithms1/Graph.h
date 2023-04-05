#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <deque>

using std::vector, std::string;

class Graph{
private:
    int nodes{};
    vector<vector<int>> adjacencyList;

public:
    //Default constructor
    Graph();

    //Constructor with 1 parameter
    explicit Graph(const string &fileName);

    //Copy constructor
    Graph(const Graph &other);

    //Print the graph on the screen
    void printGraph();

    //BFS algorithm
    void BFS(int start);
};