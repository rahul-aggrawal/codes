#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t mutex,rw_mutex;
int data = 0,rcount = 0;

void *reader(void *arg)
{
        int f;
        f = ((int)arg);
        
        sem_wait(&mutex);
        rcount++;
        if(rcount==1)
           sem_wait(&rw_mutex);
           
        sem_post(&mutex);
        
        printf("Data read by the reader%d is %d\n",f,data);
        sleep(1);
        
        sem_wait(&mutex);
        rcount--;
        if(rcount==0)
           sem_post(&rw_mutex);
        sem_post(&mutex);
}

void *writer(void *arg)
{
        int f;
        f = ((int) arg);
        sem_wait(&rw_mutex);
        data++;
        printf("Data writen by the writer%d is %d\n",f,data);
        sleep(1);
        sem_post(&rw_mutex);
}

int main()
{
        int i; 
        pthread_t rid[5],wid[5];
        sem_init(&mutex,0,1);
        sem_init(&rw_mutex,0,1);
        for(i=0;i<5;i++)
	{
                pthread_create(&wid[i],NULL,writer,(void *)i);
                pthread_create(&rid[i],NULL,reader,(void *)i);
        }
        for(i=0;i<5;i++)
	{
                pthread_join(wid[i],NULL);
                pthread_join(rid[i],NULL);
        }
        pthread_exit(NULL);
        return 0;
}
