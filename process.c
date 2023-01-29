#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>

void generatePrimeNumbers(int, int);

int main(void) {
    int input;
    printf("Ingrese número de primos: ");
    scanf("%d", &input);
    pid_t pid = fork();

    generatePrimeNumbers(input, getpid());

}


void generatePrimeNumbers(int n, pid_t pid) {
    int num = 2;
    int limit = 1;

    while (limit <= n) {
        int coeficient = 0;

        for(int factor = 1; factor <= num; factor++) {
            if (num % factor == 0) {
                coeficient ++;
            }
        }

        if (coeficient  == 2) {
            limit++;
            printf("Process %d: El número %d es primo.\n", pid, num);
        }
        num++;
    }


}
