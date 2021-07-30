
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <unistd.h>

#define size 100
int main()
{
    pid_t id;
    int pfd[2];
    int pfdr[2];
unsigned char buff[size];
unsigned char buff1[size];
    pipe(pfd);
    pipe(pfdr);
    id=fork();

    if(id == 0)
    {
        printf("Child process\n");
        close(pfd[1]);
        read(pfd[0],  buff, size);
        printf("The data from the parent is %s\n",buff);
        close(pfd[0]);

        close(pfdr[0]);
        write(pfdr[1], "hii\n", 4);
        close(pfdr[1]);
    }
    else
    {
        printf("Parent process\n");
        close(pfd[0]);
        write(pfd[1], "hii viswanth\n" ,13);
        close(pfd[1]);

        close(pfdr[1]);
        read(pfdr[0], buff1, size);
        printf("The data from the child is %s\n",buff1);
        close(pfdr[0]);
    }
}