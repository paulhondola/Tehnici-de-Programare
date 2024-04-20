/*
3. Se dau n bombe, numerotate de la 1 la n, pentru fiecare cunoscandu-se
coordonatele (x,y) unde sunt plasate si raza de distrugere r. La explozia unei
bombe se va distruge totul in interiorul si pe cercul de centru (x,y) si raza r,
iar daca exista alte bombe in aceasta zona, acestea vor exploda la randul lor.
Se da indicele k al primei bombe care explodeaza si se cere sa se calculeze cate
bombe raman neexplodate. Datele se citesc din fisierul bombe.in si rezultatele
se vor afisa in fisierul bombe.out. In fisierul bombe.in pe prima linie se afla
numerele n si k, iar pe urmatoarele n linii coordonatele si razele de distrugere
ale celor n bombe. n si k sunt numere naturale, coordonatele numere intregi, iar
razele numere naturale. Exemplu:

bombe.in
8 5
4 5 4
-3 -4 1
4 1 1
2 1 3
2 2 2
1 1 2
-1 1 2
-3 3 3
bombe.out
3
Explicatie: Prima explodeaza bomba rosie (a 5-a), ea declanseaza cele doua bombe
verzi, iar fiecare dintre cele verzi declaseaza cate una albastra. Bombele negre
raman neexplodate.
1
*/

#include "bombs.h"

// READING
void read_index_data(size_t *count, size_t *index, FILE *file)
{
  if (fscanf(file, "%zu %zu", count, index) != 2)
  {
    printf("Invalid input for count and index\n");
    exit(1);
  }
}

bomb_t read_bomb_data(int id, size_t size, FILE *file)
{
  float x, y, r;

  if (fscanf(file, "%f %f %f", &x, &y, &r) != 3)
  {
    printf("Invalid input for bomb data\n");
    exit(2);
  }

  int *visited = malloc(size * sizeof(int));

  if (visited == NULL)
  {
    perror("Memory allocation failed\n");
    exit(3);
  }

  return (bomb_t){id, x, y, r, FALSE, 0, visited};
}

void check_bombs_in_radius(bomb_t *arr, size_t count, size_t index)
{
  size_t in_radius = 0;
  for (size_t i = 0; i < count; i++)
    if (i != index && is_in_radius(arr[index], arr[i]))
      arr[index].bombs_in_radius[in_radius++] = i;

  arr[index].bombs_in_radius_count = in_radius;
}

bomb_t *read_bomb_array_data(size_t count, FILE *file)
{

  bomb_t *arr = malloc(count * sizeof(bomb_t));

  if (arr == NULL)
  {
    perror("Memory allocation failed\n");
    exit(4);
  }

  for (size_t i = 0; i < count; i++)
    arr[i] = read_bomb_data(i, count - 1, file);

  for (size_t i = 0; i < count; i++)
    check_bombs_in_radius(arr, count, i);

  return arr;
}

// WRITING
void print_bomb_data(bomb_t bomb, FILE *file)
{
  fprintf(file, "ID: %d | X: %d | Y: %d | R: %d | BOMBS IN RADIUS: %zu | ",
          bomb.id, bomb.x, bomb.y, bomb.radius, bomb.bombs_in_radius_count);

  switch (bomb.state)
  {
  case TRUE:
    fprintf(file, "EXPLODED\n");
    break;
  case FALSE:
    fprintf(file, "NOT EXPLODED\n");
    break;
  default:
    fprintf(file, "UNKNOWN\n");
  }
}

void print_bomb_array_data(bomb_t *bombs, size_t count, FILE *file)
{
  for (size_t i = 0; i < count; i++)
    print_bomb_data(bombs[i], file);
}

void print_bomb_statistics(bomb_t *arr, size_t count, FILE *file)
{
  size_t exploded = 0, unexploded = 0;
  for (size_t i = 0; i < count; i++)
    if (arr[i].state == TRUE)
      exploded++;
    else
      unexploded++;

  fprintf(file, "Exploded: %zu | Not Exploded: %zu\n", exploded, unexploded);
}

// BOMB EXPLOSION

int is_in_radius(bomb_t main, bomb_t secondary)
{
  return (main.x - secondary.x) * (main.x - secondary.x) +
             (main.y - secondary.y) * (main.y - secondary.y) <=
         main.radius * main.radius;
}

void explode(bomb_t main_bomb, bomb_t *arr, size_t count)
{

  for (size_t i = 0; i < main_bomb.bombs_in_radius_count; i++)
    if (arr[main_bomb.bombs_in_radius[i]].state == FALSE)
    {
      arr[main_bomb.bombs_in_radius[i]].state = TRUE;
      explode(arr[main_bomb.bombs_in_radius[i]], arr, count);
    }
}
