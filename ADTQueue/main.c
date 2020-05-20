/**
 * @file main.c
 * 
 * @brief Provides an example program that uses the
 * ADT Queue. Please note that the QueueElem type
 * must be defined as 'char'.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int main() {

	PtQueue q = queueCreate(10);

	printf("Enqueueing characters a, b, c and d... ");
	queueEnqueue(q, 'a');
	queueEnqueue(q, 'b');
	queueEnqueue(q, 'c');
	queueEnqueue(q, 'd');
	printf("Done. \n");

	int size;
	queueSize(q, &size);
	printf("\nQueue contains %d elements.\n\n", size);

	char x;
	queueFront(q, &x);
	printf("Element at front of queue: %c \n", x);

	printf("Dequeueing all elements until empty: \n");
	while (!queueIsEmpty(q)) {
		queueDequeue(q, &x);
		queueElemPrint(x); //expected: a,b,c,d
		printf("\n");
	}

	queueSize(q, &size);
	printf("\nQueue contains %d elements.\n\n", size);

	queueDestroy(&q);

	return EXIT_SUCCESS;
}
