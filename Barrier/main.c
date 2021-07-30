
#include<stdio.h>
#include<pthread.h>
#include <unistd.h>


void *i2c(void *data)
{
    printf("I2C init Started\n");
    sleep(3);
    printf("I2C init Completed\n");
}

void *uart(void *data)
{
    printf("UART init started\n");
    sleep(5);
    printf("UART init Completed\n");
}

void *eth(void *data)
{
    printf("ETH init started\n");
    sleep(2);
    printf("ETH init Completed\n");
}

void *eeprom(void *data)
{
    printf("EEPROM init started\n");
    sleep(6);
    printf("EEPROM init Completed\n");
}

int main()
{
    pthread_t pr1_tid,pr2_tid,pr3_tid,pr4_tid;

    pthread_create(&pr1_tid, NULL, i2c, NULL);
    pthread_create(&pr2_tid, NULL, uart, NULL);
    pthread_create(&pr3_tid, NULL, eth, NULL);
    pthread_create(&pr4_tid, NULL, eeprom, NULL);
    pthread_join(pr1_tid, NULL);
    pthread_join(pr2_tid, NULL);
    pthread_join(pr3_tid, NULL);
    pthread_join(pr4_tid, NULL);

    return 0;
}