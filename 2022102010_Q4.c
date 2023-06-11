/* Write a program in C to find the determinant of a matrix based
on Laplace Expansion Theorem. Choose a matrix of shape 5x5 and you
need to expand using the nth row or column based on your roll number :
n = roll_numbder%5.

If the last digit of your roll number is ODD, Go for Row Expansion,
otherwise go for Column Expansion.
*/

// Save the file as <RollNo>_Q4.c

// Use the following matrix to test your program.
// Matrix = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10},
// {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20},
// {21, 22, 23, 24, 25}}

#include <stdio.h>
#define MATRIX_SIZE 5

void get_cofactor(int size, int matrix[size][size], int cofactor[size - 1][size - 1], int p, int q)
{
  // Implementation of get_cofactor function...
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      if (i < p && j < q)
      {
        cofactor[i][j] = matrix[i][j];
      }
      else if (i > p && j < q)
      {
        cofactor[i - 1][j] = matrix[i][j];
      }
      else if (i < p && j > q){
        cofactor[i][j-1] = matrix[i][j];
      }
      else if (i > p && j > q)
      {
        cofactor[i - 1][j - 1] = matrix[i][j];
      }
    }
  }
}

int determinant_recursive(int size, int matrix[size][size])
{
  // Implementation of determinant_recursive function...
  if (size == 1)
  {
    return matrix[0][0];
  }
  else
  {
    int det = 0;
    for (int row = 0; row < size; row++)
    {
      int cofactor[size - 1][size - 1];
      get_cofactor(size, matrix, cofactor, row,0);
      int sign = (row % 2 == 0) ? 1 : -1;
      det += matrix[row][0] * sign * determinant_recursive(size - 1, cofactor);
    }
    return det;
  }
}

int laplace_expansion(int matrix[MATRIX_SIZE][MATRIX_SIZE],int n)
{
  // Implementation of laplace_expansion function...
  int det = 0;
  int cofactor[MATRIX_SIZE - 1][MATRIX_SIZE - 1];
  for (int row = 0; row < MATRIX_SIZE; row++)
  {
    get_cofactor(MATRIX_SIZE, matrix, cofactor, row, n-1);
    int sign = (row % 2 == 0) ? 1 : -1;
    det = det + matrix[row][n-1] * sign * determinant_recursive(MATRIX_SIZE - 1, cofactor);
  }
  return det;
}

int main()
{
  int matrix[MATRIX_SIZE][MATRIX_SIZE];
  int n;
  printf("Enter the elements of the matrix:\n");
  for (int i = 0; i < MATRIX_SIZE; i++)
  {
    for (int j = 0; j < MATRIX_SIZE; j++)
    {
      scanf("%d", &matrix[i][j]);
    }
  }
  printf("Enter the value of n:\n");
  scanf("%d", &n);
  printf("The determinant of the matrix is %d.\n", laplace_expansion(matrix, n));
  return 0;
}