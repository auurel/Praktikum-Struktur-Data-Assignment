# <h1 align="center">Laporan Praktikum Modul Stack</h1>
<p align="center">Indy Aurellia Az Zahra</p>
<p align="center">2311110020</p>

## Dasar Teori

Queue merupakan struktur data yang menyusun elemen-elemen data dalam urutan linier. Prinsip dasar dari struktur data ini adalah “First In, First Out” (FIFO) yang berarti elemen data yang pertama dimasukkan ke dalam antrean akan menjadi yang pertama pula untuk dikeluarkan.
Caranya bekerja adalah seperti jejeran orang yang sedang menunggu antrean di supermarket di mana orang pertama yang datang adalah yang pertama dilayani (First In, First Out). Pada struktur data ini, urutan pertama (data yang akan dikeluarkan) disebut Front atau Head. Sebaliknya, data pada urutan terakhir (data yang baru saja ditambahkan) disebut Back, Rear, atau Tail. Proses untuk menambahkan data pada antrean disebut dengan Enqueue, sedangkan proses untuk menghapus data dari antrean disebut dengan Dequeue. 

#### Fungsi Queue

Queue memiliki peran penting dalam berbagai aplikasi dan algoritma. Salah satu fungsi utamanya yaitu mengatur dan mengelola antrean tugas atau operasi secara efisien. Di sistem komputasi, queue digunakan untuk menangani tugas-tugas seperti penjadwalan proses, antrean pesan, dan manajemen sumber daya.

#### Jenis-Jenis Queue

##### Berdasarkan implementasinya

- Linear/Simple Queue : elemen data disusun dalam barisan linear dan penambahan serta penghapusan elemen hanya terjadi pada dua ujung barisan tersebut
- Circular Queue : ujung-ujung barisan terhubung satu sama lain, menciptakan struktur antrean yang berbutar.

##### Berdasarkan Penggunaannya

- Priority Queue : setiap elemen memiliki prioritas tertentu. Elemen dengan prioritas tertinggi akan diambil terlebih dahulu.
- Double-ended Queue (Dequeue) : elemen dapat ditambahkan atau dihapus dari kedua ujung antrean.

#### Keuntungan Queue

- Data berjumlah besar dapat dikelola dengan mudah dan efisien.
- Proses insert dan delete data dapat dilakukan dengan mudah karena mengikuti aturan first in first out (FIFO).
- Efisien dalam menangani tugas berdasarkan urutan kedatangan.

#### Keterbatasan Queue

- Tidak efisien untuk pencarian elemen tertentu dalam antrean.
- Memerlukan alokasi memori yang cukup untuk menyimpan antrean.


## Guided

```C++
#include <iostream>

using namespace std;

const int maksimalQueue = 5;
int front = 0;
int back = 0;

string queueTeller[5];

bool isFull() {
    if (back == maksimalQueue) {
        return true;
    } else {
        return false;
    }
}

bool isEmpty() {
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) {
    if (isFull()) {
        cout << "Antrian Penuh" << endl;
    } else {
        if (isEmpty()) {
            queueTeller[0] = data;
            front++;
            back++;
        } else {
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() {
    return back;
}

void clearQueue() {
    if (isEmpty()) {
        cout  << "Antrian masih kosong" << endl;
    } else {
        for  (int i = 0 ; i < back ; i++ )
            queueTeller[i] = "";
    }
    back = 0;
    front = 0;
}

void viewQueue() {
    cout << "Data antrian teller: " << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```
Kode di atas merupakan implementasi sebuah antrian (queue) menggunakan array. Dalam kode ini, queue digunakan untuk menampung nama-nama teller yang sedang menunggu proses.

Fungsi-fungsi yang tersedia dalam kode ini meliputi:
- 'isFull()' : Mengecek apakah antrian penuh.
- 'isEmpty()' : Mengecek apakah antrian kosong.
- 'enqueueAntrian(string data)' : Menambahkan data ke antrian.
- 'dequeueAntrian()' : Menghapus data dari antrian.
- 'countQueue()' : Menghitung jumlah data dalam antrian.
- 'clearQueue()' : Menghapus semua data dalam antrian.
- 'viewQueue()' : Menampilkan isi antrian.

Berdasarkan kode di atas bisa kita tahu bahwa antrian dapat digunakan untuk mengatur urutan proses pada suatu sistem, seperti dalam contoh di atas, untuk menampung nama-nama teller yang sedang menunggu proses. Queue memungkinkan penambahan dan penghapusan data secara berurutan, serta memungkinkan pengecekan apakah antrian penuh atau kosong.


## Unguided 

### 1. Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list

