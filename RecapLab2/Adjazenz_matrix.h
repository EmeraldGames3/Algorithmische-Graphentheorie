#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Adjmatrix {
private:
    int n{};
    int matrix[20][20]{};
public:
    explicit Adjmatrix(const string &filename);

    void print_graph();

    bool is_edge(int x, int y);

    void angrenzende_knoten(int x);
};