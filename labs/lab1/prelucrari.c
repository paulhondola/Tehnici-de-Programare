#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINES 10
#define MAX_COLLUMNS 10
#define MAX_MATRIX_VALUE 100

int **alloc_matrix(int lines, int collumns)
{
  int **matrix = (int **)malloc(lines * sizeof(int *));
  for (int i = 0; i < lines; i++)
  {
    matrix[i] = (int *)malloc(collumns * sizeof(int));
  }
  return matrix;
}

void free_matrix(int **matrix, int lines)
{
  for (int i = 0; i < lines; i++)
  {
    free(matrix[i]);
  }
  free(matrix);
}

void fill_matrix(int **matrix, int lines, int collumns)
{
  srand(time(NULL));
  for (int i = 0; i < lines; i++)
  {
    for (int j = 0; j < collumns; j++)
    {
      matrix[i][j] = rand() % MAX_MATRIX_VALUE;
    }
  }
}

void print_matrix(int **matrix, int lines, int collumns)
{
  for (int i = 0; i < lines; i++)
  {
    for (int j = 0; j < collumns; j++)
    {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int max_line(int **matrix, int line, int collumns)
{
  int max = matrix[line][0];
  for (int i = 1; i < collumns; i++)
  {
    if (matrix[line][i] > max)
    {
      max = matrix[line][i];
    }
  }
  return max;
}

int sum_line(int **matrix, int line, int collumns)
{
  int sum = 0;
  for (int i = 0; i < collumns; i++)
  {
    sum += matrix[line][i];
  }
  return sum;
}

int min_sum(int **matrix, int line, int collumns)
{
  return sum_line(matrix, line, collumns) - max_line(matrix, line, collumns);
}

void print_min_sum(int **matrix, int lines, int collumns)
{
  for (int i = 0; i < lines; i++)
  {
    printf("Min sum for line %d: %d\n", i, min_sum(matrix, i, collumns));
  }
}

void left_shift(int **matrix, int lines, int collumns)
{
  for (int i = 0; i < lines; i++)
  {
    int aux = matrix[i][0];
    for (int j = 0; j < collumns - 1; j++)
    {
      matrix[i][j] = matrix[i][j + 1];
    }
    matrix[i][collumns - 1] = aux;
  }
}

int *create_block_matrix(int **matrix, int lines, int collumns)
{
  int *block_matrix = (int *)malloc(lines * collumns * sizeof(int));
  for (int i = 0; i < lines; i++)
  {
    for (int j = 0; j < collumns; j++)
    {
      block_matrix[i * collumns + j] = matrix[i][j];
    }
  }
  return block_matrix;
}

void print_block_matrix(int *block_matrix, int lines, int collumns)
{
  for (int i = 0; i < lines; i++)
  {
    for (int j = 0; j < collumns; j++)
    {
      printf("%d ", block_matrix[i * collumns + j]);
    }
    printf("\n");
  }
}

int check_equal_elements_on_line(int *block_matrix, int line, int collumns)
{
  for (int i = 0; i < collumns - 1; i++)
  {
    if (block_matrix[line * collumns + i] !=
        block_matrix[line * collumns + i + 1])
    {
      return 0;
    }
  }
  return 1;
}

int check_equal_elements_in_matrix(int *block_matrix, int lines, int collumns)
{
  int counter = 0;
  for (int i = 0; i < lines; i++)
  {
    counter += check_equal_elements_on_line(block_matrix, i, collumns);
  }
  return counter;
}

int main(void)
{
  int **matrix = (int **)alloc_matrix(MAX_LINES, MAX_COLLUMNS);

  fill_matrix(matrix, MAX_LINES, MAX_COLLUMNS);

  int *block_matrix = create_block_matrix(matrix, MAX_LINES, MAX_COLLUMNS);

  print_block_matrix(block_matrix, MAX_LINES, MAX_COLLUMNS);
  // print_matrix(matrix, MAX_LINES, MAX_COLLUMNS);

  // print_min_sum(matrix, MAX_LINES, MAX_COLLUMNS);

  free_matrix(matrix, MAX_LINES);
  free(block_matrix);

  return 0;
}
