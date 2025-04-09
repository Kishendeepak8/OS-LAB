#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int philosophers[MAX] = {0};
int hungryList[MAX];
int hungryCount = 0;

void allow_one_to_eat() {
    printf("allow one philosopher to eat at any time\n");
    for (int i = 0; i < hungryCount; i++) {
        int p = hungryList[i];
        printf("P %d is waiting\n", p);
    }

    for (int i = 0; i < hungryCount; i++) {
        int p = hungryList[i];
        printf("P %d is granted to eat\n", p);
        printf("P %d has finished eating\n", p);
        for (int j = 0; j < hungryCount; j++) {
            int other = hungryList[j];
            if (j != i) printf("P %d is waiting\n", other);
        }
    }
}
void allow_two_to_eat() {
    printf("allow two philosophers to eat at any time\n");
    for (int i = 0; i < hungryCount; i++) {
        printf("P %d is waiting\n", hungryList[i]);
    }
    int i = 0;
    while (i < hungryCount) {
        if (i + 1 < hungryCount) {
            printf("P %d is granted to eat\n", hungryList[i]);
            printf("P %d is granted to eat\n", hungryList[i+1]);
            printf("P %d has finished eating\n", hungryList[i]);
            printf("P %d has finished eating\n", hungryList[i+1]);
            i += 2;
        } else {
            printf("P %d is granted to eat\n", hungryList[i]);
            printf("P %d has finished eating\n", hungryList[i]);
            i++;
        }

        for (int j = i; j < hungryCount; j++) {
            printf("P %d is waiting\n", hungryList[j]);
        }
    }
}
int main() {
    int total, choice;
    printf("enter the total number of philosophers: ");
    scanf("%d", &total);

    printf("how many are hungry: ");
    scanf("%d", &hungryCount);

    for (int i = 0; i < hungryCount; i++) {
        int pos;
        printf("enter philosopher %d position (1 to %d): ", i + 1, total);
        scanf("%d", &pos);
        hungryList[i] = pos;
        philosophers[pos - 1] = 1;
    }

    do {
        printf("\n1. one can eat at a time\n");
        printf("2. two can eat at a time\n");
        printf("3. exit\n");
        printf("enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                allow_one_to_eat();
                break;
            case 2:
                allow_two_to_eat();
                break;
            case 3:
                printf("exiting\n");
                break;
            default:
                printf("invalid choice\n");
        }
    } while (choice != 3);

    return 0;
}


