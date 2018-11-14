#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
int buf[5],f,r;
sem_t mutex,full,empty;
void *produce(void *arg)
{
    int i;
    for(i=0;i<10;i++)
    {
        sem_wait(&empty);
        sem_wait(&mutex);
        printf("produced item is %d\n",i);
        buf[(++r)%5]=i;
        sem_post(&mutex);
        sem_post(&full);
    }
}
void *consume(void *arg)
{
        int item,i;
        for(i=0;i<10;i++)
	{
            sem_wait(&full);
            sem_wait(&mutex);
            item=buf[(++f)%5];
            printf("consumed item is %d\n",item);
            sem_post(&mutex);
            sem_post(&empty);
        }
}
int main()
{
    pthread_t p,c;
    sem_init(&mutex,0,1);
    sem_init(&empty,0,5);
    sem_init(&full,0,0);

    pthread_create(&p,NULL,produce,NULL);
    pthread_create(&c,NULL,consume,NULL);
    
    pthread_join(p,NULL);
    pthread_join(c,NULL);
}
