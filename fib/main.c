#include <stdio.h>
#include <stdlib.h>

#include "fib.h"

extern int counterInd;
extern int* invokeCounterArr;

int main(int argc, char *argv[]){
	int i;
	int *result;
	int m;
	int ctSize;
	
	/*counter = malloc(sizeof(int));
	*counter = 0;*/
	m = atoi(argv[1]);
	if (argc <=1){
		printf("please have some integer input\n");
		exit(1);
	}
	printf("line 22: invokeCounterArr is at %p\n", invokeCounterArr);
	ctSize=1;
	invokeCounterArr =(int *) malloc(sizeof(int)*ctSize);
	printf("line 25: invokeCounterArr is at %p\n", invokeCounterArr);
	counterInd = 0;

	/* initialize the counter arr*/
	invokeCounterArr[counterInd] = 0;
		
	result = (int *) malloc(m*sizeof(int));
	

	for (i=0; i<m; i++){
		/* *counter += 1;*/
		result[i] = fib(i);
		printf("fib of %d is %d\n", i, result[i]);
	}

	printf("result arr is:\n[ ");
	for (i=0; i<m; i++){
		printf("%d, ", result[i]);
	}
	printf("]\n");
	
	printf("fib() has been invoked %d times.\n", invokeCounterArr[counterInd]);
	return 0;
}
