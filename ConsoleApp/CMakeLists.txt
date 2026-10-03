# ConsoleApp/CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(ConsoleApp LANGUAGES CXX)

# Добавляем путь к папке с установленной библиотекой и заголовком
# По умолчанию ищем их в корне проекта (Lab1/lib и Lab1/include)
set(LIB_DIR "${CMAKE_SOURCE_DIR}/lib" CACHE PATH "Папка с MathLibrary.dll")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include" CACHE PATH "Папка с MatrixOperations.h")

# --- Проверка наличия библиотеки ---
find_library(MATH_LIBRARY
    NAMES MathLibrary
    PATHS ${LIB_DIR}
    NO_DEFAULT_PATH
)

find_path(MATH_INCLUDE
    NAMES MatrixOperations.h
    PATHS ${INCLUDE_DIR}
    NO_DEFAULT_PATH
)

if(NOT MATH_LIBRARY)
    message(FATAL_ERROR "MathLibrary не найдена в ${LIB_DIR}. Сначала собери и установи библиотеку (make install или cmake --install).")
endif()

if(NOT MATH_INCLUDE)
    message(FATAL_ERROR "MatrixOperations.h не найден в ${INCLUDE_DIR}. Сначала собери и установи библиотеку.")
endif()

message(STATUS "Found library: ${MATH_LIBRARY}")
message(STATUS "Found header: ${MATH_INCLUDE}")

# --- Сборка приложения ---
add_executable(ConsoleApp
    ConsoleApp.cpp
)

# Подключаем заголовок и линкуемся с библиотекой
target_include_directories(ConsoleApp PRIVATE
    ${INCLUDE_DIR}
)

target_link_libraries(ConsoleApp PRIVATE
    ${MATH_LIBRARY}
)