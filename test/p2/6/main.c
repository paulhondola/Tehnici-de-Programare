#include <iso646.h>
#include <stdio.h>
#include <stdlib.h>

int read_array_data(int v[], int n) {

  for (int i = 0; i < n; i++)
    if (scanf("%d", &v[i]) != 1)
      return 0;

  return 1;
}

void make_sum_array(int arr[], int sum[], int n) {
  sum[0] = arr[0];
  for (int i = 1; i < n; i++)
    sum[i] = sum[i - 1] + arr[i];
}

void print_array(int v[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", v[i]);

  printf("\n");
}

int b_search(int v[], int left, int right, int searched) {

  if (left > right)
    return -1;

  int mid = (left + right) / 2;

  if (v[mid] == searched)
    return mid;

  if (v[mid] < searched)
    return b_search(v, mid + 1, right, searched);
  else
    return b_search(v, left, mid - 1, searched);
}

void get_index(int arr[], int sum[], int n) {
  for (int i = 0; i < n; i++) {
    int index = b_search(sum, 0, n - 1, arr[i]);

    printf("%d ", index + 1);
  }
}

int main(void) {

  // data input
  int n = 0;
  if (scanf("%d", &n) != 1)
    return 1;

  int v[n], sum[n];
  if (read_array_data(v, n) == 0)
    return 2;

  make_sum_array(v, sum, n);

  print_array(v, n);
  print_array(sum, n);

  get_index(v, sum, n);

  return 0;
}
