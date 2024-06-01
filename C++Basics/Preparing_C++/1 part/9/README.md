## Опишите, как вы создавали и обрабатывали собственный класс исключений в C++. Приведите примеры, где ваши исключения помогли улучшить обработку ошибок в программе.

### Move semantics — это механизм в C++, который позволяет эффективно перемещать ресурсы (например, память) из одного объекта в другой без лишних копирований. Это достигается за счет использования правильного и эффективного обмена ресурсами между объектами.
```cpp
#include <iostream>
#include <exception>

class CustomException : public std::exception {
public:
    CustomException(const char* message) : msg(message) {}
    
    const char* what() const throw() {
        return msg.c_str();
    }
    
private:
    std::string msg;
};

int divide(int a, int b) {
    if (b == 0) {
        throw CustomException("Division by zero");
    }
    return a / b;
}

int main() {
    try {
        int result = divide(10, 0);
        std::cout << "Result: " << result << std::endl;
    } catch (const CustomException& e) {
        std::cerr << "Custom Exception caught: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Standard Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
```
### В данном примере класс MyString имеет обычный конструктор для инициализации строки и move constructor для эффективного перемещения данных. При вызове std::move(a) в функции main(), ресурсы строки из объекта a перемещаются в объект b, а при этом в объекте a указатель на строку становится нулевым, тем самым избегая дополнительного копирования памяти.

#### Использование move semantics позволяет значительно повысить производительность приложения, так как при перемещении объектов вместо копирования ресурсов, можно просто "перехватить" эти ресурсы, что особенно важно при работе с большими объемами данных. Это позволяет уменьшить нагрузку на процессор и использовать ресурсы более эффективно, что в конечном итоге улучшает производительность приложения.
