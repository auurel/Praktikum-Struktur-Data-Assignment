# <h1 align="center">Laporan Praktikum Modul Rekursif</h1>
<p align="center">Indy Aurellia Az Zahra</p>
<p align="center">2311110020</p>

## Dasar Teori

Fungsi rekursi (Recursive Function) adalah suatu fungsi yang memanggil dirinya sendiri, artinya fungsi tersebut dipanggil didalam tubuh fungsi itu sendiri. Fungsi yang seperti ini disebut fungsi rekursif (recursive function ). Dalam sebuah fungsi rekursif pemanggilan dapat terjadi berulang kali. Karena ada proses yang berulang-ulang maka harus ada suatu kondisi yang mengakhiri prosesnya. Jika tidak, maka proses tidak akan pernah berhenti sampai memori yang digunakan tidak dapat menampung lagi.

#### Kelebihan 
- Kode rekursif menyajikan solusi yang mudah dimengerti dan bersih, menignkatkan kejelasan
- Rekursi terbukti efektif untuk menangani masalah yang dapat diuraikan menjadi subtugas-serupa, seperti penjelajahan struktur data pohon.
- Dalam beberapa kasus, solusi rekursif dapat memberikan kode yang lebih elegan dan lebih kompak dibandingkan dengan pendekatan iteratif

#### Kekurangan
- Efisiensi ruang menjadi masalah utama dalam rekursi karena setiap panggilan rekursif menambah overhead pada call stack
- Beberapa implementasi rekursif mungkin kurang efisien secara waktu, terutama ketika terdapat overhead pemanggilan fungsi
- Kesulitan dalam pemahaman konsep rekursi oleh beberapa programmer dapat memunculkan potensi bug dan kompleksitas pemecahan masalah


## Guided

### 1. Rekursif Langsung (Direct Recursion) 

```C++
#include <iostream>

using namespace std;

void countdown(int n) {
    if (n == 0) {
        return;
    }

    cout << n << " ";
    countdown(n - 1);
}

int main() {
    cout << "Rekursif langsung: ";
    countdown(5);
    cout << endl;
    return 0;
}
```

Kode di atas adalah contoh program yang menggunakan rekursif langsung untuk mencetak bilangan dari 5 ke bawah. Rekursif langsung adalah teknik di mana fungsi memanggil dirinya sendiri secara langsung.

Dalam kode di atas, terdapat dua fungsi: 'countdown' dan 'main'. Fungsi 'main' memanggil fungsi 'countdown' dengan argumen 5. Fungsi 'countdown' mencetak nilai 'n' dan kemudian memanggil dirinya sendiri dengan argumen 'n - 1' hingga 'n' menjadi 0.

#### Output 
```c++
Rekursif Langsung: 5 4 3 2 1
```

### 2. Rekursif Tidak Langsung (Indirect Recursion)

```C++
#include <iostream>

using namespace std;

void functionB(int n);

void functionA(int n) {
    if (n > 0) {
        cout << n << " ";
        functionB(n-1);
    }
}

void functionB(int n) {
    if (n > 0) {
        cout << n << " ";
        functionA(n / 2);
    }
}

int main() {
    int num = 5;
    cout << "Rekursif tidak langsung: ";
    functionA(num);
    return 0;
}
```

Kode di atas merupakan contoh program yang menggunakan rekursif tidak langsung untuk mencetak bilangan dari 5 ke bawah. Rekursif tidak langsung adalah teknik di mana fungsi memanggil dirinya sendiri secara tidak langsung melalui fungsi lain.

Dalam kode di atas, terdapat tiga fungsi: 'functionA', 'functionB', dan 'main'. Fungsi 'main' memanggil fungsi 'functionA' dengan argumen 'num' yang bernilai 5. Fungsi 'functionA' mencetak nilai 'n' dan kemudian memanggil fungsi 'functionB' dengan argumen 'n-1'. Fungsi 'functionB' mencetak nilai 'n' dan kemudian memanggil fungsi 'functionA' dengan argumen 'n / 2'.

#### Output 
```c++
Rekursif Tidak Langsung: 5 4 2 1
```


## Unguided 

### 1.	Buatlah sebuah program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif!

### Contoh Output:

#### Masukkan bilangan bulat positif: 5
#### Faktorial dari 5 adalah: 120


```C++
#include <iostream>

using namespace std;

// Fungsi rekursif untuk menghitung faktorial
int faktorial(int n) {
    // Kondisi base untuk menghentikan rekursif
    if (n == 0 || n == 1) {
        return 1;
    } else {
        // Fungsi rekursif untuk menghitung faktorial
        return n * faktorial(n - 1);
    }
}

int main() {
    int num;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> num;

    // Cek apakah inputan adalah bilangan bulat positif
    if (num > 0) {
        cout << "Faktorial dari " << num << " adalah: " << faktorial(num) << endl;
    } else {
        cout << "Inputan harus bilangan bulat positif." << endl;
    }

    return 0;
}
```

