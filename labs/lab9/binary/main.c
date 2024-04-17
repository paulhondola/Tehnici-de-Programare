#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float function(float x) { return (x * x) - 3; }

double search_radacina_functie(float a, float b, float limit) {
  printf("a= %lf b=%lf\n", a, b);
  // float aux = (a + b) / 2;  // initial, aux = mijlocul intervalului

  // if(fabs(b - a) < limit)  // intervalul este foarte mic (ex.: limit = 10 ^
  // -6)
  // {
  //     printf("Nu s-a putut identifica o solutie exacta.\n");
  //     return aux;
  // }

  if (fabs(b - a) < limit) {
    return a;
  } else {
    double mij = (a + b) / 2;
    if (function(a) * function(mij) < 0) {
      return search_radacina_functie(a, mij, limit);
    } else {
      return search_radacina_functie(mij, b, limit);
    }
  }
}

int main(void) {
  printf("Radacina (aproximativa) a functiei este: %lf\n",
         search_radacina_functie(1, 3, 1.0 / 1000000));
  return 0;
}
