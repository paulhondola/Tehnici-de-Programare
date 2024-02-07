#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

int zone_sum(int matrix[][MAX_SIZE], int n, int zone)
{
    int sum = 0;
    
    // zona 1 -> i < j / i + j < n + 1
    // zona 2 -> i < j / i + j > n + 1
    // zona 3 -> i > j / i + j > n + 1
    // zona 4 -> i > j / i + j < n + 1

    switch (zone)
    {
    case 1:
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(i < j && i + j < n - 1)
                    sum += matrix[i][j];
        break;

    case 2:
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                if(i + j > n - 1)
                    sum += matrix[i][j];
        break;

    case 3:
        for(int i = 0; i < n; i++)
            for(int j = 0; j < i; j++)
                if(i + j > n - 1)
                    sum += matrix[i][j];
        break;

    case 4:
        for(int i = 0; i < n; i++)
            for(int j = 0; j < i; j++)
                if(i + j < n - 1)
                    sum += matrix[i][j];
        break;
    
    default:
        break;
    }

    return sum;
}


void print_matrix(int matrix[][MAX_SIZE], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}


int main(void)
{
    int matrix[MAX_SIZE][MAX_SIZE] = 
    {
        {7, 4, 8, 5, 10},
        {7, 7, 10, 2, 2},
        {1, 2, 8, 8, 4 },
        {9, 9, 5, 3, 2 },
        {3, 6, 7, 1, 7 }
    };

    print_matrix(matrix, MAX_SIZE);

    printf("Suma zonei 1: %d\n", zone_sum(matrix, MAX_SIZE, 1));

    printf("Suma zonei 2: %d\n", zone_sum(matrix, MAX_SIZE, 2));

    printf("Suma zonei 3: %d\n", zone_sum(matrix, MAX_SIZE, 3));

    printf("Suma zonei 4: %d\n", zone_sum(matrix, MAX_SIZE, 4));

    return 0;
}
