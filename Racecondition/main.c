#include<stdio.h>
#include<pthread.h>

int count=0;

void *Incthread(void *data)
{
    while(1)
    {
    count++;
    printf("Inc Thread=%d\n",count);
}
}

void *Decthread(void *data)
{
    while(1)
    {
   count--;
    printf("Dec Thread=%d\n",count);
}
}

int main()
{
    pthread_t pr_tid1, pr_tid2;
    pthread_create(&pr_tid1, NULL, Incthread, NULL);
    pthread_create(&pr_tid2, NULL, Decthread, NULL);
    pthread_join(pr_tid1, NULL);
    pthread_join(pr_tid2, NULL);
    
    return 0;
}