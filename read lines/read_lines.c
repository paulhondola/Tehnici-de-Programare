#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

typedef struct {
  char line[MAX_LINE_LEN];
  unsigned len;
  unsigned word_count;
} line_t;

char *read_line(FILE *file) {
  char *line = malloc(MAX_LINE_LEN);

  if (line == NULL) {
    perror("Alloc line failed");
    return NULL;
  }

  if (fgets(line, MAX_LINE_LEN, file) == NULL) {
    free(line);
    return NULL;
  }

  if (line[strlen(line) - 1] == '\n')
    line[strlen(line) - 1] = '\0';

  if (line[strlen(line) - 1] == '\0') {
    free(line);
    return NULL;
  }

  return line;
}

line_t *read_lines(FILE *file, unsigned *size) {

  *size = 0;
  line_t *lines = NULL;
  char *line = NULL;

  while (1) {

    if ((line = read_line(file)) == NULL)
      break;

    (*size)++;
    lines = realloc(lines, *size * sizeof(line_t));

    strcpy(lines[*size - 1].line, line);
    lines[*size - 1].len = strlen(line);
    lines[*size - 1].word_count = 0;

    free(line);
  }

  return lines;
}

void print_lines(line_t *lines, unsigned size) {
  for (unsigned i = 0; i < size; i++) {
    printf("Line %d: %s, Length: %u\n", i, lines[i].line, lines[i].len);
  }
}

int main(void) {

  line_t *lines = NULL;

  FILE *file = fopen("in.txt", "r");

  if (file == NULL) {
    printf("Error! Could not open file\n");
    return -1;
  }

  unsigned size = 0;

  lines = read_lines(file, &size);

  print_lines(lines, size);

  fclose(file);

  free(lines);

  return 0;
}
