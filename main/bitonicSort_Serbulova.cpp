#include <iostream>
#include <list>
using namespace std;

template <typename T>
void bitonicMerge(list<T>& data, int low, int cnt) // cnt - count
{
    if (cnt > 1) {
        int k = cnt / 2;

        for (int i = low; i < low + k; ++i) {
            auto it1 = next(data.begin(), i);
            auto it2 = next(data.begin(), i + k);
            if (*it2 < *it1) {
                iter_swap(it1, it2);
            }
        }

        bitonicMerge(data, low, k);         
        bitonicMerge(data, low + k, k);     
    }
}

template <typename T>
void bitonicSort(list<T>& data, int low, int cnt) 
{
    if (cnt > 1) {
        int k = cnt / 2;

        bitonicSort(data, low, k);

        bitonicMerge(data, low, cnt);
    }
}

void BitonicSortSerbulova(list<int>& data) {
    int n = data.size();
    int nextPowerOf2 = 1;

    while (nextPowerOf2 < n) {
        nextPowerOf2 *= 2;
    }

    list<T> paddedData(data);
    for (int i = 0; i < nextPowerOf2 - n; ++i) {
        paddedData.push_back(T{});
    }

    bitonicSort(paddedData, 0, paddedData.size());

    paddedData.remove(T{});

    return paddedData;
}