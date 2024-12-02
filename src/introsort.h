/******************************
 * File: introsort.h
 * Purpose: --TODO--
 * Authors: Ian Zhou.
 * Created: 11/30/2024
 ******************************/

//TODO: Please format and set up this file (Follow the template of the other files I have created - Phoenix)
#pragma once
#include <cmath>
#include <vector>

using namespace std;

class intro {
public:
    template <class T>
    static void sort(vector<T>& arr);

private:
    template <class T>
    static void introsort(vector<T>& arr, int start, int end, int depthLimit);

    template <class T>
    static int partition(vector<T>& arr, int start, int end);

    template <class T>
    static void heapsort(vector<T>& arr, int start, int end);

    template <class T>
    static void heapify(vector<T>& arr, int n, int i, int start);

    template <class T>
    static void insertionSort(vector<T>& arr, int start, int end);
};

template <class T>
void intro::sort(vector<T>& arr) {
    int depthLimit = 2 * log2(arr.size());
    introsort(arr, 0, arr.size() - 1, depthLimit);
}

template <class T>
void intro::introsort(vector<T>& arr, int start, int end, int depthLimit) {
    if (end - start <= 16) {
        insertionSort(arr, start, end);
        return;
    }
    if (depthLimit == 0) {
        heapsort(arr, start, end);
        return;
    }
    int pivot = partition(arr, start, end);

    introsort(arr, start, pivot - 1, depthLimit - 1);
    introsort(arr, pivot + 1, end, depthLimit - 1);
}

template <class T>
int intro::partition(vector<T>& arr, int start, int end) {
    T pivot = arr[end]; // Choose last element as the pivot
    int i = start - 1;

    for (int j = start; j < end; ++j) {
        if (arr[j] <= pivot) {
            swap(arr[++i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return i + 1;
}

template <class T>
void intro::heapsort(vector<T>& arr, int start, int end) {
    int n = end - start + 1;

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i, start);
    }

    // Extract elements from the heap
    for (int i = n - 1; i > 0; --i) {
        swap(arr[start], arr[start + i]);
        heapify(arr, i, 0, start);
    }
}

template <class T>
void intro::heapify(vector<T>& arr, int n, int i, int start) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[start + left] > arr[start + largest]) {
        largest = left;
    }

    if (right < n && arr[start + right] > arr[start + largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[start + i], arr[start + largest]);
        heapify(arr, n, largest, start);
    }
}

template <class T>
void intro::insertionSort(vector<T>& arr, int start, int end) {
    for (int i = start + 1; i <= end; ++i) {
        T key = arr[i];
        int j = i - 1;

        while (j >= start && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

