#include <stdio.h>
#include <stdlib.h>
#include "mytime.h"

#define DAY_TO_SECONDS 86400

typedef struct time {    
    int hours, minutes, seconds;

    /*  TODO: EXERCISE. Store time with total seconds elapsed from 0:00:00 
        All functions should me modified appropriately.
    */
} Time;

/**
 * @brief Auxiliary function to convert a total amounts of seconds 
 * elapsed from 00:00:00 to a PtTime instance.
 * 
 * @param totalSeconds total seconds to convert
 * @return PtTime instance or NULL if totalSeconds < 0.
 */
static PtTime secondsToTime(int totalSeconds) {
    if(totalSeconds < 0) return NULL;

    int hours = totalSeconds / 3600;
    totalSeconds = totalSeconds % 3600;
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;

    return timeCreate(hours, minutes, seconds);
}

PtTime timeCreate(int hour, int minute, int second) {
    if(hour > 23 || hour < 0) return NULL;
    if(minute > 59 || minute < 0) return NULL;
    if(second > 59 || second < 0) return NULL;

    PtTime new = (PtTime)malloc(sizeof(Time)); 
    if(new == NULL) return NULL; // or if(!new)

    new->hours = hour;
    new->minutes = minute;
    new->seconds = second;

    return new;
}

int timeDestroy(PtTime *ptT) {
    if (ptT == NULL || *ptT == NULL) return TIME_NULL;
    
    free(*ptT);
    *ptT = NULL;

    return TIME_OK;
}

int timeGetHour(PtTime t, int *hour) {
    if (t == NULL || hour == NULL) return TIME_NULL;
    *hour = t->hours;
    return TIME_OK;
}

int timeGetMinute(PtTime t, int *minute) {
    if (t == NULL || minute == NULL) return TIME_NULL;
    *minute = t->minutes;
    return TIME_OK;
}

int timeGetSecond(PtTime t, int *second) {
    if (t == NULL || second == NULL) return TIME_NULL;
    *second = t->seconds;
    return TIME_OK;
}

int timeToSeconds(PtTime t, int *totalSeconds) {
    if (t == NULL || totalSeconds == NULL) return TIME_NULL;
    
    *totalSeconds = 3600 * t->hours + 60 * t->minutes + t->seconds;

    return TIME_OK;
}

PtTime timeAdd(PtTime t1, PtTime t2) {
    if (t1 == NULL || t2 == NULL) return NULL;

    //int t1Seconds = 3600 * t1->hours + 60 * t1->minutes + t1->seconds;
    //int t2Seconds = 3600 * t2->hours + 60 * t2->minutes + t2->seconds;

    int t1Seconds, t2Seconds;
    timeToSeconds(t1, &t1Seconds);
    timeToSeconds(t2, &t2Seconds);

    int total = t1Seconds + t2Seconds;

    // Edge case: if the sum overflows 24h, subtract those 24h (rollover).
    if(total >= DAY_TO_SECONDS) {
        total = total - DAY_TO_SECONDS;
    }

    /*
    int hours = total / 3600;
    total = total % 3600;
    int minutes = total / 60;
    int seconds = total % 60;

    return timeCreate(hours, minutes, seconds);
    */

    return secondsToTime(total);
}

PtTime timeDiff(PtTime t1, PtTime t2) {
    if (t1 == NULL || t2 == NULL) return NULL;
    
    int t1Seconds, t2Seconds;
    timeToSeconds(t1, &t1Seconds);
    timeToSeconds(t2, &t2Seconds);

    int total = t1Seconds - t2Seconds;

    // Edge case: if difference is negative, it means we rollback a day
    // Imagine the clock arms going back midnight...
    if(total < 0) {
        total = DAY_TO_SECONDS + total; // 'total' is negative, the value will be subtracted
    }

    return secondsToTime(total);
}

void timePrint(PtTime t) {
    if (t == NULL) {
        printf("(NULL TIME)\n");
        return;
    }

    // Print in hh:mm:ss format
    printf("%02d:%02d:%02d\n", t->hours, t->minutes, t->seconds);
}
