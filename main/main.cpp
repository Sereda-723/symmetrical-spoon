#include <chrono>
#include <algorithm>
#include <string>
#include <iostream>
#include <list>
#include <chrono>
#include <fstream>
#include "data_generator.h"
#include "sort_algorithms.h"
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
    sort_method(sorted_data);
    auto stop = chrono::system_clock::now();
    auto time = chrono::duration_cast<chrono::microseconds>(stop - start).count();

    bool is_sorted = std::is_sorted(sorted_data.begin(), sorted_data.end());

    cout << "Algorithm " << method_name << (is_sorted ? " completed successfully." : " completed with an error.") << endl;
cout << "Time: " << time << " mcs" << endl << endl;
}

int main() {
    int size = 100;
    list<int> data;

    cout << "************ Comparison of algorithms for sorting structures with sequential access ************" << endl;

    
    dataset = "BestCase";
    cout << "Testing on the best case...." << endl;
    data = generateBestData(size);
    RUN(heapSort_Aliev);
    // RUN(treeSort);
    // RUN(mergeSortBatmanov);
    // RUN(gnomeSortNikitina);
    // RUN(shakerSort);
    // RUN(insertionSortSereda);

    dataset = "WorstCase";
    cout << "Testing on the worst case...." << endl;
    data = generateWorstData(size);
    RUN(heapSort_Aliev);
    // RUN(treeSort);
    // RUN(mergeSortBatmanov);
    // RUN(gnomeSortNikitina);
    // RUN(shakerSort);
    // RUN(insertionSortSereda);

    dataset = "RandomCase";
    cout << "Testing on the random case...." << endl;
    data = generateRandomData(size);
    RUN(heapSort_Aliev);
    // RUN(treeSort);
    // RUN(mergeSortBatmanov);
    // RUN(gnomeSortNikitina);
    // RUN(shakerSort);
    // RUN(insertionSortSereda);

    cout << "Press Enter to exit...";
    cin.get();  
    return 0;

}

