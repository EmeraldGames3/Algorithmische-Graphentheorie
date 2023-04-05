#include "Graph.h"

Graph::Graph() : nodes(0) {}

Graph::Graph(const string &fileName) {
    std::ifstream file(fileName);

    file >> nodes;
    adjacencyList.resize(nodes);

    std::string line;
    int node, connectedNode;
    std::getline(file, line); // read the rest of the first line

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        iss >> node;
        while (iss >> connectedNode) {
            adjacencyList[node].push_back(connectedNode);
        }
    }
    file.close();
}

void Graph::printGraph() {
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

Graph::Graph(const Graph &other) : nodes(other.nodes){
    adjacencyList = other.adjacencyList;
}
