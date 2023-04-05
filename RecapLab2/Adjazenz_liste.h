#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class AdjazenzListe {
private:
    int n{};
    vector<vector<int>> adj_liste;
public:
    AdjazenzListe();

    AdjazenzListe(const string &filename);

    AdjazenzListe(AdjazenzListe &adjazenzListe);

    void add_edge(const vector<int> &arr);

    void print_graph();

    bool is_edge(int x, int y);

    void angrenzende_knoten(int x);

    void komplement();

    AdjazenzListe durchschnitt(AdjazenzListe graph);
};