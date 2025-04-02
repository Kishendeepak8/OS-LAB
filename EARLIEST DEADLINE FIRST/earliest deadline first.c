
#include <stdio.h> #include <stdlib.h> #include <math.h>

#define MAX_PROCESSES 10

int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }

int lcm(int a, int b) { return (a * b) / gcd(a, b); }

int is_schedulable(int n, float utilization) { return utilization <= 1.0; }

void earliest_deadline_first(int n, int exec_time[], int deadline[], int period[]) { int hyperperiod = period[0]; for (int i = 1; i < n; i++) { hyperperiod = lcm(hyperperiod, period[i]); }

int remaining_time[MAX_PROCESSES] = {0};
int next_deadline[MAX_PROCESSES];
for (int i = 0; i < n; i++) {
    next_deadline[i] = deadline[i];
}

printf("\nScheduling Timeline:\n");
for (int time = 0; time < hyperperiod; time++) {
    int earliest = -1;
    for (int i = 0; i < n; i++) {
        if (time % period[i] == 0) {
            remaining_time[i] = exec_time[i];
            next_deadline[i] = time + deadline[i];
        }
        if (remaining_time[i] > 0 && (earliest == -1 || next_deadline[i] < next_deadline[earliest])) {
            earliest = i;
        }
    }

    if (earliest != -1) {
        printf("Time %d: Task %d is executing\n", time, earliest + 1);
        remaining_time[earliest]--;
    } else {
        printf("Time %d: Idle\n", time);
    }
}

}

int main() { int n; int exec_time[MAX_PROCESSES], deadline[MAX_PROCESSES], period[MAX_PROCESSES]; float utilization = 0.0;

printf("Enter the number of tasks: ");
scanf("%d", &n);

for (int i = 0; i < n; i++) {
    printf("Enter execution time, deadline, and period for Task %d: ", i + 1);
    scanf("%d %d %d", &exec_time[i], &deadline[i], &period[i]);
    utilization += (float)exec_time[i] / period[i];
}

if (is_schedulable(n, utilization)) {
    printf("\nTasks are schedulable using Earliest-Deadline-First Scheduling.\n");
    earliest_deadline_first(n, exec_time, deadline, period);
} else {
    printf("\nTasks are NOT schedulable using Earliest-Deadline-First Scheduling.\n");
}

return 0;

}\
