# <h1 align="center">Laporan Praktikum Modul Linked List</h1>
<p align="center">Indy Aurellia Az Zahra</p>
<p align="center">2311110020</p>

## Dasar Teori

### Linked List

Salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis dan terbatas adalah senarai berkait (linked list). Suatu senarai berkait (linked list) adalah suatu simpul (node) yang dikaitkan dengan simpul yang lain dalam suatu urutan tertentu. Suatu simpul dapat berbentuk suatu struktur atau class. Simpul harus mempunyai satu atau lebih elemen struktur atau class yang berisi data. Secara teori, linked list adalah sejumlah node yang dihubungkan secara linier dengan bantuan pointer. Senarai berkait lebih efisien di dalam melaksanakan penyisipan-penyisipan dan penghapusan-penghapusan. Senarai berkait juga menggunakan alokasi penyimpanan secara dinamis, yang merupakan penyimpanan yang dialokasikan pada runtime. Karena di dalam banyak aplikasi, ukuran dari data itu tidak diketahui pada saat kompile, hal ini bisa merupakan suatu atribut yang baik juga. Setiap node akan berbentuk struct dan memiliki satu buah field bertipe struct yang sama, yang berfungsi sebagai pointer. Dalam menghubungkan setiap node, kita dapat menggunakan cara first-create-first-access ataupun first-create-lastaccess. Yang berbeda dengan deklarasi struct sebelumnya adalah satu field bernama next, yang bertipe struct tnode. Hal ini sekilas dapat membingungkan. Namun, satu hal yang
jelas, variabel next ini akan menghubungkan kita dengan node di sebelah kita, yang juga bertipe struct tnode. Hal inilah yang menyebabkan next harus bertipe struct tnode. 

#### Operasi-Operasi Linked List

- Insert : Istilah Insert berarti menambahkan sebuah simpul baru ke dalam suatu linked list.
- IsEmpty : Fungsi ini menentukan apakah linked list kosong atau tidak
- Find First : Fungsi ini mencari elemen pertama dari linked list.
- Find Next : Fungsi ini mencari elemen sesudah elemen yang ditunjuk now.
- Retrieve : Fungsi ini mengambil elemen yang ditunjuk oleh now. Elemen tersebut lalu
dikembalikan oleh fungsi.
- Update : Fungsi ini mengubah elemen yang ditunjuk oleh now dengan isi dari sesuatu.
- Delete Now : Fungsi ini menghapus elemen yang ditunjuk oleh now. Jika yang dihapus adalah
elemen pertama dari linked list (head), head akan berpindah ke elemen berikutnya.
- Delete Hand : Fungsi ini menghapus elemen yang ditunjuk head. Head berpindah ke elemen
sesudahnya
- Clear : Fungsi ini menghapus linked list yang sudah ada. Fungsi ini wajib dilakukan bila
anda ingin mengakhiri program yang menggunakan linked list. Jika anda
melakukannya, data-data yang dialokasikan ke memori pada program sebelumnya
akan tetap tertinggal di dalam memori.


#### Single Linked List

Linked list merupaka suatu bentuk struktur data yang berisi kumpulan data yang disebut sebagai node yang tersusun secara sekuensial, saling sambung menyambung, dinamis, dan terbatas. setiap elemen dalam linked list dihubungkan ke elemen lain melalui pointer. Pointer adalah alamat elemen. Linked List dibentuk dengan cara menunjuk pointer next suatu elemen ke elemen yang mengikutinya. Pointer terakhir pada elemen terakhir merupakan NULL (akhir dari suatu list). Elemen pada awal suatu list disebut head dan elemen terakhir dari suatu list disebut tail. Karena struktur data ini hanya memerlukan satu pointer untuk setiap simpul, maka Single Linked List umumnya lebih efisien dalam penggunaan memori dibandingkan dengan jenis Linked List lainnya, seperti Double Linked List dan Circular Linked List.

![single linked list](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/e6fb34ad-6392-4142-95ac-dd3464a9869f)



