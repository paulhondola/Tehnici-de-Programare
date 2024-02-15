#include "lists.h"
#include "files.h"

node *create_list(FILE *file)
{
    node *head = NULL;
    int number;

    while (fscanf(file, "%d", &number) != EOF)
    {
        head = add_to_back(head, number);
    }

    return head;
}


node *create_odd_list(node *head)
{
    node *odd_number_list = NULL;

    while (head != NULL)
    {
        if (head->data % 2 != 0)
        {
            odd_number_list = add_to_back(odd_number_list, head->data);
        }

        head = head->next;
    }

    return odd_number_list;
}


node *create_even_list(node *head)
{
    node *even_number_list = NULL;

    while (head != NULL)
    {
        if (head->data % 2 == 0)
        {
            even_number_list = add_to_back(even_number_list, head->data);
        }

        head = head->next;
    }

    return even_number_list;
}





int main(void)
{
    FILE *file = open_file("date.txt", "r");

    node *number_list = create_list(file);

    node *odd_number_list = create_odd_list(number_list);

    node *even_number_list = create_even_list(number_list);

    number_list = remove_element_x(number_list, 1);

    print_list(number_list);

    print_list(odd_number_list);

    print_list(even_number_list);

    if(number_list != NULL)
        free_list(number_list);
    
    if(odd_number_list != NULL)
        free_list(odd_number_list);
        
    if(even_number_list != NULL)
        free_list(even_number_list);

    close_file(file);

    return 0;
}
