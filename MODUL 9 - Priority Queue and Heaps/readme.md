# <h1 align="center">Laporan Praktikum Modul Priority Queue and Heaps</h1>
<p align="center">Indy Aurellia Az Zahra</p>
<p align="center">2311110020</p>

## Dasar Teori

## Priority Queue 
Priority Queue adalah struktur data khusus yang memungkinkan kita menyimpan elemen-elemen dengan nilai prioritas tertentu. Konsep dasar Priority Queue mirip dengan antrian biasa, namun perbedaannya adalah setiap elemen dalam Priority Queue memiliki nilai prioritas yang menentukan urutan elemen saat diambil. Elemen dengan nilai prioritas tertinggi akan diambil terleih dahulu, bukan elemen yang paling lama berada dalam antrian

### Cara Kerja Priority Queue
Priority Queue dapat diimplementasikan dengan menggunakan struktur data dasar seperti heap atau binary search tree yang memungkinkan kita untuk melakukan operasi penyisipan (insert) dan penghapusan (delete) dalam waktu logaritmik. Dengan struktur data ini, kita dapat dengan mudah mengakses elemen dengan nilai prioritas tertinggi tanpa harus memindahkan seluruh elemen lainnya.

## Heap
Heap adalah struktur data berbentuk complete binary tree yang memenuhi heap property. Complete binary tree sendiri dapat didefinisikan sebagai binary tree dimana semua level penuh, kecuali level terakhir. Semua kunci atau nilai pada level terakhir harus rata kiri apabila tidak terisi penuh.

Gambar dibawah ini adalah salah satu contoh dari complete binary tree
![introduction-to-heaps-complete-tree](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/b26e2123-e1c2-41a7-a6ee-27df9474bd02)

### Jenis-Jenis Heap Property
- Max-Heap : Kunci atau nilai yang ada di simpul mana pun harus lebih besar dari kunci/nilai yang ada di kedua simpul anaknya. Kunci terbesar ada di simpul akar (root node).
- Min-Heap : Kunci yang ada di simpul mana pun harus lebih kecil dari kunci yang ada di kedua anaknya. Kunci terkecil ada di simpul akar.

### Operasi-Operasi Pada Struktur Data Heap
- Heapify : Proses untuk mengatur ulang heap untuk mempertahankan properti heap.
- Find-max (atau Find-min) : Menemukan item maksimum dari max-heap, atau item minimum dari min-heap.
- Insertion : Menambahkan item baru di heap.
- Deletion : Menghapus item dari heap.
- Extract Min-Max : Mengembalikan dan menghapus elemen maksimum atau minimum masing-masing di max-heap dan min-heap.


## Guided

```C++
#include <iostream>
#include <algorithm>

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (1 <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = 1;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);

    std::cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }    
    std::cout << "\n";

    std::cout << "Node with maximum priority : " << extractMax() << "\n";

    std::cout << "Priority queue after extracting maximum : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    changePriority(2, 49);
    std::cout << "Priority queue after priority change : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";
    
    remove(3);
    std::cout << "Priority queue after removing the element : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    return 0;
}
```
Kode di atas merupakan definisi dari heap biner 'H' yang berukuran 50, dengan ukuran awal -1. Heap tersebut digunakan untuk menyimpan elemen dalam antrian prioritas, di mana elemen yang memiliki prioritas tertinggi berada di akar heap.

#### # Fungsi
- 'parent(int i)' : mengembalikan parent index dari node ke index 'i'
- 'leftChild(int i)' : mengembalikan left child index dari node ke index 'i'
- 'rightChild(int i)' : mengembalikan rightChild index dari node di indeks 'i'
- 'shiftUp(int i)' : menggeser node di indeks 'i' ke atas heap jika lebih besar dari induknya
- 'shiftDown(int i)' : menggeser node di indeks 'i' ke bawah heap jika lebih kecil dari anak-anaknya
- 'insert(int p)' : menyisipkan elemen baru 'p' ke dalam heap dan menggeser jika diperlukan
- 'extractMax()' : menghapus dan mengembalikan elemen dengan prioritas tertinggi dari heap.
- 'changePriority(int i, int p)' : mengubah prioritas node di indeks i menjadi p dan menggeser jika diperlukan
- 'getMax()' : mengembalikan elemen dengan prioritas tertinggi dari heap.
- 'remove(int i)' : menghapus node di indeks i dari heap dan menggeser elemen yang tersisa ke atas

