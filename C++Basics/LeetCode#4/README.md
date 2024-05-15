****1. Дан целочисленный массив , возвращает третье отличное максимальное число в этом массиве. Если третий максимум не существует, возвращается максимальное число.nums****

```Пример 1:
Input: nums = [3,2,1]
Output: 1
```
```Пример 2:
Input: nums = [1,2]
Output: 2
```

```cpp
#include <iostream>
#include <vector>
#include <set>
#include<algorithm>

int thirdMax(std::vector<int>& nums) {
    std::set<int> uniqueNums(nums.begin(), nums.end());
    std::vector<int> uniqueNumsVector(uniqueNums.begin(), uniqueNums.end());

    std::sort(uniqueNumsVector.rbegin(), uniqueNumsVector.rend());

    if (uniqueNumsVector.size() < 3) {
        return uniqueNumsVector[0];
    } else {
        return uniqueNumsVector[2];
    }
}

int main() {
    std::vector<int> nums = {1,3,6,8,3,0,2,3,12,7,4};
    int result = thirdMax(nums);
    std::cout << result << std::endl;

    return 0;
}
```

****2. Дан целочисленный массив nums, переместить все четные целые числа в начало массива, за которыми следуют все нечетные целые числа.
Возвращает любой массив, удовлетворяющий этому условию.****

```Пример 1:
Input: nums = [3,1,2,4]
Output: [2,4,3,1]
```
```Пример 2:
Input: nums = [0]
Output: [0]
```

```cpp
#include <iostream>
#include <vector>

std::vector<int> moveEvenNumbers(std::vector<int>& nums) {
    int n = nums.size();
    int left = 0, right = n - 1;

    while (left < right) {
        if (nums[left] % 2 != 0) {
            if (nums[right] % 2 == 0) {
                std::swap(nums[left], nums[right]);
                left++;
                right--;
            } else {
                right--;
            }
        } else {
            left++;
        }
    }

    return nums;
}

int main() {
    std::vector<int> nums = {1,3,6,8,3,0,2,3,12,7,4};
    std::vector<int> result = moveEvenNumbers(nums);

    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```
****3. Дан целочисленный массив nums, переместить все нули в его конец, сохраняя относительный порядок ненулевых элементов.
Обратите внимание, что вы должны сделать это на месте, не создавая копию массива..****

```Пример 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
```
```Пример 2:
Input: nums = [0]
Output: [0]
```
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

void moveZeroes(std::vector<int>& nums) {
    int nonZeroIdx = 0;

    // Move all non-zero elements to the front
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            std::swap(nums[i], nums[nonZeroIdx]);
            nonZeroIdx++;
        }
    }
}

int main() {
    std::vector<int> nums = {0, 1, 0, 3, 12};

    moveZeroes(nums);

    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```
