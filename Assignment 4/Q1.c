#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue() {
    int val;
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        printf("Enter value: ");
        scanf("%d", &val);
        if (front == -1) front = 0;
        queue[++rear] = val;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
    } else {
        printf("Dequeued: %d\n", queue[front++]);
        if (front > rear) front = rear = -1;
    }
}

void peek() {
    if (front == -1 || front > rear) printf("Queue is empty\n");
    else printf("Front element: %d\n", queue[front]);
}

void display() {
    if (front == -1) printf("Queue is empty\n");
    else {
        for (int i = front; i <= rear; i++) printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    printf("Name: Shourya Singh\n");
    int choice;
    while(1) {
        printf("\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit: ");
        scanf("%d", &choice);
        if(choice == 1) enqueue();
        else if(choice == 2) dequeue();
        else if(choice == 3) peek();
        else if(choice == 4) display();
        else break;
    }
    return 0;
}
