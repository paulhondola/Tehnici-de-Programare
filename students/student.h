#ifndef __STUDENT_H
#define __STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENT_NAME_LEN 100
#define MAX_OPTIONAL_NAME_LEN 10
#define MAX_LINE_LENGTH 100
#define CHUNK_SIZE 16
#define CODE_COUNT 4

typedef struct STUDENT_T *student_t;

student_t read_student_data(FILE *);

student_t *get_students(unsigned, FILE *);

void sort_students(student_t *, unsigned);

int get_student_index(const char *, student_t *, unsigned);

void print_student_data(student_t);

void free_student_data(student_t);

#endif
