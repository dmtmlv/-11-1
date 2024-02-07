cmake_minimum_required(VERSION 3.0)
project(YandexAPIExample)

# Добавляем исполняемый файл и исходный файл
add_executable(YandexAPIExample main.cpp)

# Находим и подключаем библиотеки httplib и nlohmann/json
find_package(nlohmann_json REQUIRED)
find_package(httplib REQUIRED)

# Указываем пути для включения заголовочных файлов библиотек
target_include_directories(YandexAPIExample PRIVATE ${NLOHMANN_JSON_INCLUDE_DIR})
target_include_directories(YandexAPIExample PRIVATE ${HTTPLIB_INCLUDE_DIRS})

# Линкуем библиотеки
target_link_libraries(YandexAPIExample PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(YandexAPIExample PRIVATE httplib::httplib)
