#include "spectacole.h"
#include <stdlib.h>
#include <string.h>

// checkers

int check_time(time t) {

  if (t.hour < 0 || t.hour > 23 || t.minute < 0 || t.minute > 59) {

#ifdef DEBUG
    fprintf(stderr, "Invalid time format\n");
#endif

    return 0;
  }
  return 1;
}

// input functions

spectacol *read_spectacol(FILE *f) {

  char name[MAX_NAME_LEN];
  time start, end;

  spectacol *s = NULL;

  if (fgets(name, MAX_NAME_LEN, f) == NULL) {

#ifdef DEBUG
    fprintf(stderr, "Error reading name\n");
#endif
    return NULL;
  }

  if (fscanf(f, "%d:%d %d:%d", &start.hour, &start.minute, &end.hour,
             &end.minute) != 4) {

#ifdef DEBUG
    fprintf(stderr, "Error reading data\n");
#endif

    return NULL;
  }

  if (check_time(start) * check_time(end) == 0)
    return NULL;

  s = malloc(sizeof(spectacol));

  if (s == NULL) {

#ifdef DEBUG
    fprintf(stderr, "Error allocating memory\n");
#endif

    return s;
  }

  if (name[strlen(name) - 1] == '\n')
    name[strlen(name) - 1] = '\0';

  strncpy(s->name, name, MAX_NAME_LEN);
  s->start = start;
  s->end = end;

  return s;
}

spectacol **read_all_spectacole(FILE *f, int *n) {

  int index = 0;
  spectacol **s = NULL;

  s = malloc(MAX_SPECTACOLE * sizeof(spectacol *));

  if (s == NULL) {

#ifdef DEBUG
    fprintf(stderr, "Error allocating memory\n");
#endif

    return NULL;
  }

  while (1) {

    s[index] = read_spectacol(f);

    // consume newline character
    fgetc(f);

    if (s[index] == NULL)
      break;

    index++;

    if (index == MAX_SPECTACOLE) {

#ifdef DEBUG
      fprintf(stderr, "Limit reached\n");
#endif
      break;
    }
  }

  *n = index;

  return s;
}

// comparison functions

int cmp_end_time(const void *a, const void *b) {

  spectacol *s1 = *(spectacol **)a;
  spectacol *s2 = *(spectacol **)b;

  if (s1->end.hour < s2->end.hour)
    return -1;
  if (s1->end.hour > s2->end.hour)
    return 1;

  if (s1->end.minute < s2->end.minute)
    return -1;
  if (s1->end.minute > s2->end.minute)
    return 1;

  return 0;
}

// sort

void sort_spectacole(spectacol **s, int n) {
  qsort(s, (size_t)n, sizeof(spectacol *), cmp_end_time);
}

// output functions

void print_spectacol(spectacol *s) {

  if (s == NULL)
    return;

  printf("%s\n%02d:%02d %02d:%02d\n", s->name, s->start.hour, s->start.minute,
         s->end.hour, s->end.minute);
}
