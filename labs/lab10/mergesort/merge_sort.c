#include "/Users/paulhondola/Faculta/Tehnici de Programare/project/rand array/rand_array.h"
#include <stdio.h>
#include <time.h>
#define SIZE 1000

void merge_sort(int v[], int left, int right) {
  if (left == right)
    return;

  int mid = (left + right) / 2;
  int i = left;
  int j = mid + 1;

  merge_sort(v, left, mid);
  merge_sort(v, mid + 1, right);

  int aux[right - left + 1];
  int k = 0;

  while (i <= mid && j <= right) {
    if (v[i] < v[j])
      aux[k++] = v[i++];
    else
      aux[k++] = v[j++];
  }

  while (i <= mid)
    aux[k++] = v[i++];

  while (j <= right)
    aux[k++] = v[j++];

  for (i = 0; i < k; i++)
    v[left + i] = aux[i];
}

void print_array(int v[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", v[i]);
  printf("\n");
}

int comparator(const void *p, const void *q) { return (*(int *)p - *(int *)q); }

void test_merge_sort(int size) {

  int *v = make_rand_limit_array(size, 0, 1000);

  clock_t start, end;
  double cpu_time_used;
  start = clock();

  merge_sort(v, 0, size - 1);

  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("SIZE: %d -> %lf\n", size, cpu_time_used);
  free(v);
}

int main(void) {

  srand(time(NULL));

  for (int i = 1; i <= 100; i++)
    test_merge_sort(SIZE * i);

  return 0;
}
