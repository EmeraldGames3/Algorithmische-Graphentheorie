#include <iostream>
#include "Graph.h"

using std::cout;

int main() {
    Graph graph10k("10k.txt");
    Graph graph100k("100k.txt");
    Graph graph1m("1m.txt");

//    graph10k.BFS(0);
//    graph10k.text();

    cout << "\n10k:\n";
    cout << graph10k.weg(0, 7738);
    cout << graph10k.weg(793, 6174) << "\n";

    cout << "\n100k:\n";
    cout << graph100k.weg(81768, 55850);
    cout << graph100k.weg(19126, 53548) << "\n";

    cout << "\n1M:\n";
    cout << graph1m.weg(696751, 505396);
    cout << graph1m.weg(0, 895812) << "\n";
}
