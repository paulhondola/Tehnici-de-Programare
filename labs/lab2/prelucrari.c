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


int main(void)
{
    int **matrix = (int **)alloc_matrix(MAX_LINES, MAX_COLLUMNS);

    fill_matrix(matrix, MAX_LINES, MAX_COLLUMNS);

    print_matrix(matrix, MAX_LINES, MAX_COLLUMNS);

    free_matrix(matrix, MAX_LINES);

    return 0;
}
