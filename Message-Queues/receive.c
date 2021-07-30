#include <stdio.h>
#include <fcntl.h>           
#include <sys/stat.h> 
#include <mqueue.h>
#include <string.h>

mqd_t cdacmq;
struct mq_attr cdacmq_attr;
char buff[128];
int msg_prio;
int stringlen;

int main()
{
    cdacmq_attr.mq_flags = 0;
    cdacmq_attr.mq_maxmsg = 4;
    cdacmq_attr.mq_msgsize = 128;
    cdacmq_attr.mq_curmsgs = 0;

    cdacmq = mq_open("/file", O_RDONLY, &cdacmq_attr);

    mq_receive(cdacmq, buff, 128, &msg_prio);
    printf("The received Data=%s\n Msg prio=%d\n", buff, msg_prio);
    stringlen = strlen(buff);
    printf("String lenght = %d\n", stringlen);

    mq_close(cdacmq);

    return 0;
}
