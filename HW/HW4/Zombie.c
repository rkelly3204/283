//A C program to demonstrate Orphan Process
//Parent Process finshes execution while the 
//child process is running. The child process
//becomes orphan.

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main()
{
	//Create a child process
	int pid = fork();

	if (pid > 0)
		printf("inparent process\n");

	//Note that pid is 0 in child process
	// and negative if fork() fails
	else if (pid == 0)
	{
		sleep(30);
		printf("in child process\n");
	}

	return 0;
}

