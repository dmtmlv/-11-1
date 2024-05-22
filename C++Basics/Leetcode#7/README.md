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

****2. Вы поднимаетесь по лестнице. Чтобы добраться до вершины, нужно сделать несколько шагов****

```**Пример 1:**
Input: n = 2
Output: 2
```
```**Пример 2:**
Input: n = 3
Output: 3

```
**Решение:**
```cpp
class Solution {
public:
    int climbStairs(int n) {
    if (n == 1) {
        return 1;
    }

    std::vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}
};
```

****3. Реализуем pow(x, n), который вычисляет возведенный в степень****

```**Пример 1:**
Input: x = 2.00000, n = 10
Output: 1024.00000
```
```**Пример 2:**
Input: x = 2.10000, n = 3
Output: 9.26100

```
**Решение:**
```cpp
class Solution {
public:
 double myPow(double x, int n) {
    if (n == 0) {
        return 1.0;
    }
    if (n < 0) {
        x = 1 / x;
        n = -n;
    }
    double result = 1.0;
    double current_product = x;
    for (int i = n; i > 0; i /= 2) {
        if (i % 2 == 1) {
            result *= current_product;
        }
        current_product *= current_product;
    }
    return result;
}
};
```
