#include <chrono>
#include <algorithm>
#include <string>
#include <iostream>
#include <list>
#include <chrono>
#include <fstream>
#include <data_generator.h>
#include <sort_algorithms.h>
#include <vector>


using namespace std;

#define RUN(x) {                \
    Run(#x, x, data);           \
}

string dataset;
vector<string> logs;


template<typename T, typename SortMethod>
void Run(const string& method_name, SortMethod sort_method, const list<T>& data) {
    cout << "Running the algorithm: " << method_name << endl;

    cout << "The original array: ";
    for (const auto& item : data) {
        cout << item << " ";
    }
    cout << endl;

    auto start = chrono::high_resolution_clock::now();
    list<T> sorted_data = data;
    auto stop = chrono::system_clock::now();
    auto time = chrono::duration_cast<chrono::microseconds>(stop - start).count();

    bool is_sorted = std::is_sorted(sorted_data.begin(), sorted_data.end());

    cout << "Algorithm " << method_name << (is_sorted ? " completed successfully." : " completed with an error.") << endl;
cout << "Time: " << duration << " mcs" << endl << endl;
}

int main() {
    int size = 100;
    cout << "************ Comparison of algorithms for sorting structures with sequential access ************" << endl;

    dataset = "BestCase";
    cout << "Testing on the best case...." << endl;
    list<int> data = generateBestData(size);
    RUN(heapSortAliev);
    RUN(treeSort);
    RUN(mergeSortBatmanov);
    RUN(gnomeSortNikitina);
    RUN(shakerSort);
    RUN(insertionSortSereda);

    dataset = "WorstCase";
    cout << "Testing on the worst case...." << endl;
    list<int> data = generateWorstData(size);
    RUN(heapSortAliev);
    RUN(treeSort);
    RUN(mergeSortBatmanov);
    RUN(gnomeSortNikitina);
    RUN(shakerSort);
    RUN(insertionSortSereda);

    dataset = "RandomCase";
    cout << "Testing on the random case...." << endl;
    list<int> data = generateRandomData(size);
    RUN(heapSortAliev);
    RUN(treeSort);
    RUN(mergeSortBatmanov);
    RUN(gnomeSortNikitina);
    RUN(shakerSort);
    RUN(insertionSortSereda);

}

