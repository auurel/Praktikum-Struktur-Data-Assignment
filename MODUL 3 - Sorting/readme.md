# <h1 align="center">Laporan Praktikum Algoritma Struktur Data</h1>
<p align="center">Indy Aurellia Az Zahra</p>

## Dasar Teori

### Sorting

Sorting atau pengurutan adalah proses menyusun elemen-elemen dari masukan awal acak menjadi keluaran akhir tertata dengan urutan tertentu. Proses tersebut diimplementasikan dalam bermacam aplikasi. Pengurutan memberikan fleksibilitas dalam penyajian data kepada penggunanya, pengguna dapat dengan mudah melakukan analisa dan memahami isi informasi yang terkandung didalam data tersebut.

Contoh sorting:
- Data acak       : 5 6 8 1 3 25 10
- Ascending       : 1 3 5 6 8 10 25
- Descending      : 25 10 8 6 5 3 1

### 1. Insertion sort

Salah satu algoritma sorting yang paling sederhana adalah insertion sort. Insertion Sort
disebut-sebut sebagai metode pertengahan. Artinya, metode ini memiliki kecepatan ratarata antara metode primitif (bubble dan selection) dan modern (merge dan quick).
Metode ini, didasarkan pada sebuah kunci yang diambil pada elemen ke-2 pada sebuah larik, lalu menyisipkan elemen tersebut jika kondisi percabangan terpenuhi. Metode penyisipan (insertion) bertujuan untuk menjadikan bagian sisi kiri larik terurutkan sampai dengan seluruh larik berhasil diurutkan


### 2. Merge sort

Merge sort adalah metode pengurutan yang menggunakan pola divide and conquer.
Strateginya adalah dengan membagi sekelompok data yang akan diurutkan menjadi beberapa kelompok kecil terdiri dari maksimal dua nilai untuk dibandingkan dan digabungkan lagi secara keseluruhan. 

Langkah kerja dari Merge sort:
1. Divide
Memilah elemen – elemen dari rangkaian data menjadi dua bagian dan mengulangi pemilahan hingga satu elemen terdiri maksimal dua nilai
2. Conquer
Mengurutkan masing-masing elemen
3. Kombinasi
Mengkombinasikan dua bagian tersebut secara rekursif untuk mendapatkan rangkaian data berurutan. Proses rekursi berhenti jika mencapai elemen dasar. Hal ini terjadi bilamana bagian yang akan diurutkan menyisakan tepat satu elemen. Sisa pengurutan satu elemen tersebut menandakan bahwa bagian tersebut telah terurut sesuai rangkaian.


### 3. Bubble sort

Merupakan metode sorting termudah, diberi nama “Bubble” karena proses pengurutan secara
berangsur- angsur bergerak/berpindah ke posisinya yang tepat, seperti gelembung yang keluar dari sebuah gelas bersoda. Bubble Sort mengurutkan data dengan cara membandingkan elemen sekarang dengan elemen berikutnya. Jika elemen sekarang lebih besar dari elemen berikutnya maka kedua elemen tersebut ditukar, jika pengurutan ascending. Jika elemen sekarang lebih kecil dari elemen berikutnya, maka kedua elemen tersebut ditukar, jika pengurutan descending. Algoritma ini seolah-olah menggeser satu per satu elemen dari kanan ke kiri atau kiri ke kanan, tergantung jenis pengurutannya. Ketika satu proses telah selesai, maka bubble sort akan mengulangi proses, demikian seterusnya. Kapan berhentinya? Bubble sort berhenti jika seluruh array telah diperiksa dan tidak ada pertukaran lagi yang
bisa dilakukan, serta tercapai perurutan yang telah diinginkan


### 4. Selection sort

Merupakan kombinasi antara sorting dan searching. Untuk setiap proses, akan dicari elemen-elemen yang belum diurutkan yang memiliki nilai terkecil atau terbesar akan dipertukarkan ke posisi yang tepat di dalam array. Misalnya untuk putaran pertama, akan dicari data dengan nilai terkecil dan data ini akan ditempatkan di indeks terkecil `(data[0])`, pada putaran kedua akan dicari data kedua terkecil, dan akan ditempatkan di indeks kedua `(data[1])`. Selama proses, pembandingan dan pengubahan hanya dilakukan pada indeks pembanding saja, pertukaran data secara fisik terjadi pada akhir proses.


### 5. Quick sort

