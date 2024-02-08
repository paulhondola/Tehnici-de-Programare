#include <stdio.h>
#include <stdlib.h>

typedef int stack_item;

typedef struct stack {
    stack_item *contents;
    int top;
    int size;
} stack;


stack init_stack(int size)
{
    stack s;
    s.contents = malloc((unsigned long)size * sizeof(stack_item));
    s.top = 0;
    s.size = size;
    return s;
}

void push(stack *s, stack_item i)
{
    if (s->top < s->size) 
    {
        s->contents[s->top++] = i;
    }
}


void pop(stack *s)
{
    if (s->top > 0)
    {
        s->top--;
    }
    else
    {
        printf("Stack is empty\n");
    }
}

stack_item peek(stack *s)
{
    if (s->top > 0)
    {
        return s->contents[s->top - 1];
    }
    return 0;
}


int main(void)
{
    stack my_stack = init_stack(10);

    stack_item el = peek(&my_stack);

    if(el == 0)
    {
        printf("Stack is empty\n");
    }

    for(int i = 0; i < 10; i++)
    {
        push(&my_stack, i);
        el = peek(&my_stack);

        printf("Element at the top of the stack: %d\n", el);
    }

    pop(&my_stack);

    el = peek(&my_stack);

    printf("Element at the top of the stack: %d\n", el);

    
    free(my_stack.contents);

    return 0;
}
