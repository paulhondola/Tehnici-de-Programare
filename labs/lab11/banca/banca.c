/*
6. Se citesc de la intrarea standard, 3 numere naturale S, n si e cu urmatoarele
semnificatii: S este o suma de bani care trebuie platita folosind bancnote care
au valori puterile lui e, de la e la 0, la e la n. Se se afiseze modalitatea de
plata (câte bancnote de ce tip) folosind un numar minim de bancnote de tipurile
precizate si sa se afiseze la final numarul total de bancnote folosite.
*/

#include <stdio.h>
// tip de bancota sau moneda
typedef struct {
  int val;
  char *nume;
} Tip;
#define NTIPURI 10

Tip tipuri[NTIPURI] = {{50000, "500 lei"}, {20000, "200 lei"},
                       {10000, "100 lei"}, {5000, "50 lei"},
                       {1000, "10 lei"},   {500, "5 lei"},
                       {100, "1 leu"},     {50, "50 bani"},
                       {10, "10 bani"},    {1, "1 ban"}};

int main(void) {

  float valLei;
  printf("valoare: ");
  scanf("%g", &valLei);
  int valBani = (int)(valLei * 100);
  int iTip = 0;
  while (valBani) {
    int n = valBani / tipuri[iTip].val;
    if (n) {
      // Il indexul curent in tipuri / l cat timp mai sunt bani de platit /
      //    l numarul de unitati(bancnote sau monede)
      //     cu acea valoare
      printf("%d x %s\n", n, tipuri[iTip].nume);
      valBani -= n * tipuri[iTip].val;
    }
    ++iTip;
  }
  return 0;
}
