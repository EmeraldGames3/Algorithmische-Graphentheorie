#pragma once

#include <string>
#include <utility>

using std::string;

struct Edge {
    string city1;
    string city2;
    int weight;

    //Default constructor
    Edge() : weight{0} {}

    //Constructor with 2 parameters
    Edge(string _city1, string _city2, int _weight) : city1{std::move(_city1)},
                                                      city2{std::move(_city2)},
                                                      weight{_weight} {}
};

struct Node {
    Edge edge;
    Node *next;

    //Default constructor
    Node() : edge{Edge()}, next{nullptr} {}

    //Constructor with 1 parameter
    explicit Node(Edge _edge) : edge{std::move(_edge)}, next{nullptr} {}
};

class Graph {
private:
    Node *head;
    int nodes;
    int edges;

public:
    //Constructor with 1 parameter
    explicit Graph(const string &fileName);

    //Destructor
    ~Graph();

    //Print the Graph
    void printGraph() const;

    //Find the shortest path using Dijkstra
    void shortestPath(const string &city1, const string &city2);
};