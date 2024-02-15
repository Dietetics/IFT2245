//
// Created by 何永康 on 2024-02-15.
//


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

/* Considérez le code suivant et
 * supposez que le vrai PID de l’enfant est 1234 et
 * le vrai PID du parent est 5678
 * (la fonction getpid renvoie le PID du processus qui l'appelle)
 * */

int main(int argc, char *argv[]) {
    pid_t pid, pid1, pid2;
    printf("1pid = %d \n", pid);
    printf("1pid1 = %d \n", pid1);
    printf("1pid2 = %d \n", pid2);
    printf("\n------------\n");

    pid1 = getpid();
    printf("2pid = %d \n", pid);
    printf("2pid1 = %d \n", pid1);
    printf("2pid2 = %d \n", pid2);
    printf("\n------------\n");

    pid = fork();
    printf("3pid = %d \n", pid);
    printf("3pid1 = %d \n", pid1);
    printf("3pid2 = %d \n", pid2);
    printf("\n------------\n");

    pid2 = getpid();
    printf("4pid = %d \n", pid);
    printf("4pid1 = %d \n", pid1);
    printf("4pid2 = %d \n", pid2);
    printf("\n------------\n");

    if (pid == 0) {
        printf("child: pid = %d \n", pid);
        printf("child: pid1 = %d \n", pid1);
        printf("child: pid2 = %d \n", pid2);
    } else {
        wait(NULL);
        printf("parent: pid = %d \n", pid);
        printf("parent: pid1 = %d \n", pid1);
        printf("parent: pid2 = %d \n", pid2);
    }
}