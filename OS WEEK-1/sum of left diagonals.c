#include <stdio.h>

int main() {
    int n, i, j;
    int sum = 0;
    printf("enter the size of the matrix: ");
    scanf("%d", &n);
    int matrix[n][n];
    printf("enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        sum += matrix[i][i];
    }
    printf("the sum of the left diagonal is: %d\n", sum);
    return 0;
}
