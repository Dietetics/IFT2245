#include <stdio.h>
#include <unistd.h>  // Include this for fork()
#include <sys/wait.h>  // Include this for wait()

int ex1();
int ex2();
int ex3();
int ex4();

int main()
{
    // ex1();
    // ex2();
    ex3();
    // ex4();
    return 0;
}


int ex1()
{
    pid_t pid;
    pid = fork();
    pid = fork();
    printf("bonjour \n"); // how many times with this get printed?
    return 0;
}



int ex2()
{
    pid_t pid;
    /* fork a child process */
    pid = fork();
    if (pid == 0) { /* child process */
        printf("I am the child %d\n",pid);
        execlp("ls","ls",NULL);
    }
    else { /* parent process */
        wait(NULL);
        printf("Child Complete\n");
    }
    printf("After the if\n");
    return 0;
}



int ex3()
{
    pid_t pid;
    int i = 1;
    int n = 3;
    for (;i<=n;){
        pid = fork();
        printf("bonjour \n"); // how many times with this get printed?
        i++;
    }
    return 0;
}


int ex4()
{
    pid_t pid;
    int value = 5;
    if(fork() == 0){
        value += 15;
        execlp("ls","ls",NULL);
        printf("Value = %d \n", value);
    }
    else {
        wait(NULL);
        printf("Value = %d \n", value);
    }
    printf("test \n");
    return 0;
}