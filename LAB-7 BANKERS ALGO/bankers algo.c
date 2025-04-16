#include <stdio.h>
#include <stdbool.h>
#define MAX_P 10
#define MAX_R 10
int allocation[MAX_P][MAX_R], max[MAX_P][MAX_R], need[MAX_P][MAX_R];
int available[MAX_R], request[MAX_R];
int processes, resources;

void calculateNeed() {
    for (int i = 0; i < processes; i++)
        for (int j = 0; j < resources; j++)
            need[i][j] = max[i][j] - allocation[i][j];
}

bool isSafe(int safeSeq[], bool verbose) {
    bool finish[MAX_P] = {false};
    int work[MAX_R];
    for (int i = 0; i < resources; i++)
        work[i] = available[i];

    int count = 0;
    while (count < processes) {
        bool found = false;
        for (int p = 0; p < processes; p++) {
            if (!finish[p]) {
                bool canProceed = true;
                for (int j = 0; j < resources; j++) {
                    if (need[p][j] > work[j]) {
                        canProceed = false;
                        break;
                    }
                }

                if (canProceed) {
                    for (int k = 0; k < resources; k++)
                        work[k] += allocation[p][k];
                    safeSeq[count++] = p;
                    finish[p] = true;

                    if (verbose) {
                        printf("P%d is visited( ", p);
                        for (int k = 0; k < resources; k++)
                            printf("%d ", work[k]);
                        printf(")\n");
                    }

                    found = true;
                }
            }
        }
        if (!found)
            return false;
    }
    return true;
}

bool requestResources(int pid, int req[], int safeSeq[]) {
    for (int i = 0; i < resources; i++) {
        if (req[i] > need[pid][i]) {
            printf("Request exceeds maximum claim.\n");
            return false;
        }
        if (req[i] > available[i]) {
            printf("Resources not available.\n");
            return false;
        }
    }
    for (int i = 0; i < resources; i++) {
        available[i] -= req[i];
        allocation[pid][i] += req[i];
        need[pid][i] -= req[i];
    }

    bool safe = isSafe(safeSeq, true);
    if (!safe) {
        for (int i = 0; i < resources; i++) {
            available[i] += req[i];
            allocation[pid][i] -= req[i];
            need[pid][i] += req[i];
        }
    }

    return safe;
}
void printSystemState() {
    printf("\n%-8s %-12s %-12s %-12s\n", "Process", "Allocation", "Max", "Need");
    for (int i = 0; i < processes; i++) {
        printf("P%-7d", i);
        for (int j = 0; j < resources; j++)
            printf("%d ", allocation[i][j]);
        printf("\t     ");
        for (int j = 0; j < resources; j++)
            printf("%d ", max[i][j]);
        printf("\t     ");
        for (int j = 0; j < resources; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }

    printf("\nAvailable Resources: ");
    for (int i = 0; i < resources; i++)
        printf("%d ", available[i]);
    printf("\n");
}

int main() {
    printf("Enter number of processes: ");
    scanf("%d", &processes);

    printf("Enter number of resources: ");
    scanf("%d", &resources);

    for (int i = 0; i < processes; i++) {
        printf("\nEnter details for P%d\n", i);
        printf("Enter allocation: ");
        for (int j = 0; j < resources; j++)
            scanf("%d", &allocation[i][j]);

        printf("Enter Max: ");
        for (int j = 0; j < resources; j++)
            scanf("%d", &max[i][j]);
    }

    printf("\nEnter Available Resources: ");
    for (int i = 0; i < resources; i++)
        scanf("%d", &available[i]);

    calculateNeed();
    printSystemState();

    printf("\nEnter New Request Details --\n");
    int pid;
    printf("Enter pid: ");
    scanf("%d", &pid);

    printf("Enter Request for Resources: ");
    for (int i = 0; i < resources; i++)
        scanf("%d", &request[i]);

    int safeSeq[MAX_P];
    if (requestResources(pid, request, safeSeq)) {
        printf("\nSYSTEM IS IN SAFE STATE\n");
        printf("The Safe Sequence is -- ( ");
        for (int i = 0; i < processes; i++)
            printf("P%d ", safeSeq[i]);
        printf(")\n");
    } else {
        printf("\nSYSTEM IS NOT IN SAFE STATE\n");
    }

    return 0;
}


