/**
 * @file main.c
 * 
 * @brief Provides an example program that uses the
 * ADT Queue. Please note that the StackElem type
 * must be defined as 'char'.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int main() {

	PtQueue s = queueCreate(10);

	printf("Enqueueing characters a,b,c and d... \n");
	queueEnqueue(s, 'a');
	queueEnqueue(s, 'b');
	queueEnqueue(s, 'c');
	queueEnqueue(s, 'd');

	queuePrint(s); //a,b,c,d

	QueueElem x;
	queueFront(s, &x);
	printf("Elemento in front of queue: ");
	queueElemPrint(x); //a

	printf("Dequeueing all elements... \n");
	while (!queueIsEmpty(s)) {
		QueueElem y;
		queueDequeue(s, &y);
		queueElemPrint(y); //a,b,c,d
	}

	queuePrint(s); //empty

	queueDestroy(&s);

	queuePrint(s); // (NULL)

	return EXIT_SUCCESS;
}
