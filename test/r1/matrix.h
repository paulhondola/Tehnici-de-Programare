#ifndef __MATRIX_H
#define __MATRIX_H

#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    OK,
    MATRIX_OVERFLOW
} status_t;
typedef double element_t;
typedef struct Matrix *matrix_t;
typedef struct Vector *vector_t;

matrix_t init_matrix(size_t, size_t);

status_t assign_value(matrix_t, size_t, size_t, element_t);

matrix_t sum(matrix_t, matrix_t);

int bigger(element_t, element_t);

vector_t filter(matrix_t, int (*)(element_t, element_t), element_t);

void print_vector(vector_t);

void free_vector(vector_t);

void print_matrix(matrix_t);

void free_matrix(matrix_t);

#endif
