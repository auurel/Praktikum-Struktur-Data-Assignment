# <h1 align="center">Laporan Praktikum Modul Algoritma Struktur Data</h1>
<p align="center">Indy Aurellia Az Zahra</p>

## Dasar Teori

Array merupakan kumpulan-kumpulan variabel yang menyimpan data dengan tipe yang sama atau data-data yang tersusun secara linear dimana di dalamnya terdapat elemen dengan tipe yang sama. Indeks dalam array menyatakan elemen yang disimpan dan panjang atau length menyatakan total elemen yang tersimpan. Ada beberapa jenis array yang perlu kita ketahui, diantaranya:

1.	Array satu dimensi
Array satu dimensi adalah kumpulan elemen-elemen identik yang tersusun dalam satu baris, tetapi isi dari elemen tersebut boleh berbeda.  Dapat disebut juga dengan istilah vektor yang menggambarkan data dalam suatu urutan.

Contoh:
```C++
#include <iostream>
using namespace std;
int main() {
    int arr[5] = {7, 1, 5, 3, 4}; //deklarasi array
    cout<< arr[1] << endl;
    cout<< arr[4];
}
```


2.	Array dua dimensi
Array dua dimensi merupakan perluasan dari sebuah array satu dimensi. Jika array satu dimensi hanya terdiri dari sebuah baris dengan beberapa kolom elemen maka array dua dimensi terdiri dari beberapa baris dan beberapa kolom elemen yang bertipe sama. Pendeklarasian array dua dimensi hampir sama dengan pendeklarasian array satu dimensi, kecuali bahwa array dua dimensi terdapat dua jumlah elemen array yang terdapat di dalam kurung siku dan keduanya tidak boleh tidak sama

Contoh:
```C++
#include <iostream>
using namespace std;
int main() {
  int arr [2] [2] = {{1,5}, {1,7}};
  for (int i=10; i<2; i++) { //baris
    for(int j=0; j<2; j++) { //kolom
      cout << arr [i] [j] << ends;
    };
    cout << endl;
  };
}
```


3. Array tiga dimensi
 Array tiga dimensi digunakan untuk mengelola data dalam bentuk 3 dimensi atau tiga sisi


4. Array multidimensi
Sebenarnya array banyak dimensi ini tidak terlalu sering dipakai seperti halnyaarray satu dimensi, dua dimensi, dan tiga dimensi. Array banyak dimensi ini pada dasarnya sama dengan array sebelimnya kecuali pada jumlah dimensinya.


## Guided 

### 1. Program Input Array Tiga Dimensi

```C++
#include <iostream>
using namespace std;

// PROGRAM INPUT ARRAY 3 DIMENSI
int main() {
    // Deklarasi array
    int arr[2][3][3];
    // Input elemen
    for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 3; y++) {
            for (int z = 0; z < 3; z++) {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }

    // Output Array
    for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 3; y++) {
            for (int z = 0; z < 3; z++) {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;

    // Tampilan array
    for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 3; y++) {
            for (int z = 0; z < 3; z++) {
                cout << arr[x][y][z] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}
```
Program diatas merupakan contoh cara mendeklarasikan dan menggunakan array tiga dimensi pada C++
Program dimulai dengan standar `#include <iostream>` dan menggunakan `namespace std;` pernyataan. Fungsi main() dimulai dengan mendeklarasikan array tiga dimensi arr dengan dimensi 2x3x3. Program kemudian mengulang setiap elemen array, meminta pengguna untuk memasukkan nilainya. Setelah semua elemen dimasukkan, program mengulangi array lagi dan mengeluarkan nilai setiap elemen. Program kemudian mengeluarkan nilai array dalam format 2D (format matriks) agar lebih mudah dibaca. Singkatnya, program ini mendemonstrasikan cara mendeklarasikan dan menggunakan array tiga dimensi di C++, serta mengambil input pengguna dan menampilkan konten array.


