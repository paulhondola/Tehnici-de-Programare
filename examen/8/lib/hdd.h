#ifndef __HDD_H
#define __HDD_H

// DEPENDENCIES
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// DATA TYPES
typedef struct MEMORY *mem_t;
typedef struct HDD *hdd_t;

// CONSTANTS
#define MAX_INFO_LEN 40

// FUNCTIONS
hdd_t init_hdd(size_t capacity_protected, size_t capacity_open);
hdd_t add_mem(hdd_t, char *info, size_t address, bool is_protected);
void show_hdd_data(hdd_t);

void mem_destructor(mem_t);
void hdd_destructor(hdd_t);

#endif
