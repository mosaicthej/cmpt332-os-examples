#include "fib.h"
int* invokeCounterArr;
int counterInd;

int fib(int x){
	invokeCounterArr[counterInd] += 1; /* increment the counter for each recursive call */
	if (x==0){
		return 0;
	
	} else if (x==1) {
		return 1;
	
	} else {
		return fib(x-1) + fib(x-2);
	}
}

