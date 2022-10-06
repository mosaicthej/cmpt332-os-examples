/*
create new pthreads
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


void *print_message_function( void *ptr );

/*
     a structure to pass arguments to print_message_function
     with 2 members
          - value 1,
          - value 2
*/
typedef struct thread_data{
     char* message;
     int  value1;
     int  value2;
} TDATA, *PTDATA;

/*
     pass how many threads to create as an argument from the command line
*/
int main(int argc, char* argv[])
{    
     
     int            i, rc;
     int            numThreads;
     pthread_t *    threads;
     PTDATA    *    threadData;

     if (argc == 1)
     {
          numThreads = 2;
     }
     else
     {
          numThreads = atoi(argv[1]);
     }

     printf("creating %d threads with pthread_create()\n", numThreads);

     /*
          allocate memory for the threads
     */
     threads = (pthread_t *)malloc(numThreads * sizeof(pthread_t));

     /*
          allocate memory for the thread data
     */
     threadData = (PTDATA *)malloc(numThreads * sizeof(PTDATA));
     /*
     initalize the thread data,
          - message is "message from thread %d" where %d is the thread number
          - value1 is the thread number
          - value2 is the thread number + 10
     */
     for (i = 0; i < numThreads; i++)
     {
          threadData[i] = (PTDATA)malloc(sizeof(TDATA));
          threadData[i]->message = (char *)malloc(100 * sizeof(char));
          sprintf(threadData[i]->message, "message from thread %d", i);
          threadData[i]->value1 = i;
          threadData[i]->value2 = i + 10;
     }

     /*
          create the threads
     */
     for (i = 0; i < numThreads; i++)
     {
          rc = pthread_create(&threads[i], NULL, print_message_function, (void *)threadData[i]);
          if (rc)
          {
               printf("ERROR; return code from pthread_create() is %d for thread %d", rc, i);
               exit(-1);
          }
     }

     /*
          wait for the threads to finish
     */
     for (i = 0; i < numThreads; i++)
     {
          pthread_join(threads[i], NULL);
     }

     /*
          free the memory
     */

     for (i = 0; i < numThreads; i++)
     {
          free(threadData[i]->message);
          free(threadData[i]);
     }
     free(threadData);
     free(threads);

     return 0;

}

/*
     squaring the value1 and value2
     print the message and the values
*/

void *print_message_function( void *ptr )
{    
     PTDATA data;
     int v1Squared, v2Squared;
     data = (PTDATA)ptr;
     v1Squared = data->value1 * data->value1;
     v2Squared = data->value2 * data->value2;
     printf("\nmessage: %s\n", data->message);
     printf("value1: %d, value1 square: %d\n", data->value1, v1Squared);
     printf("value2: %d, value2 square: %d\n", data->value2, v2Squared);
     pthread_exit(NULL);
}
