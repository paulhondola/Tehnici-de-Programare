#ifndef __RAND_ARRAY_H
#define __RAND_ARRAY_H

#include <stdlib.h>
#include <time.h>

unsigned *make_rand_array(unsigned element_count);

unsigned *make_rand_limit_array(unsigned element_count, unsigned a, unsigned b);

int get_new_element_asc(int *array, unsigned element_count, unsigned steps);

int get_new_element_desc(int *array, unsigned element_count, unsigned steps);

int *make_rand_flexi_array(unsigned element_count,
                           int (*getNewElement)(int *array,
                                                unsigned element_count,
                                                unsigned steps),
                           unsigned steps);
#endif
