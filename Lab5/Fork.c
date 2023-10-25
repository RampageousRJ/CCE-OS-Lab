#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
	pid_t pidval=fork();

	if(pidval==0){
		printf("\nPID of Child Process:  %d\n",getpid());
        printf("PPID of Child Process:  %d\n",getppid());
    }
	else if(pidval>0){
		printf("\nPID of Parent Process: %d\n",getpid());
        printf("PPID of Parent Process: %d\n",getpid());
    }
    else{
        printf("\nFork Failed...");
    }
	return 0;
}