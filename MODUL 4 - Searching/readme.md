# <h1 align="center">Laporan Praktikum Modul Searching</h1>
<p align="center">Indy Aurellia Az Zahra</p>

## Dasar Teori
Algoritma pencarian (searching algorithm) adalah algoritma yang menerima sebuah argumen kunci dan dengan langkah-langkah tertentu akan mencari elemen data dengan kunci tersebut. Setelah proses pencarian dilaksanakan, akan diperoleh salah satu dari dua kemungkinan, yaitu data yang dicari ditemukan (successful) atau tidak ditemukan (unsuccessful). Searching juga dapat dianggap sebagai proses pencarian suatu data di dalam sebuah array dengan cara mengecek satu persatu pada setiap index baris atau setiap index kolomnya dengan menggunakan teknik perulangan untuk melakukan pencarian data.
Ada 2 metode yang terdapat pada algoritma Searching yaitu:


A. Sequential Search
        
Sequential Searching merupakan algoritma pencarian beruntun  yang  prosesnya  membandingkan  setiap elemen  satu  persatu  secara  beruntun,  mulai  dari elemen  pertama  sampai  elemen  yang  di  cari  di temukan  atau  seluruh  elemen  sudah  di  periks. Sequential search termasuk kedalam teknik pencarian data array yang paling mudah, dimana data dalam array dibaca satu demi satu dan diurutkan dari index terkecil ke index terbesar, maupun sebaliknya. Pencarian terhadap elemen data array dapat dalam kondisi belum terurut dan sudah terurut.
        
Perbedaanya dapat dirincikan seperti berikut :
- Data yang belum terurut :
    - (a) Secara umum pencarian berjalan dengan relatif lambat.
    - (b) Waktu pencarian sebanding dengan jumlah elemen array.
- Data yang sudah terurut :
    - (a) Dapat meningkatkan kinerja pencarian.
    - (b) Karena dapat segera menyimpulkan bahwa data yang dicari tidak terdapat di dalam array bila ditemukan
          terhadap elemen data array yang dicari


B. Binary Search

Algoritma binary search merupakan salah satu algoritma yang digunakan untuk melakukan proses pencarian data yang sudah terurut. Jika data belum terurut maka harus dilakukan proses pengurutan (sorting) terlebih dahulu. Yang artinya proses pencarian data tidak akan dapat dilakukan jika data tidak terurut.

Langkah-langkah pengerjaan dari teknik pencarian biner dapat dijelaskan sebagai berikut:
- Mula-mula diambil posisi awal 0 dan posisi akhir = N – 1
- Menentukan posisi data tengah dengan rumus (posisi awal + posisi akhir) / 2.
- Elemen Data yang dicari dibandingkan dengan elemen data tengah.
- Jika lebih kecil, proses dilakukan kembali tetapi posisi akhir dianggap sama dengan posisi tengah –1.
- Jika lebih besar, porses dilakukan kembali tetapi posisi awal dianggap sama dengan posisi tengah + 1. Demikian seterusnya sampai data tengah sama dengan yang dicari.


## Guided 

### 1. Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data

```C++
#include <iostream>
using namespace std;
int main () {
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;
    // Algoritma Sequential Search
    for (i = 0; i < n; i++) {
        if(data[i] == cari) {
            ketemu = true;
            break;
        }
    }
        cout << "\t Program Sequential Search Sederhana\n" << endl;
        cout << "data: {9 , 4, 1, 7, 5, 12, 4, 13, 4, 10}\n" << endl;
    if (ketemu) {
        cout << "angka " << cari << " ditemukan pada indeks ke-" << i << endl;
    } else {
        cout << cari << "tidak dapat ditemukan pada data." << endl;
    }
    return 0;
}
```
Kode diatas merupakan contoh program yang menggunakan algoritma Sequential Search untuk mencari sebuah angka dalam sebuah array. Program ini memiliki variabel `n` yang berisi nilai 10, yang akan digunakan sebagai ukuran array data. Array data diisi dengan beberapa angka, salah satunya adalah angka yang akan dicari, yang disimpan dalam variabel `cari`.
Program menggunakan perulangan `for` untuk melakukan pencarian angka `cari` dalam array `data`. Jika angka `cari` ditemukan, variabel `ketemu` akan diatur menjadi `true`, dan perulangan akan dihentikan dengan perintah `break`. Jika angka `cari` tidak ditemukan, variabel `ketemu` akan tetap `false`.
Setelah perulangan selesai, program akan menampilkan hasil pencarian. Jika angka `cari` `ditemukan`, program akan menampilkan pesan `"angka [cari] ditemukan pada indeks ke-[i]"`. Jika angka `cari` `tidak ditemukan`, program akan menampilkan pesan `"angka [cari] tidak dapat ditemukan pada data"`.
Program ini menggunakan algoritma Sequential Search, yang merupakan algoritma pencarian yang sederhana yang mencari sebuah elemen dalam sebuah koleksi secara linear. `Jika angka yang dicari tidak ditemukan, maka algoritma akan mengembalikan indeks -1.`


