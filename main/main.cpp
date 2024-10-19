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

template<typename T>

