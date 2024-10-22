#include <sort_algorithms.h>


void insertionSortSereda(std::list<int>& data) {

}

#include <iostream>
#include <list>

using namespace std;

// Функция для слияния двух отсортированных подсписков
void merge(list<int>& arr, list<int>::iterator left, list<int>::iterator mid, list<int>::iterator right) {
    // Создаем временные списки
    list<int> L(left, mid);
    list<int> R(mid, right);

    // Слияние отсортированных подсписков в исходный список
    auto it = left; // Итератор для исходного списка
    auto itL = L.begin();
    auto itR = R.begin();

    while (itL != L.end() && itR != R.end()) {
        if (*itL <= *itR) {
            *it = *itL;
            itL++;
        }
        else {
            *it = *itR;
            itR++;
        }
        it++;
    }

    // Копируем оставшиеся элементы (если есть)
    while (itL != L.end()) {
        *it = *itL;
        itL++;
        it++;
    }
    while (itR != R.end()) {
        *it = *itR;
        itR++;
        it++;
    }
}

// Рекурсивная функция для сортировки слиянием
void mergeSort(list<int>& arr, list<int>::iterator left, list<int>::iterator right) {
    if (distance(left, right) > 1) { // Проверяем, не является ли список пустым или не содержит ли он только один элемент
        // Находим середину списка
        auto mid = next(left, distance(left, right) / 2);

        // Рекурсивно сортируем левую и правую части
        mergeSort(arr, left, mid);
        mergeSort(arr, mid, right);

        // Сливаем отсортированные части
        merge(arr, left, mid, right);
    }
}

int main() {
    list<int> arr = { 12, 11, 13, 5, 6, 7 };

    setlocale(LC_ALL, "RU");

    cout << "Исходный список: ";
    for (auto it = arr.begin(); it != arr.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    mergeSort(arr, arr.begin(), arr.end());

    cout << "Отсортированный список: ";
    for (auto it = arr.begin(); it != arr.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
