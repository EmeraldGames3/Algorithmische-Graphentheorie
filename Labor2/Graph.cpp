#include "Graph.h"
#include <fstream>
#include <iostream>

using namespace std;

Graph::Graph() {
    n = 0;
    m = 0;
}

//make kantenListe
Graph::Graph(const std::string &fileName) {
    ifstream f;
    f.open(fileName);
    f >> n;
    f >> m;

    int x, y;
    for (int i = 0; i < m; i++) {
        f >> x >> y;
        kantenList.push_back(pair(x, y));
        addEdge(x, y);
    }
    makeAdjacencyList();
}

//Copy constructor
Graph::Graph(Graph &graph) {
    this->n = graph.n;
    this->m = graph.m;
    this->kantenList = graph.kantenList;

    for (int i = 0; i < this->n; i++) {
        for (int j = 0; j < this->n; j++) {
            this->matrix[i][j] = graph.matrix[i][j];
        }
    }
    this->adjacencyList = graph.adjacencyList;
}

//Constructor with Kantenliste as parameter
Graph::Graph(const std::vector<std::pair<int, int>> &_kantenList, int _n) {
    this->n = _n;
    this->m = kantenList.size();
    this->kantenList = _kantenList;

    int max = 0;

    for (int i = 0; i < kantenList.size(); i++) {
        if (max < kantenList[i].first)
            max = kantenList[i].first;
        if (max < kantenList[i].second)
            max = kantenList[i].second;

        addEdge(kantenList[i].first, kantenList[i].second);
    }
    n = max;

    makeAdjacencyList();
}

void Graph::addEdge(int x, int y) {
    matrix[x][y] = 1;
    matrix[y][x] = 1;
}

bool Graph::isEdge(int x, int y) {
    return matrix[x][y] == 1;
}

void Graph::printGraphMatrix() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void Graph::printGraphAdjacencyList() {
    for (int i = 0; i < adjacencyList.size(); i++) {
        cout << i << ": ";
        for (int j: adjacencyList[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void Graph::makeAdjacencyList() {
    adjacencyList.resize(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                adjacencyList[i].push_back(j);
            }
        }
    }
}

int Graph::maxDegree() {
    int max = 0;
    for (int i = 0; i < adjacencyList.size(); i++) {
        if (adjacencyList[i].size() > max)
            max = adjacencyList[i].size();
    }
    return max;
}

int Graph::minDegree() {
    int min = INT16_MAX;
    for (int i = 0; i < adjacencyList.size(); i++) {
        if (adjacencyList[i].size() < min)
            min = adjacencyList[i].size();
    }
    return min;
}

void Graph::printKantenList() {
    for (int i = 0; i < kantenList.size(); i++) {
        cout << kantenList[i].first << ' ' << kantenList[i].second << "\n";
    }
}

Graph Graph::komplement() {
    std::vector<pair<int, int>> newKantenList{}; // empty vector

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            if (!isEdge(i, j))
                newKantenList.push_back(pair(i, j));
        }
    }

    return Graph(newKantenList, this->n);
}

void Graph::printGraphAndKomplement() {
    cout << "Graph:\n";
    this->printKantenList();
    cout << "\nKomplement:\n";
    this->komplement().printKantenList();
}

bool Graph::isEmptyGraph() const {
    return n == 0 && m == 0;
}
