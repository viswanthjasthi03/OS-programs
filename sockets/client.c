#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<linux/in.h>

int cfd;
struct sockaddr_in saddr;
unsigned char buff[1024];

int main()
{
    cfd = socket(AF_INET,SOCK_STREAM,0);
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    saddr.sin_port = htons(5678);
    connect(cfd,(struct sockaddr *)&saddr,sizeof(struct sockaddr_in));
    read(cfd,buff,1024);
    printf("Server sent: %s\n",buff);
    write(cfd , "Hello C \n",8);
    close(cfd);
}