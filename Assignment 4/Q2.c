#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue() {
    int val;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value: ");
    scanf("%d", &val);
    newNode->data = val;
    newNode->next = NULL;
    if (rear == NULL) front = rear = newNode;
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (front == NULL) printf("Queue Underflow\n");
    else {
        struct Node* temp = front;
        printf("Dequeued: %d\n", front->data);
        front = front->next;
        if (front == NULL) rear = NULL;
        free(temp);
    }
}

void peek() {
    if (front == NULL) printf("Queue is empty\n");
    else printf("Front: %d\n", front->data);
}

void display() {
    struct Node* temp = front;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
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
