#include "Adjazenz_liste.h"
#include "Kanten_liste.h"

using namespace std;

int main() {
    KantenListe kantenliste("kanten_liste.txt");
    kantenliste.print_graph();
    cout << endl;
    //
    // Test MERGESORT
    vector<int> arr = {2, 3, 1, 4};
    kantenliste.MergeSort(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
    //havel_hakimi
    cout << kantenliste.havel_hakimi("date.in");

}