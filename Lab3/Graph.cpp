#include "Graph.h"

Graph::Graph() : nodes(0) , edges(0){}

Graph::Graph(const string &fileName) {
    std::ifstream file(fileName);

    file >> nodes;
    file >> edges;
    adjacencyList.resize(nodes);

    for(int i = 0; i <  edges; i++){
        int node, conectedNode;
        file >> node >> conectedNode;
        adjacencyList[node].push_back(conectedNode);
        adjacencyList[conectedNode].push_back(node);
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

void Graph::weg(int start, int stop) {
    std::vector<bool> visited(nodes, false);
    std::vector<int> parent(nodes, -1);
    std::deque<int> q;
    q.push_back(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop_front();

        if (current == stop) {
            // Backtrack to find the shortest path
            std::vector<int> path;
            path.push_back(current);
            int node = current;
            while (parent[node] != -1) {
                path.push_back(parent[node]);
                node = parent[node];
            }
            std::cout << "Shortest path from " << start << " to " << stop << ": ";
            for (int i = path.size() - 1; i >= 0; i--)
                std::cout << path[i] << " ";
            std::cout << std::endl;
            return;
        }

        for (int neighbor : adjacencyList[current]) {
            if (!visited[neighbor]) {
                q.push_back(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = current;
            }
        }
    }

    // If we reach here, there is no path from start to stop
    std::cout << "No path from " << start << " to " << stop << std::endl;
}
