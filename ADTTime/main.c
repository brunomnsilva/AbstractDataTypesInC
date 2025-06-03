#include <stdio.h> 
#include <stdlib.h>
#include "mytime.h"

int main() {

    /*
    Problem Statement:
    Maria clocked in at work at 9:22:40 and clocked out at 17:40:02.
    How long did she work, and did she meet the mandatory requirement of working eight hours per day?
    If she worked extra time, at what time can she clock in tomorrow?
    */

    PtTime in = timeCreate(9, 22, 40); // Assume allocation OK
    PtTime out = timeCreate(17, 40, 2);

    PtTime workTime = timeDiff(out, in);

    printf("Worked for: ");
    timePrint(workTime);

    int workHours;
    timeGetHour(workTime, &workHours);
    if(workHours >= 8) {
        printf("✅ Met the mandatory eight hours.\n");

        // Quanto tempo trabalhou a mais? Vamos subtrair 8h ao total trabalhado
        PtTime eightHours = timeCreate(8, 0, 0);
        PtTime additional = timeDiff(workTime, eightHours);

        printf("Additional work time: ");
        timePrint(additional);

        PtTime nineHours = timeCreate(9, 0, 0);
        PtTime tomorrowIn = timeAdd(nineHours, additional);

        printf("Tomorrow can clock in at: ");
        timePrint(tomorrowIn);

        timeDestroy(&eightHours);
        timeDestroy(&additional);
        timeDestroy(&nineHours);
        timeDestroy(&tomorrowIn);

    } else {
        printf("❌ Did not meet the mandatory eight hours.\n");
    }

    timeDestroy(&in);
    timeDestroy(&out);
    timeDestroy(&workTime);

    return EXIT_SUCCESS;
}
