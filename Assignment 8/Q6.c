#include <stdio.h>

int main() {
    int n, key, found = 0;
    int arr[100];

    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter size: ");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    printf("Enter element to search: ");
    scanf("%d",&key);

    for(int i=0;i<n;i++) {
        if(arr[i] == key) {
            printf("Found at position %d\n", i);
            found = 1;
        }
    }

    if(!found)
        printf("Element not found\n");

    printf("Name: %s\n", name);

    return 0;
}
