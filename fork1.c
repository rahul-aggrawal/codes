#include  <stdio.h>
#include  <string.h>
#include  <sys/types.h>
#include  <signal.h>

void main()
{
	int p=fork();
	printf("Child id=%d\n",getpid());
	printf("Parent id=%d\n",getppid());	
}
