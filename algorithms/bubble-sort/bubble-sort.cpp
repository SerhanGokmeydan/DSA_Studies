#include "bubble-sort.hpp"

void bubbleSort(std::vector<int> &arr) {
    bool swapped;
    for (int i = 0; i < arr.size() - 1; i++) {
        swapped = false;
        for (int j = 0; j < arr.size() - i - 1; j++) {
            int temp = 0;
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}
