#include "mapElem_items.h"
#include "item.h"

#include <stdio.h>

void mapKeyPrint(MapKey key) {
	printf("%d \n", key);
}

void mapValuePrint(MapValue value) {
	itemPrint(&value);
}

bool mapKeyEquals(MapKey key1, MapKey key2) {
	return (key1 == key2); 
}