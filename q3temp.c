#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MATRIX_SIZE 2
#define EPSILON 1e-6

float absolute(float a) {
  return (a >= 0) ? a : -1 * a;
}

void matrix_vector_multiply(int matrix[MATRIX_SIZE][MATRIX_SIZE], float vector[MATRIX_SIZE], float result[MATRIX_SIZE]) {
  for (int i = 0; i < MATRIX_SIZE; i++) {
    float temp = 0;
    for (int j = 0; j < MATRIX_SIZE; j++) {
      temp += matrix[i][j] * vector[j];
    }
    result[i] = temp;
  }
}

void normalize_vector(float vector[MATRIX_SIZE]) {
  float magnitude = 0;
  for (int i = 0; i < MATRIX_SIZE; i++) {
    magnitude += vector[i] * vector[i];
  }
  magnitude = sqrt(magnitude);
  for (int i = 0; i < MATRIX_SIZE; i++) {
    vector[i] = vector[i] / magnitude;
  }
}

bool is_eigenvector(int matrix[MATRIX_SIZE][MATRIX_SIZE], float vector[MATRIX_SIZE]) {
  float result[MATRIX_SIZE];
  matrix_vector_multiply(matrix, vector, result);
  normalize_vector(vector);
  normalize_vector(result);

  for (int i = 0; i < MATRIX_SIZE; i++) {
    if (absolute(vector[i] - result[i]) > EPSILON) {
      return false;
    }
  }
  return true;
}

int main() {
  int matrix[MATRIX_SIZE][MATRIX_SIZE] = {{1, 2}, {3, 4}};
  float vector[MATRIX_SIZE] = {2, 1};

  if (is_eigenvector(matrix, vector)) {
    printf("The vector is an eigenvector for the matrix.\n");
  } else {
    printf("The vector is not an eigenvector for the matrix.\n");
  }

  return 0;
}
