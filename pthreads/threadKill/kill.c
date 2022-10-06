/*
    a parent thread creates n child threads
    the child threads increment a global counter in an infinite loop
    the parent threads sleep for timeout seconds
    then kills the child threads
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

/*
    global counter array (n counters for n threads)
*/

unsigned long *counter;

/*
    thread function
    increment the counter in an infinite loop
*/

void *threadFunction(void *arg)
{
    int threadNum = *(int *)arg;
    while (1)
    {
        counter[threadNum]++;
    }
}

/*
    parent thread function
    create n child threads
    sleep for timeout seconds
    then kill the child threads
*/
int parentThread(int threads, int timeout){
    int i;
    pthread_t *threadArray;
    int *threadNum;

    /*
        allocate memory for the threads
    */
    threadArray = (pthread_t *)malloc(threads * sizeof(pthread_t));

    /*
        allocate memory for the thread numbers
    */
    threadNum = (int *)malloc(threads * sizeof(int));

    /*
        allocate memory for the counters
    */
    counter = (unsigned long *)malloc(threads * sizeof(unsigned long));

    /*
        initialize the counters
    */
    for (i = 0; i < threads; i++)
    {
        counter[i] = 0;
    }

    /*
        create the threads
    */
    for (i = 0; i < threads; i++)
    {
        threadNum[i] = i;
        pthread_create(&threadArray[i], NULL, threadFunction, &threadNum[i]);
    }

    /*
        sleep for timeout seconds
    */

    sleep(timeout);

    /*
        kill the threads
    */

    for (i = 0; i < threads; i++)
    {
        pthread_cancel(threadArray[i]);
    }

    /*
        print the counters
    */

    for (i = 0; i < threads; i++)
    {
        printf("counter[%d] = %lu for thread %d\n", i, counter[i], threadNum[i]);

        if (counter[i] == 0)
        {
            printf(" (thread was killed before it could increment the counter)\n");
        }

    }

    /*
        free the memory
    */

    free(threadArray);
    free(threadNum);
    free(counter);
    
    return 0;
}


/*
    main function
    from command line, get:
        - number of threads
        - timeout
    pass to parent thread function
*/
int main(int argc, char *argv[])
{
    int numThreads;
    int timeout;

    if (argc != 3)
    {
        printf("usage: %s numThreads timeout (in seconds) \r ", argv[0]);
        return(1);
    }

    numThreads = atoi(argv[1]);
    timeout = atoi(argv[2]);

    /*
        calls parentThread function
    */
    parentThread(numThreads, timeout);

    return 0;
}