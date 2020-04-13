#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

struct bstnode;
typedef struct bstnode* PtBSTNode;

typedef struct bstnode {
    BSTElem element;
    PtBSTNode parent;
    PtBSTNode left;
    PtBSTNode right;
} BSTNode;

typedef struct bstImpl {
    PtBSTNode root;
} BST;

PtBST bstCreate() {
    PtBST bst = (PtBST) malloc( sizeof(BST) );
    if( bst == NULL ) return NULL;

    bst->root = NULL;

    return bst;
}

int bstDestroy(PtBST* ptBst) {
    PtBST bst = *ptBst;
    if(bst == NULL) return BST_NULL;

    bstClear(bst); /* free nodes */

    free(bst);

    *ptBst = NULL;

    return BST_OK;
}


int _bstInsert(PtBSTNode treeRoot, BSTElem elem) {
    if( treeRoot == NULL ) return BST_NULL;

    int compare = bstElemCompare(elem, treeRoot->element);

    if( compare == 0 ) {
        return BST_OK; /* already exists */
    } else if( compare < 0 ) {
        if( treeRoot->left == NULL ) {
            PtBSTNode new = (PtBSTNode) malloc( sizeof(BSTNode) );
            if( new == NULL ) return BST_FULL;

            new->element = elem;
            new->parent = treeRoot;
            new->left = new->right = NULL;

            treeRoot->left = new;

            return BST_OK;
        } else {
            /* recursive call */
            return _bstInsert(treeRoot->left, elem);
        }
    } else {
        if( treeRoot->right == NULL ) {
            PtBSTNode new = (PtBSTNode) malloc( sizeof(BSTNode) );
            if( new == NULL ) return BST_FULL;

            new->element = elem;
            new->parent = treeRoot;
            new->left = new->right = NULL;

            treeRoot->right = new;

            return BST_OK;
        } else {
            /* recursive call */
            return _bstInsert(treeRoot->right, elem);
        }
    }
}


int bstInsert(PtBST bst, BSTElem elem) {
    if( bst == NULL ) return BST_NULL;

    if( bst->root == NULL ) {
        PtBSTNode node = (PtBSTNode) malloc( sizeof(BSTNode) );
        if( node == NULL ) return BST_FULL;

        node->element = elem;
        node->parent = node->left = node->right = NULL;
        bst->root = node;
    } else {
        _bstInsert(bst->root, elem);
    }

    return BST_OK;
}

void _removeNode(PtBST bst, PtBSTNode node) {

    PtBSTNode parent = node->parent;

    if( node->left == NULL && node->right == NULL ) {
        if( parent == NULL) {
            free(bst->root);
            bst->root = NULL;
        } else if( parent->left == node ) {
            free(parent->left);
            parent->left = NULL;
        } else {
            free(parent->right);
            parent->right = NULL;
        }
    }
    
    else if( node->left != NULL && node->right != NULL ) {
        BSTElem minElem;
        bstMinimum(bst, &minElem);

        bstRemove(bst, minElem);

        node->element = minElem;
    }

    else {
        PtBSTNode subTree = (node->left != NULL) ? node->left : node->right;

        if(node == bst->root) {
            free(bst->root);
            bst->root = subTree;
            subTree->parent = NULL;
        } else {
            if( parent->left == node ) {
                free(parent->left);
                parent->left = subTree;
            } else {
                free(parent->right);
                parent->right = subTree;
            }
            subTree->parent = parent;
        }
    }
}


int _bstRemove(PtBST bst, PtBSTNode subTree, BSTElem elem) {
    if( bst == NULL ) return BST_NULL;
    if( subTree == NULL ) return BST_OK; /* not found */

    int compare = bstElemCompare(elem, subTree->element);
    if( compare == 0) {
        _removeNode(bst, subTree);
    } else if( compare < 0 ) {
        _bstRemove(bst, subTree->left, elem);
    } else {
        _bstRemove(bst, subTree->right, elem);
    }

    return BST_OK;
}

int bstRemove(PtBST bst, BSTElem elem) {
    if( bst == NULL ) return BST_NULL;
    if( bstIsEmpty(bst) ) return BST_EMPTY;

    return _bstRemove(bst, bst->root, elem);
}

bool _bstContains(PtBSTNode treeRoot, BSTElem elem) {
    if( treeRoot == NULL ) return false;

    int compare = bstElemCompare(elem, treeRoot->element);

    if( compare == 0 ) return true;
    else if( compare < 0 ) return _bstContains(treeRoot->left, elem);
    else return _bstContains(treeRoot->right, elem);
}

