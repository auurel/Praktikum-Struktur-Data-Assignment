# <h1 align="center">Laporan Praktikum Modul Stack</h1>
<p align="center">Indy Aurellia Az Zahra</p>
<p align="center">2311110020</p>

## Dasar Teori

Stack merupakan sebuah struktur data yang digunakan untuk menyimpan sejumlah objek atau variabel. Sesuai dengan namanya, stack sering kali terlihat seperti tumpukan dalam bentuk fisik. Karakteristik khas dari stack adalah penggunaan aturan LIFO (Last In, First Out). Artinya, data yang terakhir dimasukkan ke dalam stack akan menjadi data pertama yang diambil atau dikeluarkan. 

Konsep ini mirip dengan tumpukan buku, di mana buku yang terakhir diletakkan di atas tumpukan harus diambil terlebih dahulu sebelum bisa mengakses buku yang berada di bagian bawah tumpukan.

###### Operasi utama pada stack meliputi:
- Push : menambahkan elemen baru ke dalam stack pada posisi teratas
- Pop : menghapus elemen teratas dari stack dan mengembalikan nilainya
- Peek atau Top : mengecek elemen teratas dari stack tanpa menghapusnya
- IsEmpty : memeriksa apakah stack kosong atau tidak
- Size : mengembalikan jumlah elemen dalam stack

###### Kelebihan stack
- Manajemen data efisien
- Manajemen fungsi efisien
- Kontrol atas pengalokasian memori
- Manajemen smart memory yang membersihkan objek secara otomatis
- Lebih tahan lama, aman, dan tidak ada pengubahan ukuran variabel

###### Kekurangan stack
- Ukuran memori terbatas
- Banyaknya objek dan meningkatkan risiko stack overflow
- Tidak memungkinkan adanya akses acak
- Fungsi dan program tidk terdefinisi jika penyimpanan variabel ditimpa variabel lain
- Potensi terjadinya hang atau penghentian yang tidak diinginkan ketika tumpukan berada di luar memori

## Guided 

### 1. [Nama Topik]

```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArraybuku() {
    for (int i = top; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya data = " << countStack() << endl;

    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout << "\n";

    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;

    cetakArrayBuku();

    return 0;
}



```
Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Unguided 

### 1. [Soal]

```C++
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string kata;
    stack<char> s;

    cout << "Program Mengecek Kata dan Kalimat Palindrom" << endl;
    cout << "Input Kata : ";
    getline(cin, kata);

    // Memasukan kata kedalam stack
    for (int i = 0; i < kata.length(); i++) {
        s.push(kata[i]);
    }

    // Mengecek apakah kata yang diinputkan polindrom
    bool palindrome = true;
    for (int i = 0; i < kata.length(); i++) {
        if (kata[i]!= s.top()) {
            palindrome = false;
            break;
        }
        s.pop();
    }

    if (palindrome) {
        cout << "Hasil : Kata/Kalimat Tersebut Palindrom" << endl;
    } else {
        cout << "Hasil : Kata/Kalimat Tersebut Bukan Palindrom" << endl;
    }

    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)

### 2. [Soal]

```C++
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string kalimat;
    stack<char> s;

    cout << "Program Mengubah Urutan Kalimat" << endl;
    cout << "Input Kalimat : ";
    getline(cin, kalimat);

    // Memasukan kalimat kedalam stack
    for (int i = 0; i < kalimat.length(); i++) {
        s.push(kalimat[i]);
    }

    // Mengeluarkan kalimat dari stack dan merubah urutan kalimat
    string reversed = "";
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }

    // Mencetak hasil urutan kalimat
    int start = 0;
    for (int i = 0; i < reversed.length(); i++) {
        if (reversed[i] == ' ') {
            cout << reversed.substr(start, i - start) << " ";
            start = i + 1;
        }
    }
    cout << reversed.substr(start) << endl;

    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] G. M. Putri, K. A. D. Pradja, M. B. Azizi, P. Nurwahid, A. S. Perdana, and M. ., “Implementasi Stack dan Array pada Pengurutan Lagu dengan Metode Selection Sort”, JTEKSIS, vol. 6, no. 2, pp. 286-296, Apr. 2024.
