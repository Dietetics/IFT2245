//
// Created by 何永康 on 2024-02-14.
//
#include <stdio.h>
#include <unistd.h>  // Include this for fork()
#include <sys/wait.h>  // Include this for wait()
#include <pthread.h> // Ajout de cette ligne pour inclure pthread

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
