# <h1 align="center">Laporan Praktikum Modul Hash Tabel</h1>
<p align="center">Indy Aurellia Az Zahra</p>
<p align="center">2311110020</p>

## Dasar Teori

Hash table merupakan struktur data yang secara asosiatif menyimpan data. Dalam hal ini,data disimpan dalam format array, di mana setiap nilai data memiliki nilai indeks uniknya sendiri. Akses data akan menjadi cepat jika kita mengetahui indeks dari data yang diinginkan. Dengan demikian, hash table menjadi struktur data dimana operasi penyisipan dan pencarian data terjadi sangat cepat terlepas dari ukuran data tersebut. Hash table menggunakan array sebagai media penyimpanan dan tekniknya untuk menghasilkan indeks suatu elemen yang dimasukkan atau ditempatkan.

### Fungsi Hash Table Pada Data

Fungsi utamanya pada data adalah mempercepat proses akses data. Hal ini berkaitan dengan peningkatan data dalam jumlah besar yang diproses oleh jaringan data global dan lokal. Hash table adalah solusi untuk membuat proses akses data lebih cepat dan memastikan bahwa data dapat dipertukarkan dengan aman. 
Di dalam banyak bidang, hash table dikembangkan dan digunakan karena menawarkan kelebihan dalam efisiensi waktu operasi, mulai dari pengarsipan hingga pencarian data. Contohnya adalah bidang jaringan komputer yang mengembangkannya menjadi hybrid open hash table, yang kemudian dipakai untuk memproses jaringan komputer.



## Guided-1

```C++
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;

// Fungsi hash sederhana
int hash_func(int key) {
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Node {
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class hash table
class HashTable {
private:
    Node** table;
public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }
    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Insertion
    void insert(int key, int value) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node* node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // Searching
    int get(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    // Deletion
    void remove(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Traversal
    void traverse() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                cout << current->key << ": " << current->value << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
   
    // Deletion
    ht.remove(4);
   
    // Traversal
    ht.traverse();
   
    return 0;
}
```


Kode di atas adalah implementasi sebuah hash table (tabel hash) yang menggunakan struktur data linked list untuk mewakili setiap elemen dalam tabel. Hash table ini memiliki fungsi insert untuk menambahkan elemen, get untuk mencari nilai elemen berdasarkan kunci, dan remove untuk menghapus elemen berdasarkan kunci. Fungsi traverse digunakan untuk menampilkan semua elemen dalam tabel.

Output dari kode di atas adalah sebagai berikut:

```C++
Get key 1: 10
Get key 4: -1
1: 10
2: 20
3: 30
```

- Get key 1: 10 : Fungsi 'get' digunakan untuk mencari nilai elemen dengan kunci 1. Karena elemen dengan kunci 1 telah ditambahkan sebelumnya, fungsi ini mengembalikan nilai 10.
- Get key 4: -1 : Fungsi 'get' digunakan untuk mencari nilai elemen dengan kunci 4. Karena elemen dengan kunci 4 tidak ada dalam tabel, fungsi ini mengembalikan nilai -1.
- 1: 10, 2: 20, 3: 30 : Fungsi 'traverse' digunakan untuk menampilkan semua elemen dalam tabel. Hasilnya adalah daftar elemen dengan kunci dan nilai yang telah ditambahkan sebelumnya.


### Guided-2

```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;

string name;
string phone_number;

class HashNode {
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];
public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);

        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name) {
        int hash_val = hashFunc(name);

        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    string searchByName(string name) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                return node->phone_number;
            }
        }
        return "";
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (auto pair : table[i]) {
                if (pair != nullptr) {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap employee_map;

    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;

    employee_map.remove("Mistah");

    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;

    cout << "Hash Table : " << endl;

    employee_map.print();

    return 0;
}
```

Kode di atas adalah implementasi sebuah hash map (tabel hash) yang digunakan untuk menyimpan informasi tentang karyawan. Hash map ini memiliki fungsi insert untuk menambahkan informasi karyawan, fungsi remove untuk menghapus informasi karyawan, dan fungsi search untuk mencari nomor HP berdasarkan nama karyawan. Fungsi print digunakan untuk menampilkan isi hash map.

