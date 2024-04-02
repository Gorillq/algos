#include <iostream>
#include <vector>
#include <algorithm>

void randomizer(int* arr, int size) {
    int tmp;
    for (int i = 0; i < size; ++i) {
        tmp = rand() % 99;
        arr[i] = tmp;
    }
}
void printer(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int tmp;
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
            }
        }
    }
}

int main() {
    srand((unsigned) time(NULL));
    int n = 8;
    int* arr  = new int[n];
    randomizer(arr, n);
    std::cout << "unsorted" << " ";
    printer(arr, n);
    bubbleSort(arr, n);
    std::cout << "sorted" << " ";
    printer(arr, n);
    delete[] arr;
    return 0;
}
