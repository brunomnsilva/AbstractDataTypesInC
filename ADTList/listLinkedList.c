/**
 * @file listLinkedList.c
 * 
 * @brief Provides an implementation of the ADT List with a 
 * doubly-linked list with sentinels as the underlying 
 * data structure.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node* PtNode;

typedef struct node {
	ListElem element;
	PtNode next, prev;
} Node;

typedef struct listImpl {
	PtNode header;
	PtNode trailer;
	unsigned int size; 
} ListImpl;


PtNode nodeAtRank(PtList list, int rank) {
	
	int currentRank = 0;
	PtNode currentNode = list->header->next;
	while (currentNode != NULL) { 

		if (currentRank == rank) return currentNode;

		currentRank++;
		currentNode = currentNode->next;
	}

	/* may be optimized if rank > size/2 by starting at trailer */

	return NULL;
}


PtList listCreate(unsigned int initialCapacity) {
		
	PtList newList = (PtList)malloc(sizeof(ListImpl));
	if (newList == NULL) return NULL;

	newList->header = (PtNode)malloc(sizeof(Node));
	newList->trailer = (PtNode)malloc(sizeof(Node));

	newList->header->prev = NULL;
	newList->header->next = newList->trailer;

	newList->trailer->prev = newList->header;
	newList->trailer->next = NULL;

	newList->size = 0;

	return newList;
}

int listDestroy(PtList *ptList) {
	PtList list = *ptList;
	if (list == NULL) return LIST_NULL;

	PtNode current = list->header;
	while (current != NULL) {
		PtNode remove = current;
		current = current->next;
		free(remove);
	}

	free(list);

	*ptList = NULL;

	return LIST_OK;
}

int listAdd(PtList list, int rank, ListElem elem) {
	if (list == NULL) return LIST_NULL;
	if (rank < 0 || rank > list->size) return LIST_INVALID_RANK;


	PtNode nodeCurRank = nodeAtRank(list, rank);
	PtNode nodePrevRank = nodeCurRank->prev;

	PtNode newNode = (PtNode)malloc(sizeof(Node));
	newNode->element = elem;
	newNode->next = nodeCurRank;
	newNode->prev = nodePrevRank;

	nodePrevRank->next = newNode;
	nodeCurRank->prev = newNode;

	list->size++;

	return LIST_OK;
}

int listRemove(PtList list, int rank, ListElem *ptElem) {
	if (list == NULL) return LIST_NULL;
	if (list->size == 0) return LIST_EMPTY;
	if (rank < 0 || rank > list->size - 1) return LIST_INVALID_RANK;

	PtNode nodeCurRank = nodeAtRank(list, rank);
	*ptElem = nodeCurRank->element;

	PtNode nodeNextRank = nodeCurRank->next;
	PtNode nodePrevRank = nodeCurRank->prev;
	nodePrevRank->next = nodeNextRank;
	nodeNextRank->prev = nodePrevRank;

	free(nodeCurRank);

	list->size--;

	return LIST_OK;
}

int listGet(PtList list, int rank, ListElem *ptElem) {
	if (list == NULL) return LIST_NULL;
	if (rank < 0 || rank > list->size - 1) return LIST_INVALID_RANK;

	PtNode node = nodeAtRank(list, rank);
	if (node != NULL) {
		*ptElem = node->element;
	}

	return LIST_OK;
}

int listSet(PtList list, int rank, ListElem elem, ListElem *ptOldElem) {
	if (list == NULL) return LIST_NULL;
	if (rank < 0 || rank > list->size - 1) return LIST_INVALID_RANK;

	PtNode node = nodeAtRank(list, rank);
	if (node != NULL) {
		*ptOldElem = node->element;
		node->element = elem;
	}

	return LIST_OK;
}

int listSize(PtList list, int *ptSize) {
	if (list == NULL) return LIST_NULL;

	*ptSize = list->size;

	return LIST_OK;
}

bool listIsEmpty(PtList list) {
	if (list == NULL) return 1;

	return (list->size == 0);
}

int listClear(PtList list) {
	if (list == NULL) return LIST_NULL;

	PtNode current = list->header->next;
	while (current != list->trailer) {
		PtNode remove = current;
		current = current->next;
		free(remove);
	}

	list->header->next = list->trailer;
	list->trailer->prev = list->header;

	list->size = 0;

	return LIST_OK;
}
void listPrint(PtList list) {
	if (list == NULL) {
		printf("(LIST NULL)\n");
	}
	else if (list->size == 0) {
		printf("(LIST EMPTY)\n");
	}
	else {
		int rank = 0;
		PtNode current = list->header->next;
		while (current != list->trailer) {

			printf("Rank %d: ", rank);
			listElemPrint(current->element);

			rank++;
			current = current->next;
		}
	}
	printf("\n");
}