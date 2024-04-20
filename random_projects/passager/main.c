/*
Clientul va avea acces la urmatoarele functii declarate intr-un fisier header:

Prezentati sub forma de comentarii in cod, analiza complexitatii din punct de
vedere al timpului de executie si al memoriei utilizate, in termeni de O()
pentru functiile implementate;

Biblioteca nu va expune clientului detaliile de implementare ale tipului de
date, iar utilizarea se va face doar prin intermediul functiilor implementate.

Puteti implementa si orice alte functii/tipuri de date pe care le considerati
necesare pentru "eleganta" solutiei. In fisierul header nu pot fi adaugate alte
functii.

Implementati de asemenea si un client in care sa ilustrati utilizarea
bibliotecii. Pentru simplificarea testarii, puteti genera siruri de caractere
aleatoare de lungime fixa.
*/

#include "pasager.h"

int main(void)
{

  avion_t avion = init_avion(5, 12);

  for (int i = 0; i < 15; i++)
    avion = add_pasager(avion, "Ion", i * 10, 1);

  for (int i = 0; i < 3; i++)
    avion = add_pasager(avion, "Ion", i * 10, 2);

  int total_moved = move_pasageri(avion, 12, 1);

  printf("TOTAL MUTATI LA CATEGORIA 2: %d\n", total_moved);

  afisare_pasageri(avion, -1);

  return 0;
}