#### Double Linked List

Double linked list adalah struktur data yang terdiri dari banyak node yang terhubung. Setiap node terbagi menjadi tiga bagian, yaitu bagian yang berisi data, bagian yang terhubung ke node sebelumnya, dan bagian yang terhubung ke node berikutnya. Implementasi double linked list di C++ dilakukan menggunakan class dan struct. Double linked list memiliki kelebihan seperti dapat menampung data yang berbeda-beda, dapat menampung data yang tidak diketahui jumlahnya, dan dapat menampung data yang dinamis



## Guided 

### 1. Single Linked List

```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node {
    int data;
    Node *next; // Tanda * mendefinisikan variabel pointer yaitu menyimpan alamat dari variabel lain
};

Node *head;
Node *tail;

// Inisialisasi Node
void init() { // Menggunakan void supaya tidak perlu memberikan return value
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah list kosong
bool isEmpty() {
    return (head == NULL);
}

// Tambah Data di Depan
void insertDepan(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru; // 1 node ini terdapat head, tail, dan variabel baru
    } else {
        baru->next = head;
        head = baru;
    }
}

// Tambah Data di Belakang
void insertBelakang(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung Jumlah Node
int hitungList() {
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Tambah Data di Tengah
void insertTengah(int data, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *baru = new Node();
        baru->data = data;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Node di Depan
void hapusDepan() {
    if (!isEmpty()) {
        Node *hapus = head;
        if (head->next != NULL) {
            head = head->next;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di Belakang
void hapusBelakang() {
    if (!isEmpty()) {
        Node *hapus = tail;
        if (head != tail) {
            Node *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di Tengah
void hapusTengah(int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi di luar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *hapus;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
}

// Ubah Data di Depan
void ubahDepan(int data) {
    if (!isEmpty()) {
        head->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Data di Tengah
void ubahTengah(int data, int posisi) {
    if (!isEmpty()) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            Node *bantu = head;
            for (int nomor = 1; nomor < posisi; nomor++) {
                bantu = bantu->next;
            }
            bantu->data = data;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Data di Belakang
void ubahBelakang(int data) {
    if (!isEmpty()) {
        tail->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Semua Node
void clearList() {
    Node *hapus;
    while (head != NULL) {
        hapus = head;
        head = head->next;
        delete hapus;
    }
    tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil() {
    Node *bantu = head;
    if (!isEmpty()) {
        while (bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init(); // Harus ada untuk menginisialisasi capsul nodenya
    insertDepan(3); tampil();
    insertBelakang(5); tampil();
    insertDepan(2); tampil();
    insertDepan(1); tampil();
    hapusDepan(); tampil();
    hapusBelakang(); tampil();
    insertTengah(7, 2); tampil();
    hapusTengah(2); tampil();
    ubahDepan(1); tampil();
    ubahBelakang(8); tampil();
    ubahTengah(11, 2); tampil();
    clearList();
    return 0;
}
```
Kode di atas digunakan untuk mengoperasikan suatu data menggunakan Single Linked List. Pada kode diatas, terdapat beberapa opsi untuk menghapus, menambah, membersihkan, dan mengubah data di suatu list.

Program dimulai dengan inisialisasi list menggunakan fungsi `init()`, yang mengatur kedua pointer `head` dan `tail` ke `NULL`, menunjukan bahwa list masih kosong.
Fungsi 'isEmpty()' berguna untuk memeriksa apakah list masih kosong dengan mengembalikan 'true' jika pointer 'head' adalah 'NULL', dan 'false' jika tidak.

##### Penggunaan di Depan ('insertDepan')
'insertDepan' berfungsi untuk menginputkan node baru di depan list. Membuat node baru dengan nilai yang diberikan dengan mengatur pointer 'next' ke 'NULL'. Jika list masih kosong, mengatur keduanya pointer 'head' dan 'tail' ke node baru. Jika tidak, mengatur pointer 'head' ke node baru dan mengatur pointer 'next' node baru ke node yang sekarang menjadi 'head'.

