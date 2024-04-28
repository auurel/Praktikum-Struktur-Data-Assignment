# <h1 align="center">Laporan Praktikum Modul Struct</h1>
<p align="center">Indy Aurellia Az Zahra</p>
<p align="center">2311110020</p>

## Dasar Teori

## Pengertian Struct

Dalam bahasa C++ ```struct``` merupakan struktur data yang memungkinkan terjadinya pembentukan tipe data baru dengan menggabungkan berbagai macam variabel dengan tipe data berbeda yang tersedia dalam C++. Tipe data yang baru dapat dibentuk diluar tipe data yang sudah ada dengan menggabungkan beberapa tipe data tersebut sesuai dengan program yang dibutuhkan.

Berbeda dengan ```array``` yang memungkinkan penyimpangan beberapa tipe data yang sama, ```struct``` dapat menyimpan dan menggabungkan berbagai variabel dengan tipe data yang berbeda. Misalkan data mengenai nama, NIM, program studi, dan universitas. Keempat data tersebut memiliki tipe data yang berbeda tetapi masih bisa digolongkan dalam satu kelompok yaitu data mahasiswa.

Berbagai variabel yang membangun suatu struktur juga disebut sebagai elemen atau anggota struktur. Penggunaan ```struct``` memudahkan pemetaan entitas dari sebuah kehidupan yang nyata ataupun suatu model dengan penyimpanan dan handling dalam C++.

## Notasi Struct

Notasi (syntax) struct dalam C++ terbilang mudah untuk dipahami dan digunakan. Tuliskan kata kunci "struct" tanpa petik pada awal kode dilanjutkan dengan nama struktur yang diinginkan seperti nama_struktur. Kemudian tambahkan berbagai variabel dengan berbagai tipe data berbeda yang diperlukan di dalam tanda kurung kurawal. Seanjutnya nama_struktur akan dianggap sebagai tipe data baru yang dapat digunakan dalam program.




## Guided 

### 1. Guided 1

Buatlah sebuah struktur dengan nama buku yang berisi judul_buku, pengarang, penerbit, tebal_halaman, harga_buku. Isi dengan nilai kemudian tampilkan.

```C++
#include <iostream>

using namespace std;

// Mendefinisikan struktur buku
struct buku {
    string judulBuku;
    string pengarang;
    string penerbit;
    int tebalHalaman;
    int hargaBuku;
};

int main() {
    // Mendeklarasikan variabel favorit dengan tipe buku
    buku favorit;

    // Mengisi data ke dalam variabel favorit
    favorit.judulBuku = "The Alpha Girl's Guide";
    favorit.pengarang = "Henry Manampiring";
    favorit.penerbit = "Gagas Media";
    favorit.tebalHalaman = 253;
    favorit.hargaBuku = 79000;

    // Menampilkan informasi buku favorit
    cout << "\tBuku Favorit Saya" << endl;
    cout << "\tJudul Buku : " << favorit.judulBuku << endl;
    cout << "\tPengarang : " << favorit.pengarang << endl;
    cout << "\tPenerbit : " << favorit.penerbit << endl;
    cout << "\tTebal Halaman: " << favorit.tebalHalaman << " halaman" << endl;
    cout << "\tHarga Buku : Rp " << favorit.hargaBuku << endl;
 
    return 0;
}
```

Kode di atas mendefinisikan struktur "buku" dan menampilkan informasi tentang buku favorite. Struktur "buku" memiliki enam atribut: "`judulBuku`", "`pengarang`", "`penerbit`", "`tebalHalaman`", dan "`hargaBuku`". Selanjutnya, program ini menampilkan informasi tentang buku favorite, termasuk judul, pengarang, penerbit, tebal halaman, dan harga buku. output dari program diatas adalah informasi tentang buku favorite yang diinputkan.

 
### 2. Guided 2

Buatlah sebuah struktur dengan skema seperti dibawah, isi dengan nilai kemudian jalankan.
![soal guided-2](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/fbb5f799-0eaa-429b-8aa4-19c9491e708c)


