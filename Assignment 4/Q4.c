#include <stdio.h>
#define MAX 5

int cqueue[MAX];
int front = -1, rear = -1;

void enqueue() {
    int val;
    if ((rear + 1) % MAX == front) printf("Queue Overflow\n");
    else {
        printf("Enter value: ");
        scanf("%d", &val);
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        cqueue[rear] = val;
    }
}

void dequeue() {
    if (front == -1) printf("Queue Underflow\n");
    else {
        printf("Dequeued: %d\n", cqueue[front]);
        if (front == rear) front = rear = -1;
        else front = (front + 1) % MAX;
    }
}

void display() {
    if (front == -1) printf("Queue is empty\n");
    else {
        int i = front;
        while (1) {
            printf("%d ", cqueue[i]);
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

int main() {
    printf("Name: Shourya Singh\n");
    int choice;
    while(1) {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit: ");
        scanf("%d", &choice);
        if(choice == 1) enqueue();
        else if(choice == 2) dequeue();
        else if (choice == 3) display();
        else break;
    }
    return 0;
}
