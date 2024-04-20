#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 4000
#define MAX_SONG_NAME 50
#define MAX_ARTIST_NAME 100
#define MAX_LINE 1000

typedef enum
{
  ASCENDING,
  DESCENDING
} order_key;
typedef enum
{
  SONG,
  ARTIST,
  YEAR
} sort_key;

typedef struct
{
  char song_name[MAX_SONG_NAME];
  char artist[MAX_ARTIST_NAME];
  unsigned release_year;
} record;

void storing(FILE *csv_file, record *song_array, int *no_of_songs,
             unsigned selected_year)
{
  char line[1000];
  fgets(line, 1000, csv_file);

  int count = 0;

  while (!feof(csv_file))
  {

    if (fgets(line, MAX_LINE, csv_file) == NULL)
      break;

    char *token = NULL;

    if (line[0] == '"')
    {

      token = strtok(line + 1, "\"");

      strncpy(song_array[count].song_name, token, MAX_SONG_NAME);

      token = strtok(NULL, ",");

      strncpy(song_array[count].artist, token, MAX_ARTIST_NAME);

      token = strtok(NULL, ",");

      if (strchr("0123456789", token[0]))
        song_array[count].release_year = 0;

      song_array[count].release_year = atoi(token);
    }

    else
    {

      token = strtok(line, ",");

      strncpy(song_array[count].song_name, token, MAX_SONG_NAME);

      token = strtok(NULL, ",");

      strncpy(song_array[count].artist, token, MAX_ARTIST_NAME);

      token = strtok(NULL, ",");

      if (strchr("0123456789", token[0]))
        song_array[count].release_year = 0;

      song_array[count].release_year = atoi(token);
    }

    if (song_array[count].release_year == selected_year)
      count++;
  }

  *no_of_songs = count;
}

void printing(record array_songs[], int no_of_songs)
{
  for (int i = 0; i < no_of_songs; i++)
  {
    printf("%s - %s - %u\n", array_songs[i].song_name, array_songs[i].artist,
           array_songs[i].release_year);
  }
}

int year_compare_asc(const void *p, const void *q)
{
  int p_year = ((record *)p)->release_year;
  int q_year = ((record *)q)->release_year;
  return p_year - q_year;
}

int year_compare_desc(const void *p, const void *q)
{
  int p_year = ((record *)p)->release_year;
  int q_year = ((record *)q)->release_year;
  return -(p_year - q_year);
}

int song_name_compare_asc(const void *p, const void *q)
{
  return strcmp(((record *)p)->song_name, ((record *)q)->song_name);
}

int song_name_compare_desc(const void *p, const void *q)
{
  return -strcmp(((record *)p)->song_name, ((record *)q)->song_name);
}

int artist_name_compare_asc(const void *p, const void *q)
{
  return strcmp(((record *)p)->artist, ((record *)q)->artist);
}

int artist_compare_desc(const void *p, const void *q)
{
  return -strcmp(((record *)p)->artist, ((record *)q)->artist);
}

void sort_records(record *array, int no_of_songs, sort_key s, order_key o)
{

  // ARTIST
  if (s == ARTIST && o == ASCENDING)
  {
    qsort(array, no_of_songs, sizeof(record), artist_name_compare_asc);
  }

  if (s == ARTIST && o == DESCENDING)
  {
    qsort(array, no_of_songs, sizeof(record), artist_compare_desc);
  }

  // SONG
  if (s == SONG && o == ASCENDING)
  {
    qsort(array, no_of_songs, sizeof(record), song_name_compare_asc);
  }

  if (s == SONG && o == DESCENDING)
  {
    qsort(array, no_of_songs, sizeof(record), song_name_compare_desc);
  }

  // YEAR
  if (s == YEAR && o == ASCENDING)
  {
    qsort(array, no_of_songs, sizeof(record), year_compare_asc);
  }

  if (s == YEAR && o == DESCENDING)
  {
    qsort(array, no_of_songs, sizeof(record), year_compare_desc);
  }
}

int main(int argc, char *argv[])
{

  if (argc != 3)
  {
    perror("Not enough arguments!\n");
    return -1;
  }

  FILE *csv_file;
  csv_file = fopen(argv[1], "r");

  if (csv_file == NULL)
  {
    perror("File problem\n");
    exit(EXIT_FAILURE);
  }

  unsigned selected_year = atoi(argv[2]); // strtol(argv[2], NULL, 10)

  record song_name[MAX_RECORDS];
  int no_of_songs;

  storing(csv_file, song_name, &no_of_songs, selected_year);

  sort_records(song_name, no_of_songs, ARTIST, ASCENDING);

  printing(song_name, no_of_songs);

  printf("%d\n", no_of_songs);

  return 0;
}
