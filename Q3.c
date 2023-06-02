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

void matrix_vector_multiply(int matrix[MATRIX_SIZE][MATRIX_SIZE], int vector[MATRIX_SIZE], int result[MATRIX_SIZE])
{
  // Implementation of matrix_vector_multiply function...
  for (int i = 0; i < MATRIX_SIZE; i++)
  {
    int temp = 0;
    for (int j = 0; j < MATRIX_SIZE; j++)
    {
      temp += matrix[i][j] * vector[j];
    }
    result[i] = temp;
  }
}

void normalize_vector(int vector[MATRIX_SIZE])
{
  // Implementation of normalize_vector function...
  
}

bool is_eigenvector(int matrix[MATRIX_SIZE][MATRIX_SIZE], int vector[MATRIX_SIZE])
{
  // Implementation of is_eigenvector function...
  
}

int main()
{
  int matrix[MATRIX_SIZE][MATRIX_SIZE];
  int vector[MATRIX_SIZE];

  // int Matrix[MATRIX_SIZE][MATRIX_SIZE] = {{1, 2}, {3, 4}};
  // int vector[MATRIX_SIZE] = {2,1};

  // int result[MATRIX_SIZE];
  // matrix_vector_multiply(Matrix,vector,result);
  // for (int i=0;i<MATRIX_SIZE;i++){
  //   printf("%d ",result[i]);
  // }


  if (is_eigenvector(matrix, vector))
    printf("The vector is an eigenvector for the matrix.\n");
  else
    printf("The vector is not an eigenvector for the matrix.\n");
  printf("\n");

  return 0;
}
