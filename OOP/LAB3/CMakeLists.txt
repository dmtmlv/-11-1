cmake_minimum_required(VERSION 3.10)
project(Any)

set(CMAKE_CXX_STANDARD 11)

add_executable(Any any.cpp any.h)

set_target_properties(Any PROPERTIES
    CXX_STANDARD_REQUIRED ON
)