Quick sort adalah sebuah algoritma pengurutan yang efisien dan sering digunakan. Hal ini karena quick sort beroperasi dengan prinsip divide and conquer.
Lebih detailnya, quick sort bekerja dengan memilih sebuah elemen dari array sebagai pivot. Setelah itu, quick sort mengatur ulang elemen-elemen lain dalam array. Dengan begitu, semua elemen dengan nilai lebih kecil dari pivot berada sebelumnya, sebaliknya juga sama.
Setelah pemisahan tersebut, pivot berada pada posisi akhirnya. Kemudian, proses ini akan diulangi secara rekursif untuk sub-array di kiri dan kanan pivot. Ini dilakukan sampai seluruh array menjadi terurut.


## Guided 

### 1. Mengurutkan secara ascending untuk data numerik bertipe double menggunakan Algoritma Bubble Sort

```C++
#include <iostream>

using namespace std;

void bubble_sort(double arr[], int length) {
    bool not_sorted = true;
    int j=0;
    double tmp;

    while (not_sorted) {
        not_sorted = false;
        j++;
        for (int i = 0; i < length - j; i++) {
            if (arr[i] > arr[i+1]) {
                tmp = arr[i];
                arr[i] = arr[i +1];
                arr[i + 1] = tmp;
                not_sorted = true;
            } // end of if
        } // end of for loop
    } // end of while loop
} // end of bubble_sort

void print_array(double a[], int length) {

    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {

    int length = 5;
    double a[] = {22.1, 15.3, 8.2, 33.21, 99,99};

    cout << "Urutan bilangan sebelum sorting: " << endl;
    print_array(a, length);

    bubble_sort(a, length);

    cout << "\nUrutan bilangan setelah sorting: " << endl;
    print_array(a, length);
}
```

#### Outuput

![Screenshot (1235)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/ed8b3a2e-921f-4d7a-b92f-d4676c00b677)

![Screenshot (1233)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/52cd8534-1b7e-4895-80b7-a1bf0d77fc17)

Kode diatas menunjukan algoritma pengurutan untuk mengurutkan array angka float (desimal) secara ascending. 
Fungsi `bubble_sort()` sendiri digunakan untuk mengambil array elemen panjang dan mengurutkannya ditempatnya.
Lalu variabel boolean `not_sorted` digunakan untuk melacak apakah ada pertukaran yang dilakukan selama iterasi loop, jika tidak ada pertukaran yang dilakukan, itu berarti array telah diurutkan dan loop dapat dihentikan.
Fungsi `print_array()` merupakan fungsi yang digunakan untuk mencetak konten array dengan elemen panjang konsol
Fungsi `main()` berfungsi untuk menginisialisasi array yang terdiri dari lima angka floating-point dan mencetaknya menggunakan fungsi `print_array()`


### 2. Mengurutkan karakter secara descending (dari terbesar hingga terkecil) menggunakan Algoritma Insertion Sort

``` C++
#include <iostream>

using namespace std;

void insertion_sort(char arr[], int length) {
    int i, j;
    char tmp;

    for (i = 1; i < length; i++) {
        j = 1;

        while (j > 0 && arr[j - 1] < arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        } // end of while loop
    } // end of for loop
}

void print_array(char a[], int length) {

    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}
int main() {

    int length = 6;
    char a[length] = {'c', 'f', 'a', 'z', 'd', 'p'};

    cout << "Urutan karakter sebelum sorting: " << endl;
    print_array(a, length);

    insertion_sort(a, length); 

    cout << "\nUrutan karakter setelah sorting: " << endl;
    print_array(a, length);
}
```

#### Output

![Screenshot (1236)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/e6d4999f-5353-4a88-b015-2d9dcfc933c6)

![Screenshot (1237)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/f7f9388c-eedf-431e-b91f-519d5b393a60)

Kode diatas mengimplementasikan algoritma sorting Insertion sort untuk mengurutkan array karakter. Fungsi `insertion_sort` sendiri adalah untuk menerima dua parameter, yaitu `arr` dan panjangnya `length`
Dalam fungsi `insertion_sort`, dilakukan perulangan untuk setiap elemen dalam array, kecuali elemen pertama. Untuk setiap elemen, dilakukan perulangan ke belakang sampai elemen tersebut berada di posisi yang tepat atau sampai ketemu elemen yang lebih kecil. Setiap perulangan, elemen yang lebih kecil digeser ke belakang, sampai elemen tersebut ditemukan.


## Unguided 


