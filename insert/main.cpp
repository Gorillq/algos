#include <iostream>

void puter(int* arr, int size) {
    int tmp;
    for (int i = 0; i < size; ++i) {
        std::cout << "Element: " << i << std::endl;
        std::cin >> tmp;
        arr[i] = tmp;
    }
}

void randomiz(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 99;
    }
}

void inserSort(int* arr, int size) {
    for (int i = 1; i < size; ++i) {
        for (int j = i; j > 0; --j) {
            if (arr[j-1] > arr[j]) {
                std::swap(arr[j - 1], arr[j]);
            }
        }
    }
}
void canon(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
int main() {
    std::cout << "size\n";
    int x, size;
    std::cin >> size;
    srand((unsigned) time(NULL));
    int* arr = new int[size];
    std::cout << "Option\n"
                 "1. random\n"
                 "2. self insert\n";
    std::cin >> x;
    switch(x) {
        case 1:
            randomiz(arr, size);
            break;
        case 2:
            puter(arr, size);
            break;
        default:
            std::cout << "BS\n";
            return EXIT_FAILURE;
    }
    canon(arr, size);
    std::cout << "sorting\n";
    inserSort(arr, size);
    std::cout << "sorted:" << std::endl;
    canon(arr, size);
    delete[] arr;
    return 0;
}
