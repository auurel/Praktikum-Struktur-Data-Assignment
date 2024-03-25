#include <iostream>

int main() {
    int x, y, z;
    std::cout << "Enter the size of the 3D array (x y z): ";
    std::cin >> x >> y >> z;

    int arr[x][y][z];

    std::cout << "Enter the elements of the 3D array:\n";
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                std::cin >> arr[i][j][k];
            }
        }
    }

    std::cout << "The 3D array is:\n";
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                std::cout << arr[i][j][k] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    return 0;
}