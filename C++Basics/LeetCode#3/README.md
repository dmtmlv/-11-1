****1. Дан целочисленный массив. Программа должна возвращать максимальную разницу между двумя последовательными элементами в отсортированном виде. Если массив содержит менее двух элементов, то возвращает 0****

```**Пример 1:**
Input: nums = [3,6,9,1]
Output: 3
```
```**Пример 2:**
Input: nums = [10]
Output: 0
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
  int max = -1000;
  int arr[] = {10, 4,2,100,2,8,12,43,77};
  int n = sizeof(arr) / sizeof(arr[0]);

  insertionSort(arr, n);

  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  int count = 0;
  for (int i = 0; i < n; i++){
    if(abs(arr[i] - arr[i+1]) > max){
      max = abs(arr[i] - arr[i+1]);
    }
    else if(n <= 1){
      max = 0;
    }
    else{
      count++;
      i ++;
    }
  }
  std::cout<<"\n"<< max;
}
```

****2. Дан целочисленный массив фиксированной длины, дублируйте каждое вхождение нуля, сдвигая оставшиеся элементы вправо.
Обратите внимание, что элементы, превышающие длину исходного массива, не записываются. Внесите описанные выше изменения во входной массив на месте и ничего не возвращайте.****

```Пример 1
Input: arr = [1,0,2,3,0,4,5,0]
Output: [1,0,0,2,3,0,0,4]
```
```Пример 2
Input: arr = [1,2,3]
Output: [1,2,3]
```
```cpp
#include <iostream>

class Solution {
public:
    static void duplicateZeros(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                for (int j = n - 1; j > i; j--) {
                    arr[j] = arr[j - 1];
                }
                i++;
            }
        }
    }
};

int main() {
    Solution s;
    int arr[] = {1,0,2,3,0,4,5,0};
    int n = sizeof(arr) / sizeof(arr[0]);
    Solution::duplicateZeros(arr, n);

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
}
```
