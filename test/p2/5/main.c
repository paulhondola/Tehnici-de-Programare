#include <math.h>
#include <stdio.h>

double f(double x) { return sin(x) + sin(2 * x) + x; }

double bisectie(double y, double a, double b, double (*f)(double), double tol) {
  double c = (a + b) / 2.0;
  if ((b - a) / 2.0 < tol)
    return c;

  if (f(c) < y)
    return bisectie(y, c, b, f, tol);
  else
    return bisectie(y, a, c, f, tol);
}

double findRootIterativ(double y, double (*f)(double), double tol) {
  double a = 0.0;
  double b = 1.0;
  double c;

  while ((b - a) / 2.0 > tol) {
    c = (a + b) / 2.0;
    if (f(c) < y)
      a = c;
    else
      b = c;
  }
  return (a + b) / 2.0;
}

int main() {
  double y;
  scanf("%lf", &y);
  printf("%lf\n", bisectie(y, 0.0, 1.0, f, pow(10, -8)));
  printf("%lf\n", findRootIterativ(y, f, pow(10, -8)));
  return 0;
}
