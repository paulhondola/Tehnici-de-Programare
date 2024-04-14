#ifndef __RAND_ARRAY_H
#define __RAND_ARRAY_H

#include <math.h>
#include <stdlib.h>
#include <time.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// P R O I E C T  1 -  R A N D O M  A R R A Y S
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int *make_rand_array(unsigned element_count);

int *make_rand_limit_array(unsigned element_count, unsigned a, unsigned b);

int get_new_element_asc(int *array, unsigned element_count, unsigned steps);

int get_new_element_desc(int *array, unsigned element_count, unsigned steps);

int *make_rand_flexi_array(unsigned element_count,
                           int (*getNewElement)(int *array,
                                                unsigned element_count,
                                                unsigned steps),
                           unsigned steps);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// P R O I E C T  2 -  N O R M A L  D I S T R I B U T I O N
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

double *generate_gauss_distribution(size_t element_count, double mean,
                                    double standard_deviation);

double *generate_poisson_distribution(size_t element_count, double lambda);

#endif
