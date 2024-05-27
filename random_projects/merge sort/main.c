#include <stdio.h>

void merge_sort(int v[], int low, int high) {

  if (low == high)
    return;

  int mid = (low + high) / 2;
  int i = low;
  int j = mid + 1;

  merge_sort(v, low, mid);
  merge_sort(v, mid + 1, high);

  int aux[high - low + 1];
  int index = 0;

  while (i <= mid && j <= high)
    if (v[i] < v[j])
      aux[index++] = v[i++];
    else
      aux[index++] = v[j++];

  while (i <= mid)
    aux[index++] = v[i++];

  while (j <= high)
    aux[index++] = v[j++];

  for (i = 0; i < index; i++)
    v[low + i] = aux[i];
}

void print_array(int v[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", v[i]);
  printf("\n");
}

int main(void) {
  int v[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  int n = sizeof(v) / sizeof(*v);

  merge_sort(v, 0, n - 1);

  print_array(v, n);

  return 0;
}
