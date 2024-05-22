****1. Напишите функцию, которая переворачивает строку. Входная строка задается в виде массива символов.
Это необходимо сделать, изменив входной массив на месте с помощью дополнительной памяти.****

```**Пример 1:**
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
```
```**Пример 2:**
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

```
**Решение:**
```cpp
class Solution {
public:
    void reverseString(std::vector<char>& s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }
}
};
```

****2. Учитывая односвязный список, переверните список и верните перевернутый список****

```**Пример 1:**
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
```
```**Пример 2:**
Input: head = [1,2]
Output: [2,1]

```
**Решение:**
```cpp
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        return prev;
    }
};
```

****3. Если у вас есть связанный список, поменяйте местами каждые два соседних узла и верните его голову. Вы должны решить проблему, не изменяя значения в узлах списка (т.е. могут быть изменены только сами узлы).****

```**Пример 1:**
Input: head = [1,2,3,4]
Output: [2,1,4,3]

```
```**Пример 2:**
Input: head = [1]
Output: [1]
```
**Решение:**
```cpp
struct ListNode {    
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        while (head && head->next) {
            ListNode* first = head;
            ListNode* second = head->next;
            prev->next = second;
            first->next = second->next;
            second->next = first;
            prev = first;
            head = first->next;
        }
        return dummy->next;
    }
};
```