bool bstContains(PtBST bst, BSTElem elem) {
    if( bst == NULL ) return false;
    if( bstIsEmpty(bst) ) return false;

    return _bstContains(bst->root, elem);
}

int bstMinimum(PtBST bst, BSTElem* ptMin) {
    if( bst == NULL ) return BST_NULL;
    if( bstIsEmpty(bst) ) return BST_EMPTY;
    
    /* iterative algorithm */
    PtBSTNode minNode = bst->root;
    while(minNode->left != NULL) {
        minNode = minNode->left;
    }

    *ptMin = minNode->element;

    return BST_OK;
}

int bstMaximum(PtBST bst, BSTElem* ptMax) {
    if( bst == NULL ) return BST_NULL;
    if( bstIsEmpty(bst) ) return BST_EMPTY;

    /* iterative algorithm */
    PtBSTNode maxNode = bst->root;
    while(maxNode->right != NULL) {
        maxNode = maxNode->right;
    }

    *ptMax = maxNode->element;

    return BST_OK;
}

int max(int a, int b) {
    if( a >= b ) return a;
    else return b;
}

int _bstHeightCalc(PtBSTNode treeRoot) {
    if( treeRoot == NULL ) return -1;

    return 1 + max(_bstHeightCalc(treeRoot->left), _bstHeightCalc(treeRoot->right) );
}

int bstHeight(PtBST bst, int* ptHeight) {
    if( bst == NULL ) return BST_NULL;

    *ptHeight = _bstHeightCalc(bst->root);
    
    return BST_OK;
}

int _bstNodeCount(PtBSTNode treeRoot) {
    if(treeRoot == NULL) return 0;

    return 1 + _bstNodeCount(treeRoot->left) + _bstNodeCount(treeRoot->right);
}

int bstSize(PtBST bst, int* ptSize) {
    if( bst == NULL ) return BST_NULL;

    *ptSize = _bstNodeCount(bst->root);

    return BST_OK;
}

bool bstIsEmpty(PtBST bst) {
    return bst->root == NULL;
}

void _freeNodes(PtBSTNode treeRoot) {
    /* pos-order traversal with node free */
    if( treeRoot == NULL ) return;

    _freeNodes(treeRoot->left);
    _freeNodes(treeRoot->right);

    free(treeRoot);
}

int bstClear(PtBST bst) {
    if( bst == NULL ) return BST_NULL;

    _freeNodes(bst->root);

    bst->root = NULL;

    return BST_OK;
}


void _bstPrintInOrder(PtBSTNode treeRoot) {
    if( treeRoot == NULL ) return;

    _bstPrintInOrder(treeRoot->left);
    bstElemPrint(treeRoot->element);
    _bstPrintInOrder(treeRoot->right);
}

void _bstPrintPreOrder(PtBSTNode treeRoot) {
    // bases case 
    if (treeRoot == NULL) 
        return; 
  
    // push the root data as character 
    bstElemPrint(treeRoot->element); 
  
    // if leaf node, then return 
    if (!treeRoot->left && !treeRoot->right) 
        return; 
  
    // for left subtree 
    printf("( "); 
    _bstPrintPreOrder(treeRoot->left); 
    printf(")"); 
  
    // only if right child is present to  
    // avoid extra parenthesis 
    if (treeRoot->right) { 
        printf("( "); 
        _bstPrintPreOrder(treeRoot->right); 
        printf(")");  
    } 
}

void _printSpaces(int n) {
    for(int i=0; i<n; i++) {
        printf("    ");
    }
}
void _bstPrintInOrderHeight(PtBSTNode treeRoot) {
    if( treeRoot == NULL ) return;

    _bstPrintInOrderHeight(treeRoot->right);
    
    int height = _bstHeightCalc(treeRoot);
    _printSpaces(height);
    bstElemPrint(treeRoot->element);
    printf("\n");


    _bstPrintInOrderHeight(treeRoot->left);
}

void bstPrint(PtBST bst) {
    if( bst == NULL ) {
        printf("(BST NULL)\n");
    } else if( bstIsEmpty(bst) ) {
        printf("(BST EMPTY)\n");
    } else {
        //_bstPrintInOrder(bst->root);
        //_bstPrintPreOrder(bst->root);
        _bstPrintInOrderHeight(bst->root);
        printf("\n");
    }
}
