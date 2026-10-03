#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIB_API __declspec(dllexport)
#else
#define MATHLIB_API __declspec(dllimport)
#endif

namespace MathLibrary {

	const int MATRIX_SIZE = 4;

	MATHLIB_API void addMatrix(const int a[MATRIX_SIZE][MATRIX_SIZE], const int b[MATRIX_SIZE][MATRIX_SIZE], int result[MATRIX_SIZE][MATRIX_SIZE]);
	MATHLIB_API void subtractMatrix(const int a[MATRIX_SIZE][MATRIX_SIZE], const int b[MATRIX_SIZE][MATRIX_SIZE], int result[MATRIX_SIZE][MATRIX_SIZE]);
	MATHLIB_API void multiplyMatrix(const int a[MATRIX_SIZE][MATRIX_SIZE], const int b[MATRIX_SIZE][MATRIX_SIZE], int result[MATRIX_SIZE][MATRIX_SIZE]);

}

#endif
