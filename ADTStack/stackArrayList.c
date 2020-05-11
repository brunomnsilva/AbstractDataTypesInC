/**
 * @file stackArrayList.c
 * 
 * @brief Provides an implementation of the ADT Stack with an array list
 * as the underlying data structure.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#include "stack.h" 
#include <stdio.h>
#include <stdlib.h>

/* 'struct stackImpl' forward declared in stack.h */
typedef struct stackImpl { 
    StackElem *elements;    /* unalocated array of elements */
    int capacity;           /* length of allocated array */
    int size;               /* current number of elements */
} StackImpl;

static bool ensureCapacity(PtStack stack) {
    if (stack->size == stack->capacity) {
        int newCapacity = stack->capacity * 2;
        StackElem* newArray = (StackElem*) realloc( stack->elements, 
                                newCapacity * sizeof(StackElem) );
        
        if(newArray == NULL) return false; 

        stack->elements = newArray;
        stack->capacity = newCapacity;
    }
    
    return true;
}

PtStack stackCreate(unsigned int initialCapacity) {
    PtStack stack = (PtStack)malloc(sizeof(StackImpl));
    if (stack == NULL) return NULL;

    stack->elements = (StackElem*)calloc(initialCapacity,
                        sizeof(StackElem));

    if (stack->elements == NULL) {
        free(stack);
        return NULL;	
    }

    stack->size = 0;
    stack->capacity = initialCapacity;

    return stack;
}

int stackDestroy(PtStack *ptStack) {
    PtStack stack = (*ptStack);
    if (stack == NULL) return STACK_NULL;

    free(stack->elements);
    free(stack);

    *ptStack = NULL;

    return STACK_OK;
}

int stackPush(PtStack stack, StackElem elem) {
    if (stack == NULL) return STACK_NULL;
    
    if(!ensureCapacity(stack)) return STACK_FULL;

    stack->elements[stack->size] = elem;
    stack->size++;

    return STACK_OK;
}

int stackPop(PtStack stack, StackElem *ptElem) {
    if (stack == NULL) return STACK_NULL;

    if (stack->size == 0) return STACK_EMPTY;

    *ptElem = stack->elements[stack->size - 1];
    stack->size--;

    return STACK_OK;
}

int stackPeek(PtStack stack, StackElem *ptElem) {
    if (stack == NULL) return STACK_NULL;

    if (stack->size == 0) return STACK_EMPTY;

    *ptElem = stack->elements[stack->size - 1];

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

    stack->size = 0;

    return STACK_OK;
}

void stackPrint(PtStack stack) {
    if (stack == NULL) {
        printf("(Stack NULL)\n");
    }
    else if (stackIsEmpty(stack)) {
        printf("(Stack Empty)\n");
    }
    else {
        /* print elements from top to bottom */
        printf("Stack contents (top to bottom): \n");
    
        for (int i = stack->size - 1; i >= 0; i--) {
            stackElemPrint(stack->elements[i]);
        }
        
        printf("--- bottom --- \n");
    }
    printf("\n");
}

