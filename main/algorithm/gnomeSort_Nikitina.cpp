#include "sort_algorithms.h"
#include <iostream>
#include <list>

void gnomeSort_Nikitina(std::list<int>& data) {
    if (data.size() < 2) {
        return;
    }

    auto it = data.begin();
    auto prev = it;

    std::advance(it, 1);

    while (it != data.end()) {
        if (*prev <= *it) {
            prev = it;
            ++it;
        } else {
            std::iter_swap(it, prev);

            if (prev != data.begin()) {
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