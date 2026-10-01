cmake_minimum_required(VERSION 3.25)
project(cbank C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Header dosyalarının konumunu göster
include_directories(include)

# Kaynak kodları (.c) listele
add_executable(cbank
    src/main.c
    src/customer.c
    src/currency.c
    src/input.c
    src/validate.c
    src/menu.c
)