#include "bubble-sort.hpp"
#include <iostream>

int main() {
    std::vector<int> arr = {4, 1, 0, 6, 9, 2};
    bubbleSort(arr);

    for (int i : arr) {
        std::cout << i << ", ";
    }
}
