#include<semaphore.h>
#include<pthread.h>
#include<stdio.h>
#define N 5

sem_t c[N];

void *philo(void *p)
{
        int i=(int)p;
        sem_wait(&c[i]);
        sem_wait(&c[(i+1)%N]);
        
        printf("Philosopher %d eats\n",i);
        sleep(1);
        
        sem_post(&c[i]);
        sem_post(&c[(i+1)%N]);
       
}

void main()
{
       int i,a;
       pthread_t p[N];
       
       for(i=0;i<N;i++)
               sem_init(&c[i],0,1);
       for(i=0;i<N;i++)
                pthread_create(&p[i],NULL,philo,(void *)i);
       
       for(i=0;i<N;i++)
               pthread_join(p[0],NULL);
}
