****1. Числа Фибоначчи, обычно обозначаемые, образуют последовательность, называемую последовательностью Фибоначчи, такую, что каждое число является суммой двух предыдущих.****

```**Пример 1:**
Input: n = 2
Output: 1
```
```**Пример 2:**
Input: n = 3
Output: 2

```
**Решение:**
```cpp
class Solution {
public:
    int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    int prev = 0;
    int curr = 1;
    for (int i = 2; i <= n; i++) {
        int temp = curr;
        curr = prev + curr;
        prev = temp;
    }
    return curr;
}
};
```
