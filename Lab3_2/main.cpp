#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include "Graph.h"

using namespace std;

pair<vector<vector<char>>, pair<int, int>> getMatrix(const string &filename) {
    ifstream file(filename);
    vector<vector<char>> matrix;
    string line;
    pair<int, int> start;

    std::getline(file, line); // discard the first line

    for (int i = 0; std::getline(file, line); i++) {
        std::vector<char> row;
        for (int j = 0; j < line.size(); j++) {
            row.push_back(line[j]);
            if (line[j] == 'S') {
                start = make_pair(i, j);
            }
        }
        matrix.push_back(row);
    }

    return make_pair(matrix, start);
}

void printLabyrinth(const vector<vector<char>> &matrix) {
    for (const auto &row: matrix) {
        for (const auto &ch: row) {
            cout << ch;
        }
        cout << endl;
    }
    cout << endl;
}

void solution(vector<vector<char>> &matrix, pair<int, int> start) {
    vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
    vector<vector<pair<int, int>>> parent(matrix.size(), vector<pair<int, int>>(matrix[0].size()));
    queue<pair<int, int>> queue;

    queue.push(start);
    visited[start.first][start.second] = true;

    while (!queue.empty()) {
        pair<int, int> currentPosition = queue.front();
        queue.pop();

        int row = currentPosition.first;
        int col = currentPosition.second;

        // Check if we reached the finish
        if (matrix[row][col] == 'F') {
            pair<int, int> parentPos = parent[row][col];
            row = parentPos.first;
            col = parentPos.second;

            // Follow the parent pointers to trace the path
            while (row != start.first || col != start.second) {
                matrix[row][col] = '*';
                parentPos = parent[row][col];
                row = parentPos.first;
                col = parentPos.second;
            }
            break;
        }

        // Visit the neighbors of the current position
        if (row > 0 && matrix[row-1][col] != 'X' && !visited[row-1][col]) { // up
            queue.push(make_pair(row-1, col));
            visited[row-1][col] = true;
            parent[row-1][col] = currentPosition;
        }
        if (row < matrix.size()-1 && matrix[row+1][col] != 'X' && !visited[row+1][col]) { // down
            queue.push(make_pair(row+1, col));
            visited[row+1][col] = true;
            parent[row+1][col] = currentPosition;
        }
        if (col > 0 && matrix[row][col-1] != 'X' && !visited[row][col-1]) { // left
            queue.push(make_pair(row, col-1));
            visited[row][col-1] = true;
            parent[row][col-1] = currentPosition;
        }
        if (col < matrix[0].size()-1 && matrix[row][col+1] != 'X' && !visited[row][col+1]) { // right
            queue.push(make_pair(row, col+1));
            visited[row][col+1] = true;
            parent[row][col+1] = currentPosition;
        }
    }

    printLabyrinth(matrix);
}

Graph createGraphFromMatrix(vector<vector<char>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    Graph graph(rows * cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 'X') {
                int currentVertex = i * cols + j;
                if (i > 0 && matrix[i-1][j] != 'X') { // up
                    int neighbor = (i-1) * cols + j;
                    graph.addEdge(currentVertex, neighbor);
                }
                if (i < rows-1 && matrix[i+1][j] != 'X') { // down
                    int neighbor = (i+1) * cols + j;
                    graph.addEdge(currentVertex, neighbor);
                }
                if (j > 0 && matrix[i][j-1] != 'X') { // left
                    int neighbor = i * cols + j-1;
                    graph.addEdge(currentVertex, neighbor);
                }
                if (j < cols-1 && matrix[i][j+1] != 'X') { // right
                    int neighbor = i * cols + j+1;
                    graph.addEdge(currentVertex, neighbor);
                }
            }
        }
    }
    return graph;
}

int main() {
    pair<vector<vector<char>>, pair<int, int>> matrix_start = getMatrix("labyrinth.txt");
    auto matrix = matrix_start.first;
    auto start = matrix_start.second;

    auto graph = createGraphFromMatrix(matrix);
    graph.text();

    solution(matrix, start);
}
