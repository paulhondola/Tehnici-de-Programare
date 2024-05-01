/*
2. Se dau trei numere naturale n a b, 1 ≤ a < b < n. Să se determine o
modalitate de a-l scrie pe n ca sumă de termeni egali cu a sau b în care numărul
de termeni egali cu a este maxim. La intrare se vor citi n a si b, in aceasta
ordine, iar la iesire se va scrie valoarea numarului de aparitii ale lui a si
ale lui b, in aceasta ordine, separate prin minim un spatiu.
*/

#include <stdio.h>

int main(void) {
  int n, a, b;

  n = 999;
  a = 17;
  b = 23;

  int a_count = 0;
  int b_count = 0;

  a_count = n / a;

  while (1) {
    if ((n - a_count * a) % b == 0) {

      b_count = (n - a_count * a) / b;
      break;
    }

    a_count--;
  }

  if (a_count < 0 || b_count < 0) {
    printf("Nu exista\n");
    return 0;
  }

  printf("%d %d\n", a_count, b_count);

  return 0;
}
