cmake_minimum_required(VERSION 3.25)
project(cbank C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 1. Önce src altındaki tüm .c dosyalarını yakala
file(GLOB SOURCES "src/*.c")

# 2. Sonra hedefi (executable) oluştur
add_executable(cbank ${SOURCES})

# 3. En son oluşturulan cbank hedefine include dizinini bağla
target_include_directories(cbank PRIVATE include)