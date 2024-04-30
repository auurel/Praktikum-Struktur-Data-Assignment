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