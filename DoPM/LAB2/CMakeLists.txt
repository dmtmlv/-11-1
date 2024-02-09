cmake_minimum_required(VERSION 3.0)
project(YandexAPIExample)

add_executable(YandexAPIExample main.cpp)

find_package(nlohmann_json REQUIRED)
find_package(httplib REQUIRED)

target_include_directories(YandexAPIExample PRIVATE ${NLOHMANN_JSON_INCLUDE_DIR})
target_include_directories(YandexAPIExample PRIVATE ${HTTPLIB_INCLUDE_DIRS})

target_link_libraries(YandexAPIExample PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(YandexAPIExample PRIVATE httplib::httplib)
