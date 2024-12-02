#pragma once
#include <vector>

using namespace std;

class Insertion {
public:
    template <class T> static void sort(vector<T>& arr);
};

template<class T>
void Insertion::sort(vector<T> &arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i]; // Store next unsorted element
        int j = i - 1; // Index previous element

        // Shift everything until value has proper spot
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        // Replace duplicate with stored element
        arr[j + 1] = key;
    }
}
