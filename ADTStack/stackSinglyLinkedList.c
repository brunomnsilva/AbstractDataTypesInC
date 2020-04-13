/**
 * @file stackSinglyLinkedList.c
 * 
 * @brief Provides an implementation of a stack with a singly-linked
 * list as the underlying data structure.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#include "stack.h" 
#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node* PtNode;

typedef struct node {
    StackElem element;
    PtNode next;
} Node;

typedef struct stackImpl { 
	PtNode top;
	int size;
} StackImpl;

PtStack stackCreate(unsigned int initialCapacity) {
	PtStack newStack = (PtStack)malloc(sizeof(StackImpl));
	if (newStack == NULL) return NULL;
	
	newStack->top = NULL;
	newStack->size = 0;

	return newStack;
}

int stackDestroy(PtStack *ptStack) {

	PtStack stack = (*ptStack);

	if (stack == NULL) return STACK_NULL;

	PtNode current = stack->top;
	PtNode previous = NULL;
    while(current != NULL) {
		previous = current;
        current = current->next;
        free(previous);
    }

	free(stack);

	*ptStack = NULL;

	return STACK_OK;
}

int stackPush(PtStack stack, StackElem elem) {
	if (stack == NULL) return STACK_NULL;
	
	PtNode newTop = (PtNode)malloc(sizeof(Node));
	if(newTop == NULL) return STACK_FULL;

	PtNode curTop = stack->top;

	newTop->element = elem;
	newTop->next = curTop;

	stack->top = newTop;
	
	stack->size++;

	return STACK_OK;
}

int stackPop(PtStack stack, StackElem *ptElem) {
	if (stack == NULL) return STACK_NULL;

	if (stack->size == 0) return STACK_EMPTY;

    PtNode curTop = stack->top;
	PtNode newTop = stack->top->next;

	*ptElem =  curTop->element;

	stack->top = newTop;

	free(curTop);

	stack->size--;

	return STACK_OK;
}

int stackPeek(PtStack stack, StackElem *ptElem) {
	if (stack == NULL) return STACK_NULL;

	if (stack->size == 0) return STACK_EMPTY;

	*ptElem = stack->top->element;

	return STACK_OK;
}

int stackSize(PtStack stack, int *ptSize) {
	if (stack == NULL) return STACK_NULL;

	*ptSize = stack->size;

	return STACK_OK;
}

bool stackIsEmpty(PtStack stack) {
	if (stack == NULL) return true;

	return (stack->size == 0);
}

int stackClear(PtStack stack) {
	if (stack == NULL) return STACK_NULL;

    PtNode current = stack->top;
	PtNode previous = NULL;
    while(current != NULL) {
		previous = current;
        current = current->next;
        free(previous);
    }

	stack->size = 0;

	return STACK_OK;
}

void stackPrint(PtStack stack) {
	if (stack == NULL) {
		printf("(Stack NULL)\n");
	}
	else if (stack->size == 0) {
		printf("(Stack Empty)\n");
	}
	else {
		printf("Stack contents: \n");
		/* Print from top to base */
		PtNode current = stack->top;
		while (current != NULL) {
			stackElemPrint(current->element);
			current = current->next;
		}
		printf("----------------\n");
	}
}

