#include <iostream>
#include <list>

struct Order {
    int id;
    std::string item;
};

int main() {
    std::list<Order> orders;

    // Добавление заказов
    orders.push_back({1, "Товар 1"});
    orders.push_back({2, "Товар 2"});
    orders.push_back({3, "Товар 3"});

    // Вывод списка заказов до отмены
    std::cout << "Список заказов до отмены:\n";
    for (const auto& order : orders) {
        std::cout << "Заказ #" << order.id << ": " << order.item << std::endl;
    }

    // Отмена заказа id = 2)
    int canceledOrderId = 2;
    auto it = std::find_if(orders.begin(), orders.end(), [canceledOrderId](const Order& order) {
        return order.id == canceledOrderId;
    });

    if (it != orders.end()) {
        orders.erase(it);
        std::cout << "Заказ #" << canceledOrderId << " был отменен.\n";
    } else {
        std::cout << "Заказ с id = " << canceledOrderId << " не найден.\n";
    }

    // Вывод списка заказов после отмены
    std::cout << "Список заказов после отмены:\n";
    for (const auto& order : orders) {
        std::cout << "Заказ #" << order.id << ": " << order.item << std::endl;
    }

    return 0;
}

