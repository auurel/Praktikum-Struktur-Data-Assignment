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
