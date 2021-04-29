/**
 * @file stackLinkedList.c
 * 
 * @brief Provides an implementation of the ADT Stack with a 
 * doubly-linked list with sentinels as the underlying 
 * data structure.
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
    StackElem element; 	/* element to store at node */
    PtNode next;		/* pointer to next node */
    PtNode prev;		/* pointer to previous node */
} Node;

typedef struct stackImpl { 
    PtNode header;
    PtNode trailer;
    int size;
} StackImpl;

PtStack stackCreate() {
    PtStack stack = (PtStack)malloc(sizeof(StackImpl));
    if (stack == NULL) return NULL;
    
    stack->header = (PtNode)malloc(sizeof(Node));
    if (stack->header == NULL) {
        free(stack);
        return NULL;
    }
    stack->trailer = (PtNode)malloc(sizeof(Node));
    if (stack->trailer == NULL) {
        free(stack->header);
        free(stack);
        return NULL;
    }

    stack->header->prev = NULL;
    stack->header->next = stack->trailer;

    stack->trailer->next = NULL;
    stack->trailer->prev = stack->header;

    stack->size = 0;

    return stack;
}

int stackDestroy(PtStack *ptStack) {
    PtStack stack = (*ptStack);

    if (stack == NULL) return STACK_NULL;

    PtNode current = stack->header->next;
    while(current != stack->trailer) {
        current = current->next;
        free(current->prev);
    }

    free(stack->header);
    free(stack->trailer);
    free(stack);

    *ptStack = NULL;

    return STACK_OK;
}

int stackPush(PtStack stack, StackElem elem) {
    if (stack == NULL) return STACK_NULL;
    
    PtNode newTop = (PtNode)malloc(sizeof(Node));
    if(newTop == NULL) return STACK_NO_MEMORY;

    PtNode curTop = stack->header->next;

    newTop->element = elem;
    newTop->prev = stack->header;
    newTop->next = curTop;

    stack->header->next = newTop;
    curTop->prev = newTop;

    stack->size++;

    return STACK_OK;
}

int stackPop(PtStack stack, StackElem *ptElem) {
    if (stack == NULL) return STACK_NULL;

    if (stack->size == 0) return STACK_EMPTY;

    PtNode curTop = stack->header->next;
    PtNode newTop = stack->header->next->next;

    *ptElem =  curTop->element;

    stack->header->next = newTop;
    newTop->prev = stack->header;

    free(curTop);

    stack->size--;

    return STACK_OK;
}

int stackPeek(PtStack stack, StackElem *ptElem) {
    if (stack == NULL) return STACK_NULL;

    if (stack->size == 0) return STACK_EMPTY;

    PtNode curTop = stack->header->next;
    *ptElem = curTop->element;

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

    PtNode current = stack->header->next;
    while(current != stack->trailer) {
        current = current->next;
        free(current->prev);
    }

    stack->header->next = stack->trailer;
    stack->trailer->prev = stack->header;

    stack->size = 0;

    return STACK_OK;
}

void stackPrint(PtStack stack) {
    if (stack == NULL) {
        printf("(Stack NULL)");
    }
    else if (stack->size == 0) {
        printf("(Stack Empty)");
    }
    else {
        printf("Stack contents (top to bottom): \n");
        /* Print elements from top to bottom */
        PtNode current = stack->header->next;
        while (current != stack->trailer) {
            stackElemPrint(current->element);
            printf("\n");
            
            current = current->next;
        }
        printf("--- bottom --- \n");
    }
    printf("\n");
}