### 2. Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search

```c++
#include <iostream>
#include <conio.h>
#include <iomanip> 
using namespace std;

int data[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void selection_sort()
{
    int temp, min, i, j;

    for (i=0; i<7;i++)
    {
        min = i;
        for(j = i+1; j<7; j++)
        {
            if(data[j]<data[min])
            {
                min=j;
            }
        }
        temp = data[i];
        data[i] = data[min];
        data[min] = temp;
    }
}

void binarysearch ()
{
    //searching
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = 7;
    while (b_flag == 0 && awal<=akhir)
    {
        tengah = (awal + akhir) /2;
        if(data[tengah] == cari)
        {
            b_flag = 1;
            break;
        }
        else if(data[tengah] < cari)
            awal = tengah + 1;
        else
            akhir = tengah -1;
    }
        if(b_flag == 1)
            cout <<"\n   Data ditemukan pada index ke-" << tengah << endl;
        else
            cout <<"\n Data tidak ditemukan\n";
}

int main()
{
    cout << "\t     BINARY SEARCH   " << endl;
    cout << "\n Data        : ";
    //tampilkan data awal
    for(int x = 0; x<7; x++)
        cout << setw(3) << data[x];
    cout << endl;

    cout << "\n Masukkan data yang ingin anda cari  :   ";
    cin >> cari;
    cout << "\n Data diurutkan  :   ";
    // Urutkan data dengan selection sort
    selection_sort();
    // Tampilkan data setelah diurutkan
    for(int x = 0; x<7; x++)
        cout << setw(3) << data[x];

    cout << endl;

        binarysearch();

    _getche();
    return EXIT_SUCCESS;
}
```
Kode diatas merupakan contoh program yang menggunakan algoritma Binary Search untuk mencari sebuah angka dalam sebuah array. Program diatas mempunyai variabel data yang berisi beberapa angka, yang salah satunya adalah angka yang akan dicari, yang disimpan dalam variabel `cari`.
Program menggunakan fungsi `selection_sort` untuk mengurutkan angka dalam array data melalui algoritma Selection Sort. Setelah angka ditemukan, program akan menampilkan hasil pencarian. Jika angka `cari` `ditemukan`, program akan menampilkan pesan `"Data ditemukan pada index ke-[tengah]"`. Jika angka `cari` `tidak ditemukan`, program akan menampilkan pesan `"Data tidak ditemukan"`.
Program ini menggunakan algoritma Binary Search, yang merupakan algoritma pencarian yang efisien yang mencari sebuah elemen dalam sebuah koleksi. Jika angka yang dicari tidak ditemukan, maka algoritma akan mengembalikan indeks -1.



## Unguided 

### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!

```C++
#include <iostream>
#include <string>
using namespace std;

int binarySearch(string arr, char x) {
    int kiri = 0, kanan = arr.length() - 1;
    while (kiri <= kanan) {
        int mid = kiri + (kanan - kiri) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            kiri = mid + 1;
        else
            kanan = mid - 1;
    }
    return -1;
}

int main() {
    string arr;
    char x;
    cout << "Enter the string: ";
    getline(cin, arr);
    cout << "Enter the character to search: ";
    cin >> x;
    int result = binarySearch(arr, x);
    if (result == -1)
        cout << "Character not found";
    else
        cout << "Character found at index " << result;
    return 0;
}
```

#### Output:
![Unguided-1 output](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/9bb5baf3-915c-41e1-a3cb-c9eeac9b2283)

Kode diatas merupakan contoh program yang menggunakan algoritma Binary Search untuk mencari sebuah huruf dalam sebuah kalimat. Program ini memiliki variabel `arr` yang berisi sebuah kalimat, yang akan dicari huruf, yang disimpan dalam variabel `x`.
Program menggunakan fungsi `binarySearch` untuk mencari huruf `x` dalam kalimat `arr` melalui algoritma Binary Search. Setelah huruf ditemukan, program akan menampilkan hasil pencarian. Jika huruf `x` `ditemukan`, program akan menampilkan pesan `"Character found at index [result]"`. Jika huruf `x` `tidak ditemukan`, program akan menampilkan pesan `"Character not found"`.
Program ini menggunakan algoritma Binary Search, yang merupakan algoritma pencarian yang efisien. Jika huruf yang dicari tidak ditemukan, maka algoritma akan mengembalikan indeks -1.

#### Full code Screenshot:
![Unguided-1](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/18ed1406-2e36-410b-9023-d5a39b088229)


### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!

```C++
#include <iostream>
#include <string>
using namespace std;

int countVokal(string sentence) {
    int count = 0;
    for (char c : sentence) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }
    return count;
}

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    int result = countVokal(sentence);
    cout << "Banyaknya huruf vokal : " << result << endl;
    return 0;
}
```
#### Output:
![Unguided-2 output](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/83505385-25d1-42ee-964f-5c57325278f5)

