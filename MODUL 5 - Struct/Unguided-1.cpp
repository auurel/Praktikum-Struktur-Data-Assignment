#include <iostream>
#include <string>

using namespace std;

struct buku {
    string judul_buku[5];
    string pengarang[5];
    string penerbit[5];
    int tebal_halaman[5];
    double harga_buku[5];
};

int main() {
    // Initialize the buku struct
    buku book;

    // Assign values to each field of the struct
    book.judul_buku[0] = "Book Title 1";
    book.pengarang[0] = "Author 1";
    book.penerbit[0] = "Publisher 1";
    book.tebal_halaman[0] = 100;
    book.harga_buku[0] = 15.99;

    // Assign values to the other fields of the struct
    book.judul_buku[1] = "Book Title 2";
    book.pengarang[0] = "Author 1";
    book.penerbit[0] = "Publisher 1";
    book.tebal_halaman[0] = 100;
    book.harga_buku[0] = 15.99;

    // Assign values to the other fields of the struct
    book.judul_buku[1] = "Book Title 2";
    book.pengarang[0] = "Author 1";
    book.penerbit[0] = "Publisher 1";
    book.tebal_halaman[0] = 100;
    book.harga_buku[0] = 15.99;

    // Display the values of each field of the struct
    cout << "Book 1: " << endl;
    cout << "Title: " << book.judul_buku[0] << endl;
    cout << "Author: " << book.pengarang[0] << endl;
    cout << "Publisher: " << book.penerbit[0] << endl;
    cout << "Pages: " << book.tebal_halaman[0] << endl;
    cout << "Price: $" << book.harga_buku[0] << endl;

    // Display the values of the other fields of the struct
    // ... and so on

    return 0;
}