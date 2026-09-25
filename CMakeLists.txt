cmake_minimum_required(VERSION 4.3)
project(cbank C)

set(CMAKE_C_STANDARD 23)

add_executable(cbank main.c
        customer.h
        customer.c
        menu.c
        menu.h)
