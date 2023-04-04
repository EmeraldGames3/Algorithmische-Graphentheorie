#pragma once
#include <vector>
#include "Graph.h"

class GraphAdj{
private:
    int nodes;
    int edges;
    std::vector<std::vector<int>> adjacencyList;

public:
    explicit GraphAdj(const Graph &graph);

    int maxDegree();

    int minDegree();

};