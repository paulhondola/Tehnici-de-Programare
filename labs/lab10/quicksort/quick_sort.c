#include "/Users/paulhondola/Faculta/Tehnici de Programare/project/rand array/rand_array.h"
#include <stdio.h>
#include <time.h>
#define SIZE 1000

void swap(int *p1, int *p2) {
  int temp;
  temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}

int partition(int arr[], int low, int high) {
  // choose the pivot
  int pivot = arr[high];

  // Index of smaller element and Indicate
  // the right position of pivot found so far
  int i = (low - 1);

  for (int j = low; j <= high; j++) {
    // If current element is smaller than the pivot
    if (arr[j] < pivot) {
      // Increment index of smaller element
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);

  return (i + 1);
}

// The Quicksort function Implement

void quick_sort(int arr[], int low, int high) {
  // when low is less than high
  if (low < high) {
    // pi is the partition return index of pivot

    int pi = partition(arr, low, high);

    // Recursion Call
    // smaller element than pivot goes left and
    // higher element goes right
    quick_sort(arr, low, pi - 1);
    quick_sort(arr, pi + 1, high);
  }
}
// functia de determinare a pozitiei pivotului (preluat din CLRS)
/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */

void print_array(int v[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", v[i]);
  printf("\n");
}

int comparator(const void *p, const void *q) { return (*(int *)p - *(int *)q); }

void test_quick_sort(int size) {

  int *v = make_rand_limit_array(size, 0, 1000);

  clock_t start, end;
  double cpu_time_used;
  start = clock();

  quick_sort(v, 0, size - 1);

  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("SIZE: %d -> %lf\n", size, cpu_time_used);

  free(v);
}

int main(void) {

  srand(time(NULL));

  for (int i = 1; i <= 1000; i += 10)
    test_quick_sort(SIZE * i);

  return 0;
}
