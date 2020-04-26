/**
 * @file complex.c
 * @brief Defines a data structure and implements complex.h
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#include "complex.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct complex {
    double real;
    double imaginary;
} Complex;

PtComplex complexCreate (double re, double im) {
    PtComplex c = (PtComplex) malloc( sizeof(Complex) );
    
    if( c == NULL) return NULL;

    c->real = re;
    c->imaginary = im;

    return c;
}

int complexDestroy (PtComplex *ptC) {
    PtComplex c = *ptC;

    if( c == NULL ) return COMPLEX_NULL;

    free(c);

    *ptC = NULL;

    return COMPLEX_OK;
}

int complexRe (PtComplex c, double *re) {
    if( c == NULL ) return COMPLEX_NULL;

    (*re) = c->real;

    return COMPLEX_OK;
}

int complexIm (PtComplex c, double *im) {
    if( c == NULL ) return COMPLEX_NULL;

    (*im) = c->imaginary;

    return COMPLEX_OK;
}
    
PtComplex complexAdd (PtComplex w, PtComplex z) {
    if( w == NULL || z == NULL) return NULL;

    PtComplex c = (PtComplex) malloc( sizeof(Complex) );
    
    if( c == NULL) return NULL;

    c->real = w->real + z->real;
    c->imaginary = w->imaginary + z->imaginary;

    return c;
}

PtComplex complexMultiply (PtComplex w, PtComplex z) {
    if( w == NULL || z == NULL) return NULL;

    PtComplex c = complexCreate(0,0);
    
    if( c == NULL) return NULL;

    c->real = (w->real * z->real - w->imaginary * z->imaginary);
    c->imaginary = (w->imaginary * z->real + w->real * z->imaginary);

    return c;
}

int complexMod (PtComplex w, double* modulus) {
    if( w == NULL ) return COMPLEX_NULL;

    (*modulus) = sqrt( w->real * w->real + w->imaginary * w->imaginary);

    return COMPLEX_OK;
}

int complexArg (PtComplex w, double *argument) {
    if( w == NULL ) return COMPLEX_NULL;

    (*argument) = atan2( w->real, w->imaginary );

    return COMPLEX_OK;
}

void complexPrint(PtComplex w) {
    if( w == NULL ) 
        printf("(NULL)\n");
    else
        printf("%.3f + %.3fi\n", w->real, w->imaginary);
}