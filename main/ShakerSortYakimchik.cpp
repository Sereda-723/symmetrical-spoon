// #include <sort_algorithms.h>
// #include <iostream>
// #include <list>

// void ShakerSort(std::list<int>& data) {
//     bool swapped = true;
//     auto start = lst.begin();
//     auto end = lst.end();
//     --end;

//     while (swapped) {
//         swapped = false;

//         for (auto it = start; it != end; ++it) {
//             auto next = std::next(it);
//             if (*it > *next) {
//                 std::swap(*it, *next);
//                 swapped = true;
//             }
//         }

//         if (!swapped)
//             break;

//         swapped = false;
//         --end;

//         for (auto it = end; it != start; --it) {
//             auto prev = std::prev(it);
//             if (*prev > *it) {
//                 std::swap(*prev, *it);
//                 swapped = true;
//             }
//         }

//         ++start;
//     }
//     }
// }