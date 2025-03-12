#include <stdio.h>
int main() {
    int n, i, j, temp, bt[20], p[20], wt[20], tat[20];
    float wtavg = 0, tatavg = 0;
    printf("enter total number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("enter burst time %d: ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    wt[0] = 0;
    tat[0] = bt[0];
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = tat[i - 1] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }
    wtavg /= n;
    tatavg /= n;

    printf("\nprocess\nburst time\nwaiting time\nturnaround time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }
    printf("\naverage waiting time = %.2f", wtavg);
    printf("\naverage turnaround time = %.2f", tatavg);

    return 0;
}
