//
// Created by 何永康 on 2024-02-14.
//
#include <stdio.h>
#include <unistd.h>  // Include this for fork()
#include <sys/wait.h>  // Include this for wait()
#include <stdlib.h> // Pour inclure exit()
#include <pthread.h> // Ajout de cette ligne pour inclure pthread


int main(int argc, char *argv[]) {
    printf("hello world (pid:%d)\n", (int) getpid()); int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("Child (pid:%d)\n", (int) getpid());
        sleep(1); } else {
        wait(NULL);
        printf("Parent of %d (pid:%d)\n", rc, (int) getpid()); }
    return 0; }
