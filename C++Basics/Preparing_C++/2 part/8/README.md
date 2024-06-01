### Представьте, что вы создаёте систему управления встречами, где каждая встреча имеет уникальный ID, дату и время. Какие контейнеры STL вы бы использовали и почему? Напишите пример кода для добавления новой встречи и удаления существующей.

- Для управления встречами, где каждая встреча имеет уникальный ID, дату и время, был использован std::map для хранения встреч по их уникальному ID. Использование std::map обеспечивает автоматическую сортировку по ключу (в данном случае ID)