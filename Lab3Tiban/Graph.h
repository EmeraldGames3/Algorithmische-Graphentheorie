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
    int adjacencyMatrix[100][100]{};

public:
    Graph();

    //Constructor with 1 parameter
    explicit Graph(const string &fileName);

    //BFS algorithm
    void BFS(int start);

    void printGraph();

    void printConexComponent();
};