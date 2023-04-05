#include <vector>
#include <string>

using namespace std;

class KantenListe {
private:
    int n, m;
    vector<pair<int, int>> kanten_list = {};
public:

    KantenListe();

    KantenListe(string filename);

    KantenListe(KantenListe &kantenListe);

    void add_edge(int x, int y);

    void print_graph();

    bool is_edge(int x, int y);

    void angrenzende_knoten(int x);

    KantenListe komplement();

    void MergeSortedIntervals(vector<int> &v, int s, int m, int e);

    void MergeSort(vector<int> &v, int s, int e);

    bool havel_hakimi(string filename);

};