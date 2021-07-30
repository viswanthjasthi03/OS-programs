
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
int fp;
fp = open("desd.txt",O_WRONLY|O_CREAT);
write(fp, "viswanth\n", 9);
close(fp);
return 0;
}