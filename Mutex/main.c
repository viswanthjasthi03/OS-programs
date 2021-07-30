
#include<stdio.h>
#include<pthread.h>

int count=0;
pthread_mutex_t mutex_count;

void *Incthread(void *data)
{
    while(1)
    {
    pthread_mutex_lock(&mutex_count);
    count++;
    printf("Inc Thread=%d\n",count);
    pthread_mutex_unlock(&mutex_count);
}
}

void *Decthread(void *data)
{
    while(1)
    {
   pthread_mutex_lock(&mutex_count);
   count--;
    printf("Dec Thread=%d\n",count);
    pthread_mutex_unlock(&mutex_count); 
}
}

int main()
{
    pthread_t pr_tid1, pr_tid2;
    pthread_mutex_init(&mutex_count, NULL);
    pthread_create(&pr_tid1, NULL, Incthread, NULL);
    pthread_create(&pr_tid2, NULL, Decthread, NULL);
    pthread_join(pr_tid1, NULL);
    pthread_join(pr_tid2, NULL);
    pthread_mutex_destroy(&mutex_count);

    return 0;
}