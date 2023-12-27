#include <iostream>

using std::swap;

class Sort {
private:
    static void MergeSort(int* arr, int left, int right, int reverse);
    static void merge(int* arr, int l1, int r1, int l2, int r2, int reverse);
public:
    static void InsertSort(int *nums, int len, bool reverse=false);
    static void MergeSort(int* arr, int len, bool reverse=false);
};
