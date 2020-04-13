#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int main()
{
	pid_t pid;
    int input = 0;
    int output = 0;
    //int shared_arr[2] = {0};
    // 자식 프로세스가 종료된 후 부모 프로세스에게 전달할 값을 기록할 배열
    //char buff[1024];
    //pipe(shared_arr);

    // 부모 프로세스 PID
    printf("Parent Process(PID: %d)\n", getpid());

    while (1) {
        printf("input: ");
        scanf("%d", &input);
        if (input>= 0)
        // 입력된 숫자가 음수이면  다시 입력을 받는다.
            break;
        printf("Please re-enter positive numbers!!\n");
        getchar();
    }

    // 자식 프로세스 생성
    pid = fork();
    if (pid < 0){
        fprintf(stderr, "Fork Failed!");
        return 1;
    }

    else if (pid == 0 ){
        printf("Child Process(PID: %d)\n", getpid());
        int i = 0;
        for(i = 1; i <= input; i++){
            output += i;
        }
        printf("Child Process Result: %d\n", output);
        //sprintf(buff, "%d", output);
        //write(shared_arr[1], buff, 1024);
    }

    else {
        wait(NULL);
        printf("Child Coplete\n");
        //read(shared_arr[0], buff, strlen(buff));
        //printf("Parent Process Result:%s\n", buff);
    }
	return 0;
}
