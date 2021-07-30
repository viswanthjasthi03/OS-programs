#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int data=0;
pthread_rwlock_t rwlock;


void *i2c(void *data)
{
    printf("I2C: Before Lock\n");
    pthread_rwlock_rdlock(&rwlock);
    printf("I2C: Got Locked\n");
    sleep(2);
    printf("I2C:%d\n",data);
    pthread_rwlock_unlock(&rwlock);
    printf("I2C: After Unlock\n");
}

void *uart(void *data)
{
    printf("UART: Before Lock\n");
    pthread_rwlock_wrlock(&rwlock);
    printf("UART: Got Locked\n");
    sleep(2);
    data++;
    printf("UART:%d\n",data);
    pthread_rwlock_unlock(&rwlock);
    printf("UART: After Unlock\n");
}

void *eth(void *data)
{
    printf("ETH: Before Lock\n");
    pthread_rwlock_rdlock(&rwlock);
    printf("ETH: Got Locked\n");
    sleep(2);
    printf("ETH:%d\n",data);
    pthread_rwlock_unlock(&rwlock);
    printf("ETH: After Unlock\n");
}

void *eeprom(void *data)
{
    printf("EEPROM: Before Lock\n");
    pthread_rwlock_wrlock(&rwlock);
    printf("EEPROM: Got Locked\n");
    sleep(2);
    data++;
    printf("EEPROM:%d\n",data);
    pthread_rwlock_unlock(&rwlock);
    printf("EEPROM: After Unlock\n");
}
int main()
{
    pthread_t pr_tid,pr1_tid,pr2_tid,pr3_tid;
    pthread_rwlock_init(&rwlock, NULL);
    pthread_create(&pr_tid, NULL, i2c, NULL);
    pthread_create(&pr1_tid, NULL, uart, NULL);
    pthread_create(&pr2_tid, NULL, eth, NULL);
    pthread_create(&pr3_tid, NULL, eeprom, NULL);
    pthread_join(pr_tid, NULL);
    pthread_join(pr1_tid, NULL);
    pthread_join(pr2_tid, NULL);
    pthread_join(pr3_tid, NULL);
    pthread_rwlock_destroy(&rwlock);
}