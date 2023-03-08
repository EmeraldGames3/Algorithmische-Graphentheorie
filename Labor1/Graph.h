#include <vector>

class Graph {
private:

    int n{};
    int m{};
    int matrix[100][100]{};
    std::vector<std::vector<int>> adjacencyList;

public:

    Graph();

    void addEdge(int x, int y);

    bool isEdge(int x, int y);

    void printGraph();

    void printList();

    void makeList();

    int maxDegree();

    int minDegree();
};