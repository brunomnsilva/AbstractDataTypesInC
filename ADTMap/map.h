/**
 * @file map.h
 * @brief Definition of the ADT Map in C.
 * 
 * Defines the type PtMap and associated operations.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#pragma once

#define MAP_OK            0
#define MAP_NULL          1
#define MAP_NO_MEMORY     2
#define MAP_EMPTY         3
#define MAP_FULL          4
#define MAP_UNKNOWN_KEY	  5

#include "mapElem.h"
#include <stdbool.h>

/** Forward declaration of the data structure. */
struct mapImpl;

/** Definition of pointer to the  data stucture. */
typedef struct mapImpl *PtMap;

/**
 * @brief Creates a new empty map.
 * 
 * @return PtMap pointer to allocated data structure, or
 * @return NULL if unsufficient memory for allocation
 */
PtMap mapCreate();

/**
 * @brief Free all resources of a map.
 * 
 * @param ptMap [in] ADDRESS OF pointer to the map
 * 
 * @return MAP_OK if success, or
 * @return MAP_NULL if '*ptMap' is NULL 
 */
int mapDestroy(PtMap *ptMap);

/**
 * @brief Add a key-value mapping to a map.
 * 
 * If 'key' already exists, the currently
 * mapped value is silently replaced by 'value'
 * 
 * @param map [in] pointer to the map
 * @param key [in] key 
 * @param value  [in] value
 * 
 * @return MAP_OK if successful, or
 * @return MAP_UNKNOWN_KEY if 'key' doesn't exist, or
 * @return MAP_FULL if no capacity available, or
 * @return MAP_NO_MEMORY if unsufficient memory for allocation, or
 * @return MAP_NULL if 'map' is NULL 
 */
int mapPut(PtMap map, MapKey key, MapValue value);

/**
 * @brief Removes a mapping from a map.
 * 
 * The function returns the value associated with 'key'
 * and removes 'key' from the map if the operation is
 * successful.
 * 
 * The specified key must exist.
 * 
 * @param map [in] pointer to the map
 * @param key [in] key for removal
 * @param ptValue [out] address of variable to hold the value
 * 
 * @return MAP_OK if successful and value in 'ptValue', or
 * @return MAP_UNKNOWN_KEY if 'key' doesn't exist, or
 * @return MAP_EMPTY if the map is empty, or
 * @return MAP_NULL if 'map' is NULL 
 */
int mapRemove(PtMap map, MapKey key, MapValue *ptValue);

/**
 * @brief Retrieves ther value associated with
 * a key from a map.
 * 
 * The specified key must exist.
 * 
 * @param map [in] pointer to the map
 * @param key [in] key for retrieval
 * @param ptValue [out] address of variable to hold the value
 * 
 * @return MAP_OK if successful and value in 'ptValue', or
 * @return MAP_UNKNOWN_KEY if 'key' doesn't exist, or
 * @return MAP_EMPTY if the map is empty, or
 * @return MAP_NULL if 'map' is NULL 
 */
int mapGet(PtMap map, MapKey key, MapValue *ptValue);

/**
 * @brief Checks whether a map contains a key.
 * 
 * @param map [in] pointer to the map
 * @param key [in] key to check
 * 
 * @return 'true' if 'key' exists, or
 * @return 'false' if 'key' doesn't exist or 'map' is NULL
 */
bool mapContains(PtMap map, MapKey key);

/**
 * @brief Retrieves the set of keys of a map.
 * 
 * This function returns a dynamically allocated array
 * with length equal to the size of the map, containing
 * the keys of the map in no particular order.
 * 
 * The caller is responsible for deallocating 
 * (freeing) the array. 
 * 
 * @param map [in] pointer to the map
 * 
 * @return array containing the keys
 * @return NULL if 'map' is empty or NULL
 */
MapKey* mapKeys(PtMap map);

/**
 * @brief Retrieves the set of values of a map.
 * 
 * This function returns a dynamically allocated array
 * with length equal to the size of the map, containing
 * the values of the map in no particular order.
 * 
 * The caller is responsible for deallocating 
 * (freeing) the array. 
 * 
 * @param map [in] pointer to the map
 * 
 * @return array containing the values
 * @return NULL if 'map' is empty or NULL
 */
MapValue* mapValues(PtMap map);

/**
 * @brief Retrieves the size of a map.
 * 
 * @param map [in] pointer to the map
 * @param ptSize [out] address of variable to hold the value
 * 
 * @return MAP_OK if successful and value in 'ptSize', or
 * @return MAP_NULL if 'map' is NULL 
 */
int mapSize(PtMap map, int *ptSize);

/**
 * @brief Checks whether a map is empty.
 * 
 * @param map [in] pointer to the map
 * 
 * @return 'true' if empty or if 'map' is NULL, or
 * @return 'false' it not empty
 */
bool mapIsEmpty(PtMap map);

/**
 * @brief Clears the contents of a map.
 * 
 * This operation will remove all current valueents in the map,
 * returning to an empty state.
 * 
 * @param map [in] pointer to the map
 * 
 * @return MAP_OK if successful, or
 * @return MAP_NULL if 'map' is NULL 
 */
int mapClear(PtMap map);

/**
 * @brief Prints the contents of a map.
 * 
 * @param map [in] pointer to the map
 */
void mapPrint(PtMap map);

