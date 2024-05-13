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