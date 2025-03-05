#include <stdio.h>

int main() {
    int n, i;
    int first, second;
    printf("enter the number of elements in the array ");
    scanf("%d", &n);

    if (n < 2) {
        printf("array should have two elements to find the second largest\n");
        return 0;
    }
    int arr[n];
    printf("nter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    first = second = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }
    if (second == first) {
        printf("there is no second largest element in the array\n");
    } else {
        printf("the second largest element is %d\n", second);
    }
    return 0;
}
