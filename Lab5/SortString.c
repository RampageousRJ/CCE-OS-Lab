#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{

	pid_t pidval = fork();
	int i, j;
	pid_t *turn;


	if(pidval == 0)
	{
		printf("ENTERING Child Process\n");
		printf("Sorted Orderc: ");
		for(i = 2; i < argc - 1; i++)
		{
			for(j = i + 1; j < argc; j++)
			{
				if(strcmp(argv[i], argv[j]) > 0)
				{
					char *temp = argv[i];
					argv[i] = argv[j];
					argv[j] = temp;
				}
			}
		}
		
		for(i = 2; i < argc; i++){
			printf("%s ", argv[i]);
		}
        printf("\nEXITING Child Process\n");
	}

	else if(pidval > 0)
	{
		wait(turn);
		printf("\nENTERING Parent Process\n");
		printf("Unsorted Order: ");
		for(i = 2; i < argc; i++){
			printf("%s ", argv[i]);
		}
        printf("\nEXITING Parent Process\n");
	}

	else
	{
		printf("Unsuccessful Fork Attempt...");
	}

	return 0;
}