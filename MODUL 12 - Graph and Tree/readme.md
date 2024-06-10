# <h1 align="center">Laporan Praktikum Modul Graph and Tree</h1>
<p align="center">Indy Aurellia Az Zahra</p>
<p align="center">2311110020</p>

## Dasar Teori

Graph adalah jenis struktur data umum yang susunan datanya tidak berdekatan satu sama lain (non-linier). Graph terdiri dari kumpulan simpul berhingga untuk menyimpan data dan antara dua buah simpul terdapat hubungan saling keterkaitan.

Graph banyak dimanfaatkan untuk menyelesaikan masalah dalam kehidupan nyata, dimana masalah tersebut perlu direpresentasikan atau diimajinasikan seperti sebuah jaringan. Contohnya adalah jejaring sosial (seperti Facebook, Instagram, LinkedIn, dkk)

### Jenis-Jenis Graph

Graph dapat dibedakan berdasarkan arah jelajahnya dan ada tidaknya label bobot pada relasinya.

Berdasarkan arah jelajahnya graph dibagi menjadi Undirected graph dan Directed graph.

- Undirected Graph
Pada undirected graph, simpul-simpulnya terhubung dengan edge yang sifatnya dua arah. Misalnya kita punya simpul 1 dan 2 yang saling terhubung, kita bisa menjelajah dari simpul 1 ke simpul 2, begitu juga sebaliknya.

![image](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/6bd13cb9-1342-4254-b363-6c2cb12bde0b)

- Directed Graph
Kebalikan dari undirected graph, pada graph jenis ini simpul-simpulnya terhubung oleh edge yang hanya bisa melakukan jelajah satu arah pada simpul yang ditunjuk. Sebagai contoh jika ada simpul A yang terhubung ke simpul B, namun arah panahnya menuju simpul B, maka kita hanya bisa melakukan jelajah (traversing) dari simpul A ke simpul B, dan tidak berlaku sebaliknya.

![image](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/4a9871c2-b792-465e-9f1e-3c9f9565094c)


### Fungsi dan Kegunaan Graph
- Graph digunakan untuk merepresentasikan aliran komputasi.
- Digunakan dalam pemodelan grafik.
- Graph dipakai pada sistem operasi untuk alokasi sumber daya.
- Google maps menggunakan graph untuk menemukan rute terpendek.
- Graph digunakan dalam sistem penerbangan untuk optimasi rute yang efektif.
- Pada state-transition diagram, graph digunakan untuk mewakili state dan transisinya.
- Di sirkuit, graph dapat digunakan untuk mewakili titik sirkuit sebagai node dan kabel sebagai edge.
- Graph digunakan dalam memecahkan teka-teki dengan hanya satu solusi, seperti labirin.
- Graph digunakan dalam jaringan komputer untuk aplikasi Peer to peer (P2P).
- Umumnya graph dalam bentuk DAG (Directed acyclic graph) digunakan sebagai alternatif blockchain untuk cryptocurrency. Misalnya crypto seperti IOTA

## Guided-1

```C++
#include <iostream>
#include <iomanip>

using namespace std;

string simpul[7] ={"Ciamis",
                    "Bandung",
                    "Bekasi",
                    "Tasikmalaya",
                    "Cianjur",
                    "Purwokerto",
                    "Yogjakarta"
                    };
int busur[7][7] =
{
    {0,7,8,0,0,0,0},
    {0,0,5,0,0,15,0},
    {0,6,0,0,5,0,0},
    {0,5,0,0,2,4,0},
    {23,0,0,10,0,0,8},
    {0,0,0,0,7,0,3},
    {0,0,0,0,9,4,0}};

void tampilGraph() {
    for(int baris =0; baris <7; baris++) {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++) {
            if (busur[baris] [kolom] !=0) {
                cout << " " << simpul[kolom] << "(" << busur[baris] [kolom] << ")";
            }
        }
        cout << endl;
    }
}

int main() {
    tampilGraph();
    return 0;
}
```

Kode di atas adalah program yang digunakan untuk menampilkan grafik jaringan (network) menggunakan struktur data 2D array dan fungsi 'tampilGraph'.

Berikut adalah interpretasi kode tersebut:

A. Deklarasi Variabel:

- 'simpul' adalah array string yang berisi nama-nama kota.
- 'busur' adalah array 2D yang berisi jarak antar kota.

B. Fungsi tampilGraph:

