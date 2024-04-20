/*
3. Serii de puteri. Calculaţi, cu o precizie dată, valoarea lui ex după
dezvoltarea în serie Taylor:

ex = 1 + x1/1! + x2/2! + x3/3! + ...

Calculaţi suma până când termenul curent devine mai mic decât o valoare dată
(de ex. 10-6). Pentru a evita recalcularea lui n! transmiteţi ca parametru şi
termenul curent, şi calculaţi-l pe următorul după relaţia: xn/n! = xn-1/(n-1)!
x/n.
*/

// ex = 1 + x^1/1! + x^2/2! + x^3/3! + x^4/4!.....

#include <math.h>
#include <stdio.h>
#define TOL pow(10, -6)

double taylor(double x, double current_x, unsigned n, unsigned current_n,
              double tol)
{

  if (n == 0)
  {
    n++;
    return 1 + taylor(x, 1, n, 1, tol);
  }

  current_x = current_x * x;
  current_n = current_n * n;

  fprintf(stderr, "x:%lf -> n:%u\n", current_x, current_n);

  double next = current_x / current_n;

  fprintf(stderr, "%u -> %lf\n", n, next);

  if (fabs(next) < tol)
  {
    return next;
  }

  return next + taylor(x, current_x, n, current_n, tol);
}

int main(void)
{

  double x = 1;

  printf("e^%lf = %lf\n", x, taylor(x, 0, 0, 0, TOL));

  return 0;
}
