#include <stdio.h>

#define MAX 50

int search(int key, int frame[], int n) {
    for (int i = 0; i < n; i++)
        if (frame[i] == key)
            return 1;
    return 0;
}

int findLRU(int time[], int n) {
    int min = time[0], pos = 0;
    for (int i = 1; i < n; i++)
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    return pos;
}

void FIFO(int pages[], int n, int frames) {
    int frame[MAX], front = 0, count = 0;

    printf("\nFIFO Page Replacement Process:\n");
    for (int i = 0; i < frames; i++) frame[i] = -1;

    for (int i = 0; i < n; i++) {
        if (!search(pages[i], frame, frames)) {
            frame[front] = pages[i];
            front = (front + 1) % frames;
            count++;

            printf("PF No. %d: ", count);
            for (int j = 0; j < frames; j++)
                printf("%d ", frame[j]);
            printf("\n");
        }
    }

    printf("FIFO Page Faults: %d\n", count);
}

void LRU(int pages[], int n, int frames) {
    int frame[MAX], time[MAX], count = 0, timer = 0;

    printf("\nLRU Page Replacement Process:\n");
    for (int i = 0; i < frames; i++) frame[i] = -1;

    for (int i = 0; i < n; i++) {
        int flag = search(pages[i], frame, frames);
        if (!flag) {
            int pos = -1;
            for (int j = 0; j < frames; j++)
                if (frame[j] == -1) {
                    pos = j;
                    break;
                }

            if (pos == -1)
                pos = findLRU(time, frames);

            frame[pos] = pages[i];
            count++;

            printf("PF No. %d: ", count);
            for (int j = 0; j < frames; j++)
                printf("%d ", frame[j]);
            printf("\n");
        }

        for (int j = 0; j < frames; j++)
            if (frame[j] == pages[i])
                time[j] = ++timer;
    }

    printf("LRU Page Faults: %d\n", count);
}

int predict(int pages[], int n, int frame[], int frames, int index) {
    int farthest = index, pos = -1;
    for (int i = 0; i < frames; i++) {
        int j;
        for (j = index; j < n; j++) {
            if (frame[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }

        if (j == n)
            return i;
    }
    return (pos == -1) ? 0 : pos;
}

void Optimal(int pages[], int n, int frames) {
    int frame[MAX], count = 0;

    printf("\nOptimal Page Replacement Process:\n");
    for (int i = 0; i < frames; i++) frame[i] = -1;

    for (int i = 0; i < n; i++) {
        if (!search(pages[i], frame, frames)) {
            int pos = -1;
            for (int j = 0; j < frames; j++)
                if (frame[j] == -1) {
                    pos = j;
                    break;
                }

            if (pos == -1)
                pos = predict(pages, n, frame, frames, i + 1);

            frame[pos] = pages[i];
            count++;

            printf("PF No. %d: ", count);
            for (int j = 0; j < frames; j++)
                printf("%d ", frame[j]);
            printf("\n");
        }
    }

    printf("Optimal Page Faults: %d\n", count);
}

int main() {
    int pages[MAX], n, frames;

    printf("Enter the number of Frames: ");
    scanf("%d", &frames);
    printf("Enter the length of reference string: ");
    scanf("%d", &n);
    printf("Enter the reference string: ");
    for (int i = 0; i < n; i++) scanf("%d", &pages[i]);

    FIFO(pages, n, frames);
    LRU(pages, n, frames);
    Optimal(pages, n, frames);

    return 0;
}
