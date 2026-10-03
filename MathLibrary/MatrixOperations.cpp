#include "MatrixOperations.h"

namespace MathLibrary {

    void addMatrix(const int a[MATRIX_SIZE][MATRIX_SIZE], const int b[MATRIX_SIZE][MATRIX_SIZE], int result[MATRIX_SIZE][MATRIX_SIZE]) {
        for (int i = 0; i < MATRIX_SIZE; i++)
            for (int j = 0; j < MATRIX_SIZE; j++)
                result[i][j] = a[i][j] + b[i][j];
    }

    void subtractMatrix(const int a[MATRIX_SIZE][MATRIX_SIZE], const int b[MATRIX_SIZE][MATRIX_SIZE], int result[MATRIX_SIZE][MATRIX_SIZE]) {
        for (int i = 0; i < MATRIX_SIZE; i++)
            for (int j = 0; j < MATRIX_SIZE; j++)
                result[i][j] = a[i][j] - b[i][j];
    }

    void multiplyMatrix(const int a[MATRIX_SIZE][MATRIX_SIZE], const int b[MATRIX_SIZE][MATRIX_SIZE], int result[MATRIX_SIZE][MATRIX_SIZE]) {
        for (int i = 0; i < MATRIX_SIZE; i++)
            for (int j = 0; j < MATRIX_SIZE; j++) {
                result[i][j] = 0;
                for (int k = 0; k < MATRIX_SIZE; k++)
                    result[i][j] += a[i][k] * b[k][j];
            }
    }

}