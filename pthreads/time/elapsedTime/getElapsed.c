/*
    example shows how to get the elapsed time between two events
    in this exmaple, use sleep() to simulate an event
    have a start time, and an end time
    then get the elapsed time
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/*
    pass the time to sleep in seconds as an argument from the command line
    if no argument is passed, use 2 seconds
    the argument might be needs to be integer.
*/

int main(int argc, char *argv[])
{
    int sleepTime;
    time_t startTime, endTime;
    double elapsedTime;

    if (argc == 1)
    {
        sleepTime = 2;
    }
    else
    {
        sleepTime = atoi(argv[1]);
    }

    printf("sleeping for %d seconds\n", sleepTime);

    time(&startTime);
    sleep(sleepTime);
    time(&endTime);

    elapsedTime = difftime(endTime, startTime);
    /*
        precision is only to the three decimal places
    */
    printf("elapsed time: %.3f seconds\n", elapsedTime);

    return 0;
}
