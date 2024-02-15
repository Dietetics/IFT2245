#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

#define INPUT_VALUE 100 // Définir la valeur totale à utiliser pour le calcul
#define NUM_THREADS 4   // Définir le nombre de threads à utiliser

int sum; /* this data is shared by the thread(s) */

void *runner(void *endpoints); /* the thread */

struct interval {
    unsigned int start;
    unsigned int end;
};

int main(int argc, char *argv[])
{
    pthread_attr_t attr; /* set of attributes for the thread */
    pthread_t tid[NUM_THREADS]; /* the thread identifier */

    //...

    int num_threads = NUM_THREADS;
    int j;
    sum = 0;
    int start = 1;
    int input = INPUT_VALUE;
    int end = input / num_threads;

    for (j = 0; j < num_threads; j++) {
        /* get the default attributes */
        pthread_attr_init(&attr);
        struct interval *inter = malloc(sizeof(struct interval));
        inter->start = start;
        inter->end = end;
        pthread_create(&tid[j], &attr, runner, (void *)inter);

        start = end + 1;
        end = end + input / num_threads;
    }

    for (j = 0; j < num_threads; j++) {
        /* now wait for the thread to exit */
        pthread_join(tid[j], NULL);
    }

    printf("sum = %d\n", sum);
    return 0;
}

void *runner(void *input_interval)
{
    struct interval *inter = (struct interval *)input_interval;
    int i;

    printf("Start = %d, end = %d \n", inter->start, inter->end);

    for (i = inter->start; i <= inter->end; i++)
        sum += i;

    free(inter);
    pthread_exit(0);
}
