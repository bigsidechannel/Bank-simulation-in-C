cmake_minimum_required(VERSION 3.31.6)
project(cbank C)

set(CMAKE_C_STANDARD 23)

add_executable(cbank main.c
        customer.c
        currency.c
        input.c
        validate.c
        bank.h
        menu.c)
