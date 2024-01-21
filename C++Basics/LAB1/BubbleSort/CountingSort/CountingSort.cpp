#include <iostream>
#include <vector>

void countingSort(std::vector<int>& arr, int max) {
    std::vector<int> count(max + 1, 0);
    std::vector<int> result(arr.size());

    for (int num : arr) {
        count[num]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        result[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (size_t i = 0; i < arr.size(); i++) {
        arr[i] = result[i];
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    std::vector<int> arr = { 64, 34, 25, 12, 22, 11, 90 };
    int max = 90;

    std::cout << "Исходный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    countingSort(arr, max);

    std::cout << "\nОтсортированный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    return 0;
}