#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#define N 2

sem_t seats,mutex;
int c=0;

void* student(void *arg)
{
    int id=((int)arg);
    sem_wait(&seats);
    sem_wait(&mutex);
    c++;
    if(c>0)
        printf("Professor is awake\n");
    printf("Student studies%d\n",id);
    sleep(5);
    sem_post(&mutex);
    c--;
    if(c==0)
        printf("Professor sleeps\n");
    sem_post(&seats);
}


int main()
{
    sem_init(&seats,0,N);
    sem_init(&mutex,0,1);
    pthread_t a[5];
    int i;
    for(i=0;i<5;i++)
        pthread_create(&a[i],0,student,(void*)i);
    for(i=0;i<5;i++)
        pthread_join(a[i],0);

}
