/**
 * @file main.c
 * @brief Provides an example program for the PtComplex type.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#include "complex.h"

#include <stdlib.h>
#include <stdio.h>


int main() {

	PtComplex a = complexCreate(1,4);
	PtComplex b = complexCreate(3,2);
	PtComplex c = NULL;

	if( a == NULL || b == NULL) {
		printf("Could not create numbers.\n");
		return EXIT_FAILURE;
	}

	printf("a = "); complexPrint(a);
	printf("b = "); complexPrint(b);
	printf("c = "); complexPrint(c);

	c = complexMultiply(a, b);

	printf("c = a * b = "); complexPrint(c);

	double modulus;
	complexMod(c, &modulus);
	printf("|c| = %.2f\n", modulus); 

	complexDestroy(&a);
	complexDestroy(&b);
	complexDestroy(&c);

	return EXIT_SUCCESS;
}