#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 100

/* Definim structura pentru stiva */
struct Stack 
{
    int top;
    int data[MAX_SIZE];
};

/* Functie de verificare a stivei goale */
int isEmpty(struct Stack *stack) 
{
    return (stack->top == -1);
}

/* Functie de verificare a stivei pline */
int isFull(struct Stack *stack) 
{
    return (stack->top == MAX_SIZE - 1);
}

/* Functie de adaugare a unui element in stiva */
void push(struct Stack *stack, int value) 
{
    if (isFull(stack)) 
    {
        printf("Stiva este plina!\n");
        exit(EXIT_FAILURE);
    }
    stack->data[++stack->top] = value;
}

/* Functie de extragere a unui element din stiva */
int pop(struct Stack *stack) 
{
    if (isEmpty(stack)) 
    {
        printf("Stiva este goala!\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--];
}

/* Functie de citire a unei expresii aritmetice de la tastatura */
void readExpression(char *expression) 
{
    printf("Introduceti o expresie aritmetica: ");
    fgets(expression, MAX_SIZE, stdin);
}

/* Functie de evaluare a expresiei aritmetice */
int evaluate(char *expression) 
{
    struct Stack *stack = malloc(sizeof(struct Stack));
    stack->top = -1;
    int i, len, num = 0, operand1, operand2, result;
    char ch, operator;
    len = strlen(expression);
    for (i = len - 1; i >= 0; i--) 
    {
        ch = expression[i];
        /* Daca este operand, il adaugam in stiva */
        if (isdigit(ch)) 
        {
            num = (num * 10) + (int)(ch - '0');
        } 
        else if (ch == ' ') 
        {
            if (num != 0) 
            {
                push(stack, num);
                num = 0;
            }
        } 
        else 
        {
            /* Daca este operator, extragem operandele si aplicam operatia */
            operand1 = pop(stack);
            operand2 = pop(stack);
            operator = ch;
            switch (operator) 
            {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Operator nevalid: %c\n", operator);
                    exit(EXIT_FAILURE);
            }
            /* Adaugam rezultatul in stiva */
            push(stack, result);
        }
    }
    /* Returnam rezultatul final */
    int final_result = pop(stack);
    free(stack);
    return final_result;
}

/* Functia main */
int main() 
{
    char expression[MAX_SIZE];
    readExpression(expression);
    int result = evaluate(expression);
    printf("Rezultatul expresiei este: %d\n", result);
    return 0;
}