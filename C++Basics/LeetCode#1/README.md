****1. Дан двоичный массив, возвращаем максимальное количество последовательных в массиве nums 1****

```**Пример 1:**
Input: nums = [1,1,0,1,1,1]   Output: 3
```
```**Пример 2:**
Input: nums = [1,0,1,1,0,1]   Output: 2
```
**Решение:**

```cpp
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:

    int findMaxConsecutiveOnes(std::vector<int>& nums) {
        int maxOnes = 0;
        int result = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                result++;
            } else {
                maxOnes = std::max(maxOnes, result);
                result = 0;
            }
        }

        maxOnes = std::max(maxOnes, result);

        return maxOnes;
    }    
};

int main() {
    Solution solution;
    std::vector<int> nums = {1, 1, 0, 1, 1, 1};
    std::cout << solution.findMaxConsecutiveOnes(nums) << std::endl;

    return 0;
}
```




****2. Дан массив целых чисел, возвращает, сколько из них содержат четное количество цифр.nums****
 
```**Пример 1:**
Input: nums = [12,345,2,6,7896]    Output: 2
```
```**Пример 2:**
Input: nums = [555,901,482,1771]    Output: 1
```
**Решение:**
```cpp
#include <iostream>
#include <vector>

class Solution {
public:
    int findNumbers(std::vector<int>& nums) {
        int result = 0;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int digitCount = 0;

            while (num > 0) {
                num = num / 10;
                digitCount++;
            }

            if (digitCount % 2 == 0) {
                  result++;
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {123, 345, 233, 6, 73896};
    std::cout << solution.findNumbers(nums);
}
```


**3. Дан целочисленный массив, отсортированный в неубывающем порядке, возвращает массив квадратов каждого числа, отсортированных в неубывающем порядке.nums**

```**Пример 1:**
Input: nums = [-4,-1,0,3,10]    Output: [0,1,9,16,100]
```
```**Пример 2:**
Input: nums = [-7,-3,2,3,11]    Output: [4,9,9,49,121]
```
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            nums[i] = nums[i] * nums[i];
        }
        std::sort(nums.begin(), nums.end());
        return nums;
    }
};

int main(){
    Solution solution;
    std::vector<int> nums = {-4, -1, 0, 3, 10};
    std::vector<int> result = solution.sortedSquares(nums);
    for (int num : result) {
        std::cout << num << " ";
    }
}
