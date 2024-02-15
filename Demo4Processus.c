//
// Created by 何永康 on 2024-02-14.
//
#include <stdio.h>
#include <unistd.h>  // Include this for fork()
#include <sys/wait.h>  // Include this for wait()
#include <stdlib.h> // Pour inclure exit()
#include <pthread.h> // Ajout de cette ligne pour inclure pthread

int main(int argc, char *argv[]) {
    int pid1 = fork();
    printf("Current (pid:%d)\n", (int) getpid()); if (pid1 == 0){
        printf("Executing ls -l (pid:%d)\n", (int) getpid());
        execlp("ls", "ls", "-l", NULL);
        printf("Finished executing ls -l (pid:%d)\n", (int) getpid());
    } else {
        wait(NULL);
        printf("Parent process (pid:%d)\n", (int) getpid()); }
    return 0; }