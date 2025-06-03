/**
 * @file queueArrayList.c
 * 
 * @brief Provides an implementation of the ADT Queue with an array list
 * as the underlying data structure.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#include "queue.h" 
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 20

typedef struct queueImpl {
	QueueElem *elements;
	int capacity;
	int size;
} QueueImpl;

static bool ensureCapacity(PtQueue queue) {
	if (queue->size == queue->capacity) {
		int newCapacity = queue->capacity * 2;
		QueueElem* newArray = (QueueElem*) realloc( queue->elements, 
									newCapacity * sizeof(QueueElem) );
		
		if(newArray == NULL) return false;

		queue->elements = newArray;
		queue->capacity = newCapacity;
	}
	
	return true;
}

PtQueue queueCreate() {
	PtQueue queue = (PtQueue)malloc(sizeof(QueueImpl));
	if (queue == NULL) return NULL;

	queue->elements = (QueueElem*)calloc(INITIAL_CAPACITY, 
											sizeof(QueueElem));
	if (queue->elements == NULL)
	{
		free(queue);
		return NULL;
	}

	queue->capacity = INITIAL_CAPACITY;
	queue->size = 0;

	return queue;
}

int queueDestroy(PtQueue *ptQueue) {
	PtQueue queue = *ptQueue;
	if (queue == NULL) return QUEUE_NULL;

	free(queue->elements);
	free(queue);
	*ptQueue = NULL;

	return QUEUE_OK;
}

int queueEnqueue(PtQueue queue, QueueElem elem) {
	if (queue == NULL) return QUEUE_NULL;

	if(!ensureCapacity(queue)) return QUEUE_NO_MEMORY;

	queue->elements[queue->size++] = elem;
	
	return QUEUE_OK;
}

int queueDequeue(PtQueue queue, QueueElem *ptElem) {
	if (queue == NULL) return QUEUE_NULL;

	if (queueIsEmpty(queue)) {
		return QUEUE_EMPTY;
	}

	*ptElem = queue->elements[0];
	
	for (int i = 0; i < queue->size - 1; i++) {
		queue->elements[i] = queue->elements[i + 1];
	}

	queue->size--;

	return QUEUE_OK;
}

int queueFront(PtQueue queue, QueueElem *ptElem) {
	if (queue == NULL) return QUEUE_NULL;

	if (queueIsEmpty(queue)) return QUEUE_EMPTY;

	*ptElem = queue->elements[0];

	return QUEUE_OK;
}

int queueSize(PtQueue queue, int *ptSize) {
	if (queue == NULL) return QUEUE_NULL;

	*ptSize = queue->size;

	return QUEUE_OK;
}

bool queueIsEmpty(PtQueue queue) {
	if (queue == NULL) return true;

	return (queue->size > 0) ? false : true;
}

int queueClear(PtQueue queue) {
	if (queue == NULL) return QUEUE_NULL;

	queue->size = 0;

	// Housekeeping. Array can be very large at this point, realloc to initial size
	if(queue->capacity > INITIAL_CAPACITY) {
		queue->elements = (QueueElem*)realloc(queue->elements, INITIAL_CAPACITY * sizeof(QueueElem));
		queue->capacity = INITIAL_CAPACITY;
	}

	return QUEUE_OK;
}

void queuePrint(PtQueue queue) {
	if (queue == NULL) {
		printf("(Queue NULL) \n");
	}
	else if (queue->size == 0) {
		printf("(Queue Empty) \n");
	}
	else {
		printf("Queue contents (front to end): \n");
		for (int i = 0; i < queue->size; i++) {
			queueElemPrint(queue->elements[i]);
			printf(" ");
		}
		printf("\n------------------------------ \n");
	}
}

