#include "lists.h"

#define SIZE 10

int main(void)
{
    //int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    List *list = init_list();

    list = add_front_node(list, 1);

    list = remove_front_node(list);

    list = add_back_node(list, 2);

    list = remove_front_node(list);

    print_list(list);
    
    if(list->front != NULL && list->back != NULL)
    {
        free_list(list);
    }

    free(list);

    return 0;
}
