//
// Created by 何永康 on 2024-02-15.
//

/*
LINE A value = 5
LINE B value = 5
LINE D value = 0
LINE E value = 0
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

int value = 0;
void *runner(void *param);
int main(int argc, char *argv[])
{
    pid_t pid;
    pthread_t tid;
    pthread_attr_t attr;
    pid = fork();
    if (pid == 0) {
        pthread_attr_init(&attr);
        pthread_create(&tid,&attr,runner,NULL);
        pthread_join(tid,NULL);
        printf("LINE A value = %d\n",value);
        char buffer[100];
        sprintf(buffer, "LINE B value = %d",value);
        execlp("echo","echo",buffer,NULL);
        printf("LINE C value = %d\n",value);
    }
    else if (pid > 0) {
        wait(NULL);
        printf("LINE D value = %d\n",value);
    }
    printf("LINE E value = %d\n", value);

}

void *runner(void *param) {
    value += 5;
    pthread_exit(0);
}