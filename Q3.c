// Write a program in C to check if a given vector is an eigenvector for a matrix.
// Save the file as <RollNo>_Q3.c
// Use the following matrix and vector to test your program.
// Matrix = {{1, 2}, {3, 4}}
// Vector = {2, 1}
// Expected Output: The vector is an eigenvector for the matrix.

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MATRIX_SIZE 2
#define MAX_ITERATIONS 100
#define EPSILON 1e-6

float absolute(float a)
{
  return (a >= 0) ? a : -1 * a;
}

void matrix_vector_multiply(int matrix[MATRIX_SIZE][MATRIX_SIZE], float vector[MATRIX_SIZE], float result[MATRIX_SIZE])
{
  // Implementation of matrix_vector_multiply function...
  for (int i = 0; i < MATRIX_SIZE; i++)
  {
    float temp = 0;
    for (int j = 0; j < MATRIX_SIZE; j++)
    {
      temp += matrix[i][j] * vector[j];
    }
    result[i] = temp;
  }
}

void normalize_vector(float vector[MATRIX_SIZE])
{
  // Implementation of normalize_vector function...
  float magnitude = 0;
  for (int i = 0; i < MATRIX_SIZE; i++)
  {
    magnitude += vector[i] * vector[i];
  }
  magnitude = sqrt(magnitude);
  for (int i = 0; i < MATRIX_SIZE; i++)
  {
    vector[i] = vector[i] / magnitude;
  }
}

bool is_eigenvector(int matrix[MATRIX_SIZE][MATRIX_SIZE], float vector[MATRIX_SIZE])
{
  // Implementation of is_eigenvector function...
  bool isZeroVector = true;
  for (int i=0;i<MATRIX_SIZE;i++){
    if (vector[i]!=0){
      isZeroVector = false;
      break;
    }
  }
  if (isZeroVector){
    return 1;
  }
  float result[MATRIX_SIZE];
  matrix_vector_multiply(matrix, vector, result);
  normalize_vector(vector);
  normalize_vector(result);
  for (int i = 0; i < MATRIX_SIZE; i++)
  {
    if ((result[i] > 0 && vector[i] > 0) || (result[i] < 0 && vector[i] < 0))
    {
      if (absolute(result[i] - vector[i]) > EPSILON)
      {
        return false;
      }
    }
    else
    {
      if (absolute(result[i] + vector[i]) > EPSILON)
      {
        return false;
      }
    }
  }
  return true;
}

int main()
{
  int matrix[MATRIX_SIZE][MATRIX_SIZE];
  float vector[MATRIX_SIZE];

  if (is_eigenvector(matrix, vector))
    printf("The vector is an eigenvector for the matrix.\n");
  else
    printf("The vector is not an eigenvector for the matrix.\n");
  printf("\n");

  return 0;
}
