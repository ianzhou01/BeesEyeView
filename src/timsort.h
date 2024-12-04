/******************************
 * File: timsort.h
 * Purpose: --TODO--
 * Authors: Ian Zhou, Phoenix Cushman, Matthew Golden.
 * Created: 11/30/2024
 ******************************/

//TODO: Please format and set up this file (Follow the template of the other files I have created - Phoenix)
#pragma once
#include <cmath>
#include <vector>
#include "common_defs.h"
using namespace std;

class tim {
public:
    static void sort(vector<Listing>& arr, listComp lessThan);

private:
    static void timsort(vector<Listing>& arr, int length, int RUNSIZE, listComp lessThan);

    static void merge(vector<Listing>& arr, int l, int m, int r, listComp lessThan);

    static void insertionSort(vector<Listing>& arr, int l, int r, listComp lessThan);
};

void tim::sort(vector<Listing>& arr, listComp lessThan){
    int RUNSIZE = 32;
    timsort(arr, arr.size(), RUNSIZE, lessThan);
}

//Basic insertion sort
void tim::insertionSort(vector<Listing>& arr, int l, int r, listComp lessThan) {
    for (int i = l + 1; i <= r; i++) {
        Listing& temp = arr[i];
        int j = i - 1;
        while (j >= l && lessThan(temp, arr[j])) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

//Basic merge
void tim::merge(vector<Listing> &arr, int l, int m, int r, listComp lessThan) {
    int left_size = m - l + 1;
    int right_size = r - m;
    Listing left_array[left_size], right_array[right_size];

    //Getting values of left and right arrays
    for (int i = 0; i < left_size; i++) {
        left_array[i] = arr[l + i];
    }
    for (int i = 0; i < right_size; i++) {
        right_array[i] = arr[m + 1 + i];
    }

    int left_index = 0;
    int right_index = 0;
    int merged_index = l;

    //Doing the merge and inserting smallest of the left_array and right_array to output
    while (left_index < left_size && right_index < right_size) {
        if (lessThan(left_array[left_index], right_array[right_index])) {
            arr[merged_index] = left_array[left_index];
            left_index++;
        }
        else {
            arr[merged_index] = right_array[right_index];
            right_index++;
        }
        merged_index++;
    }

    //Getting remaining from left array
    while (left_index < left_size) {
        arr[merged_index] = left_array[left_index];
        merged_index++;
        left_index++;
    }

    //Getting remaining from right array
    while (right_index < right_size) {
        arr[merged_index] = right_array[right_index];
        merged_index++;
        right_index++;
    }
}

//Tim sort
void tim::timsort(vector<Listing> &arr, int length, int RUNSIZE, listComp lessThan) {
    //Separates array into RUNSIZE chunks and insertsion sorts each of those chunks
    for (int i = 0; i < length; i += RUNSIZE) {
        insertionSort(arr, i, min(i + RUNSIZE - 1, length - 1), lessThan);
    }

    //Goes through and merges the chunks that were insertion sorted
    for (int size = RUNSIZE; size < length; size *= 2) {
        for (int left = 0; left < length; left += 2 * size) {
            int middle = left + size - 1;
            int right = min(left + 2 * size - 1,  length - 1);
            if (middle < right) {
                merge(arr, left, middle, right, lessThan);
            }
        }
    }
}

