#include "matrix.h"

struct Matrix
{
  size_t rows;
  size_t cols;
  element_t **data;
};

struct Vector
{
  size_t size;
  element_t *data;
};

matrix_t init_matrix(size_t rows, size_t cols)
{

  matrix_t m = malloc(sizeof(struct Matrix));

  if (m == NULL)
  {
    perror("matrix alloc error");
    exit(1);
  }

  *m = (struct Matrix){rows, cols, NULL};

  m->data = (element_t **)malloc(rows * sizeof(element_t *));

  if (m->data == NULL)
  {
    perror("matrix alloc error");
    exit(1);
  }

  for (size_t i = 0; i < rows; i++)
  {

    m->data[i] = (element_t *)malloc(cols * sizeof(element_t));

    if (m->data[i] == NULL)
    {
      perror("matrix alloc error");
      exit(1);
    }

    for (size_t j = 0; j < cols; j++)
      m->data[i][j] = 0;
  }

  return m;
}

status_t assign_value(matrix_t m, size_t row, size_t col, element_t value)
{

  if (row >= m->rows || col >= m->cols)
  {
    return MATRIX_OVERFLOW;
  }

  m->data[row][col] = value;
  return OK;
}

matrix_t sum(matrix_t m1, matrix_t m2)
{

  size_t max_rows = m1->rows > m2->rows ? m1->rows : m2->rows;
  size_t max_cols = m1->cols > m2->cols ? m1->cols : m2->cols;

  matrix_t sum = init_matrix(max_rows, max_cols);

  for (size_t i = 0; i < max_rows; i++)
  {
    for (size_t j = 0; j < max_cols; j++)
    {

      element_t value1 = i < m1->rows && j < m1->cols ? m1->data[i][j] : 0;
      element_t value2 = i < m2->rows && j < m2->cols ? m2->data[i][j] : 0;

      sum->data[i][j] = value1 + value2;
    }
  }

  return sum;
}

vector_t init_vector(size_t size)
{
  vector_t v = malloc(sizeof(struct Vector));

  if (v == NULL)
  {
    perror("vector alloc error");
    exit(1);
  }

  *v = (struct Vector){size, NULL};

  v->data = (element_t *)malloc(size * sizeof(element_t));

  if (v->data == NULL)
  {
    perror("vector alloc error");
    exit(1);
  }

  for (size_t i = 0; i < size; i++)
  {
    v->data[i] = 0;
  }

  return v;
}

void print_vector(vector_t v)
{
  for (size_t i = 0; i < v->size; i++)
  {
    printf("%f ", v->data[i]);
  }
  printf("\n");
}

int bigger(element_t el, element_t condition) { return el > condition; }

vector_t filter(matrix_t m, int (*condition)(element_t, element_t),
                element_t value)
{

  vector_t v = init_vector(m->rows * m->cols);

  size_t index = 0;

  for (size_t i = 0; i < m->rows; i++)
    for (size_t j = 0; j < m->cols; j++)
      if (condition(m->data[i][j], value))
        v->data[index++] = m->data[i][j];

  v->size = index;

  return v;
}

void free_vector(vector_t v)
{
  free(v->data);
  free(v);
}

void print_matrix(matrix_t m)
{
  for (size_t i = 0; i < m->rows; i++)
  {
    for (size_t j = 0; j < m->cols; j++)
    {
      printf("%f ", m->data[i][j]);
    }
    printf("\n");
  }
}

void free_matrix(matrix_t m)
{

  for (size_t i = 0; i < m->rows; i++)
  {
    free(m->data[i]);
  }

  free(m->data);
  free(m);
}
