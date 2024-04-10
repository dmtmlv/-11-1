1. Дан массив с объектами, окрашенными в красный, белый или синий цвет, отсортируйте их по месту таким образом, чтобы объекты одного цвета были смежными, с цветами в порядке красного, белого и синего.
Мы будем использовать целые числа 0, 1 и 2 для представления цвета красного, белого и синего соответственно.
Эту проблему необходимо решить без использования функции сортировки библиотеки.

 

```**Пример 1:**

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
```
```**Пример 2:**

Input: nums = [2,0,1]
Output: [0,1,2]
```

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
