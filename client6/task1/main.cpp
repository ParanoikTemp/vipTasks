#include <iostream>
#include "Sort.h"
#include <chrono>

using namespace std;

void getRandom(int* arr, int count, int sort) {
    for (int i = 0; i < count; ++i)
        arr[i] = rand() % 10000;
    if (sort == 1)
        Sort::QuickSort(arr, count);
    else if (sort == 2)
        Sort::QuickSort(arr, count, true);
}

int main() {
    string word[4] = {"Random", "Sort", "Reverse sort"};
    int nms[3] = {500, 1500, 4500};
    int tests = 10;
    for (int i = 0; i < 3; ++i) {
        for (int len: nms) {
            long long int sum = 0;
            for (int u = 0; u < tests; ++u) {
                int *nums = new int[len];
                getRandom(nums, len, i);
                auto begin = std::chrono::steady_clock::now();
                Sort::PyramidalSort(nums, len);
                auto end = std::chrono::steady_clock::now();
                auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
                long long int time = elapsed_ms.count();
                sum += time;
                delete[] nums;
            }
            cout << word[i] << ". Numbers count: " << len << " Time: " << sum / tests << endl;
        }
    }
}
