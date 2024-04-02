#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

void createPigeon(int* arr, int size, int min, int max, int* osarr) {
    std::copy(arr, arr+size, osarr);
    int range = max - min + 1;
    std::vector<int> holes[range];
    for (int i = 0; i < size; ++i) {
        holes[arr[i] - min].push_back(arr[i]);
    }
    int index = 0;
    for (int i = 0; i < range; ++i) {
        std::vector<int>::iterator it;
        for (it=holes[i].begin(); it != holes[i].end(); ++it) {
            arr[index++] = *it;
        }
    }
}
void printing(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int findMax(int* arr, int size) {
    int* finder = new int[size];
    int max;
    std::copy(arr, arr+size, finder);
    max = finder[0];
    for (int i = 1; i < size; ++i) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    delete[] finder;
    return max;
}

int findMin(int* arr, int size) {
    int* finder = new int[size];
    int min;
    std::copy(arr, arr+size, finder);
    min = finder[0];
    for (int i = 1; i < size; ++i) {
        if (min > arr[i]) {
            min = arr[i];
        }
    }
    delete[] finder;
    return min;
}

int main() {
    int liczba, nmax, nmin;
    std::cout << "podaj liczbe: ";
    std::cin >> liczba;
    int* arr = new int[liczba];
    int* sarr = new int[liczba];
    srand((unsigned) time(NULL));
    for (int i = 0; i < liczba; ++i) {
        int temp = rand() % 99;
        arr[i] = temp;
    }
    nmax = findMax(arr, liczba);
    nmin = findMin(arr, liczba);
    createPigeon(arr, liczba, nmin, nmax, sarr);
    std::cout << "unsorted:" << std::endl;
    printing(sarr, liczba);
    std::cout << "sorted: " << std::endl;
    printing(arr, liczba);
    delete[] sarr;
    delete[] arr;
    return 0;
}
