#include  <stdio.h>
#include  <string.h>
#include  <sys/types.h>
#include  <signal.h>

void main()
{
	int p=fork();	
	if(p==-1)
		printf("No child\n");
	else if(p==0)
	{
		printf("Child id=%d\n",getpid());
		sleep(5);
	}
	else
	{
		printf("Parent waiting\n");
		wait();
		printf("Parent waiting ended\n");
	}
}
