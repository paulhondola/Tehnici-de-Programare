#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW_SIZE 100
#define MAX_COLLUMN_SIZE 100

typedef int matrix_data_t;

typedef struct
{
  int rows;
  int collumns;
  matrix_data_t **data;
} matrix;

matrix init_matrix(void)
{

  int n;
  if (scanf("%d", &n) != 1)
  {
    printf("Invalid input");
    exit(1);
  }

  matrix m;
  m.rows = n;
  m.collumns = n;
  m.data = (matrix_data_t **)malloc((unsigned long)n * sizeof(matrix_data_t *));

  for (int i = 0; i < n; i++)
    m.data[i] =
        (matrix_data_t *)malloc((unsigned long)n * sizeof(matrix_data_t));

  return m;
}

void read_matrix(FILE *file, matrix *m)
{
  for (int i = 0; i < m->rows; i++)
    for (int j = 0; j < m->collumns; j++)
      if (fscanf(file, "%d", &m->data[i][j]) != 1)
      {
        printf("Invalid input");
        exit(1);
      }
}

void print_matrix(FILE *file, matrix *m)
{
  for (int i = 0; i < m->rows; i++)
  {
    for (int j = 0; j < m->collumns; j++)
      fprintf(file, "%d ", m->data[i][j]);
    fprintf(file, "\n");
  }
}

int main(void)
{

  matrix m;

  m = init_matrix();

  read_matrix(stdin, &m);
  print_matrix(stdout, &m);

  return 0;
}
