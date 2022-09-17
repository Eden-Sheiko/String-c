cmake_minimum_required(VERSION 3.23)
project(Test_eden C)

set(CMAKE_C_STANDARD 99)

add_executable(Test_eden main.c string_functions.h string_vector.h string_functions.c string_vector.c)
