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
	
} QueueImpl;


PtQueue queueCreate(unsigned int initialCapacity) {
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

	return newQueue;
}

int queueDestroy(PtQueue *ptQueue) {
	PtQueue queue = *ptQueue;
	if (queue == NULL) { return QUEUE_NULL;	}

	//alternativa 1:
	/*queueClear(queue);

	free(queue->header);
	free(queue->trailer);
	free(queue);*/

	//alternativa 2:
	/*PtNode current = queue->header->next;
	while (current != queue->trailer) {
		PtNode remove = current;
		current = current->next;
		free(remove);
	}
	free(queue->header);
	free(queue->trailer);
	free(queue);*/

	//alternativa 3: libertar todos os nos, incluindo header e trailer, num unico ciclo
	PtNode current = queue->header;
	while (current != NULL) {
		PtNode remove = current;
		current = current->next;
		free(remove);
	}
	free(queue);

	//outras alternativas: percorrer a lista ligada no sentido inverso

	*ptQueue = NULL;

	return QUEUE_OK;
}

int queueEnqueue(PtQueue queue, QueueElem elem) {
	if (queue == NULL) {return QUEUE_NULL;	}

	PtNode newNode = (PtNode)malloc(sizeof(Node));
	if (newNode == NULL) return QUEUE_NO_MEMORY;

	PtNode curEnd = queue->trailer->prev;

	newNode->element = elem;
	newNode->next = queue->trailer;
	newNode->prev = curEnd;

	queue->trailer->prev = newNode;
	curEnd->next = newNode;


	return QUEUE_OK;
}

int queueDequeue(PtQueue queue, QueueElem *ptElem) {
	if (queue == NULL) {return QUEUE_NULL;	}

	if (queueIsEmpty(queue)) {return QUEUE_EMPTY;	}

	PtNode curStart = queue->header->next;
	*ptElem = curStart->element;

	PtNode newStart = curStart->next; //ou queue->header->next->next;

	queue->header->next = newStart;
	newStart->prev = queue->header;
	
	free(curStart);

	return QUEUE_OK;
}

int queueFront(PtQueue queue, QueueElem *ptElem) {
	if (queue == NULL) {return QUEUE_NULL;	}

	if (queueIsEmpty(queue)) {	return QUEUE_EMPTY;	}

	//alternativa 1:
	//*ptElem = queue->header->next->element;

	//alternativa 2:
	PtNode curStart = queue->header->next;
	*ptElem = curStart->element;
	
	return QUEUE_OK;
}

int queueSize(PtQueue queue, int *ptSize) {
	if (queue == NULL) return QUEUE_NULL;

	int count = 0;
	PtNode current = queue->header->next;
	while (current != queue->trailer) {
		count++;
		current = current->next;
	}
	*ptSize = count;
	return QUEUE_OK;
}

bool queueIsEmpty(PtQueue queue) {
	if (queue == NULL) return 1;
	return (queue->header->next == queue->trailer) ? true : false;
}

int queueClear(PtQueue queue) {
	if (queue == NULL) return QUEUE_NULL;
	
	//alternativa 1:
	//PtNode current = queue->header->next;
	//while (current != queue->trailer) {
	//	//alternativa 1:
	//	PtNode remove = current;
	//	current = current->next;
	//	free(remove);

	//	//alternativa 2:
	//	/*current = current->next;
	//	free(current->prev);*/
	//}

	//queue->header->next = queue->trailer;
	//queue->trailer->prev = queue->header;

	//alternativa 3:
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
		//imprimir do inicio para o fim da fila:
		printf("Queue contents (begin to end): \n");
		PtNode current = queue->header->next;
		while (current != queue->trailer) {
			queueElemPrint(current->element);
			current = current->next;
		}
		printf("------------------------------ \n");
	}
}

