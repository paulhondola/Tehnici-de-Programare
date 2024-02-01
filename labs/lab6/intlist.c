#include <stdlib.h>
#include "intlist.h"

struct ilst {
  intlist_t nxt;
  int el;
};

int isempty(intlist_t lst)
{
  return lst == NULL;
}

intlist_t empty(void)
{
  return NULL;
}

int head(intlist_t lst)
{
  return lst->el;
}

intlist_t tail(intlist_t lst)
{
  return lst->nxt;
}

intlist_t cons(int el, intlist_t tl)
{
  intlist_t p = malloc(sizeof(struct ilst));
  if (!p) return NULL;
  p->el = el;
  p->nxt = tl;
  return p;
}

// returns tail, assignes *elp with head
intlist_t decons(intlist_t lst, int *elp)
{
  if (elp) *elp = lst->el;
  intlist_t tl = lst->nxt;
  free(lst);
  return tl;
}