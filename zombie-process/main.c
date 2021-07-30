
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t id;

    id = fork();

if(id == 0)
{
    printf("Child process\n");
    printf("Child process pid=%d\n",getpid());
    printf("Child process ppid=%d\n",getppid());
}
else
{
    sleep(2);
    printf("Parent process\n");
    printf("Parent process pid=%d\n",getpid());
    printf("Parent process ppid=%d\n",getppid());
}
}

