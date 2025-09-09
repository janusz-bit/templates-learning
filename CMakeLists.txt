cmake_minimum_required(VERSION 3.31.7)
project(templates-learning)
option(EXPORT_COMPILE_COMMANDS ON)
option(CXX_STANDARD 20)
option(CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} ./main.cpp)