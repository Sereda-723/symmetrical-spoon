#include "sort_algorithms.h"
#include <iostream>
#include <list>

using namespace std;

void merge(list<int>::iterator left, list<int>::iterator mid, list<int>::iterator right) {
    list<int> L(left, mid);
    list<int> R(mid, right);

    auto it = left;
    auto itL = L.begin();
    auto itR = R.begin();

    while (itL != L.end() && itR != R.end()) {
        if (*itL <= *itR) {
            *it = *itL;
            itL++;
        }
        else {
            *it = *itR;
            itR++;
        }
        it++;
    }

    while (itL != L.end()) {
        *it = *itL;
        itL++;
        it++;
    }
    while (itR != R.end()) {
        *it = *itR;
        itR++;
        it++;
    }

    mid = next(left, distance(left, mid) + distance(L.begin(), itL));
}

void mergeSort(list<int>& arr, list<int>::iterator left, list<int>::iterator right) {
    if (distance(left, right) > 1) {
        auto mid = next(left, distance(left, right) / 2);

        mergeSort(arr, left, mid);
        mergeSort(arr, mid, right);

        merge(left, mid, right);
    }
}

void mergeSort_Batmanov(list<int>& arr) {
    mergeSort(arr, arr.begin(), arr.end());
}
