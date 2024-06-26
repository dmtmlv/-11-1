## Сравните std::vector и std::list на примере вашего кода. В каких ситуациях вы использовали каждый из этих контейнеров и почему?

### Пример использования std::vector:
```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Добавление элемента в конец вектора
    vec.push_back(6);

    // Доступ к элементам по индексу
    std::cout << "Element at index 2: " << vec[2] << std::endl;

    // Перебор элементов вектора
    for (int i : vec) {
        std::cout << i << " ";
    }

    return 0;
}
```


### Пример использования std::list:
```cpp
#include <iostream>
#include <list>

int main() {
    std::list<int> mylist = {1, 2, 3, 4, 5};

    // Добавление элемента в начало списка
    mylist.push_front(0);

    // Удаление элемента из списка
    mylist.pop_back();

    // Перебор элементов списка
    for (int i : mylist) {
        std::cout << i << " ";
    }

    return 0;
}
```
std::vector и std::list оба представляют собой контейнеры для хранения коллекций данных, однако они отличаются по своей внутренней реализации и производительности в разных операциях.

**std::vector:**
- Память выделяется непрерывным блоком, что обеспечивает быстрый доступ по индексу.
- Быстрые операции добавления и удаления в конец вектора.
- Медленные операции добавления и удаления в середину вектора из-за необходимости сдвигать последующие элементы.
- Подходит для ситуаций, когда требуется произвольный доступ к элементам и частые добавления/удаления в конец.

**std::list:**
- Данные хранятся в виде двусвязного списка, что обеспечивает быстрые операции добавления и удаления в середине списка.
- Медленный доступ к элементу по индексу из-за необходимости прохода по всему списку.
- Подходит для ситуаций, когда требуется частая вставка/удаление в середину списка, но доступ по индексу не является основной операцией.
