#include <iostream>
#include <unordered_map>
#include <string>

struct Employee {
    std::string name;
    std::string position;
};

int main() {
    std::unordered_map<int, Employee> employees; // Unordered map для хранения информации о сотрудниках

    // Добавление нового сотрудника
    Employee newEmployee;
    newEmployee.name = "John Doe";
    newEmployee.position = "Software Engineer";
    int employeeID = 1;
    employees.insert(std::make_pair(employeeID, newEmployee));

    // Удаление существующего сотрудника
    int employeeToDeleteID = 1;
    auto it = employees.find(employeeToDeleteID);
    if (it != employees.end()) {
        employees.erase(it);
        std::cout << "Сотрудник с ID " << employeeToDeleteID << " был удалён.\n";
    } else {
        std::cout << "Сотрудник с ID " << employeeToDeleteID << " не найден.\n";
    }

    return 0;
}

