#include "lists.h"


List *init_list(void)
{
    List *list = (List *)malloc(sizeof(List));
    list->front = NULL;
    list->back = NULL;

    return list;
}


List *add_front_node(List *list, int data) 
{
    if(list->front == NULL && list->back == NULL) 
    {
        list->front = (Node *)malloc(sizeof(Node));
        list->front->data = data;
        list->front->next = NULL;

        list->back = list->front;

        return list;
    }

    Node *new = (Node *)malloc(sizeof(Node));

    new->data = data;

    new->next = list->front;

    list->front = new;
    
    return list;
}


List *add_back_node(List *list, int data) 
{
    if(list->front == NULL && list->back == NULL) 
    {
        list->front = (Node *)malloc(sizeof(Node));
        list->front->data = data;
        list->front->next = NULL;

        list->back = list->front;
        return list;
    }

    Node *new = (Node *)malloc(sizeof(Node));

    new->data = data;

    list->back->next = new;

    list->back = new;

    list->back->next = NULL;

    return list;
}


void print_list(List *list)
{
    Node *iterator = list->front;

    while(iterator != NULL) 
    {
        printf("%d -> ", iterator->data);
        iterator = iterator->next;
    }

    printf("NULL\n");
}


void free_list(List *list)
{
    Node *temp = NULL;
    Node *iterator = list->front;
    
    while(iterator != NULL) 
    {
        temp = iterator;
        iterator = iterator->next;
        free(temp);
    }

    free(list);
}
