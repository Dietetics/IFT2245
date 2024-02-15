#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

/* code ajuster dans deux parties pour eviter les inputs,
 * 1. upper_limit
 * 2. arg[1] vers null
 * */

#define UPPER_LIMIT 4 // Définir la limite supérieure pour le calcul de la somme

int sum; /* this data is shared by the thread(s) */

void *runner(void *param); /* the thread */

int main(int argc, char *argv[])
{
    pthread_t tid; /* the thread identifier */
    pthread_attr_t attr; /* set of attributes for the thread */

    /* get the default attributes */
    pthread_attr_init(&attr);

    /* create the thread */
    pthread_create(&tid,&attr,runner,NULL); // Passer NULL comme paramètre

    /* now wait for the thread to exit */
    pthread_join(tid,NULL);

    printf("sum = %d\n",sum);
    return 0;
}
/**
 * The thread will begin control in this function
 */
void *runner(void *param)
{
    int i, upper = UPPER_LIMIT; // Utiliser UPPER_LIMIT comme limite supérieure
    sum = 0;

    if (upper > 0) {
        for (i = 1; i <= upper; i++)
            sum += i;
    }

    pthread_exit(0);
}
