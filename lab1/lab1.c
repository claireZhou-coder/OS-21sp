#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	// the variable for outputting random value
	int x; 

	//print Hello World!
	printf("Hello world! This s CS6233 Spring 2021\r\n"); 

	//set time as the seed of random value
	srand((unsigned)time(NULL)); 
	//between 0 and 99
	x = rand()%100; 
	printf("%d\n",x);

	return 0;
};