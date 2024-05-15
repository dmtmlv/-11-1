****1. Дан массив целых чисел arr, возвращает true тогда и только тогда, когда это допустимый массив гор.****
****Напомним, что arr является горным массивом тогда и только тогда, когда:****
- arr.length >= 3
- Существуют такие, которые: i0 < i < arr.length - 1
  - arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
  - arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

```Пример 1:
Input: arr = [2,1]
Output: false
```
```Пример 2:
Input: arr = [0,3,2,1]
Output: true
```
```cpp
class Solution {
public:
    bool validMountainArray(std::vector<int>& arr) {
    int n = arr.size();

    if (n < 3) {
        return false;
    }

    int i = 0;
        
    while (i+1 < n && arr[i] < arr[i+1]) {
        i++;
    }

    // Пик горы не может быть на краю массива
    if (i == 0 || i == n-1) {
        return false;
    }

    // Спускаемся по убыванию
    while (i+1 < n && arr[i] > arr[i+1]) {
        i++;
    }

    return i == n-1;
    }
};
```



****2. Дан целочисленный массив и целое число. Программа должна возвращать наибольший элемент в массиве****

```Пример 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
```
```Пример 2:
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
```

**Решение:**
```cpp
#include <iostream>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int k = 4;
    int arr[] = { 3,2,3,1,2,4,5,5,6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

  for (int i = 0; i < n; i++) {
      std::cout << arr[i] << " ";
  }
    for (int i = 0; i < n; i++) {
      std::cout<<'\n';
      std::cout << arr[n-k] << " ";
      break;
    }
}
```
