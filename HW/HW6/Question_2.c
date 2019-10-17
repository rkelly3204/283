//Ryan Kelly
//3/8/2019
//CS283
//
//This is Question 12.17 imp


#include "csapp.h"

void *thread(void *vargp);

int main()
{
	pthread_t tid;

	Pthread_create(&tid, NULL, thread, NULL);
	Pthread_exit(NULL);
}

//Thread routine

void *thread(void *vargp)
{
	Sleep(1);
	printf("Hello, world!\n");
	return NULL;
}

