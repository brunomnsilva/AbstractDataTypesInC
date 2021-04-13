/**
 * @file queueLinkedList.c
 * 
 * @brief Provides an implementation of the ADT Queue with a 
 * doubly-linked list with sentinels as the underlying 
 * data structure.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#include "queue.h" 
#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node* PtNode;

typedef struct node {
	QueueElem element;
	PtNode prev;
	PtNode next;
} Node;

typedef struct queueImpl {
	PtNode header;
	PtNode trailer;
	int size;
} QueueImpl;


PtQueue queueCreate() {
	PtQueue newQueue = (PtQueue)malloc(sizeof(QueueImpl));
	if (newQueue == NULL) return NULL;

	newQueue->header = (PtNode)malloc(sizeof(Node));
	if (newQueue->header == NULL) {
		free(newQueue);
		return NULL;
	}
	newQueue->trailer = (PtNode)malloc(sizeof(Node));
	if (newQueue->trailer == NULL) {
		free(newQueue->header);
		free(newQueue);
		return NULL;
	}

	newQueue->header->prev = NULL;
	newQueue->header->next = newQueue->trailer;

	newQueue->trailer->next = NULL;
	newQueue->trailer->prev = newQueue->header;

	newQueue->size = 0;

	return newQueue;
}

int queueDestroy(PtQueue *ptQueue) {
	PtQueue queue = *ptQueue;
	if (queue == NULL) { return QUEUE_NULL;	}

	/* This algorithm free all nodes including sentinels */
	PtNode current = queue->header;
	while (current != NULL) {
		PtNode remove = current;
		current = current->next;
		free(remove);
	}

	free(queue);

	*ptQueue = NULL;

	return QUEUE_OK;
}

int queueEnqueue(PtQueue queue, QueueElem elem) {
	if (queue == NULL) {return QUEUE_NULL;	}

	PtNode newEnd = (PtNode)malloc(sizeof(Node));
	if (newEnd == NULL) return QUEUE_NO_MEMORY;

	PtNode curEnd = queue->trailer->prev;

	newEnd->element = elem;
	newEnd->next = queue->trailer;
	newEnd->prev = curEnd;

	queue->trailer->prev = newEnd;
	curEnd->next = newEnd;

	queue->size++;

	return QUEUE_OK;
}

int queueDequeue(PtQueue queue, QueueElem *ptElem) {
	if (queue == NULL) {return QUEUE_NULL;	}

	if (queueIsEmpty(queue)) {return QUEUE_EMPTY;	}

	PtNode curFront = queue->header->next;
	PtNode newFront = curFront->next; 

	*ptElem = curFront->element;

	queue->header->next = newFront;
	newFront->prev = queue->header;
	
	free(curFront);

	queue->size--;

	return QUEUE_OK;
}

int queueFront(PtQueue queue, QueueElem *ptElem) {
	if (queue == NULL) {return QUEUE_NULL;	}

	if (queueIsEmpty(queue)) {	return QUEUE_EMPTY;	}

	PtNode curFront = queue->header->next;
	*ptElem = curFront->element;
	
	return QUEUE_OK;
}

int queueSize(PtQueue queue, int *ptSize) {
	if (queue == NULL) return QUEUE_NULL;

	*ptSize = queue->size;

	return QUEUE_OK;
}

bool queueIsEmpty(PtQueue queue) {
	if (queue == NULL) return true;

	return (queue->size == 0);
}

int queueClear(PtQueue queue) {
	if (queue == NULL) return QUEUE_NULL;
	
	/* Can leverage queueDequeue to free nodes 
		and decrement size */
	QueueElem elem;
	while (!queueIsEmpty(queue)) {
		queueDequeue(queue, &elem);
	}

	return QUEUE_OK;
}

void queuePrint(PtQueue queue) {
	if (queue == NULL) {
		printf("(Queue NULL) \n");
	}
	else if (queue->header->next == queue->trailer) {
		printf("(Queue Empty) \n");
	}
	else {
		printf("Queue contents (front to end): \n");
		PtNode current = queue->header->next;
		while (current != queue->trailer) {
			queueElemPrint(current->element);
			printf(" ");
			current = current->next;
		}
		printf("\n------------------------------ \n");
	}
}

