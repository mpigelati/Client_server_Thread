#include "stdio.h"
#include "pthread.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"

int i=10;
	
void *Fun_1(void *arg)
{
	for( ; ; )
	{	
		i++;
		printf("Thread_FUN_1 %d\n\r",i);
		sleep(3);
	}



}

void *Fun_2(void *arg)
{

	for( ; ; )
	{	
		i++;
		printf("Thread_FUN_2  %d\n\r",i);
		sleep(3);
	}


}


int main()

{

	pthread_t tid;

	int res;

	printf("before thread rate\n\r");
	res = pthread_create(&tid, NULL, Fun_1, NULL);
	if(res != 0)
	{
		perror("error in creating thread\n\r");
		exit(0);
	}
	res = pthread_create(&tid, NULL, Fun_2, NULL);

	if(res != 0)
	{
		perror("error in creating FUN2\n\r");
		exit(0);
	}
	pthread_join(tid, NULL);
	
	printf("After thread\n\r");

}
