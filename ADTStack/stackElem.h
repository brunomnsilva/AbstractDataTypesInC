/**
 * @file stackElem.h
 * @brief Defines the type StackElem.
 * 
 * The StackElem is an alias to the type of elements 
 * held by an instance of the ADT Stack (PtStack).
 * 
 * This alias must be changed according to the use-case.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#pragma once

/** Type definition. Change according to the use-case. */
typedef int StackElem;

/**
 * @brief Prints an element.
 * 
 * Must be implemented according to the concrete
 * type of StackElem.
 * 
 * @param elem [in] element to print
 */
void stackElemPrint(StackElem elem);

