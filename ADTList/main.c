/**
 * @file main.c
 * 
 * @brief Provides an example program that uses the
 * ADT List. Please note that the ListElem type
 * must be defined as 'int'.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char** argv) {

	ListElem elem;
	PtList list = listCreate(10);

	listAdd(list, 0, 7);
	listAdd(list, 0, 4);
	listAdd(list, 1, 5);
	listAdd(list, 1, 3);
	listAdd(list, 4, 9);
	listAdd(list, 2, 2);
	listAdd(list, 6, 1);

	listPrint(list); //Expected: 4,3,2,5,7,9,1
		
	if (listGet(list, 9, &elem) == LIST_INVALID_RANK) {
		printf("9 is an invalid rank!\n");
	}

	listRemove(list, 1, &elem);
	printf("Element removed from rank 1: ");
	listElemPrint(elem);

	listPrint(list);

	int size;
	listSize(list, &size);
	printf("List size: %d \n", size);

	printf("Accessing all elements backwards: \n");	
	for (int i = size-1; i>=0; i--) {
		listGet(list, i, &elem);
		listElemPrint(elem);
	}
	

	listClear(list);
	listPrint(list);

	listDestroy(&list);
	listPrint(list);

	return (EXIT_SUCCESS);
}