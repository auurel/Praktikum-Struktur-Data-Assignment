#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string kata;
    stack<char> s;

    cout << "Program Mengecek Kata dan Kalimat Palindrom" << endl;
    cout << "Input Kata : ";
    getline(cin, kata);

    // Memasukan kata kedalam stack
    for (int i = 0; i < kata.length(); i++) {
        s.push(kata[i]);
    }

    // Mengecek apakah kata yang diinputkan polindrom
    bool palindrome = true;
    for (int i = 0; i < kata.length(); i++) {
        if (kata[i]!= s.top()) {
            palindrome = false;
            break;
        }
        s.pop();
    }

    if (palindrome) {
        cout << "Hasil : Kata/Kalimat Tersebut Palindrom" << endl;
    } else {
        cout << "Hasil : Kata/Kalimat Tersebut Bukan Palindrom" << endl;
    }

    return 0;
}