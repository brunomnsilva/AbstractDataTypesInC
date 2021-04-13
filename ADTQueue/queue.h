/**
 * @file queue.h
 * @brief Definition of the ADT Queue in C.
 * 
 * Defines the type PtQueue and associated operations.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#pragma once

#define QUEUE_OK            0
#define QUEUE_NULL          1
#define QUEUE_NO_MEMORY     2
#define QUEUE_EMPTY         3
#define QUEUE_FULL          4

#include <stdbool.h>
#include "queueElem.h"

/** Forward declaration of the data structure. */
struct queueImpl;

/** Definition of pointer to the  data stucture. */
typedef struct queueImpl *PtQueue;

/**
 * @brief Creates a new empty queue.
 * 
 * @return PtQueue pointer to allocated data structure, or
 * @return NULL if unsufficient memory for allocation
 */
PtQueue queueCreate();

/**
 * @brief Free all resources of a queue.
 * 
 * @param ptQueue [in] ADDRESS OF pointer to the queue
 * 
 * @return QUEUE_OK if success, or
 * @return QUEUE_NULL if '*ptQueue' is NULL 
 */
int queueDestroy(PtQueue *ptQueue);

/**
 * @brief Enqueue an element in a queue.
 * 
 * @param queue [in] pointer to the queue
 * @param elem  [in] element to enqueue
 * 
 * @return QUEUE_OK if successful, or
 * @return QUEUE_FULL if no capacity available, or
 * @return QUEUE_NO_MEMORY if unsufficient memory for allocation, or
 * @return QUEUE_NULL if 'queue' is NULL 
 */
int queueEnqueue(PtQueue queue, QueueElem elem);

/**
 * @brief Dequeue the element in front of a queue.
 * 
 * @param queue [in] pointer to the queue
 * @param ptElem [out] address of variable to hold the value
 * 
 * @return QUEUE_OK if successful and value in 'ptElem', or
 * @return QUEUE_EMPTY if the queue is empty, or
 * @return QUEUE_NULL if 'queue' is NULL 
 */
int queueDequeue(PtQueue queue, QueueElem *ptElem);

/**
 * @brief Retrieves the element in front of a queue.
 * 
 * @param queue [in] pointer to the queue
 * @param ptElem [out] address of variable to hold the value
 * 
 * @return QUEUE_OK if successful and value in 'ptElem', or
 * @return QUEUE_EMPTY if the queue is empty, or
 * @return QUEUE_NULL if 'queue' is NULL 
 */
int queueFront(PtQueue queue, QueueElem *ptElem);

/**
 * @brief Retrieves the size of a queue.
 * 
 * @param queue [in] pointer to the queue
 * @param ptSize [out] address of variable to hold the value
 * 
 * @return QUEUE_OK if successful and value in 'ptSize', or
 * @return QUEUE_NULL if 'queue' is NULL 
 */
int queueSize(PtQueue queue, int *ptSize);

/**
 * @brief Checks whether the queue is empty.
 * 
 * @param queue [in] pointer to the queue
 * 
 * @return 'true' if empty or if 'queue' is NULL, or
 * @return 'false' it not empty
 */
bool queueIsEmpty(PtQueue queue);

/**
 * @brief Clears the contents of a queue.
 * 
 * This operation will remove all current elements in the queue,
 * returning to an empty state.
 * 
 * @param queue [in] pointer to the queue
 * 
 * @return QUEUE_OK if successful, or
 * @return QUEUE_NULL if 'queue' is NULL 
 */
int queueClear(PtQueue queue);

/**
 * @brief Prints the contents of a queue.
 * 
 * @param queue [in] pointer to the queue
 */
void queuePrint(PtQueue queue);


