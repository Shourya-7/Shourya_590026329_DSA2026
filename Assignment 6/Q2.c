#include <stdio.h>

int heap[100];
int size = 0;

void insert(int val) {
    heap[++size] = val;
    int i = size;

    while(i > 1 && heap[i] < heap[i/2]) {
        int temp = heap[i];
        heap[i] = heap[i/2];
        heap[i/2] = temp;
        i /= 2;
    }
}

void deleteRoot() {
    heap[1] = heap[size--];

    int i = 1;
    while(2*i <= size) {
        int smallest = i;

        if(heap[2*i] < heap[smallest])
            smallest = 2*i;
        if(2*i+1 <= size && heap[2*i+1] < heap[smallest])
            smallest = 2*i+1;

        if(smallest != i) {
            int temp = heap[i];
            heap[i] = heap[smallest];
            heap[smallest] = temp;
            i = smallest;
        } else break;
    }
}

void display() {
    for(int i = 1; i <= size; i++)
        printf("%d ", heap[i]);
}

int main() {
    printf("Name: Shourya Singh\n\n");

    int n, val;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &val);
        insert(val);
    }

    printf("\nHeap: ");
    display();

    printf("\nDeleting root...\n");
    deleteRoot();

    printf("Heap after deletion: ");
    display();

    return 0;
}
