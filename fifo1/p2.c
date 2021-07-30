#include<stdio.h>
#include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <unistd.h>

#define size 100

int main()
{
    unsigned char buff[size];
    int fd;
    mkfifo("fifo", S_IRUSR|S_IWUSR);
    fd = open("fifo", O_RDONLY);
    read(fd, buff, size);
    printf("The data from the process1 is %s\n",buff);
    close(fd);
}