##### Penggunaan di Belakang ('insertBelakang')
'insertBelakang' berfungsi untuk menginputkan node baru di tengah list. Membuat node baru dengan data yang diberikan dan memeriksa apakah posisi yang diberikan dalam jangkauan list. Jika posisi 1, menginputkan node baru di depan list. Jika tidak, menemukan node di posisi yang diberikan dan mengatur pointer 'next' node sebelumnya ke node baru.

##### Penghapusan di Depan ('hapusDepan')
'hapusDepan' berfungsi untuk menghapus node di depan list dan memeriksa apakah list kosong atau tidak dan mengatur pointer head ke node berikutnya di list. Jika list hanya memiliki satu node, mengatur keduanya pointer head dan tail ke 'NULL'.

##### Penghapusan di Belakang ('hapusBelakang')
'hapusBelakang' berfungsi untuk menghapus node di belakang list dan memeriksa apakah list tidak kosong, dan jika demikian, menemukan node sebelum node terakhir di list dan mengatur pointer 'next' ke 'NULL'. Jika list hanya memiliki satu node, mengatur keduanya pointer 'head' dan 'tail' ke 'NULL'.

##### Penghapusan di Tengah ('hapusTengah')
'hapusTengah' berfungsi untuk menghapus node di tengah list dan memeriksa apakah posisi yang diberikan dalam jangkauan list. Jika posisi 1, menghapus node di depan list. Jika tidak, menemukan node di posisi yang diberikan dan mengatur pointer 'next' node sebelumnya ke node setelah node yang dihapus.

##### Modifikasi di Depan ('ubahDepan')
'ubahDepan' berfungsi untuk memodifikasi node di depan list. Memeriksa apakah list tidak kosong dan mengatur nilai data node 'head'.

##### Modifikasi di Belakang ('ubahBelakang')
'ubahBelakang' berfungsi untuk memodifikasi node di belakang list. Memeriksa apakah list tidak kosong dan mengatur nilai data node 'tail'.

#### Output
![output guided-1](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/9b5931dc-f2f1-44f4-a844-07ad5b5f200d)


### 2. Double Linked List

```C++
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev; // Previous digunakan untuk melihat data sebelumnya
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }

    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next; // Akan next terus sampai currentnya berhenti
        }
        return false;
    }

    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```
Kode di atas merupakan Double Linked List yang memungkinkan user efektif untuk menambahkan dan menghapus elemen dari awal dan akhir list. Program tersebut memungkinkan mereka untuk menambahkan, menghapus, memperbarui, dan menampilkan list.

##### Class Node
class 'Node' mewakili sebuah node tunggal dalam Double Linked List. Setiap node memiliki tiga atribut:
- 'data' : nilai integer yang disimpan dalam node
- 'prev' : pointer ke node sebelumnya dalam list
- 'next' : pointer ke node berikutnya dalam list

##### Class DoublyLinkedList
Class 'DoublyLinkedList' mewakili Double Linked List itu sendiri, ia memiliki dua atribut:
- 'head' : pointer ke node pertama dalam list
- 'tail' : pointer ke node terakhir dalam list

Beberapa metode untuk berinteraksi dengan list:
- 'push(int data)' : menambahkan node baru ke awal list dengan nilai 'data' yang diberikan
- 'pop()' : menghapus node di awal list
- 'update(int oldData, int newData)' : memperbarui nilai 'data' node pertama dalam list yang cocok dengan nilai 'oldData' ke nilai 'newData'
- 'deleteAll()' : menghapus semua node dalam list
- 'display()' : mencetak nilai 'data' semua node dalam list

##### Fungsi Main
'main' menyediakan opsi untuk pengguna agar dapat berinteraksi dengan Double Linked List. ia secara terus-menerus akan meminta user untuk memilih opsi dari menu berikut:
- Tambah Data
- Hapus Data
- Perbarui Data
- Hapus Semua Data
- Tampilkan data
- Keluar

