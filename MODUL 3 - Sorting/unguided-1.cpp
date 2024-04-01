#include <iostream>
using namespace std;

void ipsmhs(float arr[], int length){
    float temp, minimum;
    int idx_min;
    for (int i = 0 ; i < length-1 ; i++){
        minimum = arr[i];
        idx_min = i;
        for(int j = i+1 ; j < length ; j++){
            if (minimum < arr[j]){
                minimum = arr[j];
                idx_min = j;
            }
        }
        temp = arr[idx_min];
        arr[idx_min] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    float arr[5] = {3.8, 2.9, 3.3, 4.0, 2.4};
    cout << "Before sorting: ";
    for(int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    cout << "\n";
    
    // Function call to sort the array using Selection Sort
    ipsmhs(arr, 5);
    
    cout << "After sorting: ";
    for(int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}