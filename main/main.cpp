#include <chrono>
#include <algorithm>
#include <string>
#include <iostream>
#include <list>
#include <chrono>
#include <fstream>
#include "data/data_generator.h"
#include "algorithm/sort_algorithms.h"



using namespace std;

#define RUN(x, show_sort) {                \
    Run(#x, x, data, show_sort);           \
}

string dataset;



template<typename T, typename SortMethod>
void Run(const string& method_name, SortMethod sort_method, const list<T>& data, bool show_sort = false) {
    cout << "Running the algorithm: " << method_name << endl;

    

    auto start = chrono::high_resolution_clock::now();
    list<T> sorted_data = data;
    sort_method(sorted_data);
    auto stop = chrono::system_clock::now();
    auto time = chrono::duration_cast<chrono::microseconds>(stop - start).count();

    bool is_sorted = std::is_sorted(sorted_data.begin(), sorted_data.end());

    cout << "Algorithm " << method_name << (is_sorted ? " completed successfully." : " completed with an error.") << endl;
    cout << "Time: " << time << " mcs" << endl << endl;

    if (show_sort) {
        cout << "Sorted array by " << method_name << ": " << endl;
        for (auto item : sorted_data) {
            cout << item << " ";
        }
        cout << endl << endl;
    }
}

int main() {
    int size = 100;
    list<int> data;

    cout << "************ Comparison of algorithms for sorting structures with sequential access ************" << endl;
    cout << "" << endl;

    
    dataset = "BestCase";
    cout << "Testing on the best case...." << endl;
    cout << "" << endl;
    data = generateBestData(size);
    cout << "The original array: " << endl;
    for (const auto& item : data) {
        cout << item << " ";
    }
    cout << endl << endl;
    
    RUN(insertionSort_Sereda, true);
    RUN(heapSort_Aliev, false);
    RUN(mergeSort_Batmanov, false);
    RUN(BinaryTree_Serbulova, false);
    RUN(gnomeSort_Nikitina, false);
    RUN(ShakerSort_Yakimchik, false);


    dataset = "WorstCase";
    cout << "Testing on the worst case...." << endl;
    data = generateWorstData(size);
    cout << "The original array: " << endl;
    for (const auto& item : data) {
        cout << item << " ";
    }
    cout << endl << endl;
    
    RUN(insertionSort_Sereda, true);
    RUN(heapSort_Aliev, false);
    RUN(mergeSort_Batmanov, false);
    RUN(BinaryTree_Serbulova, false);
    RUN(gnomeSort_Nikitina, false);
    RUN(ShakerSort_Yakimchik, false);


    dataset = "RandomCase";
    cout << "Testing on the random case...." << endl;
    data = generateRandomData(size);
    cout << "The original array: " << endl;
    for (const auto& item : data) {
        cout << item << " ";
    }
    cout << endl << endl;
    
    RUN(insertionSort_Sereda, true);
    RUN(heapSort_Aliev, false);
    RUN(mergeSort_Batmanov, false);
    RUN(BinaryTree_Serbulova, false);
    RUN(gnomeSort_Nikitina, false);
    RUN(ShakerSort_Yakimchik, false);


    cout << "Press Enter to exit...";
    cin.get();  
    return 0;

}

