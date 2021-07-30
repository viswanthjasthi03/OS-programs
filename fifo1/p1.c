#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>



int main()
{
    int fd;
     mkfifo("fifo", S_IRUSR|S_IWUSR);
    fd = open("fifo", O_WRONLY);
    write(fd, "viswanth\n", 9);
    close(fd);
}
