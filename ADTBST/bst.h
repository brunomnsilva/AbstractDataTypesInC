#pragma once

#define BST_OK      0
#define BST_NULL    1
#define BST_EMPTY   2
#define BST_FULL    3

#include <stdbool.h>
#include "bstElem.h"

struct bstImpl;
typedef struct bstImpl* PtBST;

PtBST bstCreate();
int bstDestroy(PtBST* ptBst);

int bstInsert(PtBST bst, BSTElem elem);
int bstRemove(PtBST bst, BSTElem elem);

bool bstContains(PtBST bst, BSTElem elem);
int bstMinimum(PtBST bst, BSTElem* ptMin);
int bstMaximum(PtBST bst, BSTElem* ptMax);

int bstHeight(PtBST bst, int* ptHeight);
int bstSize(PtBST bst, int* ptSize);

bool bstIsEmpty(PtBST bst);

int bstClear(PtBST bst);

void bstPrint(PtBST bst);