#pragma once
#include <string>
#include <vector>

using namespace std;

class Graph{
private:
    int m;
    int n;
    vector<vector<bool>> matrix;

public:
    explicit Graph(const string &fileName);

    void printGraph();

    void isBipartite();
};