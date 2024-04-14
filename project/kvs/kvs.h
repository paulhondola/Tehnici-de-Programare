#ifndef __KVS_H
#define __KVS_H

#include <stdio.h>
#include <stdlib.h>

struct kv_pair {
  unsigned key;
  float value;
};

typedef struct kv_pair EL_t;

typedef struct kv_store *KVS_t;

KVS_t init_kvs(size_t);

KVS_t add_element(KVS_t, EL_t);

void print_kvs(KVS_t);

int search_key(KVS_t, unsigned);

void free_kvs(KVS_t);

#endif
