#include "hs_utils.h"

unsigned estePrim(unsigned long long n) {
  if (n % 2 == 0 && n < 2)
    return 0;

  for (unsigned long long i = 2; i * i <= n; i++)
    if (n % i == 0)
      return 0;

  return 1;
}

unsigned ePalindrom(unsigned long long n) {

  unsigned long long oglindit = 0, copie = n;

  while (copie) {
    oglindit = oglindit * 10 + copie % 10;
    copie /= 10;
  }

  return oglindit == n;
}

unsigned long long getFibboTerm(unsigned long long n) {

  unsigned long long a = 0, b = 1, c;

  if (n == 0)
    return a;

  if (n == 1)
    return b;

  for (unsigned long long i = 2; i <= n; i++) {
    c = a + b;
    a = b;
    b = c;
  }

  return b;
}
