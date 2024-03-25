#include <iostream>
#include <limits>
using namespace std;

int main() {
    int choice;
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int numbers[size];

    // Input numbers
    for (int i = 0; i < size; i++) {
        cout << "Enter number " << i+1 << ": ";
        cin >> numbers[i];
    }

    // Menu
    while (true) {
        cout << "\n1. Find maximum\n2. Find minimum\n3. Find average\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            // Mencari nilai maximum pada array
            case 1: {
                int max = std::numeric_limits<int>::min();
                for (int i = 0; i < size; i++) {
                    if (numbers[i] > max) {
                        max = numbers[i];
                    }
                }
                cout << "Maximum: " << max << endl;
                break;
            }
            // Mencari nilai minimum pada array
            case 2: {
                int min = std::numeric_limits<int>::max();
                for (int i = 0; i < size; i++) {
                    if (numbers[i] < min) {
                        min = numbers[i];
                    }
                }
                cout << "Minimum: " << min << endl;
                break;
            }
            // Mencari nilai rata-rata
            case 3: {
                int sum = 0;
                for (int i = 0; i < size; i++) {
                    sum += numbers[i];
                }
                double avg = static_cast<double>(sum) / size;
                cout << "Average: " << avg << endl;
                break;
            }
            case 4:
                exit(0);
            default:
                cout << "Invalid choice! Please enter again." << endl;
        }
    }
    return 0;
}
