#include<pthread.h>
#include<signal.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

//this is signal function.
void *sig_func()
{
printf("this is signal\n");
}

//this is thread function
void *thread_func()
{
	struct sigaction sa;
	memset(&sa,sizeof(sa),0);
	sleep(5);
	sa.sa_handler=sig_func();
	sigaction(SIGINT,&sa,NULL);
	printf("this is thread:%ld\n",pthread_self);
}

int main()
{
pthread_t tid; //id of thread.
pthread_create(&tid,NULL,&thread_func,NULL); //creating of thread.
pthread_join(tid,NULL);   //joining of thread with main.
pthread_kill(tid,SIGINT); //creating interrupt in thread.
return 0;
}