#### Output:
![Rekursif Unguided-1](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/c121cb1e-0d31-4e79-983c-0f66b3490ca8)

Kode di atas merupakan contoh program yang menggunakan rekursif langsung untuk menghitung nilai faktorial dari sebuah inputan bilangan bulat positif.

Program ini terdiri dari dua bagian utama: fungsi 'faktorial' dan fungsi 'main'.

Fungsi 'faktorial' digunakan untuk menghitung nilai faktorial dari sebuah bilangan 'n'. Fungsi ini menggunakan rekursif langsung, di mana nilai faktorial dari sebuah bilangan 'n' dihitung dengan mengalikan 'n' dengan nilai faktorial dari bilangan '(n - 1)'. Kondisi base untuk menghentikan rekursif adalah ketika 'n' menjadi 0 atau 1, di mana nilai faktorial dari 0 atau 1 adalah 1.

Fungsi 'main' meminta inputan bilangan bulat positif dari user dan kemudian memanggil fungsi 'faktorial' untuk menghitung nilai faktorial dari inputan tersebut. Jika inputan bukan bilangan bulat positif, program akan menampilkan pesan kesalahan.

Proses rekursif langsung berjalan sebagai berikut:
- Fungsi 'faktorial' dipanggil dengan argumen 'n'.
- Fungsi 'faktorial' mencari kondisi base untuk menghentikan rekursif, yaitu ketika 'n' menjadi 0 atau 1.
- Jika 'n' tidak menjadi 0 atau 1, fungsi 'faktorial' memanggil dirinya sendiri dengan argumen 'n - 1'.
- Proses ini berulang hingga 'n' menjadi 0 atau 1.
- Ketika 'n' menjadi 0 atau 1, fungsi 'faktorial' mengembalikan nilai 1, yang kemudian digunakan untuk menghitung nilai faktorial dari bilangan sebelumnya.


### 2.	Buatlah versi program Rekursif Tidak Langsung (Indirect Recursion) dari soal nomor 1 diatas!

```C++
#include <iostream>

using namespace std;

// Fungsi untuk menghitung faktorial
int faktorial(int n, int result = 1) {
    // Kondisi base untuk menghentikan rekursif
    if (n == 0) {
        return result;
    } else {
        // Fungsi rekursif untuk menghitung faktorial
        return faktorial(n - 1, n * result);
    }
}

int main() {
    int num;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> num;

    // Cek apakah inputan adalah bilangan bulat positif
    if (num > 0) {
        cout << "Faktorial dari " << num << " adalah: " << faktorial(num) << endl;
    } else {
        cout << "Inputan harus bilangan bulat positif." << endl;
    }

    return 0;
}
```

#### Output:
![Rekursif Unguided-2](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/d5e9199c-26d6-4a35-b4d3-f3c1bfc7a678)

Kode di atas merupakan contoh program yang menggunakan rekursif tidak langsung untuk menghitung nilai faktorial dari sebuah inputan bilangan bulat positif.

Program ini terdiri dari dua bagian utama: fungsi 'faktorial' dan fungsi 'main'.

Fungsi 'faktorial' digunakan untuk menghitung nilai faktorial dari sebuah bilangan 'n'. Fungsi ini menggunakan rekursif tidak langsung, di mana nilai faktorial dari sebuah bilangan 'n' dihitung dengan mengalikan 'n' dengan nilai 'faktorial' dari bilangan '(n - 1)'. Kondisi base untuk menghentikan rekursif adalah ketika 'n' menjadi 0, di mana nilai faktorial dari 0 adalah hasil akhir dari proses rekursif.

Fungsi 'main' meminta inputan bilangan bulat positif dari pengguna dan kemudian memanggil fungsi 'faktorial' untuk menghitung nilai faktorial dari inputan tersebut. Jika inputan bukan bilangan bulat positif, program akan menampilkan pesan kesalahan.

Proses rekursif tidak langsung berjalan sebagai berikut:

- Fungsi 'faktorial' dipanggil dengan argumen 'n' dan result yang bernilai 1.
- Fungsi 'faktorial' mencari kondisi base untuk menghentikan rekursif, yaitu ketika 'n' menjadi 0.
- Jika 'n' tidak menjadi 0, fungsi 'faktorial' memanggil dirinya sendiri dengan argumen 'n - 1' dan mengalikan 'n' dengan 'result'.
- Proses ini berulang hingga 'n' menjadi 0.
- Ketika 'n' menjadi 0, fungsi 'faktorial' mengembalikan nilai 'result', yang adalah hasil akhir dari proses rekursif.


## Kesimpulan


## Referensi
[1] Sjukani M, “Struktur data dengan C++(Algoritma dan Struktur Data 2 dengan C, C++)”, Mitra Wacana Media, 2007

[2] Kristanto Andri, “Algoritma dan Pemrograman dengan C++”, Graha Ilmu, 2003