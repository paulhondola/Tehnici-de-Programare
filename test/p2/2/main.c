/*
1. Implementati un joc in care calculatorul ghiceste intr-un numar cat mai mic
de mutari un numar ales de catre utilizator.  Numarul este natural, intre 1 si
100. La fiecare incercare a calculatorului de a ghici numarul, utilizatorul ii
raspunde cu un numar cuprins intre 0 si 2 avand urmatoarele semnificatii: 0 -
acesta este numarul, ai ghicit 1 - numarul meu este mai mic 2 - numarul meu este
mai mare Exemplu:

Alege te rog un numar....
Numarul tau este 50?
> 1
Numarul tau este 25?<
>2
Numarul tau este 37?
>0
Numarul ales de tine a fost gasit.
*/

#include <stdio.h>
#include <stdlib.h>
#define MIN_NUMBER 1
#define MAX_NUMBER 100
typedef enum { OK = 0, LOW = 1, HIGH = 2, ERR = -1 } binary_search_codes_t;

binary_search_codes_t enter_option(void) {

  binary_search_codes_t code = ERR;

  printf("Input option: ");
  scanf("%d", &code);

  switch (code) {
  case OK:
    break;
  case LOW:
    break;
  case HIGH:
    break;
  default:
    printf("Invalid option!\n");
    return enter_option();
  }

  return code;
}

void search_number(int number, int low, int high) {

  int mid = (low + high) / 2;
  printf("Is your number %d?\n", mid);

  binary_search_codes_t option = enter_option();

  switch (option) {
  case OK:
    printf("Your number is %d!\n", mid);
    return;
  case LOW:
    printf("Lower\n");
    search_number(number, low, mid);
    break;
  case HIGH:
    printf("Higher\n");
    search_number(number, mid, high);
    break;
  default:
    perror("ERROR");
    break;
  }
}

int main(int argc, char **argv) {

  if (argc != 2)
    return 1;

  int number = atoi(argv[1]);

  search_number(number, MIN_NUMBER, MAX_NUMBER);

  return 0;
}
