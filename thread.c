#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

void *generatePrimeNumbers(void* param);

typedef struct {
    pthread_t threadId;
    int upToN;
} thread_argument;

int main(void) {
    int input;
    printf("Ingrese número de primos: ");
    scanf("%d", &input);

    int thread_length = 2;

    pthread_t ids[thread_length];
    thread_argument* arg1 = malloc(sizeof(thread_argument));
    thread_argument* arg2 = malloc(sizeof(thread_argument));

    arg1->upToN = input;
    arg2->upToN = input;

    pthread_create(&arg1->threadId, NULL, generatePrimeNumbers, arg1);
    pthread_create(&arg2->threadId, NULL, generatePrimeNumbers, arg2);

    pthread_join(arg1->threadId, NULL);
    pthread_join(arg2->threadId, NULL);

    free(arg1);
    free(arg2);
    printf("Fin.\n");

}


void *generatePrimeNumbers(void *param) {
    thread_argument *arg = (thread_argument *) param;
    int num = 2;
    int limit = 1;

    while (limit <= arg->upToN) {
        int coeficient = 0;

        for(int factor = 1; factor <= num; factor++) {
            if (num % factor == 0) {
                coeficient ++;
            }
        }

        if (coeficient  == 2) {
            limit++;
            printf("Thread %d: El número %d es primo.\n", arg->threadId, num);
        }
        num++;
    }
}
