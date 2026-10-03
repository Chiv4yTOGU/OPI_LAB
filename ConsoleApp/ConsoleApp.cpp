#include <windows.h>
#include <iostream>
#include <string>
#include <sstream>
#include <clocale>
#include "MatrixOperations.h"

using namespace std;
using namespace MathLibrary;

void printHelp() {
    cout << "Команды: add (сложение), subtract (вычитание), "
        "multiply (умножение), exit (выход).\n";
}

void printMatrix(const int m[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++)
            cout << m[i][j] << " ";
        cout << "\n";
    }
}

bool readMatrix(int m[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        while (true) {
            cout << "Строка " << (i + 1) << ": ";
            string line;
            if (!getline(cin, line)) return false;

            istringstream iss(line);
            bool ok = true;
            for (int j = 0; j < MATRIX_SIZE; j++) {
                if (!(iss >> m[i][j])) { ok = false; break; }
            }
            if (!ok) {
                cout << "Ошибка: необходимо ввести ровно 4 числа. Попробуйте снова.\n";
                continue;
            }
            int extra;
            if (iss >> extra) {
                cout << "Ошибка: необходимо ввести ровно 4 числа. Попробуйте снова.\n";
                continue;
            }
            break;
        }
    }
    return true;
}

int main() {
        
    SetConsoleOutputCP(CP_UTF8);   
    SetConsoleCP(CP_UTF8);         
    setlocale(LC_ALL, "ru_RU.UTF-8");

    cout << "Работа с матрицами. Узнать о командах: --help\n";

    while (true) {
        cout << "Введите команду: ";
        string op;
        if (!getline(cin, op)) break;
        for (auto& c : op) c = tolower(c);

        if (op == "exit") { cout << "Выход из программы.\n"; break; }
        if (op == "--help") { printHelp(); continue; }
        if (op != "add" && op != "subtract" && op != "multiply") {
            cout << "Неверная команда. Попробуйте еще раз.\n";
            continue;
        }

        int a[MATRIX_SIZE][MATRIX_SIZE], b[MATRIX_SIZE][MATRIX_SIZE], result[MATRIX_SIZE][MATRIX_SIZE];

        cout << "Введите первую матрицу:\n";
        if (!readMatrix(a)) break;

        cout << "Введите вторую матрицу:\n";
        if (!readMatrix(b)) break;

        if (op == "add") addMatrix(a, b, result);
        else if (op == "subtract") subtractMatrix(a, b, result);
        else multiplyMatrix(a, b, result);

        cout << "Результат:\n";
        printMatrix(result);
    }
    return 0;
}