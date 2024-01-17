#include "Sort.h"

void Sort::QuickSort(int *nums, int len, bool reverse, int start, int end) {
    if (end == -1) end = len - 1;
    if (end - start < 1) return;
    int numIndex = start;
    int num = nums[numIndex];
    for (int i = start + 1; i <= end; ++i) {
        if (nums[i] < num && !reverse || nums[i] > num && reverse) {
            if (i != numIndex + 1) swap(nums[numIndex + 1], nums[i]);
            swap(nums[numIndex], nums[numIndex + 1]);
            ++numIndex;
        }
    }
    QuickSort(nums, 0, reverse, start, numIndex - 1);
    QuickSort(nums, 0, reverse, numIndex + 1, end);
}

void print(int* arr, int len) {
    for (int i = 0; i < len; ++i)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;
}

void Sort::PyramidalSort(int *arr, int len) {
    int index, num;
    for (int i = 0; i < len; ++i) {  // Формирование кучи
        index = i;
        while (arr[index] > arr[num = (int) floor((index - 1) / 2)] && index > 0) {
            swap(arr[index], arr[num]);
            index = num;
        }
    }
    for (int i = 1; i < len; ++i) {  // вынос элементов и исправление кучи
        swap(arr[0], arr[len - i]);
        index = 0;
        while (2 * index < len - i - 1 && arr[index] < max(arr[2 * index + 1], arr[2 * index + 2])) {
            if (arr[2 * index + 2] > arr[2 * index + 1] && 2 * index < len - i - 2) {
                swap(arr[index], arr[2 * index + 2]);
                index = 2 * index + 2;
            } else if (arr[2 * index + 1] > arr[index]) {
                swap(arr[index], arr[2 * index + 1]);
                index = 2 * index + 1;
            } else break;
        }
    }
}
