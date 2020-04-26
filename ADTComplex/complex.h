/**
 * @file complex.h
 * @brief Defines the type PtComplex and associated operations.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#pragma once

#define COMPLEX_OK	    0
#define COMPLEX_NULL	1

struct complex;
typedef struct complex* PtComplex;

/**
 * @brief Create a new complex number from two `double`s.
 * 
 * @param re [in] real component
 * @param im  [in] imaginary component
 * 
 * @return PtComplex pointer to allocated complex number.
 * @return NULL if unsufficient memory for allocation
 */
PtComplex complexCreate (double re, double im);

/**
* @brief Release all resources of a complex number.
* 
* @param ptC [in] ADDRESS OF PtComplex pointer to the data structure.
*
* @return COMPLEX_OK if the operation is successful and *ptC = NULL
* @return COMPLEX_NULL if 'c' is NULL
*/
int complexDestroy (PtComplex *ptC);

/**
* @brief Retrieve the real part of the complex number.
*
* @param c [in] PtComplex pointer to the number's data structure.
* @param re [out] Address of variable to hold result
*
* @return COMPLEX_OK and real part assigned to '*re'
* @return COMPLEX_NULL if 'c' is NULL
*/
int complexRe (PtComplex c, double *re);

/**
* @brief Retrieve the imaginary part of the complex number.
*
* @param c [in] PtComplex pointer to the number's data structure.
* @param im [out] Address of variable to hold result
*
* @return COMPLEX_OK and imaginary part assigned to '*im'
* @return COMPLEX_NULL if 'c' is NULL
*/
int complexIm (PtComplex c, double *im);

/**
 * @brief Add two complex numbers together.
 * 
 * @param w [in] PtComplex pointer to the data structure of first number.
 * @param z [in] PtComplex pointer to the data structure of second number.
 * 
 * @return PtComplex pointer to new computed number
 * @return NULL if 'w' or 'z' are NULL
 * @return NULL if unsufficient memory for allocation
 */
PtComplex complexAdd (PtComplex w, PtComplex z);

/**
 * @brief Multiply two complex numbers together.
 * 
 * @param w [in] PtComplex pointer to the data structure of first number.
 * @param z [in] PtComplex pointer to the data structure of second number.
 * 
 * @return PtComplex pointer to new computed number
 * @return NULL if 'w' or 'z' are NULL
 * @return NULL if unsufficient memory for allocation
 */
PtComplex complexMultiply (PtComplex w, PtComplex z);

/**
* @brief Take the magnitude (or modulus, or absolute) of a complex number.
*
* @param w [in] PtComplex pointer to the number's data structure.
* @param modulus [out] Address of variable to hold result
*
* @return COMPLEX_OK and computed magnitude assigned to '*modulus'
* @return COMPLEX_NULL if 'c' is NULL and '*modulus' unchanged
*/
int complexMod (PtComplex w, double *modulus);

/**
* @brief Take the argument (or angle) of a complex number.
*
* @param w [in] PtComplex pointer to the number's data structure.
* @param argument [out] Address of variable to hold the value
*
* @return COMPLEX_OK and computed argument assigned to '*argument'
* @return COMPLEX_NULL if 'c' is NULL and '*argument' unchanged.
*/
int complexArg (PtComplex w, double *argument);

/**
* @brief  Prints the complex number in the format "a + bi".
*
* @param c [in] PtComplex pointer to the number's data structure.
*/
void complexPrint(PtComplex c);