Berdasarkan input user, program melakukan operasi yang sesuai pada list. Misalnya, jika user menginputkan opsi 1, program akan meminta mereka untuk menginputkan data dan kemudian memanggil metode 'push' untuk menambahkan node ke awal list.

#### Output
![output guided-2](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/07bf5a23-81f0-4179-bb25-ebb6f5568fc1)


### Linked List Circular

```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST CIRCULAR

// Deklarasi Struct Node
struct Node {
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init() {
    head = NULL;
    tail = head;
}

// Pengecekan
int isEmpty() {
    if (head == NULL)
        return 1; // true
    else
        return 0; // false
}

// Buat Node Baru
void buatNode(string data) {
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList() {
    bantu = head;
    int jumlah = 0;

    while (bantu != NULL) {
        jumlah++;
        bantu = bantu->next;
    }

    return jumlah;
}

// Tambah Depan
void insertDepan(string data) {
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }

        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah Belakang
void insertBelakang(string data) {
    // Buat Node Baru
    buatNode(data);

    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }

        tail->next = baru;
        baru->next = head;
    }
}

// Tambah Tengah
void insertTengah(string data, int posisi) {
    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        baru->data = data;

        // transversing
        int nomor = 1;
        bantu = head;

        while (nomor < posisi -1) {
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Depan
void hapusDepan() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;

        if (hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (tail->next != hapus) {
                tail = tail->next;
            }

            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;

        if (hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (hapus->next != head) {
                hapus = hapus->next;
            }

            while (tail->next != hapus) {
                tail = tail->next;
            }

            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi) {
    if (isEmpty() == 0) {
        // transvering
        int nomor = 1;
        bantu = head;

        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }

        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void clearList() {
    if (head != NULL) {
        hapus = head->next;

        while (hapus != head) {
            bantu = hapus-> next;
            delete hapus;
            hapus = bantu;
        }

        delete head;
        head = NULL;
    }

    cout << "List berhasil terhapus!" << endl;
}

// Tampilan List
void tampil() {
    if (isEmpty() == 0) {
        tail = head;

        do {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);

        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init();
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
    return 0;
}
```

Kode di atas digunakan untuk menambahkan dan menghapus data. Program dapat menambah dan menghapus data di depan, tengah, dan belakang. 
- dimulai dengan inisialisasi list dengan fungsi 'init()'
- fungsi 'insertDepan()' dipanggil dua kali, menambahkan string "Ayam" dan "Bebek" di depan list
- Fungsi 'tampil()' dipanggil dua kali, menampilkan isi list. Output menunjukan bahwa list berisi string "Ayam" dan "Bebek"
- Fungsi 'insertBelakang()' dipanggil dua kali, menambahkan string "Cicak" dan "Domba" di belakang list.
- Fungsi 'hapusBelakang()' dipanggil, menghapus node di belakang list. Output menunjukan bahwa list berisi string "Ayam" dan "Bebek"
- Fungsi 'hapusDepan()' dipanggil, menghapus node di depan list. Output menunjukan bahwa list berisi string "Bebek"
- Fungsi 'insertTengah()' dipanggil, menambahkan string "Sapi" di posisi kedua dalam list
- Fungsi 'hapusTengah()' dipanggil, menghapus node di posisi kedua dalam list. Output menunjukan bahwa list berisi string "Bebek"

#### Output
![output guided-3](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/d5881901-59e5-4b5e-9ef3-3bf5550ee428)


## Unguided 

### 1. Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menginputkan input dari user

    1. Buatkah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa

    2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang, atau tengah)

![Screenshot (1380)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/6b034dac-0bf3-4042-a78c-50bfdc368c75)


