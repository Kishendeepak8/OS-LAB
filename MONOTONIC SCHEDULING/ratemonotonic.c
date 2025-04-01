#include <stdio.h>
#define MAX_TASKS 10
typedef struct {
    int id;
    int execution;
    int period;
} Task;

void sort_by_priority(Task tasks[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tasks[i].period > tasks[j].period) {

                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}

void rate_monotonic(Task tasks[], int n) {
    int time = 0;
    int completed = 0;
    while (completed < n) {
        int task_executed = -1;
        for (int i = 0; i < n; i++) {
            if (time % tasks[i].period == 0) {
                task_executed = i;
                break;
            }
        }
        if (task_executed != -1) {
            printf("At time %d: Task %d is executed\n", time, tasks[task_executed].id);
            time += tasks[task_executed].execution;
            completed++;
        } else {
            time++;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of tasks: ");
    scanf("%d", &n);
    Task tasks[n];
    for (int i = 0; i < n; i++) {
        tasks[i].id = i + 1;
        printf("\nEnter details for Task %d\n", i + 1);
        printf("Execution time (C): ");
        scanf("%d", &tasks[i].execution);
        printf("Period (T): ");
        scanf("%d", &tasks[i].period);
    }
    sort_by_priority(tasks, n);
    rate_monotonic(tasks, n);

    return 0;
}

