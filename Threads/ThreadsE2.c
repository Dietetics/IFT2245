#include <stdio.h>
#include <unistd.h>
#include <pthread.h> // Ajout de cette ligne pour inclure pthread

/* ajuster definir N and J
 * modifiant N And J avec un int, nous donnera un int
 * sinon erreur,
 * l idee de l exercice:
 * 1.comprendre value=value+value >>> 2^N J
 * 2.connaitre condition de cours; solution avec mutex


#define N 3 // Nombre de threads à créer
#define J 3  // Valeur initiale de la variable value

int value;
pthread_mutex_t mutex; // Déclaration du mutex

void *runner(void *param);

int main(int argc, char *argv[])
{
    value = J;
    pthread_t tid[N]; // Tableau des identifiants de thread
    pthread_attr_t attr; // Attributs de thread
    pthread_attr_init(&attr); // Initialisation des attributs de thread
    pthread_mutex_init(&mutex, NULL); // Initialisation du mutex

    for (int i = 0; i < N; i++) {
        pthread_create(&tid[i], &attr, runner, NULL);
    }
    for (int i = 0; i < N; i++) {
        pthread_join(tid[i], NULL);
    }
    printf("value = %d\n", value);

    pthread_mutex_destroy(&mutex); // Destruction du mutex
    pthread_attr_destroy(&attr); // Destruction des attributs de thread

    return 0;
}

void *runner(void *param)
{
    pthread_mutex_lock(&mutex); // Verrouillage du mutex avant d'accéder à value
    value = value + value;
    pthread_mutex_unlock(&mutex); // Déverrouillage du mutex après avoir modifié value
    pthread_exit(0);
}
