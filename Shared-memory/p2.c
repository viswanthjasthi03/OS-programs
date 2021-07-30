#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>


int *count;

int main()
{
    int shmd;
    shmd = shm_open("/file", O_RDWR | O_CREAT, S_IRUSR| S_IWUSR);
   ftruncate(shmd, sizeof(int));
    count = (int *)mmap(NULL, sizeof(int), PROT_READ|PROT_WRITE, MAP_SHARED, shmd, 0);

    while(1)
    {
      printf("count:%d\n", *count);
      sleep(1);
    }
    return 0;
}