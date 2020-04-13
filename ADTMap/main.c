/**
 * @file main.c
 * 
 * @brief Provides an example program that uses the
 * ADT Map. This program counts the number of occurences
 * of distinct integers within an array.
 * 
 * Please note that the MapKey and MapValue types
 * must be defined as 'int'.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#include <stdio.h>
#include <stdlib.h>
#include "map.h"

int main() {

	int vec[] = { 1,1,2,1,4,3,1,2,2,4,4,13,7,5,5,5,9 };

	PtMap map = mapCreate(4);

	printf("Processing numbers: ");
	// 'sizeof(vec) / sizeof(int)' is possible only due 
	// to static allocation in the scope of this function
	for (int i = 0; i < sizeof(vec) / sizeof(int) ; i++) {
		int number = vec[i];
		printf("%d ", number);

		if (mapContains(map, number)) { //existing number
			int count;
			mapGet(map, number, &count);
			count++;
			mapPut(map, number, count);
		}
		else {	//new number 
			mapPut(map, number, 1);
		}
	}

	// print the contents of the map
	// mapPrint(map);

	/* or, alternatively, print in table format */
	int size;
	mapSize(map, &size);
	MapKey *numbers = mapKeys(map);

	printf("\nNumber | Count \n");
	for (int i = 0; i < size; i++) {
		int count;
		mapGet(map, numbers[i], &count);
		printf("%6d | %d \n", numbers[i], count);
	}

	free(numbers); // free the array, as per documentation

	mapDestroy(&map);	
	
	return EXIT_SUCCESS;
}