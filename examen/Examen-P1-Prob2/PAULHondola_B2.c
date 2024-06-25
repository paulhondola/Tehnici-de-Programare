#include <stdio.h>

#define MAX_HEALTH 100
#define MAX_MATRIX_SIZE 100
#define MAX_NEGATIVE_VALUE -1000000000

/* DATELE TESTATE (cu redirectare din fisier)
10 10
2 2 8 8
1 -1 2 -2 3 -3 4 -4 5 -5
0 0 0 0 0 0 0 0 0 0
2 0 -3 5 -5 1 2 3 4 -1
0 5 1 -4 0 1 -2 0 1 4
0 0 0 0 0 0 0 0 0 0
1 3 0 -5 -3 2 -3 -2 1 1
3 0 4 3 1 3 5 -5 1 2
0 1 2 3 4 5 -5 4 3 2
-5 -4 -3 -2 -1 0 1 2 2 4
0 0 0 0 0 0 0 0 0 0
*/

typedef struct {
  int value, visited;
} POINT;

int read_matrix_data(POINT matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], int lines,
                     int columns) {

  for (int i = 0; i < lines; i++)
    for (int j = 0; j < columns; j++) {
      matrix[i][j].visited = 0;
      if (scanf("%d", &matrix[i][j].value) != 1)
        return 0;
    }

  return 1;
}

void print_matrix_data(POINT matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE],
                       int lines, int columns) {
  printf("MATRICEA DE INFLUENTA\n");
  printf("---------------------------------------------------------\n");
  for (int i = 0; i < lines; i++) {
    for (int j = 0; j < columns; j++)
      printf("%3d ", matrix[i][j].value);
    printf("\n");
  }
  printf("---------------------------------------------------------\n");
}

void print_matrix_visited(POINT matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE],
                          int lines, int columns) {
  printf("MATRICEA CU LOCURILE VIZITATE\n");
  printf("---------------------------------------------------------\n");
  for (int i = 0; i < lines; i++) {
    for (int j = 0; j < columns; j++)
      printf("%3d ", matrix[i][j].visited);
    printf("\n");
  }
  printf("---------------------------------------------------------\n");
}

int end_condition(int start_x, int start_y, int end_x, int end_y) {
  return start_x == end_x && start_y == end_y;
}

int get_max_value(int array[4]) {
  int max1 = (array[0] > array[1]) ? array[0] : array[1];
  int max2 = (array[2] > array[3]) ? array[2] : array[3];
  return (max1 > max2) ? max1 : max2;
}

void get_next_step(POINT matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], int lines,
                   int columns, int start_x, int start_y, int *next_x,
                   int *next_y) {

  // obtine coordonatele punctului cu valoarea maxima, care este vizitabil (este
  // in parametrii matricii) si nu este vizitat deja

  // N S E W
  int array[4] = {MAX_NEGATIVE_VALUE, MAX_NEGATIVE_VALUE, MAX_NEGATIVE_VALUE,
                  MAX_NEGATIVE_VALUE};

  // check N
  if (start_x - 1 >= 0 && matrix[start_x - 1][start_y].visited == 0)
    array[0] = matrix[start_x - 1][start_y].value;

  // check S
  if (start_x + 1 < lines && matrix[start_x + 1][start_y].visited == 0)
    array[1] = matrix[start_x + 1][start_y].value;

  // check E
  if (start_y + 1 < columns && matrix[start_x][start_y + 1].visited == 0)
    array[2] = matrix[start_x][start_y + 1].value;

  // check W
  if (start_y - 1 >= 0 && matrix[start_x][start_y - 1].visited == 0)
    array[3] = matrix[start_x][start_y - 1].value;

  int max_value = get_max_value(array);

  // printf("%d %d %d %d", array[0], array[1], array[2], array[3]);

  if (max_value == array[0]) {
    *next_x = start_x - 1;
    *next_y = start_y;
    return;
  }

  if (max_value == array[1]) {
    *next_x = start_x + 1;
    *next_y = start_y;
    return;
  }

  if (max_value == array[2]) {
    *next_x = start_x;
    *next_y = start_y + 1;
    return;
  }

  if (max_value == array[3]) {
    *next_x = start_x;
    *next_y = start_y - 1;
    return;
  }

  return;
}

void fill(POINT matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], int lines,
          int columns, int start_x, int start_y, int end_x, int end_y,
          long long int *health, long long int *path_distance) {

  (*path_distance)++; // creste numarul de pasi
  matrix[start_x][start_y].visited =
      *path_distance; // selectam punctul ca fiind vizitat
  *health +=
      matrix[start_x][start_y].value; // crestem / scadem din "viata" noastra
                                      // valoarea punctului vizitat

  if (end_condition(start_x, start_y, end_x,
                    end_y)) // verificam conditia de finalizare (s-a ajuns la
                            // punctul dorit)
  {
    print_matrix_data(matrix, lines, columns);
    print_matrix_visited(matrix, lines, columns);
    return;
  }

  int next_x = 0, next_y = 0;
  get_next_step(matrix, lines, columns, start_x, start_y, &next_x,
                &next_y); // cautam punctul optim pentru urmatorul pas
  fill(matrix, lines, columns, next_x, next_y, end_x, end_y, health,
       path_distance); // continuam recursiv din punctul ales
}

int main(void) {

  long long int health = MAX_HEALTH;
  long long int path_distance = 0;

  POINT matrix[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];

  int lines, columns, start_x, start_y, end_x, end_y;

  if (scanf("%d %d %d %d %d %d", &lines, &columns, &start_x, &start_y, &end_x,
            &end_y) != 6) {
    perror("Invalid input data!");
    return 1;
  }

  if (read_matrix_data(matrix, lines, columns) == 0) {
    perror("Invalid input data!");
    return 2;
  }

  printf("LOCATIA INITIALA: %d %d\nLOCATIA FINALA: %d %d\n\n", start_x, start_y,
         end_x, end_y);

  fill(matrix, lines, columns, start_x, start_y, end_x, end_y, &health,
       &path_distance);

  printf("Tarie ramasa: %lld\nNumar de pasi facuti: %lld\n", health,
         path_distance);

  return 0;
}
