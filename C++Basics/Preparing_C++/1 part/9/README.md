## Опишите, как вы создавали и обрабатывали собственный класс исключений в C++. Приведите примеры, где ваши исключения помогли улучшить обработку ошибок в программе.

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
