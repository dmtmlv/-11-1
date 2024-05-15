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
