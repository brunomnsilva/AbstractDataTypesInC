/**
 * @file listElem.h
 * @brief Defines the type ListElem.
 * 
 * The ListElem is an alias to the type of elements 
 * held by an instance of the ADT List (PtList).
 * 
 * This alias must be changed according to the use-case.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#pragma once

/** Type definition. Change according to the use-case. */
typedef int ListElem;

/**
 * @brief Prints an element.
 * 
 * Must be implemented according to the concrete
 * type of ListElem.
 * 
 * @param elem [in] element to print
 */
void listElemPrint(ListElem elem);

