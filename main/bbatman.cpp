#include <sort_algorithms.h> 
#include <iostream> 
#include <list> 

void insertionSortSereda(std::list<int>& data) {

}

using namespace std;

void merge(list<int>& arr, list<int>::iterator left, list<int>::iterator mid, list<int>::iterator right) {
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
}

void mergeSort(list<int>& arr) {
    left = arr.begin();
    right = arr.end();
    if (distance(left, right) > 1) {
        auto mid = next(left, distance(left, right) / 2);

        mergeSort(arr, left, mid);
        mergeSort(arr, mid, right);

        merge(arr, left, mid, right);
    }
}