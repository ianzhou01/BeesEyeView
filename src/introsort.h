/******************************
 * File: introsort.h
 * Purpose: Declaration of introsort static methods
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



