/******************************
 * File: introsort.h
 * Purpose: --TODO--
 * Authors: Ian Zhou.
 * Created: 11/30/2024
 ******************************/
#pragma once
#include <cmath>
#include <vector>
#include <functional>
#include "util.h"
#include "common_defs.h"

using namespace std;

class intro {
public:
    static void sort(vector<Listing>& arr, listComp lessThan);
    static void sort(vector<Listing>& arr, int start, int end, listComp lessThan);
private:

    static void introsort(vector<Listing>& arr, int start, int end, int depthLimit, listComp lessThan);
    
    static int partition(vector<Listing>& arr, int start, int end, listComp lessThan);
    
    static void heapsort(vector<Listing>& arr, int start, int end, listComp lessThan);

    static void heapify(vector<Listing>& arr, int n, int i, int start, listComp lessThan);

    static void insertionSort(vector<Listing>& arr, int start, int end, listComp lessThan);
};


void intro::sort(vector<Listing>& arr,
                 listComp lessThan) {
    int depthLimit = 2 * static_cast<int>(log2(arr.size()));
    introsort(arr, 0, arr.size() - 1, depthLimit, lessThan);
}

void intro::sort(vector<Listing> &arr, int start, int end,
                 function<bool(const Listing &, const Listing &)> lessThan) {
    int n = arr.size();
    // If "end" is out of range, sort whole array
    if (end >= n)
        end = n - 1;
    // If start invalid or start ahead of end, error found. (If start >= n, then start > (end <= n-1) will execute)
    if (start < 0 || start > end)
        throw runtime_error("Invalid sorting range! start = \" + to_string(start) +\n"
                            "                        \", end = \" + to_string(end)");

    int depthLimit = 2 * static_cast<int>(log2(n));
    introsort(arr, start, end, depthLimit, lessThan);
}

void intro::introsort(vector<Listing>& arr, int start, int end, int depthLimit,
                      listComp lessThan) {
    if (end - start <= 16) {
        insertionSort(arr, start, end, lessThan);
        return;
    }
    if (depthLimit == 0) {
        heapsort(arr, start, end, lessThan);
        return;
    }
    int pivot = partition(arr, start, end, lessThan);

    introsort(arr, start, pivot - 1, depthLimit - 1, lessThan);
    introsort(arr, pivot + 1, end, depthLimit - 1, lessThan);
}

int intro::partition(vector<Listing>& arr, int start, int end,
                     listComp lessThan) {
    Listing pivot = arr[end]; // Choose last element as the pivot
    int i = start - 1;

    for (int j = start; j < end; ++j) {
        if (lessThan(arr[j], pivot)) {
            swap(arr[++i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return i + 1;
}

void intro::heapsort(vector<Listing>& arr, int start, int end,
                     listComp lessThan) {
    int n = end - start + 1;

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i, start, lessThan);
    }

    // Extract elements from the heap
    for (int i = n - 1; i > 0; --i) {
        swap(arr[start], arr[start + i]);
        heapify(arr, i, 0, start, lessThan);
    }
}

void intro::heapify(vector<Listing>& arr, int n, int i, int start,
                    listComp lessThan) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If root < left child
    if (left < n && lessThan(arr[start + largest], arr[start + left])) {
        largest = left;
    }

    // If root < right child
    if (right < n && lessThan(arr[start + largest], arr[start + right])) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[start + i], arr[start + largest]);
        heapify(arr, n, largest, start, lessThan);
    }
}

void intro::insertionSort(vector<Listing>& arr, int start, int end,
                          listComp lessThan) {
    for (int i = start + 1; i <= end; ++i) {
        Listing key = arr[i];
        int j = i - 1;

        // Keep going while key < arr[j]
        while (j >= start && lessThan(key, arr[j]))
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

