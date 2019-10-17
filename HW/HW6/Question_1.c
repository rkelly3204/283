//Ryan Kelly
//3/8/2019
//CS283

//This is question 12.16 HW

#include <stdio.h>
#include <pthread.h>
#include "csapp.h"

void *thread(void *vargp);

#define DEFAULT 4

int main(int argc, char* argv[]){
	int N;
	if (argc > 2)
		unix_error("too many param");
	else if (argc == 2)
		N = atoi(argv[1]);
	else
		N = DEFAULT;

	int i;

	pthread_t tid;
	
	for (i = 0; i < N; i++){
		Pthread_create(&tid, NULL, thread, NULL);
	}
	Pthread_exit(NULL);
}
	
void *thread(void *vargp){

	printf("Hello, world\n");
	return NULL;
}

