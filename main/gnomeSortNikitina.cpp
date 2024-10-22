#include <sort_algorithms.h>
#include <iostream>
#include <list>

void gnomeSortNikitina(std::list<int>& data) {
    if (lst.size() < 2) {
        return;
    }

    auto it = lst.begin();
    auto prev = it;

    std::advance(it, 1);

    while (it != lst.end()) {
        if (*prev <= *it) {
            prev = it;
            ++it;
        } else {
            std::iter_swap(it, prev);

            if (prev != lst.begin()) {
                --it;
                --prev;
            } else {
                ++it;
                prev = it;
                --prev;
            }
        }
    }
}