### 2. Program Mencari Nilai Maksimal pada Array
```C++
#include <iostream>
using namespace std;
int main()
{
int maks, a, i = 1, lokasi;
cout << "Masukkan panjang array: ";
cin >> a;
int array[a];
cout << "Masukkan " << a << " angka\n";
for (i = 0; i < a; i++)
{
cout << "Array ke-" << (i) << ": ";
cin >> array[i];
}
maks = array[0];
for (i = 0; i < a; i++)
{
if (array[i] > maks)
{
maks = array[i];
lokasi = i;
}
}
cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
}
```
Untuk menemukan nilai maksimum, program akan membandingkan setiap nilai di array dengan nilai maks dan, jika ditemukan nilai lebih besar, maks dan lokasi akan diperbarui. Ketika proses pencarian selesai, maks akan menyimpan nilai maksimum dan lokasi akan menyimpan posisi dari maks di dalam array.

Perintah berikut bernilai utama dalam membuat program ini,yaitu:
- Menyimpan panjang array dan menginisialisasi array
- Mengambil input nilai dari pengguna
- Membandingkan nilai di array dengan variabel maks
- Memperbarui maks dan lokasi jika nilai di array lebih besar

Program ini akan mencetak nilai maksimum dan posisi dari nilai maksimum di dalam array ketika semua input telah disimpan dan nilai maksimum telah ditemukan.
Selama perulangan dalam program, i diinisialisasi ke 1 karena nilai pertama dari array dimulai dari indeks 0, sehingga dalam output akan menuliskan „Array ke-1“ untuk nilai pertama dari array.



## Unguided 

### 1. Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code unguided praktikan" << endl;
    return 0;
}
```
#### Output:
![Screenshot (1172)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/ebf3d6ee-1a05-4028-aa88-77e3d60357d3)

- #include <iostream>: Mengimpor library iostream, yang digunakan untuk input dan output dasar.
- using namespace std;: Memperjelas bahwa namespace yang digunakan adalah std.
- int main() { ... }: Fungsi utama yang akan dieksekusi.
- int array[10];: Deklarasi sebuah array dengan nama "array" dan kapasitas 10.

Jika angka yang disimpan di elemen ke-i dari array tidak habis dibagi 2, maka akan ditampilkan.
Kode ini akan meminta input dari pengguna sebanyak 10 angka, dan kemudian akan menampilkan angka-angka genap dan ganjil yang dimasukkan.


### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

```C++
#include <iostream>

int main() {
    int x, y, z;
    std::cout << "Enter the size of the 3D array (x y z): ";
    std::cin >> x >> y >> z;

    int arr[x][y][z];

    std::cout << "Enter the elements of the 3D array:\n";
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                std::cin >> arr[i][j][k];
            }
        }
    }

    std::cout << "The 3D array is:\n";
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                std::cout << arr[i][j][k] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    return 0;
}
```

### Output
![unguided-2](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/290eaa5b-acec-409f-a2ef-4ffa0fe7e2d8)

Kode diatas merupakan kode yang membuat dan menginisialisasi array bilangan bulat 3 dimensi, lalu mencetak elemen-elemennya.

- Baris pertama menyertakan library iostream untuk operasi input/output.
- Fungsi main() adalah titik masuk program.
- Di dalam main(), tiga variabel integer `x, y, dan z` dideklarasikan untuk menyimpan ukuran array 3 dimensi.
- Pengguna diminta memasukkan ukuran array 3D dalam format "x y z", dan nilainya disimpan dalam variabel x, y, dan z.
- Array 3D bilangan bulat yang disebut `arr` dibuat dengan ukuran x kali y kali z.
- Program kemudian memasukkan dua loop, loop luar yang melakukan iterasi pada dimensi pertama x, dan loop dalam yang melakukan iterasi pada dimensi kedua y. Di dalam loop dalam, loop lain disarangkan yang melakukan iterasi pada dimensi ketiga z.
- Dalam setiap iterasi, pengguna diminta memasukkan nilai, yang disimpan dalam array arr pada indeks saat ini.
- Setelah array terisi, program memasukkan kumpulan loop bersarang lainnya yang melakukan iterasi pada tiga dimensi array, dan mencetak setiap elemen yang dipisahkan oleh spasi.

Setelah mencetak semua elemen, program mengembalikan 0 untuk menunjukkan eksekusi berhasil.
Singkatnya, program ini mengambil ukuran array 3D sebagai masukan, menginisialisasinya dengan nilai yang dimasukkan pengguna, dan mencetak semua elemennya.


### 3. Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!

```C++
#include <iostream>
#include <limits>
using namespace std;

