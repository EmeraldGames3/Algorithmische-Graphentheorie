#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <set>
#include <deque>
#include <map>

using std::vector, std::string;

struct Edge{
    string city1;
    string city2;
    int weight;
};

class Graph{
protected:
    int nodes{};
    int edges{};
    vector<Edge> edgeList{};

public:
    //Constructor with 1 parameter
    explicit Graph(const string &fileName);

    //Copy constructor
    Graph(const Graph &other) = default;

    //Destructor
    ~Graph() = default;

    //Print the Graph
    void printGraph() const;

    void shortestPath(const string& city1, const string& city2);
};