### 1. Kelas S1 IF 2016 G memiliki 5 mahasiswa. Pada akhir semester mereka menerima lembar Indeks Prestasi Semester (IPS), masing-masing mahasiswa tersebut memiliki IPS sebagai berikut: {3.8, 2.9, 3.3, 4.0, 2.4}. Buatlah program untuk mengurutkan IPS mahasiswa tersebut dari yang terbesar hingga terkecil dengan menggunakan algoritma Selection Sort! 

```C++
#include <iostream>
using namespace std;

void ipsmhs(float arr[], int length){
    float temp, minimum;
    int idx_min;
    for (int i = 0 ; i < length-1 ; i++){
        minimum = arr[i];
        idx_min = i;
        for(int j = i+1 ; j < length ; j++){
            if (minimum < arr[j]){
                minimum = arr[j];
                idx_min = j;
            }
        }
        temp = arr[idx_min];
        arr[idx_min] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    float arr[5] = {3.8, 2.9, 3.3, 4.0, 2.4};
    cout << "Before sorting: ";
    for(int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    cout << "\n";
    
    // Function call to sort the array using Selection Sort
    ipsmhs(arr, 5);
    
    cout << "After sorting: ";
    for(int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}
```

#### Output:

![Screenshot (1231)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/453bd5b5-6a3d-4549-81ed-aa7dd62a4689)

![Screenshot (1232)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/13a5d278-33d5-4ded-bdb3-15b53100a101)

Kode di atas adalah program yang mengurutkan array nilai IPS mahasiswa dengan menggunakan algoritma selection sort. Program ini memiliki fungsi `ipsmhs` (IPS Mahasiswa) yang menerima dua parameter yaitu array `arr` dan panjangnya `length`.
Dalam fungsi `ipsmhs`, dilakukan perulangan untuk mencari nilai minimum dan posisi index pada setiap iterasi. Untuk setiap iterasi, dilakukan perulangan lanjutan untuk membandingkan nilai dengan nilai yang lebih kecil dari index yang lebih besar. Jika nilai yang lebih kecil ditemukan, maka nilai minimum dan posisi indexnya akan diganti dengan nilai dan posisi indeks yang lebih kecil tersebut. Setelah perulangan lanjutan selesai, dilakukan operasi swap untuk menukar nilai antara posisi minimum dan posisi indeks saat ini.
Dalam fungsi `main`, dideklarasikan array `arr` dengan panjang 5 elemen dan nilai-nilainya. Kemudian, dilakukan pencetakan isi array sebelum dan sesudah diurutkan menggunakan fungsi `ipsmhs`.

Jumlah total operasi yang sudah dilakukan dalam algoritma selection sort adalah sekitar `n(n-1)/2`, yang dalam analisis Big O disederhanakan menjadi `O(n^2)` karena faktor terpenting ketika menentukan kompleksitas waktu adalah pangkat tertinggi dari `n`.


### 2. Pak RT memiliki 10 warga dengan nama: siti, situ, sana, ana, ani, caca, cici, dida, dodo, dan dadi. Supaya mudah dalam melakukan pencarian, Pak RT akan mengurutkan namanama tersebut sesuai dengan alfabet. Buatlah program untuk membantu Pak RT dengan menggunakan algoritma Bubble Sort! 

```C++
#include <iostream>
#include <string>
using namespace std;

void bubblesort(string arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    string arr[10] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};
    cout << "Before sorting: ";
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << "\n";

    // Function call to sort the array using Bubble Sort
    bubblesort(arr, 10);

    cout << "After sorting: ";
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}
```

#### Output:

![Screenshot (1230)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/90b22f56-7779-4e8a-adfa-0387edb00ef9)

![output 2](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/3206317f-f545-4fa5-b552-ce168f7be006)

Kode di atas merupakan program yang digunakan untuk mengurutkan sebuah array of string menggunakan metode Bubble Sort. Pada bagian awal program, kita mendeklarasikan fungsi bubblesort yang menerima dua parameter, yaitu array of string `arr` dan panjang array `n`. Dalam fungsi bubblesort, kita melakukan perulangan sebanyak `n-1` kali, yang mana pada setiap perulangan, kita akan membandingkan dua elemen string yang berdekatan. Jika kedua elemen tersebut tidak terurut, maka kita akan melakukan swap, sehingga elemen yang lebih besar akan dipindahkan ke posisi yang lebih belakang. Setelah fungsi bubblesort dipanggil di bagian main, kita akan mencetak isi array sebelum dan sesudah diurutkan, yang mana akan menunjukkan efektivitas dari metode Bubble Sort.

