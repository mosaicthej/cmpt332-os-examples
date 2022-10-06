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
   int  value1;
   int  value2;
} TDATA, *PTDATA;


int main()
{
     pthread_t thread1, thread2;
     char *message1 = "Thread 1";
     char *message2 = "Thread 2";
     int  iret1, iret2;
     PTDATA thread_params;
     

     /* 
          init thread_data structure with values
     */

     /* Create independent threads each of which will execute function */
     iret1 = pthread_create( &thread1,
                             NULL,
                             print_message_function,
                             (void*) message1);
     /* Wait till threads are complete before main continues. Unless we  */
     /* wait we run the risk of executing an exit which will terminate   */
     /* the process and all threads before the threads have completed.   */

     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL); 

     printf("Thread 1 returns: %d Thread 2 returns: %d\n", iret1, iret2);
    return 0;
}

void *print_message_function( void *ptr )
{
     char *message;
     message = (char *) ptr;
     printf("message: %s\n", message);
     return 0;
}
