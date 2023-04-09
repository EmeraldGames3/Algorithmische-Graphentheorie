#include "Graph.h"

Graph::Graph() : nodes(0), edges(0) {}

Graph::Graph(const string &fileName) {
    std::ifstream file(fileName);

    file >> nodes;
    edges = 0;

    for (int i = 1; i < nodes + 1; i++) {
        for (int j = 1; j < nodes + 1; j++) {
            int x;
            file >> x;
            adjacencyMatrix[i][j] = x;
            if(x == 1){
                edges++;
            }
        }
    }
    edges /= 2;
}

void Graph::BFS(int start) {
    // Create a deque to store the nodes to be visited
    std::deque<int> q;

    // Create a vector to keep track of visited nodes
    vector<bool> visited(nodes + 1, false);

    // Mark the starting node as visited and enqueue it
    visited[start] = true;
    q.push_back(start);

    // Loop through the deque until it's empty
    while (!q.empty()) {
        // Dequeue a node from the front of the deque
        int curr = q.front();
        q.pop_front();

        // Output the current node
        std::cout << curr << " ";

        // Enqueue all adjacent nodes that haven't been visited yet

        for(int i = 1; i < nodes + 1; i++){
            if(adjacencyMatrix[curr][i] != 0 && !visited[i]){
                visited[i] = true;
                q.push_back(i);
            }
        }
    }

    std::cout << std::endl;
}


void Graph::printGraph() {
    std::cout << "Adjacency Matrix:\n";

    for (int i = 1; i < nodes + 1; i++) {
        for (int j = 1; j < nodes + 1; j++) {
            std::cout << adjacencyMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

void Graph::printConexComponent() {
    vector<bool> triedNodes = vector(nodes, false);
    int conexCounter = 0;

    std::cout << "The conex components are:\n";
    //Perform bfs, from every node to find the conex components
    //If a node was already visited do no try it again
    for(int start = 1; start < nodes + 1; start++){
        if(triedNodes[start]){
            continue;
        }
        //Count how many conex components there are
        conexCounter++;

        // Create a deque to store the nodes to be visited
        std::deque<int> q;

        // Create a vector to keep track of visited nodes
        vector<bool> visited(nodes + 1, false);

        // Mark the starting node as visited and enqueue it
        visited[start] = true;
        q.push_back(start);

        // Loop through the deque until it's empty
        while (!q.empty()) {
            // Dequeue a node from the front of the deque
            int curr = q.front();
            q.pop_front();
            triedNodes[curr] = true;

            // Output the current node
            std::cout << curr << " ";

            // Enqueue all adjacent nodes that haven't been visited yet

            for(int i = 1; i < nodes + 1; i++){
                if(adjacencyMatrix[curr][i] != 0 && !visited[i]){
                    visited[i] = true;
                    q.push_back(i);
                }
            }
        }

        std::cout<<"\n";
    }

    std::cout << "There are " << conexCounter << " conex components in this graph\n";
}
