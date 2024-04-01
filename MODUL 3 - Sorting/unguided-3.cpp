#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Masukkan bilangan n: ";
    cin >> n;

    vector<char> arr(n);
    cout << "Masukkan " << n << " karakter: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nUrutan karakter secara menaik (ascending): ";
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n\nUrutan karakter secara menurun (descending): ";
    sort(arr.begin(), arr.end(), greater<char>());
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}