#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) {
    if(low <= high) {
        int mid = (low + high)/2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] > key)
            return binarySearch(arr, low, mid-1, key);
        else
            return binarySearch(arr, mid+1, high, key);
    }
    return -1;
}

int main() {
    int n, key, result;
    int arr[100];

    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter size: ");
    scanf("%d",&n);

    printf("Enter sorted elements:\n");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    printf("Enter element to search: ");
    scanf("%d",&key);

    result = binarySearch(arr,0,n-1,key);

    if(result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    printf("Name: %s\n", name);

    return 0;
}
