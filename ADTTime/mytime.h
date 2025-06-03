/**
 * @file mytime.h
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @brief Specification of ADT Time
 * @version 0.1
 * @date 2025-04-22
 * 
 * The name is chosen not to collide with system module <time.h>.
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once

#define TIME_OK       0    /**< Operation completed successfully */
#define TIME_NULL     1    /**< Null pointer received */
#define TIME_INVALID  2    /**< Invalid time values provided */

/** @brief Opaque structure representing a time (hour, minute, second). */
struct time;
typedef struct time* PtTime;

/*
EXERCISES. Append to the specification:

int timeCompare(PtTime t1, PtTime t2);
→ Compare two time instances (similarly to strcmp): returns < 0, 0 or > 1.

int timeSet(PtTime t, int hour, int minute, int second);
→ Validates and sets the time values.

bool timeEquals(PtTime t1, PtTime t2);
→ Checks whether two time instances are equal.

PtTime timeNow(void);
→ Creates a new time instance with the current (system) time.

*/

/**
 * @brief Creates a new Time instance with the given hour, minute, and second.
 * 
 * Valid values:
 * - 0 ≤ hour < 24
 * - 0 ≤ minute < 60
 * - 0 ≤ second < 60
 * 
 * @param hour Hour value.
 * @param minute Minute value.
 * @param second Second value.
 * @return A pointer to a new Time instance, or NULL if values are invalid or there is no memory.
 */
PtTime timeCreate(int hour, int minute, int second);

/**
 * @brief Destroys a Time instance and sets the pointer to NULL.
 * 
 * @param ptT Address of the Time pointer.
 * @return TIME_OK if destroyed successfully, TIME_NULL if input is NULL.
 */
int timeDestroy(PtTime *ptT);

/**
 * @brief Retrieves the hour component of a Time instance.
 * 
 * @param t Pointer to a Time instance.
 * @param hour Address to store the hour value.
 * @return TIME_OK if successful, TIME_NULL if input is NULL.
 */
int timeGetHour(PtTime t, int *hour);

/**
 * @brief Retrieves the minute component of a Time instance.
 * 
 * @param t Pointer to a Time instance.
 * @param minute Address to store the minute value.
 * @return TIME_OK if successful, TIME_NULL if input is NULL.
 */
int timeGetMinute(PtTime t, int *minute);

/**
 * @brief Retrieves the second component of a Time instance.
 * 
 * @param t Pointer to a Time instance.
 * @param second Address to store the second value.
 * @return TIME_OK if successful, TIME_NULL if input is NULL.
 */
int timeGetSecond(PtTime t, int *second);

/**
 * @brief Converts a Time instance to the total number of seconds since 00:00:00.
 * 
 * @param t Pointer to a Time instance.
 * @param totalSeconds Address to store the total number of seconds.
 * @return TIME_OK if successful, TIME_NULL if input is NULL.
 */
int timeToSeconds(PtTime t, int *totalSeconds);

/**
 * @brief Adds two Time instances and returns the result.
 * 
 * Addition wraps around at 24:00:00 (modulo 86400 seconds).
 * 
 * @param t1 First Time operand.
 * @param t2 Second Time operand.
 * @return A new Time instance representing the sum, or NULL if any argument is NULL or there is no memory.
 */
PtTime timeAdd(PtTime t1, PtTime t2);

/**
 * @brief Computes the absolute difference between two Time instances.
 * 
 * Example: |12:30:00 - 10:15:30| = 02:14:30
 * 
 * @param t1 First Time operand.
 * @param t2 Second Time operand.
 * @return A new Time instance representing the difference, or NULL if any argument is NULL or there is no memory.
 */
PtTime timeDiff(PtTime t1, PtTime t2);

/**
 * @brief Prints a Time instance to stdout in hh:mm:ss format.
 * 
 * @param t Pointer to a Time instance.
 */
void timePrint(PtTime t);
