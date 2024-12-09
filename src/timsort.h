/******************************
 * File: timsort.h
 * Purpose: Declaration of timsort static methods
 * Authors: Matthew Golden, Ian Zhou, Phoenix Cushman.
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

    static void sort(vector<Listing>& arr, int start, int end, listComp lessThan);


private:
    static void timsort(vector<Listing>& arr, int start, int end, int RUNSIZE, listComp lessThan);

    static void merge(vector<Listing>& arr, int l, int m, int r, listComp lessThan);

    static void insertionSort(vector<Listing>& arr, int l, int r, listComp lessThan);
};
