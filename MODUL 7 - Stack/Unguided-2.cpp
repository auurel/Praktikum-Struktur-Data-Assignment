#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string kalimat;
    stack<char> s;

    cout << "Program Mengubah Urutan Kalimat" << endl;
    cout << "Input Kalimat : ";
    getline(cin, kalimat);

    // Memasukan kalimat kedalam stack
    for (int i = 0; i < kalimat.length(); i++) {
        s.push(kalimat[i]);
    }

    // Mengeluarkan kalimat dari stack dan merubah urutan kalimat
    string reversed = "";
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }

    // Mencetak hasil urutan kalimat
    int start = 0;
    for (int i = 0; i < reversed.length(); i++) {
        if (reversed[i] == ' ') {
            cout << reversed.substr(start, i - start) << " ";
            start = i + 1;
        }
    }
    cout << reversed.substr(start) << endl;

    return 0;
}