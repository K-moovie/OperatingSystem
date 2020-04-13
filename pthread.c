#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int result; // this data is shared by the threads
int* fibo; // this data is shared by the threads
void *runner(void *param); // threadscall this function
int Fibonacci(int num);

int main (int argc, char *argv[]){
	int i = 0;
	if(atoi(argv[1]) <= 0) { // 입력 값 검사
		printf("Re-enter positive numbers!!\n");
		return 1;
	}
	fibo = (int*)malloc(sizeof(int)*atoi(argv[1]));	

	pthread_t tid; // the thread identifier
	pthread_attr_t attr; // set of thread attributes

	// set the default attributes of the thread
	pthread_attr_init(&attr);

	// create the thread
	pthread_create(&tid, &attr, runner, argv[1]);

	// wait for the thread to exit
	pthread_join(tid, NULL);

	printf("Fibonacci: ");
	for(i = 0; i < atoi(argv[1]); i++){
		printf("%d ",fibo[i]);
	}
	printf("\nParents exit\n");
}

//The thread will execute in this function
void *runner(void *param){
	printf("runner start\n");
	printf("Fibonacci start\n");
	
	Fibonacci(atoi(param));
	
	printf("Fibonacci exit\n");
	printf("runner exit\n");
	
	pthread_exit(0);
}

int Fibonacci(int num) {
	if(num == 1){
		fibo[num - 1] = 0;
		return 0;
	}
	else if(num == 2) {
		fibo[num - 1] = 1;
		return 1;
	}
	else {
		fibo[num - 1] = Fibonacci(num - 2) + Fibonacci(num - 1);
	}
		return Fibonacci(num - 2) + Fibonacci(num - 1);
}
