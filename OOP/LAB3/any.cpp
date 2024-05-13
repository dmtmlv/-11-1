#include <iostream>
#include <typeinfo>
#include"any.h"
#include<iostream>

int main()
{
    setlocale(LC_ALL, "ru");
    any a;
    any b(13);
    any c(std::string("Hello world!"));
    any d(0.5);

    if (a.is_initialized()) { // проверка инициализации
        std::cout << "Объект 'a' инициализирован" << std::endl;
    }
    else {
        std::cout << "Объект 'a' не инициализирован" << std::endl;
    }

    try {
        std::cout << b.cast<int>() << std::endl;
        std::cout << d.cast<double>() << std::endl;
        std::cout << c.cast<double>() << std::endl; // вызов исключения bad_cast
        std::cout << a.cast<int>() << std::endl;  // вызов исключения any is not initialized
    }
    catch (const std::exception& e) {
        std::cout << "Исключение: " << e.what() << std::endl;
    }

    return 0;
}
