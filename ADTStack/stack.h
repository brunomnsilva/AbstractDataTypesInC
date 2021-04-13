/**
 * @file stack.h
 * @brief Definition of the ADT Stack in C.
 * 
 * Defines the type PtStack and associated operations.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#pragma once

#define STACK_OK            0
#define STACK_NULL          1
#define STACK_NO_MEMORY     2
#define STACK_EMPTY         3
#define STACK_FULL          4

#include <stdbool.h>
#include "stackElem.h"

/** Forward declaration of the data structure. */
struct stackImpl;

/** Definition of pointer to the  data stucture. */
typedef struct stackImpl *PtStack;

/**
 * @brief Creates a new empty stack.
 * 
 * @return PtStack pointer to allocated data structure, or
 * @return NULL if unsufficient memory for allocation
 */
PtStack stackCreate();

/**
 * @brief Free all resources of a stack.
 * 
 * @param ptStack [in] ADDRESS OF pointer to the stack
 * 
 * @return STACK_OK if success and *ptStack modified to NULL, or
 * @return STACK_NULL if '*ptStack' is NULL 
 */
int stackDestroy(PtStack *ptStack);

/**
 * @brief Push an element onto a stack.
 * 
 * @param stack [in] pointer to the stack
 * @param elem  [in] element to push
 * 
 * @return STACK_OK if successful, or
 * @return STACK_FULL if no capacity available, or
 * @return STACK_NO_MEMORY if unsufficient memory for allocation, or
 * @return STACK_NULL if 'stack' is NULL 
 */
int stackPush(PtStack stack, StackElem elem);

/**
 * @brief Pop the top element of a stack.
 * 
 * @param stack [in] pointer to the stack
 * @param ptElem [out] address of variable to hold the value
 * 
 * @return STACK_OK if successful and value in 'ptElem', or
 * @return STACK_EMPTY if the stack is empty, or
 * @return STACK_NULL if 'stack' is NULL 
 */
int stackPop(PtStack stack, StackElem *ptElem);

/**
 * @brief Peeks at the top of the stack.
 * 
 * @param stack [in] pointer to the stack
 * @param ptElem [out] address of variable to hold the value
 * 
 * @return STACK_OK if successful and value in 'ptElem', or
 * @return STACK_EMPTY if the stack is empty, or
 * @return STACK_NULL if 'stack' is NULL 
 */
int stackPeek(PtStack stack, StackElem *ptElem);

/**
 * @brief Retrieves the size of a stack.
 * 
 * @param stack [in] pointer to the stack
 * @param ptSize [out] address of variable to hold the value
 * 
 * @return STACK_OK if successful and value in 'ptSize', or
 * @return STACK_NULL if 'stack' is NULL 
 */
int stackSize(PtStack stack, int *ptSize);

/**
 * @brief Checks whether a stack is empty.
 * 
 * @param stack [in] pointer to the stack
 * 
 * @return 'true' if empty or if 'stack' is NULL, or
 * @return 'false' it not empty
 */
bool stackIsEmpty(PtStack stack);

/**
 * @brief Clears the contents of a stack.
 * 
 * This operation will remove all current elements in the stack,
 * returning to an empty state.
 * 
 * @param stack [in] pointer to the stack
 * 
 * @return STACK_OK if successful, or
 * @return STACK_NULL if 'stack' is NULL 
 */
int stackClear(PtStack stack);

/**
 * @brief Prints the contents of a stack.
 * 
 * @param stack [in] pointer to the stack
 */
void stackPrint(PtStack stack);

