#include <iostream>
#include <cmath>

using std::swap;
using std::floor;
using std::max;

class Sort {
public:
    static void QuickSort(int *nums, int len, int start = 0, int end = -1);
    static void PyramidalSort(int *arr, int len);
};

void print(int* arr, int len);
