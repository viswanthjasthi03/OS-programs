
#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>

int a,b,sum;
sem_t s1,s2;

int *input(void *data)
{
    while(1)
    {
    sem_wait(&s1);
    printf("Enter the value of a:");
    scanf("%d",&a);
    printf("Enter the value of b:");
    scanf("%d",&b);
    sem_post(&s2);
    }
}

int *process(void *data)
{
    while(1)
    {
    sem_wait(&s2);
    sum=a+b;
    printf("Sum=%d\n",sum);
    sem_post(&s1);
    }
}

int main()
{
    pthread_t input_tid, process_tid;
    sem_init(&s1, 0, 1);
    sem_init(&s2, 0, 0);
    pthread_create(&input_tid, NULL, input, NULL);
    pthread_create(&process_tid, NULL, process, NULL);
    pthread_join(input_tid, NULL);
    pthread_join(process_tid, NULL);
    sem_destroy(&s1);
    sem_destroy(&s2);
}
