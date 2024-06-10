#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int aurel_2311110020; // Deklarasi variabel untuk menyimpan jumlah kota

    // Input jumlah kota
    cout << "Masukkan jumlah simpul: ";
    cin >> aurel_2311110020;
    cin.ignore();  // Ignore newline character left in the input buffer

    vector<string> cities(aurel_2311110020); // untuk menyimpan nama-nama kota
    vector<vector<int>> distanceMatrix(aurel_2311110020, vector<int>(aurel_2311110020, 0)); // untuk menyimpan jarak antar kota

    // Memasukkan dan menyimpan nama kota
    for (int i = 0; i < aurel_2311110020; ++i) {
        cout << "Simpul " << i + 1 << ": "; // setiap iterasi nama kota ke-i akan dimasukkan
        getline(cin, cities[i]);
    }

    // Memasukkan dan menyimpan jarak antar simpul
    cout << "\nMasukkan bobot antar simpul : \n";
    for (int i = 0; i < aurel_2311110020; ++i) {
        for (int j = 0; j < aurel_2311110020; ++j) {
            cout << cities[i] << "-->" << cities[j] << " = ";
            cin >> distanceMatrix[i][j];
        }
    }

    // Menampilkan jarak matriks
    cout << "\n     ";
    for (const auto& city : cities) {
        cout << setw(7) << city << "  "; // setw untuk mengatur jarak / lebar tampilan
    }
    cout << endl;
    // Menampilkan setiap baris matriks jarak dengan nama kota
    for (int i = 0; i < aurel_2311110020; ++i) {
        cout << setw(7) << cities[i] << "  ";
        for (int j = 0; j < aurel_2311110020; ++j) {
            cout << setw(4) << distanceMatrix[i][j] << "  ";
        }
        cout << endl;
    }
    // Cetak nama pembuat program
    cout << endl;
    cout << "By : aurel (2311110020)" << endl;
    cout << endl;
    return 0;
}