#### # Fungsi 'main()'
- Menyisipkan beberapa elemen ke dalam heap menggunakan 'insert()'
- Menghapus elemen dengan prioritas tertinggi dari heap menggunakan 'extractMax()'
- Mengubah prioritas elemen di heap menggunakan 'changePriority()'
- Menghapus elemen dari heap menggunakan 'remove()'

#### Output 
![Screenshot (1407)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/35074f48-e941-4872-99b4-fbf4389dacd6)


## Unguided 

### 1. Modifikasi guided diatas yang mana heap dikonstruksi secara manual berdasarkan user

```C++
#include <iostream>
#include <algorithm>

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (1 <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = 1;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int p;
        std::cout << "Enter element " << i + 1 << ": ";
        std::cin >> p;
        insert(p);
    }

    std::cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }    
    std::cout << "\n";

    std::cout << "Node with maximum priority : " << extractMax() << "\n";

    std::cout << "Priority queue after extracting maximum : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    int i;
    std::cout << "Enter the index of the element to change priority: ";
    std::cin >> i;
    int p;
    std::cout << "Enter the new priority: ";
    std::cin >> p;
    changePriority(i, p);

    std::cout << "Priority queue after priority change : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";
    
    std::cout << "Enter the index of the element to remove: ";
    std::cin >> i;
    remove(i);

    std::cout << "Priority queue after removing the element : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    return 0;
}
```

#### Output:
![Screenshot (1408)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/e763847a-fa5f-4c32-93c2-ff7a74463baf)


Kode tersebut pertama-tama meminta user untuk memasukkan jumlah elemen yang akan disisipkan ke dalam priority queue. Kemudian user diminta untuk memasukkan setiap elemen satu per satu. Elemen-elemen tersebut disisipkan ke dalam priority queue menggunakan fungsi 'insert()'.

Setelah semua elemen disisipkan, kode tersebut mencetak antrian prioritas:

```c++
Antrian Prioritas : 45 31 14 13 20 7 11 12 7
```

Kode tersebut kemudian menghapus elemen dengan prioritas tertinggi dari antrian prioritas menggunakan fungsi 'extractMax()':

```c++
Node dengan prioritas tertinggi : 45
```

Antrian prioritas setelah menghapus elemen dengan prioritas tertinggi dicetak:

```c++
Antrian Prioritas setelah menghapus maksimum : 31 20 14 13 7 7 11 12
```

Selanjutnya, kode tersebut meminta pengguna untuk memasukkan indeks elemen yang akan diubah prioritas dan prioritas baru. Fungsi 'changePriority()' digunakan untuk mengubah prioritas elemen yang ditentukan.

Antrian prioritas setelah mengubah prioritas dicetak:

```c++
Antrian Prioritas setelah mengubah prioritas : 49 20 31 13 7 7 11 12
```

Akhirnya, kode tersebut meminta pengguna untuk memasukkan indeks elemen yang akan dihapus. Fungsi 'remove()' digunakan untuk menghapus elemen yang ditentukan dari antrian prioritas.

Antrian prioritas setelah menghapus elemen dicetak:

```c++
Antrian Prioritas setelah menghapus elemen : 49 12 31 20 7 7 11
```

Output menunjukkan operasi dasar antrian prioritas menggunakan heap biner, termasuk penyisipan, penghapusan elemen dengan prioritas tertinggi, perubahan prioritas, dan penghapusan.


## Kesimpulan
Priority Queue adalah konsep penting dalam algoritma yang membantu kita mengelola dan mengatur data dengan nilai prioritas tertentu. Implementasinya dalam struktur data seperti heap atau binary search tree memungkinkan operasi penyisipan dan penghapusan elemen dalam waktu logaritmik, yang sangat berguna dalam berbagai algoritma. Dengan pemahaman tentang Priority Queue, kita dapat meningkatkan efisiensi dan efektivitas algoritma yang kita gunakan dalam menyelesaikan masalah.

## Referensi
[1] Rintala, M., & Valmari, A. (2015, December). Priority queue classes with priority update. In SPLST (pp. 179-193).

[2] Doeppner, T. W., & Gebele, A. J. (1987). C++ on a parallel machine. Brown University, Department of Computer Science.