
#include<stdio.h>
#include<pthread.h>



void *thread(void *data)
{
    printf("In Thread\n");
}


int main()
{
    pthread_t pr_tid;
    printf("Before Thread\n");
    pthread_create(&pr_tid, NULL, thread, NULL);
    printf("After Thread\n");
    pthread_join(pr_tid, NULL);
    printf("Thread joined\n");

    return 0;
}