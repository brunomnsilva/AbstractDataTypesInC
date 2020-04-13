/**
 * @file mapElem.h
 * @brief Defines the types MapKey and MapValue.
 * 
 * The MapKey is an alias to the type of keys 
 * held by an instance of the ADT Map (PtMap).
 * 
 * The MapValue is an alias to the type of values 
 * held by an instance of the ADT Map (PtMap).
 *  
 * These aliases just be changed according to the use-case.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#pragma once

#include <stdbool.h>

/** Key type definition. Change according to the use-case. */
typedef int MapKey;

/** Value type definition. Change according to the use-case. */
typedef int MapValue;

/**
 * @brief Prints a key.
 * 
 * Must be implemented according concrete
 * type of MapKey.
 * 
 * @param key [in] key to print
 */
void mapKeyPrint(MapKey key);

/**
 * @brief Prints a value.
 * 
 * Must be implemented according concrete
 * type of MapValue.
 * 
 * @param value [in] value to print
 */
void mapValuePrint(MapValue value);

/**
 * @brief Compares two keys for equality.
 * 
 * This function is used by the ADT Map to perform
 * a key-based access to the underlying data.
 * 
 * @param key1 [in] a key
 * @param key2 [in] another key
 * @return 'true' if keys match, or
 * @return 'false' if keys don't match. 
 */
bool mapKeyEquals(MapKey key1, MapKey key2);
