#include <iostream>
#include <vector>

//Функция для нахождения максимального числа в массиве
int findMax(std::vector<int>& arr) {
    int max = arr[0];
    for (int num : arr) {
        if (num > max) {
            max = num;
        }
    }
    return max;
}

//Функция для выполнения цифровой сортировки
void countSort(std::vector<int>& arr, int exp) {
    std::vector<int> output(arr.size());
    std::vector<int> count(10, 0);

    for (int i = 0; i < arr.size(); i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

void radixSort(std::vector<int>& arr) {
    int max = findMax(arr);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, exp);
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    std::vector<int> arr = { 64, 34, 25, 12, 22, 11, 90 };

    std::cout << "Исходный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    radixSort(arr);

    std::cout << "\nОтсортированный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    return 0;
}