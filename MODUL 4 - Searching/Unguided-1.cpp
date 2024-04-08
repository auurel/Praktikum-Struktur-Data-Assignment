#include <iostream>
#include <string>
using namespace std;

int binarySearch(string arr, char x) {
    int kiri = 0, kanan = arr.length() - 1;
    while (kiri <= kanan) {
        int mid = kiri + (kanan - kiri) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            kiri = mid + 1;
        else
            kanan = mid - 1;
    }
    return -1;
}

int main() {
    string arr;
    char x;
    cout << "Enter the string: ";
    getline(cin, arr);
    cout << "Enter the character to search: ";
    cin >> x;
    int result = binarySearch(arr, x);
    if (result == -1)
        cout << "Character not found";
    else
        cout << "Character found at index " << result;
    return 0;
}