Kode diatas merupakan program yang digunakan untuk mencari dan menghitung jumlah huruf vokal dalam sebuah kalimat. Program ini memiliki variabel sentence yang berisi sebuah kalimat, yang akan dicari huruf vokalnya.
Program menggunakan fungsi `countVokal` untuk mencari dan menghitung jumlah huruf vokal dalam kalimat `sentence`. Fungsi ini menggunakan perulangan `for` untuk melakukan pencarian setiap huruf dalam kalimat `sentence`. Jika huruf tersebut adalah `huruf vokal`, maka variabel `count` akan `diincrement`.
Setelah pencarian selesai, program akan menampilkan hasil pencarian. Outputnya akan menampilkan pesan `"Banyaknya huruf vokal : [result]"`, dimana result adalah jumlah huruf vokal yang ditemukan dalam kalimat `sentence`.

Dalam contoh diatas, program menghitung banyaknya huruf vokal dalam kalimat "halo aku aurel", yang berisikan 7 huruf vokal.

#### Full code Screenshot:
![Screenshot (1258)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/ce58212a-eb1d-4688-a696-ed28ede01acb)


### 3. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!

```C++
#include <iostream>
using namespace std;

int sequentialSearch(int arr[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            count++;
        }
    }
    return count;
}

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int n = sizeof(data) / sizeof(data[0]);
    int x = 4;
    int result = sequentialSearch(data, n, x);
    cout << "Number of occurrences of " << x << ": " << result << endl;
    return 0;
}
```
#### Output:
![Unguided-3 output](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/e2bb4e82-66e6-438c-b4af-cf6f62827bc6)

Kode diatas merupakan program Sequential Search untuk mencari sebuah angka dalam sebuah array. Program ini memiliki variabel data yang berisi beberapa angka, yang akan dicari angka `x`.
Program menggunakan fungsi `sequentialSearch` untuk mencari angka `x` dalam array data melalui algoritma Sequential Search. Fungsi ini menggunakan perulangan `for` untuk melakukan pencarian setiap elemen dalam array data. Jika angka tersebut adalah angka `x`, maka variabel `count` akan `diincrement`.
Setelah pencarian selesai, program akan menampilkan hasil pencarian. Outputnya akan menampilkan pesan `"Number of occurrences of [x]: [result]"`, dimana result adalah jumlah angka `x` yang ditemukan dalam array data.

Dalam contoh diatas, program menghitung banyaknya angka 4 yang ditemukan dalam array data, dan jumlah angka 4 dalam array sebanyak 4

#### Full code Screenshot:
![Unguided-3](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/1d305dc2-536d-40aa-a4eb-e7fa8f11c2ed)


## Kesimpulan
Algoritma search adalah serangkaian langkah atau instruksi yang digunakan untuk mencari elemen atau informasi tertentu di dalam suatu dataset. Tujuannya adalah untuk menemukan posisi atau keberadaan elemen yang dicari. Dalam pemrograman, algoritma search menjadi salah satu teknik penting dalam menyelesaikan berbagai masalah. Ada berbagai macamm jenis algoritma search antara lain, sequential search dan binary search.

Algoritma Sequential Searching merupakan metode pencarian data yang paling sederhana. Metode pencarian ini lebih mudah dan sederhana dibandingkan dengan Binary Searching. Sehingga akan memudahkan pemrogram dalam menyelesaikan masalah. Algoritma Sequential Searching juga dapat digunakan untuk mencari data pada array dengan elemen data yang tidak berurutan. Sedangkan algoritma Binary Searching digunakan untuk mencari data pada array dengan data yang sudah terurut. Algoritma Binary Search mampu menemukan data yang ingin dicari dengan pilihan kriteria tertentu dan pengisian kata kunci dari data
yang ingin dicari.


## Referensi
[1] A. Sonita and M. Sari, “Implementasi Algoritma Sequential Searching Untuk Pencarian Nomor Surat Pada Sistem Arsip Elektronik”, pseudocode, vol. 5, no. 1, pp. 1–9, Feb. 2018.

[2] Sitompul, B.J., Yusupa, A. and Tuturoong, N.J. (2022) ‘Implementasi Algoritma binary search pada pencarian data Jemaat Gereja HKBP Manado’, Jurnal Informatika Polinema, 9(1), pp. 17–24. doi:10.33795/jip.v9i1.1123. 

[3] JOHNSON SIHOMBING, “RUNNING TIME ALGORITMA SEARCHING DATA PADA ARRAY SATU DIMENSI MENGGUNAKAN JAVA NETBEANS”, INFOKOM, vol. 6, no. 1, pp. 51-65, Jun. 2018.

[4] C. R. STmEng, Algoritma pemrograman dan struktur data menggunakan C++. 2020.