```C++
#include <iostream>
#include <string>

using namespace std;

// Struktur Node untuk menyimpan data mahasiswa
struct Node {
  string nama;
  string nim;
  Node* next; // Pointer ke node berikutnya
};

// Deklarasi pointer head untuk awal list
Node* head = nullptr;

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
  cout << "\nPROGRAM SINGLE LINKED LIST NON-CIRCULAR\n";
  cout << "=========================================\n";
  cout << "1. Tambah Depan\n";
  cout << "2. Tambah Belakang\n";
  cout << "3. Tambah Tengah\n";
  cout << "4. Ubah Depan\n";
  cout << "5. Ubah Belakang\n";
  cout << "6. Ubah Tengah\n";
  cout << "7. Hapus Depan\n";
  cout << "8. Hapus Belakang\n";
  cout << "9. Hapus Tengah\n";
  cout << "10. Hapus List\n";
  cout << "11. TAMPILKAN\n";
  cout << "0. KELUAR\n";
  cout << "Pilih Operasi : ";
}

// Fungsi untuk menambahkan node di depan list
void tambahDepan() {
  string nama, nim;
  cout << "\nMasukkan Nama : ";
  cin >> nama;
  cout << "Masukkan NIM : ";
  cin >> nim;

  Node* newNode = new Node;
  newNode->nama = nama;
  newNode->nim = nim;
  newNode->next = head;
  head = newNode;

  cout << "Data " << nama << " telah ditambahkan di depan list.\n";
}

// Fungsi untuk menambahkan node di belakang list
void tambahBelakang() {
  string nama, nim;
  cout << "\nMasukkan Nama : ";
  cin >> nama;
  cout << "Masukkan NIM : ";
  cin >> nim;

  Node* newNode = new Node;
  newNode->nama = nama;
  newNode->nim = nim;
  newNode->next = nullptr;

  if (head == nullptr) {
    head = newNode;
  } else {
    Node* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  cout << "Data " << nama << " telah ditambahkan di belakang list.\n";
}

// Fungsi untuk menambahkan node di tengah list
void tambahTengah() {
  string nama, nim;
  int posisi;

  cout << "\nMasukkan Nama : ";
  cin >> nama;
  cout << "Masukkan NIM : ";
  cin >> nim;
  cout << "Masukkan Posisi : ";
  cin >> posisi;

  if (posisi <= 0) {
    cout << "Posisi tidak valid. Data tidak ditambahkan.\n";
    return;
  }

  Node* newNode = new Node;
  newNode->nama = nama;
  newNode->nim = nim;

  int count = 1;
  Node* prev = nullptr;
  Node* curr = head;

  while (curr != nullptr && count < posisi) {
    prev = curr;
    curr = curr->next;
    count++;
  }

  if (curr == nullptr) {
    cout << "Posisi melebihi jumlah node. Data tidak ditambahkan.\n";
  } else {
    newNode->next = curr;
    if (prev == nullptr) {
      head = newNode;
    } else {
      prev->next = newNode;
    }
    cout << "Data " << nama << " telah ditambahkan di tengah list (posisi " << posisi << ").\n";
  }
}

// Fungsi untuk mengubah data node di depan list
void ubahDepan() {
  if (head == nullptr) {
    cout << "List masih kosong. Tidak ada data yang diubah.\n";
    return;
  }

  string namaBaru, nimBaru;
  cout << "\nMasukkan Nama Baru : ";
  cin >> namaBaru;
  cout << "Masukkan NIM Baru : ";
  cin >> nimBaru;

  head->nama = namaBaru;
  head->nim = nimBaru;

  cout << "Data di depan telah diubah.\n";
}

// Fungsi untuk mengubah data node di belakang list
void ubahBelakang() {
  if (head == nullptr) {
    cout << "List masih kosong. Tidak ada data yang diubah.\n";
    return;
  }

  string namaBaru, nimBaru;
  cout << "\nMasukkan Nama Baru : ";
  cin >> namaBaru;
  cout << "Masukkan NIM Baru : ";
  cin >> nimBaru;

  Node* temp = head;
  while (temp->next != nullptr) {
    temp = temp->next;
  }

  temp->nama = namaBaru;
  temp->nim = nimBaru;

  cout << "Data di belakang telah diubah.\n";
}

// Fungsi untuk mengubah data node di tengah list
void ubahTengah() {
  if (head == nullptr) {
    cout << "List masih kosong. Tidak ada data yang diubah.\n";
    return;
  }

  string namaBaru, nimBaru;
  int posisi;
  cout << "\nMasukkan Nama Baru : ";
  cin >> namaBaru;
  cout << "Masukkan NIM Baru : ";
  cin >> nimBaru;
  cout << "Masukkan Posisi : ";
  cin >> posisi;

  if (posisi <= 0) {
    cout << "Posisi tidak valid. Tidak ada data yang diubah.\n";
    return;
  }

  int count = 1;
  Node* temp = head;
  while (temp != nullptr && count < posisi) {
    temp = temp->next;
    count++;
  }

  if (temp == nullptr) {
    cout << "Posisi melebihi jumlah node. Tidak ada data yang diubah.\n";
  } else {
    temp->nama = namaBaru;
    temp->nim = nimBaru;
    cout << "Data pada posisi " << posisi << " telah diubah.\n";
  }
}

// Fungsi untuk menghapus node di depan list
void hapusDepan() {
  if (head == nullptr) {
    cout << "List masih kosong. Tidak ada data yang dihapus.\n";
    return;
  }

  Node* temp = head;
  head = head->next;
  delete temp;

  cout << "Data di depan telah dihapus.\n";
}

// Fungsi untuk menghapus node di belakang list
void hapusBelakang() {
  if (head == nullptr) {
    cout << "List masih kosong. Tidak ada data yang dihapus.\n";
    return;
  }

  Node* temp = head;
  Node* prev = nullptr;
  while (temp->next != nullptr) {
    prev = temp;
    temp = temp->next;
  }

  if (prev == nullptr) {
    head = nullptr;
  } else {
    prev->next = nullptr;
  }

  delete temp;
  cout << "Data di belakang telah dihapus.\n";
}

// Fungsi untuk menghapus node di tengah list
void hapusTengah() {
  if (head == nullptr) {
    cout << "List masih kosong. Tidak ada data yang dihapus.\n";
    return;
  }

  int posisi;
  cout << "Masukkan Posisi yang akan dihapus: ";
  cin >> posisi;

  if (posisi <= 0) {
    cout << "Posisi tidak valid. Tidak ada data yang dihapus.\n";
    return;
  }

  Node* temp = head;
  Node* prev = nullptr;
  int count = 1;

  while (temp != nullptr && count < posisi) {
    prev = temp;
    temp = temp->next;
    count++;
  }

  if (temp == nullptr) {
    cout << "Posisi melebihi jumlah node. Tidak ada data yang dihapus.\n";
  } else {
    if (prev == nullptr) {
      head = temp->next;
    } else {
      prev->next = temp->next;
    }
    delete temp;
    cout << "Data pada posisi " << posisi << " telah dihapus.\n";
  }
}

// Fungsi untuk menghapus seluruh list
void hapusList() {
  while (head != nullptr) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
  cout << "Seluruh list telah dihapus.\n";
}

// Fungsi untuk menampilkan isi list
void tampilkan() {
  if (head == nullptr) {
    cout << "List kosong.\n";
  } else {
    cout << "Daftar Mahasiswa:\n";
    Node* temp = head;
    while (temp != nullptr) {
      cout << "Nama: " << temp->nama << ", NIM: " << temp->nim << endl;
      temp = temp->next;
    }
  }
}

// Fungsi utama
int main() {
  int choice;

  do {
    tampilkanMenu();
    cin >> choice;

    switch (choice) {
      case 1:
        tambahDepan();
        break;
      case 2:
        tambahBelakang();
        break;
      case 3:
        tambahTengah();
        break;
      case 4:
        ubahDepan();
        break;
      case 5:
        ubahBelakang();
        break;
      case 6:
        ubahTengah();
        break;
      case 7:
        hapusDepan();
        break;
      case 8:
        hapusBelakang();
        break;
      case 9:
        hapusTengah();
        break;
      case 10:
        hapusList();
        break;
      case 11:
        tampilkan();
        break;
      case 0:
        cout << "Keluar dari program.\n";
        break;
      default:
        cout << "Operasi tidak valid.\n";
    }
  } while (choice != 0);

  return 0;
}
```

