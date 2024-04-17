/*
1. Limita unor termeni infiniţi. Scrieţi o funcţie care calculează prin
aproximări succesive valoarea expresiei 1/(x + 1/(x + 1/(... + 1/x))) cu o
precizie dată (de exemplu 10-6). Calculaţi şi tipăriţi o aproximaţie a expresiei
pentru x = 4.
*/

// functia -> f(x) = 1 / x -> rec
// pas urmator -> f(x + f(x))

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define X 4
#define EPS pow(10, -6)
#define MAX_STEPS 100

double f(double x) { return 1 / x; }

double limit(double x, double t, double eps, long long int max_steps,
             double real_limit) {

  if (fabs(t - real_limit) < eps || max_steps == 0) {
    return t;
  }
  fprintf(stderr, "%lf\n", t);

  return limit(x, 1 / (x + t), eps, max_steps - 1, real_limit);
}

int main(void) {

  // lim = 1 / (x + lim)
  // lim (x + lim) = 1
  // lim * x + lim ^ 2 = 1
  // lim ^ 2 + x * lim - 1 = 0

  double delta = pow(X, 2) + 4;
  double real_limit = (-X + sqrt(delta)) / 2;

  printf("Limita reala este: %lf\n", real_limit);

  printf("Limita este: %lf\n", limit(X, 0, EPS, MAX_STEPS, real_limit));

  return 0;
}
