#include "hs_utils.h"
#include <stdio.h>

int main(void) {

  for (unsigned int i = 0; i < 100; i++)
    printf("%u -> Prim: %u / Palindrom : %u / FIBO : %llu\n", i, estePrim(i),
           ePalindrom(i), getFibboTerm(i));

  return 0;
}
