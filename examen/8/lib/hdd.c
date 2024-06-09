#include "hdd.h"

// DEPENDENCIES
#include <string.h>

// DATA STRUCTURES

struct MEMORY {
  char info[MAX_INFO_LEN];
  size_t address;
  bool protected;
};

struct HDD {
  mem_t *protected_mem;
  mem_t *open_mem;
  size_t protected_mem_size;
  size_t open_mem_size;
  size_t protected_mem_capacity;
  size_t open_mem_capacity;
};

// FUNCTIONS

// INIT

mem_t create_mem_data(char *info, size_t address, bool is_protected) {
  mem_t mem = malloc(sizeof(struct MEMORY));
  if (mem == NULL)
    return NULL;

  strncpy(mem->info, info, MAX_INFO_LEN - 1);
  mem->address = address;
  mem->protected = is_protected;

  return mem;
}

hdd_t init_hdd(size_t capacity_protected, size_t capacity_open) {
  hdd_t hdd = malloc(sizeof(struct HDD));
  if (hdd == NULL)
    return NULL;

  (*hdd) = (struct HDD){NULL, NULL, 0, 0, capacity_protected, capacity_open};

  hdd->protected_mem = malloc(sizeof(mem_t) * capacity_protected);
  if (hdd->protected_mem == NULL) {
    free(hdd);
    return NULL;
  }

  hdd->open_mem = malloc(sizeof(mem_t) * capacity_open);
  if (hdd->open_mem == NULL) {
    free(hdd->protected_mem);
    free(hdd);
    return NULL;
  }

  return hdd;
}

// CHECK SPACE
bool is_full_open_mem(hdd_t hdd) {
  return hdd->open_mem_capacity == hdd->open_mem_size;
}
bool is_full_protected_mem(hdd_t hdd) {
  return hdd->protected_mem_capacity == hdd->protected_mem_size;
}

hdd_t add_mem(hdd_t hdd, char *info, size_t address, bool protected) {

  if (protected) {
    if (is_full_protected_mem(hdd)) {
      printf("Nu mai sunt adrese la categoria de memorie protejata\n");
      return hdd;
    }

    mem_t mem = create_mem_data(info, address, protected);

    hdd->protected_mem[hdd->protected_mem_size++] = mem;

    return hdd;
  }

  if (is_full_open_mem(hdd)) {
    printf("Nu mai sunt adrese la categoria de memorie libera\n");
    return hdd;
  }

  mem_t mem = create_mem_data(info, address, protected);

  hdd->open_mem[hdd->open_mem_size++] = mem;

  return hdd;
}

int move_mem_from_protected_to_open(hdd_t hdd, int count) {
  if (is_full_open_mem(hdd))
    return 0;

  size_t free_mem = hdd->open_mem_capacity - hdd->open_mem_size;

  int i = 0;

  for (i = 0; i < count && free_mem != 0; i++) {
    hdd->open_mem[i + hdd->open_mem_size] =
        hdd->protected_mem[hdd->protected_mem_size - i - 1];
    free_mem--;
  }

  return i + 1;
}

int move_mem_from_open_to_protected(hdd_t hdd, int count) {
  if (is_full_protected_mem(hdd))
    return 0;

  size_t free_mem = hdd->protected_mem_capacity - hdd->protected_mem_size;

  int i = 0;

  for (i = 0; i < count && free_mem != 0; i++) {
    hdd->protected_mem[i + hdd->protected_mem_size] =
        hdd->open_mem[hdd->open_mem_size - i - 1];
    free_mem--;
  }

  return i + 1;
}

int move_mem(hdd_t hdd, int count, bool from_protected) {
  if (from_protected)
    return move_mem_from_protected_to_open(hdd, count);
  else
    return move_mem_from_open_to_protected(hdd, count);
}

void show_memory(mem_t mem) {
  printf("ADDRESS: %zu | PROTECTED: %d | DATA: %s\n", mem->address,
         mem->protected, mem->info);
}

void show_hdd_protected_data(hdd_t hdd) {
  printf("PROTECTED DATA\nUSED: %zu | CAPACITY: %zu\n", hdd->protected_mem_size,
         hdd->protected_mem_capacity);
  for (size_t i = 0; i < hdd->protected_mem_size; i++)
    show_memory(hdd->protected_mem[i]);
}

void show_hdd_open_data(hdd_t hdd) {
  printf("OPEN DATA\nUSED: %zu | CAPACITY: %zu\n", hdd->open_mem_size,
         hdd->open_mem_capacity);
  for (size_t i = 0; i < hdd->open_mem_size; i++)
    show_memory(hdd->open_mem[i]);
}

void show_hdd_data(hdd_t hdd) {
  show_hdd_protected_data(hdd);
  show_hdd_open_data(hdd);
}

// DESTRUCTORS
void mem_destructor(mem_t mem) { free(mem); }

void hdd_free_protected(hdd_t hdd) {
  for (size_t i = 0; i < hdd->protected_mem_size; i++)
    mem_destructor(hdd->protected_mem[i]);
  free(hdd->protected_mem);
}

void hdd_free_open(hdd_t hdd) {
  for (size_t i = 0; i < hdd->open_mem_size; i++)
    mem_destructor(hdd->open_mem[i]);
  free(hdd->open_mem);
}

void hdd_destructor(hdd_t hdd) {
  hdd_free_protected(hdd);
  hdd_free_open(hdd);
  free(hdd);
}
