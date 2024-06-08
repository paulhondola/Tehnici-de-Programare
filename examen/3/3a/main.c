/*
1. Sa se implementeze o functie C care primeste un numar natural n,construieste
si afiseaza un șir format din primele 2n numere naturale, dispuse astfel:

se pleacă de la șirul 1 2
exact la mijlocul acestui șir se inserează șirul 3 4 și se obține 1 3 4 2
exact la mijlocul acestui șir se inserează șirul 5 6 7 8 și se obține 1 3 5 6 7
8 4 2 etc în general, la mijlocul șirului format din primele 2k numere naturale
se inserează șirul ordonat format din următoarele 2k numere naturale. Se va
implemente o functie main() adecvata si orice alte functii necesare.
*/

#include <math.h>
#include <stdio.h>

void fill_array(int array[], int n) {

  int start_value = 0;
  int right = 2 * n - 1;
  int left = 0;

  // filled 2 (left and right values)

  array[left++] = ++start_value;
  array[right--] = ++start_value;

  int cycles = (int)log2(n);

  int fill_size = 1;

  for (int i = 0; i < cycles; i++) {

    for (int j = 0; j < fill_size; j++) {
      array[left++] = ++start_value;
    }

    for (int j = 0; j < fill_size; j++) {
      array[right++] = ++start_value;
    }

    right -= fill_size + 2 * fill_size;

    printf("FILLED: %d\n", fill_size);

    fill_size *= 2;
  }
}

void print_array(int array[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", array[i]);
  printf("\n");
}

int main(void) {

  int n = 16;
  int array[2 * n];

  fill_array(array, n);
  print_array(array, 2 * n);

  return 0;
}
