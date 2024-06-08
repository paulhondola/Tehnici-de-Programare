#include "priority_queue.h"
#include <stdio.h>
/*
Sa se defineasca si implementeze o biblioteca-C care ofera clientului un nou tip
de date PCoada_t si setul de operatii aferente. Tipul de date PCoada_t
implementeaza conceptul de coada cu prioritate, adica o structura de date Coada
asupra careia sa adauga posibilitatea de a asigna fiecarui element o
"prioritate".

Biblioteca va implementa operatiile specifice tipului de date sub forma unor
functii cu parametri specifici.

Operatiile de inserare si stergere se vor face in timp optim, cu respectarea
prioritatii elementelor: se vor insera elemente la prima pozitie unde permite
prioritatea si se va scoate cel mai "vechi" element. Gestionarea elementelor se
va face folosind alocare dinamica de memorie.
*/

int main(void) {

  queue q = init_queue(100);

  queue_data data1 = create_queue_data(1, 2, "root");
  queue_data data2 = create_queue_data(2, 3, "chrome");
  queue_data data3 = create_queue_data(3, 4, "macos");
  queue_data data4 = create_queue_data(0, 1, "kernel");

  q = enqueue(q, data1);
  q = enqueue(q, data2);

  q = dequeue(q);
  q = enqueue(q, data3);
  q = enqueue(q, data4);

  print_queue(q);

  free_queue(q);

  return 0;
}
