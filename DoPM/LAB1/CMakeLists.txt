cmake_minimum_required(VERSION 3.0)
project(API_Weather)

set(CMAKE_CXX_STANDARD 11)

Add the required packages
find_package(cpr CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

Add the executable
add_executable(WeatherForecast main.cpp)

Link the required libraries
target_link_libraries(WeatherForecast PRIVATE nlohmann_json nlohmann_json::nlohmann_json cpr cpr::cpr)
