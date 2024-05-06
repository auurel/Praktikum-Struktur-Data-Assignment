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

#### Output

![Screenshot (1383)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/8bee933f-9fd5-4d64-bfef-efed844b5796)

Kode di atas menunjukkan fungsi-fungsi yang dilakukan pada stack array buku.
- Push Array Buku: Fungsi ini menambahkan data ke stack. Contohnya data "Kalkulus", "Struktur Data", "Matematika Diskrit", "Dasar Multimedia", dan "Inggris" ditambahkan ke stack.
- Cetak Array Buku: Fungsi ini mencetak semua data yang ada di stack.
  Dalam contoh, semua data yang telah ditambahkan ke stack dicetak.
- Apakah Data Stack Penuh?: Fungsi ini memeriksa apakah stack sudah penuh.
  Dalam contoh, stack masih memiliki ruang untuk menambahkan data lain.
- Apakah Data Stack Kosong?: Fungsi ini memeriksa apakah stack sudah kosong.
  Dalam contoh, stack masih memiliki data yang ditambahkan sebelumnya.
- Peek Array Buku: Fungsi ini menampilkan data di posisi yang ditentukan.
  Dalam contoh, data di posisi ke-2 ("Matematika Diskrit") ditampilkan.
- Pop Array Buku: Fungsi ini menghapus data di posisi yang ditentukan.
  Dalam contoh, data di posisi ke-2 ("Matematika Diskrit") dihapus.
- Banyaknya Data: Fungsi ini mencetak jumlah data yang ada di stack.
  Dalam contoh, jumlah data yang ada di stack adalah 4.
- Change Array Buku: Fungsi ini mengubah data di posisi yang ditentukan.
  Dalam contoh, data di posisi ke-2 diubah menjadi "Bahasa Jerman".
- Destroy Array Buku: Fungsi ini menghapus semua data di stack dan mengembalikan stack ke kondisi awal.
  Dalam contoh, semua data di stack dihapus dan jumlah data di stack menjadi 0.
- Cetak Array Buku (Setelah Destroy): Fungsi ini mencetak semua data yang ada di stack.
  Dalam contoh, tidak ada data yang dicetak karena stack sudah kosong.

  
## Unguided 

### 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.

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

![Screenshot (1382)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/ec86da1f-56f0-40f0-af01-27dcc79110bb)


Kode di atas digunakan untuk mengecek apakah sebuah kata atau kalimat adalah palindrom atau tidak. Palindrom adalah kata atau kalimat yang dibaca dari depan dan belakang sama.
Kode tersebut menggunakan stack untuk memasukkan setiap karakter dari kata yang diinputkan dan kemudian membandingkan setiap karakter dengan karakter yang terakhir ditambahkan ke stack. Jika setiap karakter cocok, maka kata/kalimat tersebut adalah palindrom.
Output dari kode tersebut akan menampilkan hasil pengecekan apakah kata yang diinputkan adalah palindrom atau tidak. Jika kata tersebut adalah palindrom, maka output akan berupa "Kata/Kalimat Tersebut Palindrom". Jika tidak, maka output akan berupa "Kata/Kalimat Tersebut Bukan Palindrom". 

Dalam contoh di atas, "isi" adalah palindrom karena dibaca dari depan dan belakang sama, sedangkan "orel orel" bukan palindrom karena jika dibaca dari depan atau belakang tidak sama.

#### Full code Screenshot:

![Screenshot (1382)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/1074c42f-223b-4b53-9241-06890863ef4e)


### 2. Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?

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
![Screenshot (1381) unguided-2](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/5105bc21-7bda-4ea0-9ccf-a8b0f45c1bc7)


Kode di atas digunakan untuk mengubah urutan kalimat yang diinputkan. Kode tersebut menggunakan stack untuk memasukkan setiap karakter dari kalimat dan kemudian mengeluarkan karakter-karakter tersebut dari stack untuk mengubah urutan kalimat.
Output dari kode tersebut akan menampilkan kalimat yang diinputkan dengan urutan yang dibalikkan. Jika input adalah "", maka output akan berupa "dlroW olleH".

Contoh output jika input adalah "orel membeli bubur"
Dalam contoh di atas, kalimat "orel membeli bubur" diinputkan dan kemudian urutan kalimat dibalikkan menjadi "rubub ilebmem lero".

#### Full code Screenshot:

![Screenshot (1381)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/5f5f0350-ae7b-4272-9851-4521c79c9533)


## Kesimpulan
Stack adalah suatu koleksi atau kumpulan item data yang terorganisasi dalam bentuk urutan linier, yang operasi pemasukan dan penghapusan datanya dilakukan pada salah satu sisinya. Karakteristik khas dari stack adalah penggunaan aturan LIFO (Last In, First Out). Artinya, data yang terakhir dimasukkan ke dalam stack akan menjadi data pertama yang diambil atau dikeluarkan. 

## Referensi
[1] G. M. Putri, K. A. D. Pradja, M. B. Azizi, P. Nurwahid, A. S. Perdana, and M. ., “Implementasi Stack dan Array pada Pengurutan Lagu dengan Metode Selection Sort”, JTEKSIS, vol. 6, no. 2, pp. 286-296, Apr. 2024.
[2] Anita Sindar, R. M. S. (2019). Struktur Data Dan Algoritma Dengan C++ (Vol. 1). CV. AA. RIZKY.
[3] Sulasmoro, A. H. (2022). Buku ajar algoritma dan pemrograman I. Penerbit P4I.
