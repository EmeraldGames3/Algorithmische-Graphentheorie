#include "Adjazenz_liste.h"

AdjazenzListe::AdjazenzListe(const string &filename) {
    ifstream file;
    file.open(filename);
    file >> n;
    string line;
    getline(file, line);
    for (int i = 1; i <= n; i++) {
        vector<int> arr;
        getline(file, line);
        istringstream iss(line);
        int x;
        while (iss >> x)
            arr.push_back(x);
        add_edge(arr);
    }
}

AdjazenzListe::AdjazenzListe() { n = 0; }

AdjazenzListe::AdjazenzListe(AdjazenzListe &adjazenzListe) {
    this->n = adjazenzListe.n;
    this->adj_liste = adjazenzListe.adj_liste;
}

void AdjazenzListe::add_edge(const vector<int> &arr) {
    adj_liste.push_back(arr);
}

bool AdjazenzListe::is_edge(int x, int y) {
    for (int j: adj_liste[x])
        if (j == y)
            return true;
    return false;

}

void AdjazenzListe::angrenzende_knoten(int x) {
    cout << "Angrenzende Knoten fur " << x << endl;
    for (int j: adj_liste[x])
        cout << j << " ";
}

void AdjazenzListe::print_graph() {
    cout << "Print graph" << endl;
    for (int i = 0; i < adj_liste.size(); i++) {
        cout << "Nod: " << i << " " << " Values: ";
        for (int j: adj_liste[i])
            cout << j << " ";
        cout << endl;
    }
}

void AdjazenzListe::komplement() {
    AdjazenzListe komplement;
    for (int i = 0; i < n; i++) {
        vector<int> arr;
        for (int j = 0; j < n; j++)
            if (!(is_edge(i, j))) {
                if (i != j)
                    arr.push_back(j);
            }
        komplement.adj_liste.push_back(arr);
    }
    cout << "Print komplementgraph" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nod: " << i << " " << " Values: ";
        for (int j: komplement.adj_liste[i])
            cout << j << " ";
        cout << endl;

    }
}

AdjazenzListe AdjazenzListe::durchschnitt(AdjazenzListe graph) {
    AdjazenzListe durchschnitt;
    int size;
    if (graph.adj_liste.size() < adj_liste.size()) {
        size = graph.adj_liste.size();
        for (int i = 0; i < size; i++)
            if (!graph.adj_liste[i].empty() and !adj_liste[i].empty()) {
                vector<int> arr;
                for (int j = 0; j < adj_liste[i].size(); j++)
                    if (find(graph.adj_liste[i].begin(), graph.adj_liste[i].end(), adj_liste[i][j]) !=
                        graph.adj_liste[i].end()) {
                        arr.push_back(adj_liste[i][j]);
                    }
                durchschnitt.adj_liste.push_back(arr);
            }

    } else {
        size = this->adj_liste.size();
        for (int i = 0; i < size; i++)
            if (!graph.adj_liste[i].empty() and !adj_liste[i].empty()) {
                vector<int> arr;
                for (int j = 0; j < graph.adj_liste[i].size(); j++)
                    if (find(adj_liste[i].begin(), adj_liste[i].end(), graph.adj_liste[i][j]) !=
                        graph.adj_liste[i].end()) {
                        arr.push_back(graph.adj_liste[i][j]);
                    }
                durchschnitt.adj_liste.push_back(arr);
            }
    }
    return durchschnitt;
}