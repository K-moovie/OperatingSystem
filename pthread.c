#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int result; // this data is shared by the threads
void *runner(void *param); // threadscall this function
int Fibonacci(int num);

int main (int argc, char *argv[]){
	
	if (atoi(argv[1]) <= 0) {
	printf("Re-enter positive numbers!!\n");
	return 1;
	}
	
	pthread_t tid; // the thread identifier
	pthread_attr_t attr; // set of thread attributes
	// set the default attributes of the thread
	pthread_attr_init(&attr);
	// create the thread
	pthread_create(&tid, &attr, runner, argv[1]);
	// wait for the thread to exit
	pthread_join(tid, NULL);

	printf("Fibonacci: %d\n", result);
}

//The thread will execute in this function
void *runner(void *param){
	/*int i, upper = atoi(param);
	result = 0;
	for(i = 1; i <= upper; i++)
		result += i;
	*/
	
	result = Fibonacci(atoi(param));

	pthread_exit(0);
}

int Fibonacci(int num){
	if (num == 1)
		return 0;
	else if(num == 2)
		return 1;
	else
		return Fibonacci(num-2) + Fibonacci(num-1);
}
