/**
 * @file mapLinkedList.c
 * 
 * @brief Provides an implementation of the ADT Map with a 
 * doubly-linked list with sentinels as the underlying 
 * data structure.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#include "map.h"
#include <stdlib.h>
#include <stdio.h>

/** definition of tuple KeyValue */ 
typedef struct keyValue {
	MapKey key;
	MapValue value;
} KeyValue;

struct node;
typedef struct node* PtNode;

typedef struct node {
    KeyValue element; 
    PtNode next;
    PtNode prev;
} Node;

typedef struct mapImpl {
	PtNode header;
    PtNode trailer;
	int size;
} MapImpl;

/**
 * @brief Auxiliary function to find the node of a specific key. 
 * 
 * Keys are compared by using mapKeyEquals function.
 * 
 * @param map [in] pointer to the map
 * @param key [in] key to find
 * @return PtNode pointer of node containing 'key', or
 * @return NULL if no node contains 'key'
 */
PtNode findNodeOfKey(PtMap map, MapKey key) {
	if (map == NULL) return NULL;

	PtNode current = map->header->next;
	while(current != map->trailer) {
		if (mapKeyEquals(current->element.key, key)) {
			return current;
		}

		current = current->next;
	}
	return NULL;
}

PtMap mapCreate(unsigned int initialCapacity) {
	PtMap map = (PtMap)malloc(sizeof(MapImpl));
	if (map == NULL) return NULL;
	
	map->header = (PtNode)malloc(sizeof(Node));
	if (map->header == NULL) {
		free(map);
		return NULL;
	}
	map->trailer = (PtNode)malloc(sizeof(Node));
	if (map->trailer == NULL) {
		free(map->header);
		free(map);
		return NULL;
	}

	map->header->prev = NULL;
	map->header->next = map->trailer;

	map->trailer->next = NULL;
	map->trailer->prev = map->header;

	map->size = 0;

	return map;
}

int mapDestroy(PtMap *ptMap) {
	PtMap map = *ptMap;

	if (map == NULL) return MAP_NULL;

	PtNode current = map->header->next;
    while(current != map->trailer) {
        current = current->next;
        free(current->prev);
    }

	free(map->header);
	free(map->trailer);
	free(map);

	*ptMap = NULL;

	return MAP_OK;
}

int mapSize(PtMap map, int *ptSize) {
	if (map == NULL) return MAP_NULL;

	*ptSize = map->size;

	return MAP_OK;
}

bool mapIsEmpty(PtMap map) {
	if (map == NULL) return true;

	return (map->size == 0);
}

int mapClear(PtMap map) {
	if (map == NULL) return MAP_NULL;

	PtNode current = map->header->next;
    while(current != map->trailer) {
        current = current->next;
        free(current->prev);
    }

	/* empty state of linked list */
    map->header->next = map->trailer;
    map->trailer->prev = map->header;

	map->size = 0;
	return MAP_OK;
}

void mapPrint(PtMap map) {
	if (map == NULL) {
		printf("(Map NULL)");
	}
	else if (mapIsEmpty(map)) {
		printf("(Map EMPTY)");
	}
	else {
		printf("Map contents (key / value): \n");
		PtNode current = map->header->next;
		while (current != map->trailer) {
			mapKeyPrint(current->element.key);
			printf(" : \n");
			mapValuePrint(current->element.value);
			printf("\n");

			current = current->next;
		}
	}
	printf("\n");
}

int mapPut(PtMap map, MapKey key, MapValue value) {
	if (map == NULL) return MAP_NULL;

	PtNode node = findNodeOfKey(map, key);
	if (node != NULL) {
		
		/* replace current value mapped to this key */
		node->element.value = value;

		return MAP_OK;
	}
	else {
		/* allocate new node and place it at the beggining of the list */
		PtNode newNode = (PtNode)malloc(sizeof(Node));
		if(newNode == NULL) return MAP_FULL;

		KeyValue tuple = {key, value};
		
		newNode->element = tuple;
		newNode->next = map->header->next;
		newNode->prev = map->header;

		map->header->next->prev = newNode;
		map->header->next = newNode;

		map->size++;

		return MAP_OK;
	}
}

int mapRemove(PtMap map, MapKey key, MapValue *ptValue) {
	if (map == NULL) return MAP_NULL;
	if (map->size == 0) return MAP_EMPTY;

	PtNode node = findNodeOfKey(map, key);
	if (node == NULL) return MAP_UNKNOWN_KEY;

	*ptValue = node->element.value;
	
	/* connect previous and next nodes */ 
	PtNode previous = node->prev;
	PtNode next = node->next;

	previous->next = next;
	next->prev = previous;

	free(node); /* free the node to remove */

	map->size--;
	
	return MAP_OK;
}

bool mapContains(PtMap map, MapKey key) {
	if (map == NULL) return false;

	return findNodeOfKey(map, key) != NULL;
}

int mapGet(PtMap map, MapKey key, MapValue *ptValue) {
	if (map == NULL) return MAP_NULL;
	if (map->size == 0) return MAP_EMPTY;

	PtNode node = findNodeOfKey(map, key);
	if (node == NULL) return MAP_UNKNOWN_KEY;

	*ptValue = node->element.value;
	
	return MAP_OK;
}

MapKey* mapKeys(PtMap map) {
	if (map == NULL) return NULL;

	MapKey *keys = (MapKey*)calloc(map->size, sizeof(MapKey));

	int i = 0;
	PtNode current = map->header->next;
    while(current != map->trailer) {
		keys[i++] = current->element.key;

        current = current->next;
    }

	return keys;
}

MapValue* mapValues(PtMap map) {
	if (map == NULL) return NULL;

	MapValue *values = (MapValue*)calloc(map->size, sizeof(MapValue));

	int i = 0;
	PtNode current = map->header->next;
    while(current != map->trailer) {
		values[i++] = current->element.value;

        current = current->next;
    }

	return values;
}