#include <unistd.h>
#include <stdio.h>


int main()
{
    printf("Before exec\n");
    execl("/Desktop/cdac/eos/practise/Native/main", "/Desktop/cdac/eos/practise/Native/main", NULL);
    printf("\nAfter exec\n");
    return 0;   
}