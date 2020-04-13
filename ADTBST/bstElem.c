#include "bstElem.h"
#include <stdio.h>

void bstElemPrint(BSTElem elem) {
    printf("%d ", elem);
}

int bstElemCompare(BSTElem elem1, BSTElem elem2) {
    return elem1 - elem2;
}