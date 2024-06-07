#include "lib.h"

// DEPENDENCIES ///////////////////////////
#include <stdio.h>
#include <string.h>
///////////////////////////////////////////

// CONSTANTS //////////////////////////////
#define MAX_MOVIE_NAME_LENGTH 40
#define MAX_GENRE_NAME_LENGTH 10
#define MAX_GENRE_COUNT 10
///////////////////////////////////////////

// STRUCTURES /////////////////////////////
typedef struct MOVIE *movie_t;

struct MOVIE {
  char name[MAX_MOVIE_NAME_LENGTH];
  char genre[MAX_GENRE_NAME_LENGTH];
  int run_length;
  int production_cost;
};

struct SITE {
  movie_t *data;
  int size;
  int capacity;
};

typedef struct MOVIE_LOG {
  int genres_logged;
  char genre_array[MAX_GENRE_COUNT][MAX_GENRE_NAME_LENGTH];
  int max_run_length[MAX_GENRE_COUNT];
} movie_logs_t;

movie_logs_t logs;

///////////////////////////////////////////

// FUNCTIONS //////////////////////////////

// INIT ///////////////////////////////////

site_t init_site(size_t capacity) {
  site_t site = malloc(sizeof(struct SITE));

  if (site == NULL)
    return NULL;

  site->data = malloc(capacity * sizeof(movie_t));

  if (site->data == NULL)
    return NULL;

  site->size = 0;
  site->capacity = capacity;

  return site;
}

movie_t create_movie(char *name, char *genre, int run_length,
                     int production_cost) {
  movie_t movie = malloc(sizeof(struct MOVIE));

  if (movie == NULL)
    return NULL;

  strncpy(movie->name, name, MAX_MOVIE_NAME_LENGTH - 1);
  strncpy(movie->genre, genre, MAX_GENRE_NAME_LENGTH - 1);
  movie->run_length = run_length;
  movie->production_cost = production_cost;

  return movie;
}

site_t add_movie(site_t site, char *name, char *genre, int run_length,
                 int production_cost) {

  if (site == NULL)
    return NULL;

  if (site->size == site->capacity)
    return site;

  movie_t movie = create_movie(name, genre, run_length, production_cost);

  if (movie == NULL)
    return site;

  site->data[site->size++] = movie;

  return site;
}

///////////////////////////////////////////

// OUTPUT /////////////////////////////////

void print_movie_data(movie_t movie) {

  if (movie == NULL)
    return;

  printf("NAME: %s | GENRE: %s | LENGTH: %d | COST: %d\n", movie->name,
         movie->genre, movie->run_length, movie->production_cost);
}

void show_movies(site_t site) {

  if (site == NULL)
    return;

  for (int i = 0; i < site->size; i++) {
    print_movie_data(site->data[i]);
  }
}

///////////////////////////////////////////
