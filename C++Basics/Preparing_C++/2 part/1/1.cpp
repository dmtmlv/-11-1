#include <iostream>
#include <queue>

class Task {
public:
    int id;
    int priority;

    Task(int id, int priority) : id(id), priority(priority) {}

    // Оператор сравнения необходим для сравнения задач по приоритету в очереди с приоритетом
    bool operator<(const Task& other) const {
        return priority < other.priority;
    }
};

// Функция для добавления задачи в очередь с приоритетом
void addTask(std::priority_queue<Task>& tasks, int id, int priority) {
    Task newTask(id, priority);
    tasks.push(newTask);
}

// Функция для извлечения задачи с наивысшим приоритетом из очереди
Task getTopPriorityTask(std::priority_queue<Task>& tasks) {
    Task topTask = tasks.top();
    tasks.pop();
    return topTask;
}

int main() {
    std::priority_queue<Task> tasks;

    addTask(tasks, 1, 3);
    addTask(tasks, 2, 1);
    addTask(tasks, 3, 5);

    Task topTask = getTopPriorityTask(tasks);
    std::cout << "Task ID: " << topTask.id << " Priority: " << topTask.priority << std::endl;

    return 0;
}