```C++
#include <iostream>
using namespace std;

struct hewan {
    string namaHewan;
    string jenisKelamin;
    string caraBerkembangbiak;
    string alatPernafasan;
    string tempatHidup;
    bool Karnivora;
};

struct hewanDarat {
    int jumlahKaki;
    bool menyusui;
    string suara;
};

struct hewanLaut {
    string bentukSirip;
    string bentukPertahananDiri;
};

int main() {
    hewanDarat kelinci; // Menggunakan tipe data hewanDarat untuk kelinci
    kelinci.jumlahKaki = 4;
    kelinci.menyusui = true;
    kelinci.suara = "Citcit";

    hewanLaut ikan; // Menggunakan tipe data hewanLaut untuk ikan
    ikan.bentukSirip = "Sirip ekor";
    ikan.bentukPertahananDiri = "Sisik";

    hewan serigala; // Tetap menggunakan tipe data hewan untuk serigala
    serigala.namaHewan = "Serigala";
    serigala.jenisKelamin = "Jantan";
    serigala.caraBerkembangbiak = "Melahirkan";
    serigala.alatPernafasan = "Paru-paru";
    serigala.tempatHidup = "Hutan terbuka";
    serigala.Karnivora = true;

    cout << "\t\tHewan" << endl;
    cout << "\t" << serigala.namaHewan << endl;
    cout << "\tJenis kelamin : " << serigala.jenisKelamin << endl;
    cout << "\tCara berkembangbiak : " << serigala.caraBerkembangbiak << endl;
    cout << "\tAlat pernafasan : " << serigala.alatPernafasan << endl;
    cout << "\tTempat hidup : " << serigala.tempatHidup << endl;
    cout << "\tKarnivora : " << (serigala.Karnivora ? "Yes" : "No") << endl << endl;

    cout << "\t\tHewan Darat" << endl;
    cout << "\tKelinci" << endl;
    cout << "\tJumlah kaki : " << kelinci.jumlahKaki << endl;
    cout << "\tMenyusui : " << (kelinci.menyusui ? "Yes" : "No") << endl;
    cout << "\tSuara : " << kelinci.suara << endl << endl;

    cout << "\t\tHewan Laut" << endl;
    cout << "\tIkan" << endl;
    cout << "\tBentuk sirip : " << ikan.bentukSirip << endl;
    cout << "\tBentuk pertahanan diri: " << ikan.bentukPertahananDiri << endl;

    return 0;
}
```

## Unguided 

### 1. Modifikasi tugas guided pertama, sehingga setiap item yang terdapat pada struct buku berupa array yang berukuran 5, isi dengan data kemudian tampilkan.

```C++
#include <iostream>
#include <string>

using namespace std;

struct Buku {
    string judul_buku[5];
    string pengarang[5];
    string penerbit[5];
    int tebal_halaman[5];
    double harga_buku[5];
};

void display(Buku buku) {
    for (int i = 0; i < 5; i++) {
        cout << "Judul Buku: " << buku.judul_buku[i] << endl;
        cout << "Pengarang: " << buku.pengarang[i] << endl;
        cout << "Penerbit: " << buku.penerbit[i] << endl;
        cout << "Tebal Halaman: " << buku.tebal_halaman[i] << endl;
        cout << "Harga Buku: " << buku.harga_buku[i] << endl;
        cout << "\n";
    }
}

int main() {
    Buku buku1;

    buku1.judul_buku[0] = "Buku 1";
    buku1.pengarang[0] = "Pengarang 1";
    buku1.penerbit[0] = "Penerbit 1";
    buku1.tebal_halaman[0] = 100;
    buku1.harga_buku[0] = 10000;

    buku1.judul_buku[1] = "Buku 2";
    buku1.pengarang[1] = "Pengarang 2";
    buku1.penerbit[1] = "Penerbit 2";
    buku1.tebal_halaman[1] = 200;
    buku1.harga_buku[1] = 20000;

    buku1.judul_buku[2] = "Buku 3";
    buku1.pengarang[2] = "Pengarang 3";
    buku1.penerbit[2] = "Penerbit 3";
    buku1.tebal_halaman[2] = 300;
    buku1.harga_buku[2] = 30000;

    buku1.judul_buku[3] = "Buku 4";
    buku1.pengarang[3] = "Pengarang 4";
    buku1.penerbit[3] = "Penerbit 4";
    buku1.tebal_halaman[3] = 400;
    buku1.harga_buku[3] = 40000;

    buku1.judul_buku[4] = "Buku 5";
    buku1.pengarang[4] = "Pengarang 5";
    buku1.penerbit[4] = "Penerbit 5";
    buku1.tebal_halaman[4] = 500;
    buku1.harga_buku[4] = 50000;
    // ... and so on for the other elements of the array

    display(buku1);

    return 0;
}
```
#### Output:
![unguided-1](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/fe8ef197-5bac-48d6-80b0-c6f14cbd357e)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.

[2] Dwi Putra, Muhammad T., et al. BELAJAR PEMROGRAMAN LANJUT DENGAN C++. Edited by Damayanti, Evi, CV WIDINA MEDIA UTAMA; 2023.