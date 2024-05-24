#include <iostream>

using namespace std;

// Fungsi untuk menghitung faktorial
int faktorial(int n, int result = 1) {
    // Kondisi base untuk menghentikan rekursif
    if (n == 0) {
        return result;
    } else {
        // Fungsi rekursif untuk menghitung faktorial
        return faktorial(n - 1, n * result);
    }
}

int main() {
    int num;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> num;

    // Cek apakah inputan adalah bilangan bulat positif
    if (num > 0) {
        cout << "Faktorial dari " << num << " adalah: " << faktorial(num) << endl;
    } else {
        cout << "Inputan harus bilangan bulat positif." << endl;
    }

    return 0;
}