```C++
#include <iostream>
#include <string>

using namespace std; 

// Menentukan struktur untuk sebuah node dalam daftar tertaut
struct Node {
    string data;
    Node* next;
};

// Inisialisasi queue
Node* front = nullptr;
Node* back = nullptr;

// Mengecek apakah queue full atau tidak
bool isFull() {
    // Since we are using a linked list, there is no fixed size limit
    return false;
}

// Mengecek apakah queue kosong
bool isEmpty() {
    return front == nullptr;
}

// Fungsi untuk memasukan items ke dalam queue
void enqueue(string data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = newNode;
        back = newNode;
    } else {
        back->next = newNode;
        back = newNode;
    }
}

// Fungsi untuk mengeluarkan items dari queue
void dequeue() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            back = nullptr;
        }
        delete temp;
    }
}

// Menghitung jumlah items di queue
int count() {
    int count = 0;
    Node* current = front;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// Menghapus queue
void clear() {
    while (!isEmpty()) {
        dequeue();
    }
}

// Menampilkan items dalam queue
void view() {
    Node* current = front;
    cout << "antrian items: " << endl;
    while (current != nullptr) {
        cout << current->data << endl;
        current = current->next;
    }
}

int main() {
    enqueue("Andi");
    enqueue("Maya");
    view();
    cout << "Jumlah antrian: " << count() << endl;
    dequeue();
    view();
    cout << "Jumlah antrian: " << count() << endl;
    clear();
    view();
    cout << "Jumlah antrian: " << count() << endl;
    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas adalah implementasi sebuah antrian (queue) menggunakan linked list. Dalam kode ini, antrian digunakan untuk menampung nama-nama teller yang sedang menunggu proses.

Fungsi-fungsi yang tersedia dalam kode ini meliputi:
- 'isFull()' : Mengecek apakah antrian penuh (dalam linked list, tidak ada batas ukuran, jadi selalu false).
- 'isEmpty()' : Mengecek apakah antrian kosong.
- 'enqueue(string data)' : Menambahkan data ke antrian.
- 'dequeue()' : Menghapus data dari antrian.
- 'count()' : Menghitung jumlah data dalam antrian.
- 'clear()' : Menghapus semua data dalam antrian.
- 'view()' : Menampilkan isi antrian.


- 'enqueue("Andi")' dan 'enqueue("Maya")' menambahkan nama-nama teller "Andi" dan "Maya" ke antrian.
- 'view()' menampilkan isi antrian, yang berisi nama-nama teller "Andi" dan "Maya".
- 'count()' menghitung jumlah items di queue, yang berjumlah 2.
- 'dequeue()' menghapus data dari antrian, sehingga hanya nama teller "Maya" yang tersisa.
- 'view()' menampilkan isi antrian, yang berisi nama teller "Maya".
- 'count()' menghitung jumlah items di queue, yang berjumlah 1.
- 'clear()' menghapus semua data dalam antrian, sehingga antrian menjadi kosong.
- 'view()' menampilkan isi antrian, yang kosong.
- 'count()' menghitung jumlah items di queue, yang berjumlah 0

Output di atas menunjukkan bahwa antrian awalnya berisi dua nama teller, yaitu "Andi" dan "Maya". Kemudian, "Andi" dihapus dari antrian. Setelah itu, antrian dihapus semua, sehingga menjadi kosong.


### 2. Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa

```C++
#include <iostream>
#include <string>

using namespace std;

// menentukan struktur untuk sebuah node dalam linked list
struct Node {
    string namaMahasiswa;
    string nimMahasiswa;
    Node* next;
};

// Inisialisasi queue
Node* front = nullptr;
Node* back = nullptr;

// Memeriksa apakah queue sudah penuh
bool isFull() {
    // Karena menggunakan linked list maka tidak ada batasan ukuran
    return false;
}

// Memeriksa apakah queue kosong
bool isEmpty() {
    return front == nullptr;
}

// Memasukan siswa ke dalam queue
void enqueue(string nama, string nim) {
    Node* newNode = new Node();
    newNode->namaMahasiswa = nama;
    newNode->nimMahasiswa = nim;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = newNode;
        back = newNode;
    } else {
        back->next = newNode;
        back = newNode;
    }
}

// Mengeluarkan siswa dari queue
void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            back = nullptr;
        }
        delete temp;
    }
}

// Menghitung jumlah siswa dalam queue
int count() {
    int count = 0;
    Node* current = front;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// Menghapus queue
void clear() {
    while (!isEmpty()) {
        dequeue();
    }
}

// Menampilkan siswa dalam queue
void view() {
    Node* current = front;
    cout << "Queue mahasiswa: " << endl;
    while (current != nullptr) {
        cout << "Nama Mahasiswa: " << current->namaMahasiswa << endl;
        cout << "NIM Mahasiswa: " << current->nimMahasiswa << endl;
        cout << endl;
        current = current->next;
    }
}

int main() {
    enqueue("Andi", "123456");
    enqueue("Maya", "789012");
    view();
    cout << "Queue size: " << count() << endl;
    dequeue();
    view();
    cout << "Queue size: " << count() << endl;
    clear();
    view();
    cout << "Queue size: " << count() << endl;
    return 0;
}
```

#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] Anita Sindar, R. M. S. (2019). Struktur Data Dan Algoritma Dengan C++ (Vol. 1). CV. AA. RIZKY.

[2] Utami, E., Kom, M., Dhuhita, W. M. P., Kom, S., & Kom, M. (2017). Langkah Mudah Belajar Struktur Data Menggunakan C/C++. Elex Media Komputindo.

[3]  Lai, M. "Peeking a queue in c++." Journal of Software Engineering 14.5 (2023): 234-240.