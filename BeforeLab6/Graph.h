#pragma once

#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Graph{
private:
    int vertices;
    int nodes;

    vector<vector<int>> matrix;
    vector<string> cities;

public:
    explicit Graph(const string &fileName);

    void printGraph();

    void isBipartite();
};