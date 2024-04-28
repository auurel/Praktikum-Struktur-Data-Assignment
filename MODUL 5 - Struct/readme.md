# <h1 align="center">Laporan Praktikum Modul Struct</h1>
<p align="center">Indy Aurellia Az Zahra</p>
<p align="center">2311110020</p>

## Dasar Teori


## Pengertian Struct

Dalam bahasa C++ struct merupakan struktur data yang memungkinkan terjadinya pembentukan tipe data baru dengan menggabungkan berbagai macam variabel dengan tipe data berbeda yang tersedia dalam C++. Tipe data yang baru dapat dibentuk diluar tipe data yang sudah ada dengan menggabungkan beberapa tipe data tersebut sesuai dengan program yang dibutuhkan.

Berbeda dengan array yang memungkinkan penyimpangan beberapa tipe data yang sama, struct dapat menyimpan dan menggabungkan berbagai variabel dengan tipe data yang berbeda. Misalkan data mengenai nama, NIM, program studi, dan universitas. Keempat data tersebut memiliki tipe data yang berbeda tetapi masih bisa digolongkan dalam satu kelompok yaitu data mahasiswa.

Berbagai variabel yang membangun suatu struktur juga disebut sebagai elemen atau anggota struktur. Penggunaan struct memudahkan pemetaan entitas dari sebuah kehidupan yang nyata ataupun suatu model dengan penyimpanan dan handling dalam C++.

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

Kode di atas merupakan program yang mendefinisikan tiga struktur: 'hewan', 'hewanDarat', 'hewanLaut'. Masing-masing struktur mewakili hewan yang berbeda karakteristiknya.

Struktur 'hewan' mewakili hewan umum, dengan atribut-atribut berikut:
- 'namaHewan' : nama hewan
- 'jenisKelamin' : jenis kelamin hewan (jantan atau betina)
- 'caraBerkembangbiak' : cara hewan bereproduksi (misalnya bertelur, melahirkan)
- 'alatPernapasan' : sistem pernafasan hewan (misalnya, paru-paru, insang)
- 'tempatHidup' : habitat atau lingkungan hidup hewan
- 'Karnivora' : boolean yang menunjukan apakah hewan adalah karnivora (pemakan daging)

Struktur 'hewanDarat' mewakili hewan darat (hewan yang hidup di darat) dengan atribut-atribut berikut:
- 'jumlahKaki' : jumlah kaki hewan
- 'menyusui' : boolean yang menunjukkan apakah hewan menyusui anaknya
- 'suara' : suara atau vokalisasi hewan

Struktur 'hewanLaut' mewakili hewan laut (hewan yang hidup di air), dengan atribut-atribut berikut:
- 'bentukSirip' : bentuk sirip hewan
- 'bentukPertahananDiri' : mekanisme pertahanan diri hewan (misalnya, cangkang, duri)

Kemudian program tersebut mencetak atribut-atribut dari masing-masing hewan, menggunakan struktur untuk mengakses dan mencetak informasi yang relevan. Misalnya, untuk serigala, program mencetak nama, jenis kelamin, cara bereproduksi, sistem pernafasan, habitat, dan apakah hewan tersebut karnivora. Untuk kelinci, program mencetak jumlah kaki, apakah hewan menyusui anaknya, dan suara. Untuk ikan, program mencetak bentuk sirip dan mekanisme pertahanan diri.

