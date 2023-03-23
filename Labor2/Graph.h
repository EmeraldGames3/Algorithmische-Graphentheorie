#include <vector>
#include <string>

class Graph {
private:
    int n{};
    int m{};
    int matrix[100][100]{};
    std::vector<std::vector<int>> adjacencyList{};
    std::vector<std::pair<int, int>> kantenList{};

public:
    Graph();

    explicit Graph(const std::string& fileName);

    explicit Graph(const std::vector<std::pair<int, int>>& _kantenList, int _n);

    Graph(Graph &graph);

    Graph komplement();

    void addEdge(int x, int y);

    bool isEdge(int x, int y);

    [[nodiscard]] bool isEmptyGraph() const;

    void printGraphMatrix();

    void printGraphAdjacencyList();

    void printKantenList();

    void printGraphAndKomplement();

    void makeAdjacencyList();

    int maxDegree();

    int minDegree();
};