#ifndef __LIB_H
#define __LIB_H
#include <stdlib.h>

// TYPES ///////////////////////////////////////////
typedef struct SITE *site_t;
///////////////////////////////////////////

// FUNCTIONS //////////////////////////////
site_t init_site(size_t capacity);
site_t add_movie(site_t site, char *name, char *genre, int run_length,
                 int production_cost);
void show_movies(site_t site);
void show_max_run_length(site_t site);
///////////////////////////////////////////

#endif
