

#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>

sem_t sem_count;
int count=0;;

int *Incthread(void *data)
{
    while(1)
    {
    sem_wait(&sem_count);
    count++;
    printf("Inc Thread=%d\n",count);
    sem_post(&sem_count);
    }
}

int *Decthread(void *data)
{
    while(1)
    {
    sem_wait(&sem_count);
    count--;
    printf("Dec Thread=%d\n",count);
    sem_post(&sem_count);
    }
}

int main()
{
    pthread_t pr1_tid, pr2_tid;
    sem_init(&sem_count, 0, 1);
    pthread_create(&pr1_tid, NULL, Incthread, NULL);
    pthread_create(&pr2_tid, NULL, Decthread, NULL);
    pthread_join(pr1_tid, NULL);
    pthread_join(pr2_tid, NULL);
    sem_destroy(&sem_count);
}