//
// Created by 何永康 on 2024-02-13.
//
#include <stdio.h>
#include <unistd.h>  // Include this for fork()
#include <sys/wait.h>  // Include this for wait()

int main()
{
    pid_t pid;

    /* fork a child process */
    pid = fork();


    if (pid < 0) { /* error occurred */
        fprintf(stderr, "Fork Failed\n");
        return 1;
    }
    else if (pid == 0) { /* child process */
        printf("I am the child %d\n",pid);
    }
    else { /* parent process */
        printf("I am the parent %d\n",pid);
        /* parent will wait for the child to complete */

        wait(NULL);

        printf("Child Complete\n");
    }

    printf("After the if \n");

    return 0;
}
