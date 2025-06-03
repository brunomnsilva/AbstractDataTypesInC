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
#include <time.h>
#include "list.h"

int main(int argc, char** argv) {
	srand(time(NULL));

	PtList list = listCreate();
	if(!list) return EXIT_FAILURE;

	/* Populate with values*/
	for(int i=0; i < 9; i++) {
		listAdd(list, i, (i+1) );
	}

	printf("\n--- Initial list ---\n");
	listPrint(list);
	
	/* Shuffle */
	int n;
	listSize(list, &n);
	int elem1, elem2;	
	for(int i=0; i < n; i++) {
		int randIndex = rand() % n;
		
		listGet(list, randIndex, &elem1);
		listSet(list, i, elem1, &elem2);
		listSet(list, randIndex, elem2, &elem1);
	}

	printf("\n--- After shuffle ---\n");
	listPrint(list);
	
	listDestroy(&list);

	return (EXIT_SUCCESS);
}