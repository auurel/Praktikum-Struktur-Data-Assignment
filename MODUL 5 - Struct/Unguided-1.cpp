#include <iostream>
#include <string>

using namespace std;

struct Buku {
    string judul_buku[5];
    string pengarang[5];
    string penerbit[5];
    int tebal_halaman[5];
    double harga_buku[5];
};

void display(Buku buku) {
    for (int i = 0; i < 5; i++) {
        cout << "Judul Buku: " << buku.judul_buku[i] << endl;
        cout << "Pengarang: " << buku.pengarang[i] << endl;
        cout << "Penerbit: " << buku.penerbit[i] << endl;
        cout << "Tebal Halaman: " << buku.tebal_halaman[i] << endl;
        cout << "Harga Buku: " << buku.harga_buku[i] << endl;
        cout << "\n";
    }
}

int main() {
    Buku buku1;

    buku1.judul_buku[0] = "Buku 1";
    buku1.pengarang[0] = "Pengarang 1";
    buku1.penerbit[0] = "Penerbit 1";
    buku1.tebal_halaman[0] = 100;
    buku1.harga_buku[0] = 10000;

    buku1.judul_buku[1] = "Buku 2";
    buku1.pengarang[1] = "Pengarang 2";
    buku1.penerbit[1] = "Penerbit 2";
    buku1.tebal_halaman[1] = 200;
    buku1.harga_buku[1] = 20000;

    buku1.judul_buku[2] = "Buku 3";
    buku1.pengarang[2] = "Pengarang 3";
    buku1.penerbit[2] = "Penerbit 3";
    buku1.tebal_halaman[2] = 300;
    buku1.harga_buku[2] = 30000;

    buku1.judul_buku[3] = "Buku 4";
    buku1.pengarang[3] = "Pengarang 4";
    buku1.penerbit[3] = "Penerbit 4";
    buku1.tebal_halaman[3] = 400;
    buku1.harga_buku[3] = 40000;

    buku1.judul_buku[4] = "Buku 5";
    buku1.pengarang[4] = "Pengarang 5";
    buku1.penerbit[4] = "Penerbit 5";
    buku1.tebal_halaman[4] = 500;
    buku1.harga_buku[4] = 50000;
    // ... and so on for the other elements of the array

    display(buku1);

    return 0;
}