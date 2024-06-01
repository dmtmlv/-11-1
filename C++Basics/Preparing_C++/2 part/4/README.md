### Реализуйте систему управления задачами проекта, где каждая задача имеет уникальный ID и может быть завершена или удалена. Какой контейнер STL вы бы использовали для хранения задач и почему? Напишите пример кода для этой задачи.

- Для хранения задач с уникальными ID был использован контейнер std::unordered_map, где ключом будет уникальный ID задачи, а значением будет сама задача. std::unordered_map обеспечит быстрый доступ к задачам по их ID благодаря использованию хэш-таблицы.