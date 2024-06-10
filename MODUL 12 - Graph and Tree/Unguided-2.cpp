#include <iostream>
using namespace std;

// Definisi struktur pohon
struct pohon {
    pohon* kanan;
    char data;
    pohon* kiri;
};

// Deklarasi variabel global
pohon* simpul;
pohon* root;
pohon* saatIni;
pohon* helperA;
pohon* helperB;
pohon* alamat[256];

// Fungsi untuk inisialisasi root
void inisialisasi() {
    root = NULL;
}

// membuat simpul baru
void simpulBaru(char dataMasukkan) {
    simpul = new pohon;
    simpul->data = dataMasukkan;
    simpul->kanan = NULL;
    simpul->kiri = NULL;
}

// membuat simpul akar
void simpulAkar() {
    if (root == NULL) {
        // Jika root belum ada, minta input data dan buat root
        char dataAnda;
        cout << "Silahkan masukkan data: ";
        cin >> dataAnda;
        simpulBaru(dataAnda);
        root = simpul;
        cout << "Root terbentuk..." << endl;
    } else {
        cout << "Root sudah ada..." << endl;
    }
}

// menambah simpul
void tambahSimpul() {
    if (root != NULL) {
         // Inisialisasi variabel untuk traversal dan penanda
        int i = 1, j = 1, penanda = 0;
        char dataUser;
        alamat[i] = root;

        while (penanda == 0 && j < 256) {
            // Input data untuk simpul kiri
            cout << "Masukkan data kiri (0 untuk berhenti): ";
            cin >> dataUser;
            if (dataUser != '0') {
                simpulBaru(dataUser);
                saatIni = alamat[i];
                saatIni->kiri = simpul;
                j++;
                alamat[j] = simpul;
            } else {
                penanda = 1;
                j++;
                alamat[j] = NULL;
            }
            if (penanda == 0) {
                // Input data untuk simpul kanan
                cout << "Masukkan data kanan (0 untuk berhenti): ";
                cin >> dataUser;
                if (dataUser != '0') {
                    simpulBaru(dataUser);
                    saatIni = alamat[i];
                    saatIni->kanan = simpul;
                    j++;
                    alamat[j] = simpul;
                } else {
                    penanda = 1;
                    j++;
                    alamat[j] = NULL;
                }
            }
            i++;
        }
    }
}

// Fungsi untuk traversal pre-order
void preOrder(pohon* node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder(node->kiri);
        preOrder(node->kanan);
    }
}

// Fungsi untuk traversal in-order
void inOrder(pohon* node) {
    if (node != NULL) {
        inOrder(node->kiri);
        cout << node->data << " ";
        inOrder(node->kanan);
    }
}

// Fungsi untuk traversal post-order
void postOrder(pohon* node) {
    if (node != NULL) {
        postOrder(node->kiri);
        postOrder(node->kanan);
        cout << node->data << " ";
    }
}

// menampilkan menu
void tampilkanMenu() {
    cout << "Menu:" << endl;
    cout << "1. Tambah Root" << endl;
    cout << "2. Tambah Simpul" << endl;
    cout << "3. Tampilkan Pre-order" << endl;
    cout << "4. Tampilkan In-order" << endl;
    cout << "5. Tampilkan Post-order" << endl;
    cout << "6. Keluar" << endl;
    cout << "Pilih opsi: ";
}

// Fungsi utama
int main() {
    // Inisialisasi pohon
    inisialisasi();
    int pilihan;
    do {
        // Tampilkan menu dan minta input pilihan user
        tampilkanMenu();
        cin >> pilihan;
        switch (pilihan) {
            case 1:
            // Tambah root
                simpulAkar();
                break;
            case 2:
                // Tambah simpul
                tambahSimpul();
                break;
            case 3:
                // Tampilkan traversal pre-order
                cout << "Pre-order: ";
                preOrder(root);
                cout << endl;
                break;
            case 4:
                // Tampilkan traversal in-order
                cout << "In-order: ";
                inOrder(root);
                cout << endl;
                break;
            case 5:
                // Tampilkan traversal post-order
                cout << "Post-order: ";
                postOrder(root);
                cout << endl;
                break;
            case 6:
                // Keluar dari program
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Opsi tidak valid. Silakan coba lagi." << endl;
                break;
        }
    } while (pilihan != 6);
    
    cout << " " << endl;
    cout << " " << endl;
    cout << "By: Aurel (2311110020)" << endl;
    return 0;
}