Output dari kode di atas adalah sebagai berikut:

```c++
Nomer Hp Mistah : 1234
Phone Hp Pastah : 5678
Nomer Hp Mistah setelah dihapus : 

Hash Table : 
0: 
1: 
2: 
3: 
4: [Pastah, 5678]
5: 
6: [Ghana, 91011]
7: 
8: 
9: 
10: 
```
- Nomer Hp Mistah : 1234 : Fungsi 'searchByName' digunakan untuk mencari nomor HP karyawan dengan nama "Mistah". Karena informasi karyawan ini telah ditambahkan sebelumnya, fungsi ini mengembalikan nomor HP "1234".
- Phone Hp Pastah : 5678 : Fungsi 'searchByName' digunakan untuk mencari nomor HP karyawan dengan nama "Pastah". Karena informasi karyawan ini telah ditambahkan sebelumnya, fungsi ini mengembalikan nomor HP "5678".
- Nomer Hp Mistah setelah dihapus : : Fungsi 'remove' digunakan untuk menghapus informasi karyawan dengan nama "Mistah". Fungsi 'searchByName' digunakan untuk mencari nomor HP karyawan dengan nama "Mistah" setelah dihapus. Karena informasi karyawan ini telah dihapus, fungsi ini mengembalikan string kosong.
- Hash Table : Fungsi 'print' digunakan untuk menampilkan isi hash map. Hasilnya adalah daftar karyawan yang telah ditambahkan, dengan nama dan nomor HP masing-masing.

## Unguided 

### 1. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan :
#### a.	Setiap mahasiswa memiliki NIM dan nilai.
#### b.	Program memiliki tampilan pilihan menu berisi poin C.
#### c.	Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).

```C++
#include <iostream>
#include <string>
#include <list>
#include <functional>

using namespace std;

struct Mahasiswa {
    string NIM;
    int nilai;
};

class HashTable {
private:
    int size;
    list<Mahasiswa> *table;

public:
    HashTable(int size) {
        this->size = size;
        table = new list<Mahasiswa>[size];
    }

    ~HashTable() {
        delete[] table;
    }

    int hashFunction(string NIM) {
        int sum = 0;
        for (char c : NIM) {
            sum += c;
        }
        return sum % size;
    }

    void insertMahasiswa(Mahasiswa mahasiswa) {
        int index = hashFunction(mahasiswa.NIM);
        table[index].push_back(mahasiswa);
    }

    void deleteMahasiswa(string NIM) {
        int index = hashFunction(NIM);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->NIM == NIM) {
                table[index].erase(it);
                return;
            }
        }
    }

    Mahasiswa findMahasiswaByNIM(string NIM) {
        int index = hashFunction(NIM);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->NIM == NIM) {
                return *it;
            }
        }
        return Mahasiswa();
    }

    list<Mahasiswa> findMahasiswaByNilai(int lower, int upper) {
        list<Mahasiswa> result;
        for (int i = 0; i < size; ++i) {
            for (auto it = table[i].begin(); it != table[i].end(); ++it) {
                if (it->nilai >= lower && it->nilai <= upper) {
                    result.push_back(*it);
                }
            }
        }
        return result;
    }
};

int main() {
    HashTable hashTable(10);

    int choice;
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Tambahkan data mahasiswa" << endl;
        cout << "2. Hapus data mahasiswa" << endl;
        cout << "3. Cari data mahasiswa berdasarkan NIM" << endl;
        cout << "4. Cari data mahasiswa berdasarkan rentang nilai" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Mahasiswa mahasiswa;
                cout << "Masukkan NIM: ";
                cin >> mahasiswa.NIM;
                cout << "Masukkan nilai: ";
                cin >> mahasiswa.nilai;
                hashTable.insertMahasiswa(mahasiswa);
                break;
            }
            case 2: {
                string NIM;
                cout << "Masukkan NIM: ";
                cin >> NIM;
                cout << "NIM berhasil dihapus";
                hashTable.deleteMahasiswa(NIM);
                break;
            }
            case 3: {
                string NIM;
                cout << "Masukkan NIM: ";
                cin >> NIM;
                Mahasiswa mahasiswa = hashTable.findMahasiswaByNIM(NIM);
                if (mahasiswa.NIM != "") {
                    cout << "Data mahasiswa ditemukan: " << mahasiswa.NIM << " - " << mahasiswa.nilai << endl;
                } else {
                    cout << "Data mahasiswa tidak ditemukan" << endl;
                }
                break;
            }
            case 4: {
                int lower, upper;
                cout << "Masukkan rentang nilai (80-90): ";
                cin >> lower >> upper;
                list<Mahasiswa> result = hashTable.findMahasiswaByNilai(lower, upper);
                if (!result.empty()) {
                    cout << "Data mahasiswa ditemukan: " << endl;
                    for (auto it = result.begin(); it != result.end(); ++it) {
                        cout << it->NIM << " - " << it->nilai << endl;
                    }
                } else {
                    cout << "Data mahasiswa tidak ditemukan" << endl;
                }
                break;
            }
            case 5:
                return 0;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
    }

    return 0;
}
```

