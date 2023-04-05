#include "Adjazenz_matrix.h"


Adjmatrix::Adjmatrix(const string &filename) {
    ifstream file;
    file.open(filename);
    file >> n;
    int x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            file >> x;
            matrix[i][j] = x;
        }
    }
}

bool Adjmatrix::is_edge(int x, int y) {
    if (matrix[x][y] == 1)
        return true;
    return false;
}

void Adjmatrix::angrenzende_knoten(int x) {
    cout << "Angrenzenden Knoten" << endl;
    cout << x << ": ";
    for (int i = 0; i < n; i++)
        if (matrix[x][i] == 1)
            cout << i << " ";
}

void Adjmatrix::print_graph() {
    cout << "Adjazenzmatrix" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

}