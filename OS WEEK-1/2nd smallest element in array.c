#include <stdio.h>

int main() {
    int n, i;
    int first_min, second_min;
    printf("enter the no. of elements in the array: ");
    scanf("%d", &n);
    if (n < 2) {
        printf("array should have two elements to find the second-smallest element.\n");
        return 0;
    }
    int arr[n];
    printf("enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    first_min = second_min = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] < first_min) {
            second_min = first_min;
            first_min = arr[i];
        } else if (arr[i] < second_min && arr[i] != first_min) {
            second_min = arr[i];
        }
    }
    if (second_min == first_min) {
        printf("there is no second smallest element.\n");
    } else {
        printf("the second smallest element is: %d\n", second_min);
    }
    return 0;
}
