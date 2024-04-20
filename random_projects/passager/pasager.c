#include "pasager.h"

/*
Se considera un tip de date Pasager_t, cate pastreaza urmatoarele informatii: un
sir de maxim 40 de caractere ce contine numele pasagerului, greutatea bagajului
si categoria in care acesta se afla (1 sau 2).
*/

#define MAX_PASAGER_NAME_LENGTH 41

struct PASAGER_T
{
  char name[MAX_PASAGER_NAME_LENGTH];
  int weight;
  int category;
};

/*
De asemenea, se va implementa o structura de date Avion_t care va contine doi
pointeri la cate un tablou de Pasager_t corespunzand celor doua categorii de
locuri, numarul de locuri disponibile pentru categoria 1, numarul de locuri
disponibile pentru categoria 2 si alte date considerate necesare.
*/

struct AVION_T
{
  pasager_t *pas_cat1;
  pasager_t *pas_cat2;

  size_t cat1_size;
  size_t cat1_capacity;

  size_t cat2_size;
  size_t cat2_capacity;
};

pasager_t init_pasager(const char *name, const unsigned weigth,
                       const int category)
{
  pasager_t pasager = malloc(sizeof(struct PASAGER_T));

  if (pasager == NULL)
  {
    perror("Pasager memory error!");
    exit(1);
  }

  strcpy(pasager->name, name);
  pasager->weight = weigth;
  pasager->category = category;

  return pasager;
}

avion_t init_avion(size_t cat1_cap, size_t cat2_cap)
{
  avion_t avion = malloc(sizeof(struct AVION_T));

  if (avion == NULL)
  {
    perror("Avion memory error!");
    exit(1);
  }

  *avion = (struct AVION_T){.pas_cat1 = NULL,
                            .pas_cat2 = NULL,
                            .cat1_size = 0,
                            .cat1_capacity = cat1_cap,
                            .cat2_size = 0,
                            .cat2_capacity = cat2_cap};

  avion->pas_cat1 = malloc(cat1_cap * sizeof(pasager_t));

  if (avion->pas_cat1 == NULL)
  {
    perror("Avion memory error!");
    exit(1);
  }

  avion->pas_cat2 = malloc(cat2_cap * sizeof(pasager_t));

  if (avion->pas_cat2 == NULL)
  {
    perror("Avion memory error!");
    exit(1);
  }

  return avion;
}

/*
Avion_t* adaugare(Avion_t* a, char* nume, int gr_b, int nr_cat); //primeste
drept parametru un pointer la un Avion_t curent si parametrii specifici unui
Pasager_t. Functia adauga pasagerul nou creat la categoria de locuri
corespunzatoare DOAR daca mai exista locuri disponibile la acea categorie. In
caz contrar, se va returna avionul nemodificat si se va afisa mesajul “Nu mai
sunt locuri la categoria x” (x poate fi 1 sau 2).

*/

avion_t add_pasager(avion_t av, char *nume, int greutate, int categorie)
{

  switch (categorie)
  {
  case 1:
    if (av->cat1_size == av->cat1_capacity)
    {
      printf("Nu mai sunt locuri la categoria 1\n");
      return av;
    }
    av->pas_cat1[av->cat1_size++] = init_pasager(nume, greutate, categorie);
    break;

  case 2:
    if (av->cat2_size == av->cat2_capacity)
    {
      printf("Nu mai sunt locuri la categoria 2\n");
      return av;
    }
    av->pas_cat2[av->cat2_size++] = init_pasager(nume, greutate, categorie);
    break;
  }

  return av;
}

/*
void afisarePasageri(Avion_t*, int g); //afiseaza in ordine alfabetica datele
pasagerilor din avion care au greutatea bagajului mai mare decat g
*/

pasager_t *create_pasager_array(avion_t av, size_t *size)
{

  *size = av->cat1_size + av->cat2_size;

  pasager_t *array = malloc((*size) * sizeof(pasager_t));

  if (array == NULL)
  {
    perror("Alloc error");
    exit(2);
  }

  for (size_t i = 0; i < av->cat1_size; i++)
    array[i] = av->pas_cat1[i];

  for (size_t i = 0; i < av->cat2_size; i++)
    array[i + av->cat1_size] = av->pas_cat2[i];

  return array;
}

int compare_pasager_names(const void *p, const void *q)
{
  pasager_t a = *(pasager_t *)p;
  pasager_t b = *(pasager_t *)q;

  return strcmp(a->name, b->name);
}

void afisare_pasageri(avion_t av, int greutate)
{

  size_t size = 0;
  pasager_t *array = create_pasager_array(av, &size);

  qsort(array, size, sizeof(pasager_t), compare_pasager_names);

  for (size_t i = 0; i < size; i++)
  {
    if (array[i]->weight > greutate)
    {
      printf("%s %d %d\n", array[i]->name, array[i]->weight,
             array[i]->category);
    }
  }

  free(array);
}

/*
int mutarePasageri(Avion_t*, int x, int nr_cat); //ultimii x pasageri din
categoria nr_cat trebuie mutati in cealalta categorie. Functia returneaza
numarul de pasageri care au putut fi mutati tinandu-se cont de numarul de locuri
disponibile
*/

int move_pasageri(avion_t av, size_t x, int categorie)
{

  size_t pas_moved = 0;
  size_t space_left = 0;

  switch (categorie)
  {
  case 1:

    space_left = av->cat2_capacity - av->cat2_size;
    while (1)
    {

      // nu mai sunt pasageri de mutat
      if (x == 0)
        break;

      // nu mai sunt locuri in categoria 2

      if (pas_moved == space_left)
      {
        printf("Nu mai sunt locuri la categoria 2 (MUTARE)\n");
        break;
      }

      // nu mai sunt pasageri din categoria 1 de mutat

      if (av->cat1_size == 0)
      {
        printf("Nu mai sunt pasageri la categoria 1 (MUTARE)\n");
        break;
      }

      printf("PASAGERI MUTATI %zu\n", pas_moved);

      av->pas_cat2[av->cat2_size] = av->pas_cat1[av->cat1_size - 1];

      av->cat2_size++;
      av->cat1_size--;

      av->pas_cat2[av->cat2_size - 1]->category = 3;

      pas_moved++;
      x--;
    }
    break;

  case 2:

    space_left = av->cat1_capacity - av->cat1_size;
    while (1)
    {

      // nu mai sunt pasageri de mutat
      if (x == 0)
        break;

      // nu mai sunt locuri in categoria 1
      if (pas_moved == space_left)
      {
        printf("Nu mai sunt locuri la categoria 1 (MUTARE)\n");
        break;
      }

      // nu mai sunt pasageri din categoria 2 de mutat

      if (av->cat2_size == 0)
      {
        printf("Nu mai sunt pasageri la categoria 2 (MUTARE)\n");
        break;
      }

      printf("PASAGERI MUTATI %zu\n", pas_moved);

      av->pas_cat1[av->cat2_size] = av->pas_cat2[av->cat2_size];

      av->cat1_size++;
      av->cat2_size--;

      av->pas_cat1[av->cat1_size - 1]->category = 3;

      pas_moved++;
      x--;
    }

    break;
  }

  return pas_moved;
}
