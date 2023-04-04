#include "GraphAdj.h"

GraphAdj::GraphAdj(const Graph &graph): nodes(graph.n), edges(graph.m) {
    adjacencyList.resize(nodes);
    for (int i = 0; i < nodes / 2 + 1; i++) {
        for (int j = 0; j < nodes; j++) {
            if (graph.matrix[i][j] == 1 && j > i) {
                adjacencyList[i].push_back(j);
            }
        }
    }
}

int GraphAdj::maxDegree() {
    int max = 0;
    for (int i = 0; i < adjacencyList.size(); i++) {
        if (adjacencyList[i].size() > max)
            max = adjacencyList[i].size();
    }

    return max;
}

int GraphAdj::minDegree() {
    int min = 0;

    for (const auto & i : adjacencyList) {
        if (i.size() < min)
            min = i.size();
    }

    return min;
}
