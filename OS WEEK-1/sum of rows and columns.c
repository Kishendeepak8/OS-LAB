#include <stdio.h>

int main() {
    int rows, cols;
    printf("enter the number of rows: ");
    scanf("%d", &rows);
    printf("enter the number of columns: ");
    scanf("%d", &cols);
    int matrix[rows][cols];
    printf("enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("element[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
    int rowSum[rows];
    int colSum[cols];
    for (int i = 0; i < rows; i++) {
        rowSum[i] = 0;
    }
    for (int j = 0; j < cols; j++) {
        colSum[j] = 0;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            rowSum[i] += matrix[i][j];
            colSum[j] += matrix[i][j];
        }
    }
    printf("\nsum of rows:\n");
    for (int i = 0; i < rows; i++) {
        printf("row %d: %d\n", i + 1, rowSum[i]);
    }
    printf("\nSum of columns:\n");
    for (int j = 0; j < cols; j++) {
        printf("ccolumn %d: %d\n", j + 1, colSum[j]);
    }

    return 0;
}

