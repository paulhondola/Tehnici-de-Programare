#include "lists.h"

int main(void)
{
    node *head = NULL;

    head = add_to_back(head, 1);

    head = add_to_back(head, 2);

    head = add_to_back(head, 3);

    print_list(head);

    head = insert_at(head, 4, 2);

    print_list(head);

    free_list(head);

    return 0;
}
