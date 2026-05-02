#include <stdio.h>

int main() {
    int n, i, j, temp;
    int arr[100];
    int comparisons = 0, swaps = 0;

    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            comparisons++;
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaps++;
            }
        }

        printf("Pass %d: ", i+1);
        for(int k=0;k<n;k++) printf("%d ", arr[k]);
        printf("\n");
    }

    printf("\nSorted array: ");
    for(i=0;i<n;i++) printf("%d ", arr[i]);

    printf("\nComparisons: %d", comparisons);
    printf("\nSwaps: %d", swaps);

    printf("\nName: %s\n", name);

    return 0;
}
