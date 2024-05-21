/*
2. Se dă o mulțime cu n elemente, numere naturale. Afișați în ordine
lexicografică toate permutările mulțimii date în care elementele prime sunt
puncte fixe (nu își schimbă poziția).
*/

// cele prime isi pastreaza pozitia -> celelalte fac permutari
// n total -> k prime -> n-k neprime -> n! permutari
//
#include <stdio.h>
#define MAX_STACK_SIZE 100

int is_prime(int n) {
  if (n < 2)
    return 0;

  for (int d = 2; d * d <= n; ++d)
    if (n % d == 0)
      return 0;

  return 1;
}

int count_primes(int n, int v[], int prime_array[]) {
  int count = 0;
  for (int i = 0; i < n; i++)
    if (is_prime(v[i])) {
      prime_array[i] = 1;
      count++;
    } else
      prime_array[i] = 0;

  return count;
}

int successor(int stack[], int level, int n) {

  if (stack[level] < n) {
    stack[level]++;
    return 1;
  }

  return 0;
}

int valid(int stack[], int level) {

  for (int i = 1; i < level; i++)
    if (stack[i] == stack[level])
      return 0;

  return 1;
}

int solution(int level, int count) { return level == count; }

void print(int stack[], int count) {

  for (int i = 1; i <= count; i++)
    printf("%d ", stack[i]);

  printf("\n");
}
// 0 1 1 0 1 0 1
// 1 2 3 4 5 6 7
// 1 2 3 6 5 4 7
// 1 2 3 -> 1 4 6
// 3 2 1 -> 6 4 1
//
void get_index(int stack[], int stack_count, int prime_array[],
               int indexed_stack[], int array[], int element_count) {

  int index = 1;
  for (int i = 0; i < element_count; i++)
    if (!prime_array[i])
      indexed_stack[stack[index++]] = array[i];
}

void print_prime(int array[], int element_count, int stack[], int stack_count,
                 int prime_array[]) {

  for (int i = 0, j = 1; i < element_count; i++)
    if (prime_array[i]) {
      printf("%2d  ", array[i]);
    } else {
      // array[0] = 1 -> stack[1] = 1
      // array[3] = 4 -> stack[2] = 2
      // array[6] = 7 -> stack[3] = 3
      printf("%2d  ", stack[j++]);
    }

  printf("\n");
}

int back(int array[], int element_count, int prime_array[], int prime_count) {

  int stack[MAX_STACK_SIZE] = {0, 0};
  int indexed_stack[MAX_STACK_SIZE] = {0, 0};
  int level = 1;

  int stack_max_size = element_count - prime_count;

  while (level > 0) {
    if (successor(stack, level, stack_max_size)) {
      if (valid(stack, level)) {
        if (solution(level, stack_max_size)) {
          // print(stack, stack_max_size);
          get_index(stack, stack_max_size, prime_array, indexed_stack, array,
                    element_count);
          print_prime(array, element_count, indexed_stack, level, prime_array);
        } else {
          level++;
          stack[level] = 0;
        }
      } else {
        ;
      }
    } else {
      level--;
    }
  }

  return 0;
}
int main(void) {

  int n = 0;
  int v[MAX_STACK_SIZE];
  while (1) {
    int x;
    if (scanf("%d", &x) != 1)
      break;
    v[n++] = x;
  }

  int prime_array[n];
  int prime_count = count_primes(n, v, prime_array);

  back(v, n, prime_array, prime_count);

  return 0;
}
