#include <string>

const std::string PROJECT_VERSION = "0.2";

std::string new_function() {
    return "Hello from Test_two branch";
}

void helper() {
    // вспомогательная функция
}

int calculate(int a, int b) {
    return a + b;
}

void print_version() {
    std::cout << APP_VERSION << std::endl;
}

// Конец модуля

// Интегрировано в основную ветку