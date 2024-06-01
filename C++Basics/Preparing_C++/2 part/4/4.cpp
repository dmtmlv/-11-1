#include <iostream>
#include <unordered_map>

struct Task {
    int id;
    std::string description;
    bool completed;

    Task(int id, const std::string& desc) : id(id), description(desc), completed(false) {}
};

int main() {
    std::unordered_map<int, Task> tasks;

    // Добавление задач
    tasks.insert({1, Task(1, "Implement feature A")});
    tasks.insert({2, Task(2, "Fix bug in module B")}); 
    tasks.insert({3, Task(3, "Write documentation")});

    // Завершение задачи
    if (tasks.count(2)) {
        tasks[2].completed = true;
    }

    // Удаление задачи
    tasks.erase(1);

    // Вывод всех задач
    for (const auto& pair : tasks) {
        const Task& task = pair.second;
        std::cout << "Task ID: " << task.id << ", Description: " << task.description << ", Completed: " << (task.completed ? "Yes" : "No") << std::endl;
    }

    return 0;
}
