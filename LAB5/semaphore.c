#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;
int empty = 5;
int x = 0;

void wait(int *S) {
    (*S)--;
}

void signal(int *S) {
    (*S)++;
}

void producer() {
    if (mutex == 1 && empty > 0) {
        wait(&mutex);
        signal(&full);
        wait(&empty);
        x++;

        printf("producer has produced: Item %d\n", x);
        signal(&mutex);
    } else {
        printf("buffer is full\n");
    }
}

void consumer() {
    if (mutex == 1 && full > 0) {
        wait(&mutex);
        wait(&full);
        signal(&empty);

        printf("consumer has consumed: Item %d\n", x);
        x--;

        signal(&mutex);
    } else {
        printf("buffer is emptyki\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nenter 1.producer  2.consumer  3.exit\n");
        printf("enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: producer();
                    break;
            case 2: consumer();
                    break;
            case 3: exit(0);
            default: printf("invalid choice enter 1, 2, 3.\n");
        }
    }

    return 0;
}

