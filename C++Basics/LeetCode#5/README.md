****1. ****

```Пример 1:

```
```Пример 2:

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
