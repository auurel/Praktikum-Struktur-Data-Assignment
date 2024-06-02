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
        for (auto it = table[index].begin(); it!= table[index].end(); ++it) {
            if (it->NIM == NIM) {
                table[index].erase(it);
                return;
            }
        }
    }

    Mahasiswa* findMahasiswaByNIM(string NIM) {
        int index = hashFunction(NIM);
        for (auto it = table[index].begin(); it!= table[index].end(); ++it) {
            if (it->NIM == NIM) {
                return &(*it);
            }
        }
        return nullptr;
    }

    list<Mahasiswa> findMahasiswaByNilai(int lower, int upper) {
        list<Mahasiswa> result;
        for (int i = 0; i < size; ++i) {
            for (auto it = table[i].begin(); it!= table[i].end(); ++it) {
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
                hashTable.deleteMahasiswa(NIM);
                break;
            }
            case 3: {
                string NIM;
                cout << "Masukkan NIM: ";
                cin >> NIM;
                Mahasiswa* mahasiswa = hashTable.findMahasiswaByNIM(NIM);
                if (mahasiswa!= nullptr) {
                    cout << "Data mahasiswa ditemukan: " << mahasiswa->NIM << " - " << mahasiswa->nilai << endl;
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
                    for (auto it = result.begin(); it!= result.end(); ++it) {
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