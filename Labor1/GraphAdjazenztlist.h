#include <vector>

class GraphAdj{
private:

    int n{};
    int m{};
    std::vector<std::vector<int>> adjacencyList;

public:

    GraphAdj();

    void printGraph();

    int maxDegree();

    int minDegree();
};
