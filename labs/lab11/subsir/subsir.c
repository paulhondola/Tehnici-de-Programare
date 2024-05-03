/*
4. Se dă un șir de n numere naturale. Șirul poate fi partiționat în mai multe
moduri într-un număr de subșiruri strict crescătoare. De exemplu, șirul 4 6 2 5
8 1 3 7 poate fi partiționat astfel: 4 6 8 (primul subșir), 2 5 7 (al doilea) și
1 3 (al treilea). O altă modalitate este formând patru subșiruri: 4 5 7, 6 8, 2
3 și 1.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *data;
  int count;
} partition_t;

typedef struct {
  partition_t *partitions;
  int count;
} matrix_t;

// partition operations

partition_t init_partition(const int count) {

  partition_t partition = {NULL, 0};

  partition.data = (int *)malloc(count * sizeof(int));

  if (partition.data == NULL)
    exit(3);

  return partition;
}

void print_partition(const partition_t *partition) {

  for (int i = 0; i < partition->count; i++)
    printf("%d ", partition->data[i]);

  printf("\n");
}

// add to partition from given array and index

void add_to_partition(partition_t *partition, const int *array, const int count,
                      int *index) {

  if (*index == count)
    return;

  // set first element
  partition->data[partition->count++] = array[*index];

  fprintf(stderr, "array[%d] = %d\n", *index, array[*index]);

  (*index)++;

  for (int i = *index; i < count; i++)
    if (array[i] > array[i - 1]) {
      fprintf(stderr, "array[%d] = %d\n", i, array[i]);
      partition->data[partition->count++] = array[i];
    }

    else
      break;

  *index += partition->count - 1;

  fprintf(stderr, "\nCOUNT:%d\n\n", *index);
}

// matrix operations

matrix_t init_matrix(void) { return (matrix_t){NULL, 0}; }

void realloc_matrix(matrix_t *matrix) {

  matrix->partitions = (partition_t *)realloc(
      matrix->partitions, (matrix->count + 1) * sizeof(partition_t));

  if (matrix->partitions == NULL)
    exit(2);
  else
    matrix->count++;
}

void fill_matrix(matrix_t *matrix, const int *array, const int count) {
  int index = 0;
  while (1) {

    partition_t partition = init_partition(count);

    add_to_partition(&partition, array, count, &index);

    if (partition.count == 0) {
      free(partition.data);
      break;
    }

    realloc_matrix(matrix);
    matrix->partitions[matrix->count - 1] = partition;
  }
}

// print matrix

void print_matrix(const matrix_t *matrix) {

  for (int i = 0; i < matrix->count; i++) {
    print_partition(&matrix->partitions[i]);
    printf("\n");
  }
}

int main(void) {

  // 2 3 4 2 5 8 1 3 7

  int v[] = {4, 6, 2, 5, 8, 1, 3, 7};
  int n = sizeof(v) / sizeof(v[0]);

  matrix_t matrix = init_matrix();

  fill_matrix(&matrix, v, n);

  print_matrix(&matrix);

  return 0;
}
