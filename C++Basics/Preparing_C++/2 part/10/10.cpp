#include <iostream>
#include <map>
#include <vector>

// Структура для представления заказа
struct Order {
    std::vector<std::string> dishes;
};

int main() {
    std::map<int, Order> orders; // Хранение заказов

    // Добавление нового заказа
    int orderId = 1; // Пример уникального ID заказа
    Order newOrder;
    newOrder.dishes = {"Pasta", "Salad", "Cake"}; // Пример списка блюд
    orders[orderId] = newOrder;

    // Удаление заказа
    orders.erase(orderId);

    return 0;
}

