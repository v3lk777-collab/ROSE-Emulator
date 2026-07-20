cmake_minimum_required(VERSION 3.25)
project(ROSE LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(rose
    src/cpu.cpp
    src/main.cpp
)

target_include_directories(rose PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)