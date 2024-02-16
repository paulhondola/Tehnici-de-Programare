#include "lists.h"

#define SIZE 10

int main(void)
{
    //int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    List *list = (List *)malloc(sizeof(List));

    list = add_front_node(list, 1);

    list = add_front_node(list, 2);

    list = add_front_node(list, 3);

    list = add_back_node(list, 4);

    print_list(list);

    free_list(list);

    return 0;
}
