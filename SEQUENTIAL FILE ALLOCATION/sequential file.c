#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 100

int memory[MAX_BLOCKS];

void initializeMemory() {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        memory[i] = 0;
    }
}

void displayMemory() {
    printf("Memory Block Status:\n");
    for (int i = 0; i < MAX_BLOCKS; i++) {
        printf("%d ", memory[i]);
    }
    printf("\n");
}

int allocateSequential(int fileSize, int *startIndex) {
    int found = 0;

    for (int i = 0; i <= MAX_BLOCKS - fileSize; i++) {
        found = 1;

        for (int j = 0; j < fileSize; j++) {
            if (memory[i + j] == 1) {
                found = 0;
                break;
            }
        }

        if (found) {
            for (int j = 0; j < fileSize; j++) {
                memory[i + j] = 1;
            }
            *startIndex = i;
            return 1;
        }
    }

    return 0;
}

int main() {
    int n, fileSize, startIndex;

    initializeMemory();

    printf("Enter number of files: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter size of file %d: ", i + 1);
        scanf("%d", &fileSize);

        if (allocateSequential(fileSize, &startIndex)) {
            printf("File %d allocated from block %d to %d\n", i + 1, startIndex, startIndex + fileSize - 1);
        } else {
            printf("File %d could not be allocated (Insufficient contiguous space)\n", i + 1);
        }
    }

    printf("\nFinal Memory Layout:\n");
    displayMemory();

    return 0;
}
