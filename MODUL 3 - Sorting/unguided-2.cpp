#include <iostream>
#include <string>
using namespace std;

void bubblesort(string arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    string arr[10] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};
    cout << "Before sorting: ";
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << "\n";

    // Function call to sort the array using Bubble Sort
    bubblesort(arr, 10);

    cout << "After sorting: ";
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}