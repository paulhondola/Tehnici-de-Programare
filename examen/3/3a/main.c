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

#include <stdio.h>

void rec_fill_array(int array[], int n, int start_value, int left, int right) {}

int main(void) {
  int n = 4;
  int array[2 * n];
  int start = 1;
  int right = 0;
  int left = 1;

  return 0;
}
