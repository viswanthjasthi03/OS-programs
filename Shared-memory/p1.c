
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>     
#include <fcntl.h>    
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int num;
int *count;

int main()
{
    int shmd;
    shmd = shm_open("/file", O_RDWR | O_CREAT, S_IRUSR| S_IWUSR);
    ftruncate(shmd, sizeof(int));
    count = (int *)mmap(NULL, sizeof(int), PROT_READ|PROT_WRITE, MAP_SHARED, shmd, 0);

    while(1)
    {
        printf("Enter the number:");
        scanf("%d",&num);
        *count = num;
    }
    return 0;
}