Kode di atas berguna untuk menyimpan data mahasiswa, program diatas menyediakan beberapa opsi yang dapat dijalankan, seperti menambah, mengubah, menghapus, dan menampilkan data

#### Output:

- Tambahkan data berikut diantara Farrel dan Denis: 
        Wati 2330004

![input add wati](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/2e759f6c-d0b2-438b-a9d1-8372d06216a3)

![Screenshot (1363)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/20493179-8508-4f6c-b63f-be57cb7fe308)


- Hapus data Denis

![Screenshot (1364)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/e163dfa6-2724-46ba-98a0-b5e8d2648678)

![Screenshot (1365)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/c1f0b66a-a093-4ab3-b5f4-176457e22ee0)


- Tambahkan data berikut di awal: 
        Owi 2330000 

![Screenshot (1366)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/3fb1a076-685e-4110-9b3a-9fad78eed26c)

![Screenshot (1367)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/21d33e5b-1d3c-4ed9-8847-7e8971b7aea3)


- Tambahkan data berikut di akhir: 
        David 23300100 

![Screenshot (1368)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/5186032e-e5bf-435f-b413-9c4db29ea2cd)

![Screenshot (1369)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/75ade0ab-b9e2-40c0-95f1-7cb3a3f823e7)


-  Ubah data Udin menjadi data berikut: 
        Idin 23300045

