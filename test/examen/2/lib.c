#include "lib.h"

// DEPENDENCIES ///////////////////////////
#include <stdio.h>
#include <string.h>
///////////////////////////////////////////

// CONSTANTS //////////////////////////////
#define MAX_MOVIE_NAME_LENGTH 40
#define MAX_GENRE_NAME_LENGTH 10
///////////////////////////////////////////

// STRUCTURES /////////////////////////////
typedef struct MOVIE {
  char name[MAX_MOVIE_NAME_LENGTH];
  char genre[MAX_GENRE_NAME_LENGTH];
  int run_length;
  int production_cost;
} movie_t;

struct SITE {
  struct MOVIE *data;
  int size;
};
///////////////////////////////////////////

// FUNCTIONS //////////////////////////////

// INIT ///////////////////////////////////

movie_t *create_movie(char *name, char *genre, int run_length,
                      int production_cost) {
  movie_t *movie = malloc(sizeof(movie_t));

  if (movie == NULL)
    return NULL;

  strncpy(movie->name, name, MAX_MOVIE_NAME_LENGTH - 1);
  strncpy(movie->genre, genre, MAX_GENRE_NAME_LENGTH - 1);
  movie->run_length = run_length;
  movie->production_cost = production_cost;

  return movie;
}

site_t init_site(size_t size) {
  site_t site = malloc(sizeof(struct SITE));

  if (site == NULL)
    return NULL;

  site->data = malloc(size * sizeof(movie_t));

  if (site->data == NULL)
    return NULL;

  return site;
}

///////////////////////////////////////////

site_t *add_movie(site_t *site, char *name, char *genre, int run_length,
                  int production_cost) {

  return site;
}
///////////////////////////////////////////
