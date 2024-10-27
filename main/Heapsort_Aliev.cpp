#include <iostream>
#include <list>

using namespace std;

void heapify(list<int>& arr, int n, int i) {
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (left < n && arr.begin() != arr.end() && next(arr.begin(), left) != arr.end() && *next(arr.begin(), left) > *next(arr.begin(), largest)) {
        largest = left;
    }

    if (right < n && arr.begin() != arr.end() && next(arr.begin(), right) != arr.end() && *next(arr.begin(), right) > *next(arr.begin(), largest)) {
        largest = right;
    }

    if (largest != i) {
        swap(*next(arr.begin(), i), *next(arr.begin(), largest));

        heapify(arr, n, largest);
    }
}

void heapSort(list<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(*arr.begin(), *next(arr.begin(), i));

        heapify(arr, i, 0);
    }
}

int main(list<int>& data) {
    list<int> arr = data;


    heapSort(arr);

    return 0;
}
