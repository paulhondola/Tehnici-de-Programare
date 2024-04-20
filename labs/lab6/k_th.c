// Implementati un algoritm care primeste ca parametru un numar k si returneaza
// al k-lea termen al sirului 1 1 2 1 2 3 1 2 3 4 1 2 3 4 5 ... (solutie in timp
// constant)

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

unsigned long long find_group(unsigned long long k)
{
  unsigned long long group = 1;

  float delta = 1 + 8 * k;

  float aprox_group = (sqrt(delta) - 1) / 2;

  group = ceil(aprox_group);

  return group;
}

unsigned long long find_k(unsigned long long k)
{

  unsigned long long group = find_group(k);

  unsigned long long group_leader = group * (group + 1) / 2;

  unsigned long long k_in_group = k + group - group_leader;

  return k_in_group;
}

int main(int argc, char const *argv[])
{
  unsigned long long k = 0;

  if (argc != 2)
  {
    perror("Invalid args");
    return -1;
  }

  k = atoi(argv[1]);

  printf("Group: %llu\n", find_group(k));

  printf("Element at position %llu: %llu\n", k, find_k(k));

  return 0;
}
