#include "Kanten_liste.h"
#include <fstream>
#include <iostream>
#include <bits/stdc++.h>

KantenListe::KantenListe(string filename) {
    ifstream file;
    file.open(filename);
    file >> n;
    file >> m;
    int x, y;
    for (int index = 0; index < m; index++) {
        file >> x >> y;
        add_edge(x, y);

    }
}

void KantenListe::add_edge(int x, int y) {
    kanten_list.push_back(pair(x, y));
}

bool KantenListe::is_edge(int x, int y) {
    for (int i = 0; i < kanten_list.size(); i++) {
        if (kanten_list[i].first == x && kanten_list[i].second == y)
            return true;
        if (kanten_list[i].first == y && kanten_list[i].second == x)
            return true;
    }
    return false;

}

void KantenListe::angrenzende_knoten(int x) {
    cout << endl;
    cout << "Angrenzende Knoten" << endl;
    cout << x << ": ";
    for (int i = 0; i < kanten_list.size(); i++)
        if (kanten_list[i].first == x)
            cout << kanten_list[i].second << " ";
        else if (kanten_list[i].second == x)
            cout << kanten_list[i].first << " ";


}

void KantenListe::print_graph() {
    cout << "Kantenliste\n";
    cout << "[ ";
    for (int i = 0; i < kanten_list.size(); i++) {
        cout << "[";
        cout << kanten_list[i].first << " " << kanten_list[i].second;
        cout << "] ";
    }
    cout << "]";
}

KantenListe KantenListe::komplement() {
    KantenListe graph;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!is_edge(i, j) && i != j)
                graph.add_edge(i, j);
    return graph;
}

KantenListe::KantenListe() {
    n = 0;
    m = 0;
}

KantenListe::KantenListe(KantenListe &kantenListe) {
    this->n = kantenListe.n;
    this->m = kantenListe.m;
    this->kanten_list = kantenListe.kanten_list;
}

void KantenListe::MergeSortedIntervals(vector<int> &v, int s, int m, int e) {

    vector<int> temp;

    int i, j;
    i = s;
    j = m + 1;

    while (i <= m && j <= e) {

        if (v[i] >= v[j]) {
            temp.push_back(v[i]);
            ++i;
        } else {
            temp.push_back(v[j]);
            ++j;
        }

    }

    while (i <= m) {
        temp.push_back(v[i]);
        ++i;
    }

    while (j <= e) {
        temp.push_back(v[j]);
        ++j;
    }

    for (int i = s; i <= e; ++i)
        v[i] = temp[i - s];

}

void KantenListe::MergeSort(vector<int> &v, int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        MergeSort(v, s, m);
        MergeSort(v, m + 1, e);
        MergeSortedIntervals(v, s, m, e);
    }
}

bool KantenListe::havel_hakimi(string filename) {
    ifstream file;
    int x;
    vector<int> arr;
    file.open(filename);
    while (!file.eof()) {
        file >> x;
        arr.push_back(x);
    }
    MergeSort(arr, 0, arr.size() - 1);
    int sum = 0;
    int min, max;
    bool ok = true;
    for (int i = 0; i < arr.size(); i++)
        sum += arr[i];
    if (sum % 2 != 0)
        return false;
    while (ok) {
        min = *min_element(arr.begin(), arr.end());
        max = *max_element(arr.begin(), arr.end());
        if (min < 0)
            return false;
        if (max == 0)
            return true;
        if (max > arr.size() - 1)
            return false;
        int first = arr[0];
        arr.erase(arr.begin());
        for (int i = 0; i < first; i++)
            arr[i]--;
        MergeSort(arr, 0, arr.size() - 1);
    }


}
