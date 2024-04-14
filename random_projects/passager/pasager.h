#ifndef __PASAGER_H
#define __PASAGER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PASAGER_T *pasager_t;
typedef struct AVION_T *avion_t;

avion_t init_avion(size_t, size_t);

avion_t add_pasager(avion_t, char *, int, int);

void afisare_pasageri(avion_t, int);

int move_pasageri(avion_t, size_t, int);

#endif
