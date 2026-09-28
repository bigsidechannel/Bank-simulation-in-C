cmake_minimum_required(VERSION 3.10)
project(cbank C)

set(CMAKE_C_STANDARD 23)

add_executable(cbank main.c
        customer.h
        customer.c
        currency.h
        currency.c
        input.h
        input.c
        iban.c
        iban.h
        bank.h
        menu.c
        menu.h)
