#include <stdio.h>
#include <fcntl.h>           
#include <sys/stat.h> 
#include <mqueue.h>

mqd_t cdacmq;
struct mq_attr cdacmq_attr;


int main()
{
    cdacmq_attr.mq_flags = 0;
    cdacmq_attr.mq_maxmsg = 4;
    cdacmq_attr.mq_msgsize = 128;
    cdacmq_attr.mq_curmsgs = 0;

    cdacmq = mq_open("/file", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR, &cdacmq_attr);

   mq_send(cdacmq, "viswanth\n", 9, 0);

    mq_close(cdacmq);

    return 0;
}
