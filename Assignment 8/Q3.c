#include <stdio.h>

int main() {
    int n, i, j, key;
    int arr[100];

    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for(i=0;i<n;i++) scanf("%d",&arr[i]);

    for(i=1;i<n;i++) {
        key = arr[i];
        j = i - 1;

        while(j>=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;

        printf("After inserting element %d: ", key);
        for(int k=0;k<n;k++) printf("%d ", arr[k]);
        printf("\n");
    }

    printf("\nSorted array: ");
    for(i=0;i<n;i++) printf("%d ", arr[i]);

    printf("\nName: %s\n", name);

    return 0;
}
