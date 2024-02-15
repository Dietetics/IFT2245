#include <stdio.h>
#include <unistd.h>  // Include this for fork()
#include <sys/wait.h>  // Include this for wait()
#include "main.h"




int main()
{
    // exE1();
    // ex1();
    // ex2();
    // ex3();
    ex4();
    return 0;
}



/* Considérez le code suivant et
 * supposez que le vrai PID de l’enfant est 1234 et
 * le vrai PID du parent est 5678
 * (la fonction getpid renvoie le PID du processus qui l'appelle)
 * */
void exE1() {
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