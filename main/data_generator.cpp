#include <data_generator.h>



std::list<int> generateBestData(int size) {
    std::list<int> best_case;
    for (int i = 1; i <= size; ++i) {
        best_case.push_back(i);
    }
    return best_case;
}

std::list<int> generateWorstData(int size) {
    std::list<int> worst_case;
    for (int i = size; i >= 1; i--) {
        worst_case.push_back(i);
    }
    return worst_case;
}

std::list<int> generateRandomData(int size) {
    std::list<int> random_case;
    for (int i = 0; i <= size; ++i) {
        random_case.push_back(rand() % 100);
    }
    return random_case;
}

