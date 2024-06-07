#include <math.h>
#include <stdio.h>
/*
2. Se citesc dintr-un fisier transmis ca si parametru in linie de comanda doua
numere naturale n si s (n<=10, s<=20). Afisati in ordine crescatoare toate
numerele cu n cifre care au suma cifrelor egala cu s si in care oricare doua
cifre alaturate au paritate diferita. Exemple: n=4, s=8 => 1016, 1034, 1052,
1070, 1214, 1232, ... 7010
*/

int sum_of_digits(int n) {
  if (n == 0)
    return 0;
  return n % 10 + sum_of_digits(n / 10);
}

int different_parity_digits(int n) {
  while (n) {
    if (n % 2 == n / 10 % 2)
      return 0;

    n /= 10;
  }

  return 1;
}

int main(void) {

  int n = 4;
  int s = 8;

  int start = (int)pow(10, n - 1);
  int end = start * 10;

  for (int i = start; i < end; i++)
    if (sum_of_digits(i) == s && different_parity_digits(i))
      printf("%d ", i);

  return 0;
}
