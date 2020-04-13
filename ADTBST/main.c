#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main() {

    PtBST bst = bstCreate();

    bstInsert(bst, 4);
    bstInsert(bst, 1);
    bstInsert(bst, 18);
    bstInsert(bst, 9);
    bstInsert(bst, 4);
    bstInsert(bst, 7);
    bstInsert(bst, 14);
    bstInsert(bst, 3);
    bstInsert(bst, 1);
    
    printf("Contains 18? %d \n", bstContains(bst, 18) );
    printf("Contains 5? %d \n", bstContains(bst, 5) );
    printf("Contains 7? %d \n", bstContains(bst, 7) );

    int size;
    bstSize(bst, &size);
    printf("BST Size: %d \n", size);

    int height;
    bstHeight(bst, &height);
    printf("BST Height: %d \n", height);

    int max;
    bstMaximum(bst, &max);
    printf("Maximum value: %d \n", max);

    int min;
    bstMinimum(bst, &min);
    printf("Minimum value: %d \n", min);

    bstPrint(bst);

    printf("Removing 4 and 18... \n");

    bstRemove(bst, 18);
    bstRemove(bst, 4);

    bstSize(bst, &size);
    printf("BST Size: %d \n", size);

    bstHeight(bst, &height);
    printf("BST Height: %d \n", height);
    
    bstPrint(bst);

    bstClear(bst);

    bstPrint(bst);

    
    bstDestroy(&bst);

    return EXIT_SUCCESS;
}