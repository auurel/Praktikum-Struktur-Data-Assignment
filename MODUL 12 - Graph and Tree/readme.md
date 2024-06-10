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


### 2.



## Kesimpulan

Graf merupakan kumpulan simpul yang terhubung oleh sisi dan digunakan untuk merepresentasikan berbagai hubungan antara entitas. Salah satu jenis graf yaitu, graf terarah dan tak terarah. Contoh: jaringan sosial, jaringan transportasi, graf jalan raya.

Tree (pohon) adalah jenis khusus dari graf yang tidak memiliki siklus. Memiliki simpul akar dan setiap simpul memiliki satu simpul induk kecuali simpul akar. Digunakan untuk representasi data hierarkis dan sering digunakan dalam struktur data seperti pohon biner. Contoh struktur direktori pada komputer.

## Referensi
[1] Maurer, W. D., & Lewis, T. G. (1975). Hash table methods. ACM Computing Surveys (CSUR), 7(1), 5-19.

[2] Nainggolan, S. (2022). Implementasi Algoritma SHA-256 Pada Aplikasi Duplicate Document Scanner. Resolusi: Rekayasa Teknik Informatika dan Informasi, 2(5), 201-213.