Kompleksitas waktu pada kode di atas adalah sekitar `O(n^2)`, di mana n merupakan jumlah elemen di dalam array yang akan diurutkan. Jumlah total operasi perbandingan dan pertukaran nilai dalam algoritma bubble sort adalah sekitar `n(n-1)/2`, yang menghasilkan kompleksitas waktu `O(n^2)`.


### 3. Buatlah program yang meminta user menginputkan suatu bilangan n dan meminta user untuk menginputkan sejumlah n karakter. Kemudian program akan melakukan sorting secara menaik (ascending) dan menurun (descending)! 

```C++
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Masukkan bilangan n: ";
    cin >> n;

    vector<char> arr(n);
    cout << "Masukkan " << n << " karakter: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nUrutan karakter secara menaik (ascending): ";
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n\nUrutan karakter secara menurun (descending): ";
    sort(arr.begin(), arr.end(), greater<char>());
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
```

#### Output

![Screenshot (1226)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/c5f7a82a-9780-4099-989f-e038b404b21f)

![Screenshot (1227)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/a3f3d2d1-f799-4e28-b50e-8afd7ff220fb)

Kode di atas meminta pengguna untuk memasukkan sebuah bilangan `n`, dan kemudian meminta pengguna untuk memasukkan `n karakter`. Setelah itu, program akan mengurutkan karakter tersebut dalam urutan menaik (ascending) dan menurun (descending). Pada bagian awal program, dilakukan include dari beberapa library yang dibutuhkan, yaitu `iostream`, `algorithm`, dan `vector`.
Deklarasi using namespace std; digunakan untuk mengakses semua nama dari standard namespace tanpa harus menuliskan std:: sebelumnya.
Pada bagian `int main()`, dilakukan input bilangan n menggunakan `cin`. Setelah itu, dideklarasikan sebuah vektor `arr` dengan panjang n, dan dilakukan input n karakter ke vektor tersebut. Lalu, dilakukan sorting karakter tersebut dalam urutan menaik menggunakan fungsi sort dari library algorithm, dengan parameter awal dan akhir dari vektor arr. Setelah itu, cetak urutan karakter yang telah diurutkan ke layar.
Selanjutnya, dilakukan sorting kembali karakter tersebut, tetapi ini kali pakai fungsi sort dengan parameter ketiga greater<char>(), yang akan mengurutkan karakter dalam urutan menurun. Cetak kembali urutan karakter yang telah diurutkan ke layar.

Kode di atas memiliki kompleksitas waktu `O(n^2)` untuk kedua fungsi ascending dan descending, di mana n merupakan jumlah elemen dalam array yang akan diurutkan. Perulangan pertama akan berjalan sebanyak n kali, sedangkan perulangan kedua  juga akan berjalan sebanyak n kali untuk setiap iterasi dari perulangan pertama. sebab itu, total jumlah operasi yang dilakukan adalah sekitar `n^2`, dan menghasilkan kompleksitas waktu `O(n^2)`.


## Kesimpulan
Sorting atau pengurutan adalah proses menyusun elemen – elemen dari masukan awal acak menjadi keluaran akhir tertata dengan urutan tertentu. Proses tersebut
diimplementasikan dalam bermacam aplikasi. Contoh penerapannya antara lain berupa rincian transaksi sesuai urutan tanggal dan jam pada perbankan, daftar hadir yang diurutkan berdasarkan nomor induk dan daftar pustaka yang diurutkan sesuai abjad pengarang ataupun katalog buku di perpustakaan. Fungsi-fungsi
statistik seperti median dan pembuatan kuartil data (quarter), desil dan percentil (percentile) mensyaratkan data untuk diurutkan terlebih dahulu.
Beberapa macam algoritma sorting telah dibuat karena proses tersebut sangat mendasar dan sering digunakan. Oleh karena itu, pemahaman atas algoritma – algoritma yang ada sangatlah berguna. Selain menjadi suatu aplikasi yang berdiri sendiri, pengurutan juga biasanya menjadi suatu bagian dari algoritma
yang lebih besar.

## Referensi
[1] Shalahudin, M dan Rosa. 2007. pemrograman dengan bahasa C++ dan Java  

[2] 2011. Rinaldi Munir, Algoritma Dan Pemrograman Dalam Bahasa Pascal dan C : Edisi Revisi

[3] Arief Hendra Saptadi, Desi Windi Sari, ANALISIS ALGORITMA INSERTION SORT, MERGE SORT DAN IMPLEMENTASINYA DALAM BAHASA PEMROGRAMAN C++
