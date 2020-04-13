#include <stdio.h>
#include <stdlib.h>

#include "item.h"
#include "map.h"

int main() {
	
	Item items[5];
	items[0] = itemCreate(124, "octopus", 7.2);
	items[1] = itemCreate(346, "mascarpone", 0.56);
	items[2] = itemCreate(564, "cocoa powder", 2.9);
	items[3] = itemCreate(567, "bok choy", 4.565);
	items[4] = itemCreate(234, "sea cucumbers", 1.7);

	PtMap map = mapCreate(20);
	for (int i = 0; i < 5; i++) {
		mapPut(map, items[i].code, items[i]);
	}

	int size;
	mapSize(map, &size);
	printf("%d produtos existentes... \n", size);
	
	//mapPrint(map);
	MapKey *codes = mapKeys(map);
	if (codes != NULL) {
		printf("Codigos existentes: \n");
		//o tamanho do array 'codes' � o tamanho do mapa, que sabemos do bloco anterior!
		for (int i = 0; i < size; i++) {
			mapKeyPrint(codes[i]);
		}
		printf("------------------- \n");
	}
	//importante: se j� nao precisamos de 'codes' temos de libertar a memoria explicitamente
	free(codes);
		
	int code = 0; // === MapKey
	do {
		printf("Introduza o codigo de um produto (0 para terminar): ");
		scanf("%d", &code);

		if (!mapContains(map, code)) {
			printf("PRODUTO NAO ENCONTRADO! \n");
		}
		else {
			MapValue value; // == Item
			mapGet(map, code, &value);
			mapValuePrint(value);
		}
		
	} while (code != 0);

	mapDestroy(&map);

	return EXIT_SUCCESS;
}