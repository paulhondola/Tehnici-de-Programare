#ifndef __LIB_H
#define __LIB_H
#include <stdlib.h>

// TYPES ///////////////////////////////////////////
typedef struct SITE *site_t;
///////////////////////////////////////////

// FUNCTIONS //////////////////////////////
site_t init_site(size_t size);
site_t *add_movie(site_t *, char *, char *, int, int);
void show_movies(site_t *);
void show_max_run_length(site_t *);
///////////////////////////////////////////

#endif
