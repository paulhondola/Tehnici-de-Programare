/*
4. https://www.pbinfo.ro/probleme/342/soarece (indicatie:
https://www.enjoyalgorithms.com/blog/flood-fill-problem)
*/

#include <stdio.h>
#define MAX_SIZE 100

int n, m, x_start, y_start, x_end, y_end, counter;
int matrix[MAX_SIZE][MAX_SIZE];
const int direction_x[] = {0, 0, 1, -1}; // N, S, E, W
const int direction_y[] = {1, -1, 0, 0};

void print_matrix(int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      printf("% d  ", matrix[i][j]);
    printf("\n");
  }

  printf("................................................................."
         "..........\n");
}

int inside(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; }

void back(int i, int j, int steps) {

  // directiile contin toate combinatiile de coordonate pe care le poate lua
  // soarecele daca se putea misca pe diagonale, directiile ar fi 8
  // NE, SE, NV, SV, E, V, N, S
  for (int d = 0; d < 4; d++) {

    int new_i = i + direction_x[d];
    int new_j = j + direction_y[d];

    if (inside(new_i, new_j) && matrix[new_i][new_j] == 0) {
      matrix[new_i][new_j] = steps;
      print_matrix(n, m);
      if (new_i == x_end && new_j == y_end) {
        counter++;

      } else
        back(new_i, new_j, steps + 1);

      matrix[new_i][new_j] = 0;
    }
  }
}

int main(void) {

  if (scanf("%d %d", &n, &m) != 2)
    return 1;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (scanf("%d", &matrix[i][j]) != 1)
        return 1;
      else
        matrix[i][j] = -matrix[i][j];

  if (scanf("%d %d %d %d", &x_start, &y_start, &x_end, &y_end) != 4)
    return 1;

  x_start--;
  y_start--;
  x_end--;
  y_end--;

  if (matrix[x_start][y_start] != 0 || matrix[x_end][y_end] != 0) {
    printf("Nu se poate ajunge la destinatie\n");
    return 2;
  }

  matrix[x_start][y_start] = 1;

  print_matrix(n, m);

  back(x_start, y_start, 2);

  if (counter == 0)
    printf("Nu se poate ajunge la destinatie\n");
  else
    printf("Posibilitati: %d\n", counter);
  return 0;
}
