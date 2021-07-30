
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define size 100
int main()
{
    int fp;
    unsigned char buff[size];
fp = open("desd.txt",O_RDONLY);
read(fp, buff, size);
printf("The data from the writefile=%s\n",buff);
close(fp);
return 0;
}
