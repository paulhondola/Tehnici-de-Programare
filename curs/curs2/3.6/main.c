// Aplicația 3.6: Să se completeze exemplul de implementare a colecțiilor
// eterogene folosind pointeri la funcții cu tipul de elemente ​Triunghi​.
// Un triunghi este definit prin lungimile laturilor sale.

#include "objects.h"

#include <stdio.h>

int main(void) {

  factory_t factory = init_factory();

  object_t *figura1 = factory.generate_triangle(3, 4, 5);

  object_t *figura2 = factory.generate_circle(5);

  object_t *figura3 = factory.generate_rectangle(3, 4);

  printf("Perimeter: %f\n", figura1->methods.get_perimeter(figura1));
  printf("Area: %f\n", figura1->methods.get_area(figura1));

  printf("Perimeter: %f\n", figura2->methods.get_perimeter(figura2));
  printf("Area: %f\n", figura2->methods.get_area(figura2));

  printf("Perimeter: %f\n", figura3->methods.get_perimeter(figura3));
  printf("Area: %f\n", figura3->methods.get_area(figura3));

  free(figura1);
  free(figura2);
  free(figura3);

  return 0;
}