int main() {
    int choice;
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int numbers[size];

    // Input numbers
    for (int i = 0; i < size; i++) {
        cout << "Enter number " << i+1 << ": ";
        cin >> numbers[i];
    }

    // Menu
    while (true) {
        cout << "\n1. Find maximum\n2. Find minimum\n3. Find average\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            // Mencari nilai maximum pada array
            case 1: {
                int max = std::numeric_limits<int>::min();
                for (int i = 0; i < size; i++) {
                    if (numbers[i] > max) {
                        max = numbers[i];
                    }
                }
                cout << "Maximum: " << max << endl;
                break;
            }
            // Mencari nilai minimum pada array
            case 2: {
                int min = std::numeric_limits<int>::max();
                for (int i = 0; i < size; i++) {
                    if (numbers[i] < min) {
                        min = numbers[i];
                    }
                }
                cout << "Minimum: " << min << endl;
                break;
            }
            // Mencari nilai rata-rata
            case 3: {
                int sum = 0;
                for (int i = 0; i < size; i++) {
                    sum += numbers[i];
                }
                double avg = static_cast<double>(sum) / size;
                cout << "Average: " << avg << endl;
                break;
            }
            case 4:
                exit(0);
            default:
                cout << "Invalid choice! Please enter again." << endl;
        }
    }
    return 0;
}
```

### Output
![unguided-3](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/ebff8c22-d00b-4ca1-801e-058a9abf313c)

Kode diatas merupakan kode yang melakukan berbagai operasi pada array bilangan bulat. Ukuran array dimasukkan oleh pengguna. Program ini kemudian memungkinkan pengguna untuk memilih antara mencari nilai maksimum, minimum, atau rata-rata dari array, atau keluar dari program.
- Dua baris pertama mencakup perpustakaan iostream untuk operasi input/output dan `library limits` untuk mengakses nilai minimum dan maksimum yang dapat diwakili oleh bilangan bulat.
- Penggunaan namespace std; line memudahkan penggunaan fungsi library standar tanpa harus mengawalinya dengan std::.
- Fungsi main() adalah titik masuk program.
- Di dalam main(), pilihan variabel integer dideklarasikan untuk menyimpan pilihan pengguna, dan variabel integer size dideklarasikan untuk menyimpan ukuran array.

Pengguna diminta untuk memasukkan pilihannya, dan nilainya disimpan dalam variabel choice.
Pernyataan switch digunakan untuk melakukan tindakan berbeda berdasarkan nilai pilihan.

- Kasus 1: Program menemukan nilai maksimum dalam array angka dengan menginisialisasi variabel max ke nilai integer minimum dan kemudian melakukan iterasi melalui array, memperbarui max dengan elemen saat ini jika lebih besar dari nilai max saat ini.
- Kasus 2: Program menemukan nilai minimum dalam array angka dengan menginisialisasi variabel min ke nilai integer maksimum dan kemudian melakukan iterasi melalui array, memperbarui min dengan elemen saat ini jika kurang dari nilai min saat ini.
- Kasus 3: Program menemukan nilai rata-rata array angka dengan menginisialisasi jumlah variabel menjadi 0 dan kemudian melakukan iterasi melalui array, menambahkan nilai setiap elemen ke jumlah. Rata-rata kemudian dihitung dengan membagi jumlah dengan ukuran array dan menggandakan hasilnya.

- Kasus 4: Program keluar dengan memanggil fungsi exit() dengan kode status 0.

- Default: Program menampilkan pesan kesalahan jika pengguna memasukkan pilihan yang tidak valid.
Program mengembalikan 0 untuk menunjukkan eksekusi berhasil.
Singkatnya, program ini mengambil serangkaian bilangan bulat sebagai masukan dan memungkinkan pengguna menemukan nilai maksimum, minimum, atau rata-ratanya.

## Kesimpulan
Dimensi adalah jumlah elemen atau ukuran dari sebuah array. Ukuran dari sebuah array yang diinput oleh user dengan mencantumkan `input` untuk tiap-tiap dimensinya. Jika kita dapat menggunakan program tersebut dengan tepat didalam proses pemrograman akan menghasilkan algoritma yang lebih jelas dan tepat sehingga membuat program lebih terstruktur.

## Referensi
[1] Pratama, Muhammad A. “STRUKTUR DATA ARRAY DUA DIMENSI PADA PEMROGRAMAN C++.” OSF Preprints, 29 Mar. 2020. Web.
