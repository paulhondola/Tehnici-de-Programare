#include <stdio.h>
#include <stdlib.h>

int int_cmp(const void *p, const void *q) {

  int x = *(int *)p;
  int y = *(int *)q;

  return x - y;
}

int main(void) {

  int v[] = {3, 1, 4, 5, 2, 1, 5};

  int n = sizeof(v) / sizeof(v[0]);

  qsort(v, (size_t)n, sizeof(v[0]), int_cmp);

  for (int i = 0; i < n; i++)
    printf("%d ", v[i]);

  return 0;
}
