#include <stdio.h>
#include "stack.h"

int main(){
	
	Stack_t st=initStack();
	st=push(st, 10);
	st=push(st, 20);
	st=push(st, 30);
	st=push(st, 40);
	Element_t el=peek(st);
	printf("Elementul din varf este %u\n", el);
	el=peek(st);
	printf("Elementul din varf este %u\n", el);
	pop(st);
	
	printf("Elementul din varf este %u\n", peek(st));
	
	return 0;
}
