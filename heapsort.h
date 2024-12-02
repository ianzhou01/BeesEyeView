#pragma once
#include <vector>
using namespace std;

class Heap {
public:
    template<class T> static void maxHeapify(T* arr, int n);
    template<class T> static void maxHeapify(vector<T>& arr);
    template<class T> static void minHeapify(T* arr, int n);
    template<class T> static void minHeapify(vector<T>& arr);

    template<class T> static void sort(vector<T>& arr, bool reverse = false);
    template<class T> static void sort(T *arr, int n, bool reverse = false);
private:
    template<class T> static void maxHeapifyDown(T *arr, int n, int i);
    template<class T> static void minHeapifyDown(T *arr, int n, int i);
};

template<class T>
void Heap::maxHeapifyDown(T *arr, int n, int i) {
    int largest = i; // Initial value
    while (i < n) {
        int left = 2 * i + 1; // Left child
        int right = 2 * i + 2; // Right child

        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;

        // Now, we have the largest of the three (the parent and two children)
        if (largest != i) {
            swap(arr[largest], arr[i]);
            i = largest;
        } else
            break; // Parent is greater than both children
    }
}

template<class T>
void Heap::minHeapifyDown(T* arr, int n, int i) {
    int smallest = i; // Initial value
    while (i < n) {
        int left = 2 * i + 1; // Left child
        int right = 2 * i + 2; // Right child

        if (left < n && arr[left] < arr[smallest])
            smallest = left;

        if (right < n && arr[right] < arr[smallest])
            smallest = right;

        // Now, we have the smallest of the three (the parent and two children)
        if (smallest != i) {
            swap(arr[smallest], arr[i]);
            i = smallest;
        } else
            break; // Parent is greater than both children
    }
}
// public functions

template<class T>
void Heap::maxHeapify(T *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; --i) { // Build max heap in place
        maxHeapifyDown(arr, n, i);
    }
}

template<class T>
void Heap::maxHeapify(vector<T>& arr) {
    maxHeapify(arr.data(), arr.size());
}

template<class T>
void Heap::minHeapify(T *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; --i) { // Build min heap in place
        minHeapifyDown(arr, n, i);
    }
}

template<class T>
void Heap::minHeapify(vector<T>& arr) {
    minHeapify(arr.data(), arr.size());
}

template<class T>
void Heap::sort(vector<T>& arr, bool reverse) {
    sort(arr.data(), arr.size(), reverse);
}

template<class T>
void Heap::sort(T *arr, int n, bool reverse) {
    if (!reverse) { // Sort in order
        for (int i = n / 2 - 1; i >= 0; --i) { // Build max heap in place
            maxHeapifyDown(arr, n, i);
        }
        for (int i = n - 1; i > 0; --i) { // Delete all elements from heap to sort
            swap(arr[i], arr[0]);
            maxHeapifyDown(arr, i, 0);
        }
    }
    else { // Sort in reverse
        for (int i = n / 2 - 1; i >= 0; --i) { // Build min heap in place
            minHeapifyDown(arr, n, i);
        }
        for (int i = n - 1; i > 0; --i) { // Delete all elements from heap to sort
            swap(arr[i], arr[0]);
            minHeapifyDown(arr, i, 0);
        }
    }
}

