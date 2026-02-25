#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *arr, i, max, min;

    scanf("%d", &n);
    arr = (int*)malloc(n * sizeof(int));

    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    max = min = arr[0];

    for(i = 1; i < n; i++) {
        if(arr[i] > max) max = arr[i];
        if(arr[i] < min) min = arr[i];
    }

    printf("Largest = %d\nSmallest = %d", max, min);

    free(arr);
}
