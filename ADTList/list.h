/**
 * @file list.h
 * @brief Definition of the ADT List in C.
 * 
 * Defines the type PtList and associated operations.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#pragma once

#define LIST_OK				0
#define LIST_NULL			1
#define LIST_NO_MEMORY		2
#define LIST_EMPTY			3
#define LIST_FULL			4
#define LIST_INVALID_RANK	5

#include "listElem.h"
#include <stdbool.h>

/** Forward declaration of the data structure. */
struct listImpl;

/** Definition of pointer to the  data stucture. */
typedef struct listImpl *PtList;

/**
 * @brief Creates a new empty list.
 * 
 * @return PtList pointer to allocated data structure, or
 * @return NULL if unsufficient memory for allocation
 */
PtList listCreate();

/**
 * @brief Free all resources of a list.
 * 
 * @param ptList [in] ADDRESS OF pointer to the list
 * 
 * @return LIST_OK if success, or
 * @return LIST_NULL if '*ptList' is NULL 
 */
int listDestroy(PtList *ptList);

/**
 * @brief Add an element to a list.
 * 
 * The specified rank must be in [0, size].
 * 
 * @param list [in] pointer to the list
 * @param rank [in] rank for insertion
 * @param elem  [in] element to add
 * 
 * @return LIST_OK if successful, or
 * @return LIST_INVALID_RANK if 'rank' is invalid, or
 * @return LIST_FULL if no capacity available, or
 * @return LIST_NO_MEMORY if unsufficient memory for allocation, or
 * @return LIST_NULL if 'list' is NULL 
 */
int listAdd(PtList list, int rank, ListElem elem);

/**
 * @brief Removes an element from a list.
 * 
 * The specified rank must be in [0, size - 1].
 * 
 * @param list [in] pointer to the list
 * @param rank [in] rank for removal
 * @param ptElem [out] address of variable to hold the value
 * 
 * @return LIST_OK if successful and value in 'ptElem', or
 * @return LIST_INVALID_RANK if 'rank' is invalid, or
 * @return LIST_EMPTY if the list is empty, or
 * @return LIST_NULL if 'list' is NULL 
 */
int listRemove(PtList list, int rank, ListElem *ptElem);

/**
 * @brief Retrieves an element from a list.
 * 
 * The specified rank must be in [0, size - 1].
 * 
 * @param list [in] pointer to the list
 * @param rank [in] rank for retrieval
 * @param ptElem [out] address of variable to hold the value
 * 
 * @return LIST_OK if successful and value in 'ptElem', or
 * @return LIST_INVALID_RANK if 'rank' is invalid, or
 * @return LIST_EMPTY if the list is empty, or
 * @return LIST_NULL if 'list' is NULL 
 */
int listGet(PtList list, int rank, ListElem *ptElem);

/**
 * @brief Replaces an element from a list.
 * 
 * The specified rank must be in [0, size - 1].
 * This function replaces an element in the specified rank
 * and returns the previous element at that rank.
 * 
 * @param list [in] pointer to the list
 * @param rank [in] rank for replacement
 * @param elem  [in] element to put at the specified tank
 * @param ptOldElem [out] address of variable to hold the previous element
 * 
 * @return LIST_OK if successful and previous value in 'ptOldElem', or
 * @return LIST_INVALID_RANK if 'rank' is invalid, or
 * @return LIST_EMPTY if the list is empty, or
 * @return LIST_NULL if 'list' is NULL 
 */
int listSet(PtList list, int rank, ListElem elem, ListElem *ptOldElem);

/**
 * @brief Retrieves the size of a list.
 * 
 * @param list [in] pointer to the list
 * @param ptSize [out] address of variable to hold the value
 * 
 * @return LIST_OK if successful and value in 'ptSize', or
 * @return LIST_NULL if 'list' is NULL 
 */
int listSize(PtList list, int *ptSize);

/**
 * @brief Checks whether a list is empty.
 * 
 * @param list [in] pointer to the list
 * 
 * @return 'true' if empty or if 'list' is NULL, or
 * @return 'false' it not empty
 */
bool listIsEmpty(PtList list);

/**
 * @brief Clears the contents of a list.
 * 
 * This operation will remove all current elements in the list,
 * returning to an empty state.
 * 
 * @param list [in] pointer to the list
 * 
 * @return LIST_OK if successful, or
 * @return LIST_NULL if 'list' is NULL 
 */
int listClear(PtList list);

/**
 * @brief Prints the contents of a list.
 * 
 * @param list [in] pointer to the list
 */
void listPrint(PtList list);

