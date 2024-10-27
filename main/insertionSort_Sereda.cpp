#include "sort_algorithms.h"
#include <list>

void insertionSortSereda(std::list<int>& data) {
    for (auto it = std::next(data.begin()); it != data.end(); ++it) {

        int key = *it;
        auto j = it;

        while (j != data.begin() && *std::prev(j) > key) {
            *j = *std::prev(j);
            --j;

        }
        *j = key;

    }


}