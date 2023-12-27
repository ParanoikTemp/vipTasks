#include "Sort.h"

void Sort::InsertSort(int *nums, int len, bool reverse) {
    for (int i = 0; i < len; ++i) {
        int num = nums[i];
        for (int j = i - 1; j >= 0; --j) {
            if (nums[j] > num && !reverse || nums[j] < num && reverse) swap(nums[j + 1], nums[j]);
            else {
                nums[j + 1] = num;
                break;
            }
        }
    }
}

void Sort::MergeSort(int *arr, int len, bool reverse) {
    MergeSort(arr, 0, len, reverse);
}

void Sort::MergeSort(int *arr, int left, int right, int reverse) {
    if (right - left <= 1) return;
    int center = left + (right - left) / 2;
    MergeSort(arr, left, center, reverse);
    MergeSort(arr, center, right, reverse);
    merge(arr, left, center, center, right, reverse);
}

void Sort::merge(int *arr, int l1, int r1, int l2, int r2, int reverse) {
    // l1 < l2
    int start = l1;
    int* extra = new int[r2 - l1];
    int k = 0;
    while (l1 < r1 && l2 < r2) {
        if (arr[l1] < arr[l2] && !reverse || arr[l1] > arr[l2] && reverse)
            extra[k++] = arr[l1++];
        else
            extra[k++] = arr[l2++];
    }
    while (l1 < r1)
        extra[k++] = arr[l1++];
    while (l2 < r2)
        extra[k++] = arr[l2++];
    for (int i = start, j = 0; i < r2; ++i, ++j)
        arr[i] = extra[j];
    delete[] extra;
}