Dalam keseluruhan, kode di atas menunjukkan bagaimana definisi dan penggunaan struktur untuk mewakili tipe data yang berbeda, serta bagaimana membuat instance dari struktur untuk mewakili objek yang spesifik.

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

    display(buku1);

    return 0;
}
```
#### Output:
![unguided-1](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/fe8ef197-5bac-48d6-80b0-c6f14cbd357e)

Kode di atas merupakan salah satu program yang menggunakan struktur 'Buku' untuk menyimpan informasi tentang beberapa buku dan kemudian menginisialisasi beberapa buku dan menampilkan informasi terkait buku-buku tersebut menggunakan fungsi 'display'

Struktur 'Buku' memiliki beberapa array untuk menyimpan informasi buku, yaitu:
- 'judul_buku' : array untuk menyimpan judul buku
- 'pengarang' : array untuk menyimpan nama pengarang
- 'penerbit' : array untuk menyimpan jumlah halaman buku
- 'tebal_halaman' : array untuk menyimpan jumlah halaman buku
- 'harga_buku' : array untuk menyimpan harga buku

Fungsi 'display' digunakan untuk menampilkan informasi buku yang telah disimpan di dalam struktur 'Buku'. Fungsi tersebut melakukan iterasi melalui array buku dan mencetak judul buku, pengarang, penerbit, tebal halaman, dan harga buku untuk setiap buku.

Di dalam fungsi 'main', program menginisialisasi variabel 'buku1' dari tipe 'Buku'. Lalu program mengisi informasi untuk lima buku yang berbeda kedalam array-array yang ada di dalam 'buku1'
Setelah semua informasi buku terisi, program memanggil fungsi 'display' dengan parameter 'buku1' untuk menamilkan informasi buku-buku yang telah diinisialisasi sebelumnya.
Dengan demikian, kode di atas bertujuan untuk menyimpan dan menampilkan informasi tentang beberapa buku menggunakan struktur dan array.


### 2.  Apa yang terjadi jika deklarasi variabel struct yang dibuat pada tugas guided I berjenis Array. Bagaimana cara mengisi data dan menampilkannya ?

Jika kita membuat guide I berjenis array, maka kode akan lebih sistematis karena array lebih cocok digunakkan untuk mengakses elemen-elemen yang memiliki indeks. Sedamgkan struct lebih cocok digunakan untuk mengakses field-field yang berbeda. Dalam syntax, array diinisialisasi dengan menggunakan kurung siku [], seperti int array[5];. Sedangkan struct diinisialisasi dengan menggunakan keyword struct, seperti struct Buku { string judul_buku; string pengarang; };.

Jika tugas guided Iberjenis array, maka berikut adalah cara mengisi data dan menampilkannya:

#### Deklarasi Struct Array
Deklarasi struct array dilakukan dengan menggunakan keyword 'struct' dan nama struct, diikuti oleh nama field yang akan diisi. 

```C++
struct Buku {
    string judul_buku[5];
    string pengarang[5];
    int tebal_halaman[5];
    double harga_buku[5];
};
```

#### Mengisi Data
Mengisi data struct array dilakukan dengan mengakses field-field menggunakan indeks. Contoh:

```C++
Buku buku1;

buku1.judul_buku[0] = "Buku 1";
buku1.pengarang[0] = "Pengarang 1";
buku1.tebal_halaman[0] = 100;
buku1.harga_buku[0] = 10000;

buku1.judul_buku[1] = "Buku 2";
buku1.pengarang[1] = "Pengarang 2";
buku1.tebal_halaman[1] = 200;
buku1.harga_buku[1] = 20000;
```

#### Menampilkan Data
Menampilkan data struct array dilakukan dengan mengakses field-field menggunakan index dan mencetak nilai-nilai yang tersimpan. Contoh:

```C++
void display(Buku buku) {
    for (int i = 0; i < 5; i++) {
        cout << "Judul Buku: " << buku.judul_buku[i] << endl;
        cout << "Pengarang: " << buku.pengarang[i] << endl;
        cout << "Tebal Halaman: " << buku.tebal_halaman[i] << endl;
        cout << "Harga Buku: " << buku.harga_buku[i] << endl;
        cout << endl;
    }
}

int main() {
    Buku buku1;

    // Mengisi data
    buku1.judul_buku[0] = "Buku 1";
    buku1.pengarang[0] = "Pengarang 1";
    buku1.tebal_halaman[0] = 100;
    buku1.harga_buku[0] = 10000;

    // Menampilkan data
    display(buku1);

    return 0;
}
```


## Kesimpulan

- Pemakaian struktur data yang tepat di dalam proses pemrograman akan menghasilkan algoritma yang lebih jelas dan tepat, sehingga menjadikan program secara keseluruhan lebih efisien dan sederhana

- Secara umum struktur data terdiri dari beberapa bagian seperti himpunan nilai-nilai datadan sejumlah operasi dasar yang bekerja pada data tersebut menurut suatu algoritma tertentu


## Referensi

[1] Dwi Putra, Muhammad T., et al. BELAJAR PEMROGRAMAN LANJUT DENGAN C++. Edited by Damayanti, Evi, CV WIDINA MEDIA UTAMA; 2023.