#include "spectacole.h"
#include <stdio.h>
#include <stdlib.h>

void choose_spectacole(spectacol **s, int count) {

  int index = 0;

  print_spectacol(s[0]);

  for (int i = 1; i < count; i++) {

    if (s[i]->start.hour > s[index]->end.hour) {
      print_spectacol(s[i]);
      index = i;
    } else if (s[i]->start.hour == s[index]->end.hour &&
               s[i]->start.minute >= s[index]->end.minute) {
      print_spectacol(s[i]);
      index = i;
    }
  }
}

void print_all_spectacole(spectacol **s, int count) {
  for (int i = 0; i < count; i++) {
    print_spectacol(s[i]);
    printf("\n");
  }
}

int main(void) {

  int count = 0;
  spectacol **s = NULL;

  s = read_all_spectacole(stdin, &count);

  sort_spectacole(s, count);

  choose_spectacole(s, count);
  // print_all_spectacole(s, count);

  return 0;
}
