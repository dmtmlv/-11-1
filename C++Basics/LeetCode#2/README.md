****1. Дан массив с объектами, окрашенными в красный, белый или синий цвет, отсортируйте их по месту таким образом, чтобы объекты одного цвета были смежными, с цветами в порядке красного, белого и синего.
Мы будем использовать целые числа 0, 1 и 2 для представления цвета красного, белого и синего соответственно.
Эту проблему необходимо решить без использования функции сортировки библиотеки.****

```**Пример 1:**
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
```
```**Пример 2:**
Input: nums = [2,0,1]
Output: [0,1,2]
```
**Решение**

```cpp
#include <iostream>
#include <vector>

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int red = 0, white = 0, blue = nums.size()-1;

        while(white <= blue) {
            if(nums[white] == 0) {
                std::swap(nums[white], nums[red]);
                red++;
                white++;
            } else if(nums[white] == 1) {
                white++;
            } else {
                std::swap(nums[white], nums[blue]);
                blue--;
            }
        }
    }
};

int main() {
    Solution solution;
    std::vector<int> colors = {2, 0, 2, 1, 1, 0};

    solution.sortColors(colors);

    std::cout << "Sorted colors: ";
    for(int color : colors) {
        std::cout << color << " ";
    }
    return 0;
}
```

 
 
 
****2. Школа пытается ежегодно фотографировать всех учеников. Студентам предлагается встать в одну линию в порядке убывания по росту. Пусть этот порядок представлен целочисленным массивом, где — ожидаемый рост ученика в строке expectedexpected[i]
Вам дан целочисленный массив, представляющий текущий порядок, в котором находятся студенты. Каждый из них соответствует росту ученика в строке (с индексом 0) heightsheights[i]
Программа должна возвращать количество индексов, где heights[i] != expected[i]****

 

```**Пример 1:**
Input: heights = [1,1,4,2,1,3]
Output: 3
Explanation:
heights:  [1,1,4,2,1,3]
expected: [1,1,1,2,3,4]
```

```**Пример 2:**
Input: heights = [5,1,2,3,4]
Output: 5
Explanation:
heights:  [5,1,2,3,4]
expected: [1,2,3,4,5]
```
**Решение**
```cpp
#include <iostream>
#include <vector>
#include<algorithm>

class Solution {
public:
    int heightChecker(std::vector<int>& heights) {
        std::vector<int> expected = heights;
        std::sort(expected.begin(), expected.end());

        int count = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (heights[i] != expected[i]) {
                count++;
            }
        }

        return count;
    }
};
int main(){
  std::vector<int> heights = {1,1,4,2,1,3};
  Solution s;
  std::cout << s.heightChecker(heights);
}
```


****3. Учитывая односвязный список, отсортируйте список с помощью сортировки вставкой и верните заголовок отсортированного списка****

```**Пример 1:**
Input: head = [4,2,1,3]
Output: [1,2,3,4]
```
```**Пример 2:**
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
```

```cpp Решение
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
    setlocale(LC_ALL, "ru");
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    insertionSort(arr, n);

    std::cout << "\nОтсортированный массив: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
```
