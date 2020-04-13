/**
 * @file main.c
 * 
 * @brief Provides an example program that uses the
 * ADT Stack. Please note that the StackElem type
 * must be defined as 'int'.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#include <stdio.h>
#include "stack.h"
#include <stdbool.h>

int main() {
    PtStack stack = stackCreate(4);
    int number, sum = 0;
    
    while(true) {

        printf("Number (0 to stop)? ");
        scanf("%d", &number);

        if(number == 0) break;

        int error = stackPush(stack, number);
        if( error == STACK_FULL || error == STACK_NO_MEMORY ) {
            printf("The stack reached its max limit.\n");
            break;
        }
    }

    printf("You entered the following numbers in reversed order: \n");
    while(!stackIsEmpty(stack)) {

        stackPop(stack, &number);
        printf("%d ", number);

        sum += number;
    }

    printf("\nTheir sum is: %d \n", sum);

    stackDestroy(&stack);

    return 0;
}