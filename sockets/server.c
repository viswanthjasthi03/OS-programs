#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<linux/in.h>

int cfd;
int sfd;
struct sockaddr_in saddr;
struct sockaddr_in caddr;

int len;
unsigned char buffer[1024];

int main()
{
    sfd = socket(AF_INET,SOCK_STREAM,0);
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    saddr.sin_port = htons(5678);
    bind(sfd,(struct sockaddr *)&saddr,sizeof(struct sockaddr_in));
    listen(sfd,10);
    len = sizeof(struct sockaddr_in);
    cfd = accept(sfd,(struct sockaddr *)&caddr, &len);
    
    write(cfd , "Hello S \n",8);
    read(cfd,buffer,1024);
    printf("CLient  sent: %s\n",buffer);
    close(sfd);
}