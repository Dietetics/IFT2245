//
// Created by 何永康 on 2024-02-14.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

int value = 5;
void *runner(void *param);
pthread_mutex_t lock;

int main(int argc, char *argv[]) {
    pid_t pid;
    pthread_t tid;
    pthread_attr_t attr;
    pid = fork();
    if (pid == 0) {
        pid_t pid2;
        pid2 = fork();
        if (pid2 == 0) {
            pthread_attr_init(&attr);
            pthread_create(&tid, &attr, runner, NULL);
            pthread_join(tid, NULL);
        } else {
            waitpid(pid2, NULL, 0);
        }
        printf("LINE A, value=%d\n", value);
    } else {
        waitpid(pid, NULL, 0);
    }
    printf("LINE B, value=%d\n", value);
}
void *runner(void *param) {
    value += 5;
    pthread_exit(0);
}