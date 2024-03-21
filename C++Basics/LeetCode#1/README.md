****1. Дан двоичный массив, возвращаем максимальное количество последовательных в массиве nums 1****

**Пример 1:**
Input: nums = [1,1,0,1,1,1]   Output: 3

**Пример 2:**
Input: nums = [1,0,1,1,0,1]   Output: 2

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
 
**Пример 1:**

Input: nums = [12,345,2,6,7896]    Output: 2

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