#### Output:

- add data mahasiswa
![add data mahasiswa](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/878baf5d-c29b-45ba-8c0c-952e344478b5)

- delete data mahasiswa
![delete data mahasiswa](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/80709766-ad47-445e-82c4-919131853bdd)

- find data mahasiswa
![find data mahasiswa](https://github.com/auurel/Praktikum-Struktur-Data-Assignment/assets/152810893/2c571f56-ae74-4923-bec2-29a56ffce8a8)


Kode di atas merupakan implementasi sebuah hash table yang digunakan untuk menyimpan informasi tentang mahasiswa. Hash table ini memiliki fungsi insert untuk menambahkan informasi mahasiswa, fungsi delete untuk menghapus informasi mahasiswa, fungsi find untuk mencari informasi mahasiswa berdasarkan NIM, dan fungsi findByNilai untuk mencari informasi mahasiswa berdasarkan rentang nilai.

#### Penjelasan Output

- Menu : Program menampilkan menu pilihan untuk operasi hash table.
- Tambahkan data mahasiswa : Program meminta input NIM dan nilai mahasiswa, lalu menambahkan data ke dalam hash table.
- Hapus data mahasiswa : Program meminta input NIM mahasiswa yang akan dihapus, lalu menghapus data dari hash table.
- Cari data mahasiswa berdasarkan NIM : Program meminta input NIM mahasiswa yang akan dicari, lalu mencari data berdasarkan NIM dan menampilkan hasil.
- Cari data mahasiswa berdasarkan rentang nilai : Program meminta input rentang nilai yang akan dicari, lalu mencari data mahasiswa yang memiliki nilai dalam rentang tersebut dan menampilkan hasil.
- Keluar : Program berhenti berjalan.


## Kesimpulan

Hash table merupakan struktur data yang secara asosiatif menyimpan data. Dalam hal ini,data disimpan dalam format array, di mana setiap nilai data memiliki nilai indeks uniknya sendiri. Keuntungan utama dari hash table dibandingkan struktur data lainnya adalah efisiensi dan kecepatan. Waktu yang dibutuhkan untuk mengakses sebuah elemen cukup cepat sehingga bisa lebih diandalkan. Jadi, Anda tidak perlu memakan waktu atau usaha besar untuk menyimpan dan mencari data yang diperlukan.

## Referensi
[1] Maurer, W. D., & Lewis, T. G. (1975). Hash table methods. ACM Computing Surveys (CSUR), 7(1), 5-19.

[2] Nainggolan, S. (2022). Implementasi Algoritma SHA-256 Pada Aplikasi Duplicate Document Scanner. Resolusi: Rekayasa Teknik Informatika dan Informasi, 2(5), 201-213.