#include "Graph.h"

Graph::Graph() : nodes(0) , edges(0){}

Graph::Graph(int _nodes) {
    nodes = _nodes;
    edges = 0;
    adjacencyList.resize(_nodes);
}

Graph::Graph(const Graph &other) : nodes(other.nodes), edges(other.edges) {
    adjacencyList = other.adjacencyList;
}

void Graph::text() {
    if(nodes == 0){
        std::cout << "Empty Graph\n";
        return;
    }

    for (int i = 0; i < nodes; i++) {
        std::cout << i << ": ";
        for (auto element : adjacencyList[i])
            std::cout << element << " ";
        std::cout << "\n";
    }
}

void Graph::BFS(int start) {
    std::vector<bool> visited(nodes, false);
    std::deque<int> q;
    q.push_back(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop_front();
        std::cout << current << " ";

        for (int neighbor : adjacencyList[current]) {
            if (!visited[neighbor]) {
                q.push_back(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    std::cout << std::endl;
}

int Graph::weg(int start, int stop) {
    std::vector<bool> visited(nodes, false);
    std::vector<int> length(nodes, INT16_MAX);
    std::deque<int> q;
    q.push_back(start);
    visited[start] = true;
    length[start] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop_front();

        if(current == stop)
            return length[current];

        for (auto neighbor : adjacencyList[current]) {
            if (!visited[neighbor]) {
                q.push_back(neighbor);
                length[neighbor] = length[current] + 1;
                visited[neighbor] = true;
            }
        }
    }
    std::cout << std::endl;

    std::cout << "No path from " << start << " to " << stop << "\n";
    return -1;
}

int Graph::getNumVertices() {
    return edges;
}

vector<int> Graph::getNeighbors(int v) {
    return adjacencyList[v];
}

void Graph::addEdge(int u, int v) {
    adjacencyList[u].push_back(v);
    adjacencyList[v].push_back(u); // undirected graph
}
