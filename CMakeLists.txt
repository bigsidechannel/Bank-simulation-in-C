cmake_minimum_required(VERSION 3.25)
project(cbank C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB SOURCES CONFIGURE_DEPENDS "src/*.c")

add_executable(cbank ${SOURCES})

target_include_directories(cbank PRIVATE include)

# ---- Derleyici Hata ve Uyarı Parametreleri ----
if(CMAKE_C_COMPILER_ID STREQUAL "GNU" OR CMAKE_C_COMPILER_ID STREQUAL "Clang")
    target_compile_options(cbank PRIVATE 
        -Wall          # Temel uyarıların tamamını açar
        -Wextra        # Ekstra (gelişmiş) uyarıları aktif eder
        -Wpedantic     # C23 standartlarına tam uyumluluğu zorlar, standart dışı her şeye uyarır
        -Werror        # Tüm uyarıları "Hata" olarak kabul eder ve derlemeyi durdurur (Önerilir!)
    )
elseif(CMAKE_C_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(cbank PRIVATE 
        /W4            # En yüksek mantıklı uyarı seviyesi
        /WX            # Uyarıları hataya dönüştürür
    )
endif()
