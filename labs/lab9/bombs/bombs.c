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

bomb_t read_bomb_data(FILE *file)
{
  float x, y, r;

  if (fscanf(file, "%f %f %f", &x, &y, &r) != 3)
  {
    printf("Invalid input for bomb data\n");
    exit(2);
  }

  return (bomb_t){x, y, r, FALSE};
}

bomb_t *read_bomb_array_data(size_t count, FILE *file)
{

  bomb_t *arr = malloc(count * sizeof(bomb_t));

  if (arr == NULL)
  {
    perror("Memory allocation failed\n");
    exit(3);
  }

  for (size_t i = 0; i < count; i++)
  {
    arr[i] = read_bomb_data(file);
  }

  return arr;
}

// WRITING
void print_bomb_data(bomb_t bomb, FILE *file)
{
  fprintf(file, "X: %d | Y: %d | R: %d | ", bomb.x, bomb.y, bomb.radius);

  switch (bomb.state)
  {
  case FALSE:
    fprintf(file, "NOT EXPLODED\n");
    break;
  case TRUE:
    fprintf(file, "EXPLODED\n");
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

  for (size_t i = 0; i < count; i++)
  {
    if (arr[i].state == FALSE && is_in_radius(main_bomb, arr[i]))
    {
      arr[i].state = TRUE;
      explode(arr[i], arr, count);
    }
  }
}