![Screenshot (1370)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/7394aa0e-81bd-4ad4-833d-7f382c70c11b)

![Screenshot (1371)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/aefa8520-afaa-4cc9-9f52-1e3219a75c92)


- Ubah data terakhir menjadi berikut: 
        Lucy 23300101

![Screenshot (1372)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/c9ab5cef-39a0-4387-9466-78f9d18c2ea6)

![Screenshot (1373)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/a05f0e89-341c-453a-ab6d-9a32467fd167)


- Hapus data awal

![Screenshot (1374)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/a9dc1905-45f7-460c-921b-5321079570b3)

![Screenshot (1375)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/762ad943-0fe7-46ee-9179-1258d78bfec0)


- Ubah data awal menjadi berikut: 
        Bagas 2330002

![Screenshot (1376)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/36057878-24a5-48b3-a021-e16750bc37dc)

![Screenshot (1377)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/1a4febf1-7e50-4e31-ba2a-434e629c828f)


- Hapus data akhir 

![Screenshot (1378)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/89ef867a-4a0a-460d-8b09-ab9606403941)

DATA AKHIR KESELURUHAN

![Screenshot (1379)](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/f7f5eca9-13e8-4781-8286-b8b005880221)



## Kesimpulan
Linked list merupakan kumpulan elemen-elemen data yang terhubung satu sama lain melalui penggunaan referensi atau pointer. Setiap elemen dalam linked list, yang disebut node, terdiri dari dua bagian utama: data dan referensi ke node berikutnya dalam urutan.

Salah satu keunggulan utama linked list adalah kemampuannya untuk mengatasi perubahan ukuran secara dinamis. Ketika kita ingin menambahkan atau menghapus elemen dari linked list, kita dapat melakukannya dengan mudah tanpa mempengaruhi elemen-elemen lain dalam struktur data tersebut.

## Referensi
[1] C. Brown, D. Brown, Linked List-Based Data Structures for Efficient Graph Representation. Springer Link, 2021. doi: DOI 10.1007/s10444-021-10524-8

[2] Furcy, D. (2009). JHAVEPOP: Visualizing linked-list operations in C++ and Java. Journal of Computing Sciences in Colleges, 25(1), 32-41.