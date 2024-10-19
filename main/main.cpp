#include <chrono>
#include <algorithm>
#include <string>
#include <iostream>
#include <list>
#include <chrono>
#include <fstream>
#include <data_generator.h>

using namespace std;

#define RUN(x) {                \
    Run(#x, x, data);           \
}

template<typename T, typename SortMethod>
void Run(const string& method_name, SortMethod sort_method, const list<T>& data) {
    cout << "Running the algorithm: " << method_name << endl;

    auto start = chrono::high_resolution_clock::now();
    list<T> sorted_data = data;
    auto stop = chrono::system_clock::now();
    auto time = chrono::duration_cast<chrono::microseconds>(stop - start).count();

    bool is_sorted = std::is_sorted(sorted_data.begin(), sorted_data.end());

    cout << "Algorithm " << method_name << (is_sorted ? " completed successfully." : " completed with an error.") << endl;
cout << "Time: " << duration << " mcs" << endl << endl;
}