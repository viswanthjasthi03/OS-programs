
#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>


int main()
{
    printf("pid=%d\n",getpid());
    printf("ppid=%d\n",getppid());
    fork();
    printf("After fork pid=%d\n",getpid());
    printf("After fork ppid=%d\n",getppid());
    return 0;
}
