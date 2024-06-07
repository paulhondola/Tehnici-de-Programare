#ifndef __STUDENT_H
#define __STUDENT_H

// DEPENDENCIES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DATA TYPE
typedef struct STUDENT_DATA *student_data_t;

// INPUT
student_data_t read_student_data(FILE *file);
student_data_t *read_student_data_array(FILE *file, const int size);

// OUTPUT
void print_student_data(FILE *file, const student_data_t data);
void print_student_data_array(FILE *file, const student_data_t *data,
                              const int size);

// SORTING
void sort_by_name(student_data_t *array, int size);

// SEARCH
int b_search(student_data_t *array, char *searched, int left, int right);

#endif
