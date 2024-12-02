#pragma once
#include <vector>

using namespace std;

class QuickSort {
public:
    template<class T> static void sort(vector<T>& arr);
private:
    template<class T> static void quickSort(vector<T>& arr, int low, int high);
    template<class T> static int partition(vector<T>& arr, int low, int high);
};

template<class T>
void QuickSort::sort(vector<T>& arr) {
    if (arr.empty()) return; // Guard against empty arrays
    quickSort(arr, 0, arr.size() - 1);
}

template<class T>
void QuickSort::quickSort(vector<T>& arr, int low, int high) {
    if (low < high) {
        // Partition array
        int pi = partition(arr, low, high);

        // Pivot is now in position
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

template<class T>
int QuickSort::partition(vector<T>& arr, int low, int high) {
    // Choose pivot element (here, we choose the last element)
    T pivot = arr[high];
    int i = low - 1; // Index of smaller element

    // Traverse array, rearranging elements
    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    // Place the pivot in position
    swap(arr[i + 1], arr[high]);
    return i + 1; // Return pivot index
}