- Fungsi ini digunakan untuk menampilkan grafik jaringan menggunakan array 'simpul' dan 'busur'.
- Fungsi ini menggunakan perulangan untuk mengiterasi setiap baris dan kolom dalam array 'busur'.
- Dalam setiap iterasi, fungsi ini menampilkan nama kota dan jarak antar kota yang terhubung.

C. Implementasi:

- Dalam kode, fungsi 'tampilGraph' dipanggil dalam fungsi 'main'.
- Fungsi 'main' hanya mengakses fungsi 'tampilGraph' dan tidak memiliki logika tambahan.

Contoh output dari kode tersebut adalah sebagai berikut:

![Guided-1 graph and tree](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/44b1bb5e-2deb-4cc6-b87d-51a4898726d1)


### Guided-2

```C++
#include <iostream>

using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    // constructor
    TNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TNode *node) {
    if (node != NULL) {
        cout << node -> data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(TNode *node) {
    if (node != NULL) {
        inOrder(node->left); 
        cout << node -> data << " ";
        inOrder(node->right);
    }
}

void postOrder(TNode *node) {
    if (node != NULL) {
        postOrder(node->left); 
        postOrder(node->right);
        cout << node -> data << " ";
    }
}

int main() {
    TNode *zero = new TNode(0);
    // 0
    // /\
    // NULL NULL

    TNode *one = new TNode(1);
    TNode *five = new TNode(5);
    TNode *seven = new TNode(7);
    TNode *eight = new TNode(8);
    TNode *nine = new TNode(9);

    seven->left = one;
    // 7
    // /\
    // 1 NULL

    seven->right = nine;
    // 7
    // /\
    // 1 9

    one->left = zero;
    // 7
    // /\
    // 1 9
    // /\
    // 0 NULL

    one -> right = five;
    // 7
    // /\
    // 1 9
    // /\
    // 0 5

    nine-> left = eight;
    // 7
    // /\
    // 1 9
    // /\  /\
    // 0 5 8 NULL

    preOrder(seven);
    cout << endl;

    inOrder(seven);
    cout << endl;

    postOrder (seven);
    cout << endl;

    return 0;
}
```

Kode di atas adalah implementasi struktur data binary tree dan tiga metode traversal (pre-order, in-order, dan post-order). Berikut adalah interpretasi kode tersebut:

A. Struktur Data Binary Tree:
Struktur data binary tree terdiri dari tiga bagian: 'data', 'left', dan 'right'. 'data' berisi nilai yang disimpan dalam node, sedangkan 'left' dan 'right adalah pointer ke node anak kiri dan kanan.
- Konstruktor 'TNode' digunakan untuk membuat node baru dengan nilai 'value'.

B. Metode Traversal:
- Metode 'preOrder' melakukan traversal pre-order, yaitu mengunjungi node root terlebih dahulu, lalu mengunjungi node anak kiri, dan akhirnya mengunjungi node anak kanan.
- Metode 'inOrder' melakukan traversal in-order, yaitu mengunjungi node anak kiri terlebih dahulu, lalu mengunjungi node root, dan akhirnya mengunjungi node anak kanan.
- Metode 'postOrder' melakukan traversal post-order, yaitu mengunjungi node anak kiri dan kanan terlebih dahulu, lalu mengunjungi node root.

![Guided 2 graph and tree](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/b2db7c7c-60fe-475d-9429-aa090abae25d)


## Unguided 

#### *Cantumkan NIM pada salah satu variabel di dalam program || Contoh : int nama_22102003;
### 1.	Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.

![image](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/9189e9b6-15e7-441e-8e8a-d9ff9a4b90c2)


```C++
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
```

#### Output:

![Screenshot (1513)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/8ff96976-e15f-45ea-8584-d80a1a995ad2)

Kode di atas adalah program yang digunakan untuk menampilkan grafik jaringan (network) menggunakan struktur data 2D array dan fungsi tampilGraph.

Berikut adalah interpretasi kode tersebut:

A. Deklarasi Variabel:
- 'aurel_2311110020' merupakan variabel integer yang digunakan untuk menyimpan jumlah kota.
- 'cities' adalah vector string yang digunakan untuk menyimpan nama-nama kota.
- 'distanceMatrix' adalah vector 2D yang digunakan untuk menyimpan jarak antar kota.


B. Input Jumlah Kota:

- Program menginput jumlah kota menggunakan variabel 'aurel_2311110020'.


C. Memasukkan Nama Kota:

- Program memasukkan nama-nama kota menggunakan 'getline' dan menyimpannya dalam vector 'cities'.


D. Memasukkan Jarak Antar Simpul:

- Program memasukkan jarak antar kota menggunakan 'cin' dan menyimpannya dalam matrix 'distanceMatrix'.


E. Menampilkan Jarak Matriks:

- Program menampilkan jarak matriks menggunakan perulangan dan fungsi 'setw' untuk mengatur jarak / lebar tampilan.

Dalam contoh output, program akan menampilkan grafik jaringan dengan nama-nama kota dan jarak antar kota.

Perubahan yang dilakukan adalah mengganti nama variabel `numCities` dengan `aurel_2311110020`.


### 2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!

```c++
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
```
- Tambah Root
Ketika pengguna memilih opsi ini, program akan meminta pengguna untuk memasukkan data untuk simpul akar (root) jika belum ada root yang dibuat sebelumnya.

![tambah root](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/683d439d-16b4-4e74-a394-2161df4ad9fe)


- Tambah Simpul
Ketika pengguna memilih opsi ini, program akan meminta pengguna untuk memasukkan data untuk simpul kiri dan kanan dari setiap simpul secara berturut-turut hingga pengguna memasukkan '0' untuk berhenti menambah simpul.

![tambah simpul](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/d8006552-77f5-4ea9-bcdb-b32fe7823c83)


- Tampilkan Pre-Order
Ketika pengguna memilih opsi ini, program akan menampilkan traversal pre-order dari pohon biner, yaitu mencetak data simpul dalam urutan root, kiri, kanan.

![preorder root](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/aaeec326-d87e-4329-8014-acbafb304fb4)


- Tampilkan In-Order
Ketika pengguna memilih opsi ini, program akan menampilkan traversal in-order dari pohon biner, yaitu mencetak data simpul dalam urutan kiri, root, kanan.

![inorder root](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/b9f99b19-b217-45b3-acb6-29076f7b1361)


- Tampilkan Post-Order
Ketika pengguna memilih opsi ini, program akan menampilkan traversal post-order dari pohon biner, yaitu mencetak data simpul dalam urutan kiri, kanan, root.

![post order root](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/1b06b9b2-5665-4347-aeaf-404bc4518116)


- Keluar dari Program
Ketika pengguna memilih opsi ini, program akan berhenti dan menampilkan pesan:

![keluar](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/ae42d5c2-494e-40ad-9a96-52d0cacc8dff)

-- Setiap kali pengguna memilih opsi, program akan menjalankan fungsi terkait dan mencetak hasil atau meminta input tambahan sesuai kebutuhan.

-- Setelah menyelesaikan semua operasi, program akan mencetak informasi penutup dengan nama pembuat program.

Hal ini memberikan gambaran lengkap tentang bagaimana program berfungsi dan bagaimana output dihasilkan berdasarkan interaksi pengguna.


## Kesimpulan

Graf merupakan kumpulan simpul yang terhubung oleh sisi dan digunakan untuk merepresentasikan berbagai hubungan antara entitas. Salah satu jenis graf yaitu, graf terarah dan tak terarah. Contoh: jaringan sosial, jaringan transportasi, graf jalan raya.

Tree (pohon) adalah jenis khusus dari graf yang tidak memiliki siklus. Memiliki simpul akar dan setiap simpul memiliki satu simpul induk kecuali simpul akar. Digunakan untuk representasi data hierarkis dan sering digunakan dalam struktur data seperti pohon biner. Contoh struktur direktori pada komputer.

## Referensi
[1] Grass, J. E., & Chen, Y. F. (1990, April). The C++ Information Abstractor. In C++ Conference (pp. 265-278).

[2] Malik, D. S. (2010). Data structures using C++. USA.

[3] Himawan, D. Maulana, V. Amelia, and T. Hidayat, “IMPLEMENTASI GRAF DALAM PENYIMPANAN DATA STRUKTUR BANGUNAN,” 2008. Available: https://journal.uii.ac.id/Snati/article/download/553/477. [Accessed: Jun. 08, 2024]

[4] Latifah, “PENERAPAN ALGORITHMA POHON UNTUK OPERASI PENGOLAHAN DAN PENYIMPANAN DATA DALAM TEKNIK PEMROGRAMAN (KAJIAN ALGORITHMA POHON PADA TEKNIK PEMROGRAMAN),” Jurnal TECHNO Nusa Mandiri, vol. 8, no. 2, pp. 111–120, Sep. 2016, Available: https://ejournal.nusamandiri.ac.id/index.php/techno/article/download/203/179. [Accessed: Jun. 08, 2024]
