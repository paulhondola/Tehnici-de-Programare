Recursivitate 2023
Recursivitatea este o tehnică de programare prin care o funcție se apelează pe sine pentru a rezolva o problemă mai mare. În mod general, aceasta presupune definirea unei funcții care se va apela repetat (pe sine insusi), până când se va ajunge la o soluție finală. Această soluție finală este de obicei rezultatul unei serii de operații efectuate de funcția recursivă.

Spre exemplu, să presupunem că vrem să calculăm factorialul unui număr n. Definim funcția factorial(n) astfel:

```c
function factorial(n) {
  if (n == 1) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}
```

În acest caz, funcția factorial se apelează pe sine până când se ajunge la valoarea 1, caz în care se întoarce rezultatul 1. În caz contrar, se calculează produsul dintre n și factorialul pentru n-1. Astfel, dacă vrem să calculăm factorialul lui 5, apelăm funcția astfel:

factorial(5);
Aceasta va apela funcția pentru valorile 4, 3, 2 și 1, iar rezultatul final va fi 120 (5 x 4 x 3 x 2 x 1).

Recursivitatea poate fi foarte utilă pentru rezolvarea problemelor care implică procesarea recursivă a datelor sau a structurilor de date, precum arbori sau liste. Cu toate acestea, trebuie utilizată cu grijă, deoarece poate duce la probleme de depășire a stivei (stack overflow) dacă nu este implementată corect.

Expresie prefix
O expresie aritmetică în notația prefix (sau notația poloneză prefixă) este o modalitate de a reprezenta o expresie matematică în care operatorii precedă operanzii. În notația prefix, operatorii apar înaintea operanzilor și nu este nevoie de paranteze pentru a specifica ordinea de evaluare a expresiilor.

Spre exemplu, în notația prefix, expresia aritmetică 3 + 4 _ 5 este reprezentată astfel: + 3 _ 4 5. În această notație, operatorul de adunare (+) apare înaintea operanzilor 3 și _ 4 5, unde operatorul de înmulțire (_) apare înaintea operanzilor 4 și 5.

Pentru a evalua o expresie aritmetică în notația prefix, se parcurge expresia de la stânga la dreapta, se identifică operatorii și se aplică operația corespunzătoare asupra operanzilor.

Implementarea s-a facut la curs!

Expresie infix
Pentru a implementa un program C care evaluează o expresie aritmetică în notația infix, putem folosi o stivă pentru a păstra operatorii și operanzii în ordinea corectă de evaluare. Iată un exemplu de implementare (!!! este generat algoritmic: este necesar sa il analizati si validati):

```c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 100
/_ Definim structura pentru stiva _/
struct Stack {
int top;
int data[MAX_SIZE];
};
/_ Functie de verificare a stivei goale _/
int isEmpty(struct Stack _stack) {
return (stack->top == -1);
}
/_ Functie de verificare a stivei pline */
int isFull(struct Stack *stack) {
return (stack->top == MAX_SIZE - 1);
}
/_ Functie de adaugare a unui element in stiva _/
void push(struct Stack _stack, int value) {
if (isFull(stack)) {
printf("Stiva este plina!\n");
exit(EXIT_FAILURE);
}
stack->data[++stack->top] = value;
}
/_ Functie de extragere a unui element din stiva */
int pop(struct Stack *stack) {
if (isEmpty(stack)) {
printf("Stiva este goala!\n");
exit(EXIT_FAILURE);
}
return stack->data[stack->top--];
}
/_ Functie de citire a unei expresii aritmetice de la tastatura _/
void readExpression(char _expression) {
printf("Introduceti o expresie aritmetica: ");
fgets(expression, MAX_SIZE, stdin);
}
/_ Functie de evaluare a expresiei aritmetice */
int evaluate(char *expression) {
struct Stack _stack = malloc(sizeof(struct Stack));
stack->top = -1;
int i, len, num = 0, operand1, operand2, result;
char ch, operator;
len = strlen(expression);
for (i = len - 1; i >= 0; i--) {
ch = expression[i];
/_ Daca este operand, il adaugam in stiva _/
if (isdigit(ch)) {
num = (num _ 10) + (int)(ch - '0');
} else if (ch == ' ') {
if (num != 0) {
push(stack, num);
num = 0;
}
} else {
/_ Daca este operator, extragem operandele si aplicam operatia _/
operand1 = pop(stack);
operand2 = pop(stack);
operator = ch;
switch (operator) {
case '+':
result = operand1 + operand2;
break;
case '-':
result = operand1 - operand2;
break;
case '_':
result = operand1 _ operand2;
break;
case '/':
result = operand1 / operand2;
break;
default:
printf("Operator nevalid: %c\n", operator);
exit(EXIT_FAILURE);
}
/_ Adaugam rezultatul in stiva _/
push(stack, result);
}
}
/_ Returnam rezultatul final _/
return pop(stack);
}
/_ Functia main _/
int main() {
char expression[MAX_SIZE];
readExpression(expression);
int result = evaluate(expression);
printf("Rezultatul expresiei este: %d\n", result);
return 0;
}
```

Bibliografie
https://staff.cs.upt.ro/~marius/curs/pc/old/notes2.pdf

Aplicatii propuse

1. https://staff.cs.upt.ro/~marius/curs/lp/tema2.html : exercitiile 1,2 si 3

2. https://staff.cs.upt.ro/~marius/curs/lp/tema3.html : Exercitiul 2
