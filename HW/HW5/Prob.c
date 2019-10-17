//Ryan Kelly
//2/23/2019
//CS283_HW5


#include "csapp.h"
#define N 2
#define LEN 100

int main(){

	int status, i;
	pid_t pid;

	//Parent creates N children
	for (i=0; i<N; i++)
		if( i == 0){
			printf("Installing Null Pointer\n");
			exit(0);

			if ((pid = Fork()) == 0){
				char* cptr = NULL;
				*cptr = 'd';
			}
		}

	// Parents reaps N children in no particular order
	while ((pid = waitpid(-1, &status, 0)) > 0){

		if(WIFEXITED(status))
			printf("child %d terminated normally with exit status=%d\n", pid, WEXITSTATUS(status));

		else if (WIFSIGNALED(status)){
			char buf[LEN];
			sprintf(buf, "child %d terminated by signal %d",pid, WTERMSIG(status));
			psignal(WTERMSIG(status), buf);
		}

		else
			printf("child %d terminated abnormally\n", pid);
	}

	//The only normal termination is if there are no more children
	if (errno != ECHILD)
		unix_error("Waitpid error");
	exit(0);
}

