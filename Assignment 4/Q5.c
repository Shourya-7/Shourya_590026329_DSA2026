#include <stdio.h>
#define MAX 10

int q1[MAX], q2[MAX];
int f1 = -1, r1 = -1, f2 = -1, r2 = -1;

void enq(int *q, int *f, int *r, int val) {
    if (*r == MAX - 1) return;
    if (*f == -1) *f = 0;
    q[++(*r)] = val;
}

int deq(int *q, int *f, int *r) {
    int val = q[*f];
    if (*f == *r) *f = *r = -1;
    else (*f)++;
    return val;
}

void push() {
    int val;
    printf("Enter value: ");
    scanf("%d", &val);
    enq(q2, &f2, &r2, val);
    while (f1 != -1) enq(q2, &f2, &r2, deq(q1, &f1, &r1));
    int *tf = &f1, *tr = &r1;
    f1 = f2; r1 = r2; f2 = -1; r2 = -1;
}

void pop() {
    if (f1 == -1) printf("Stack Underflow\n");
    else printf("Popped: %d\n", deq(q1, &f1, &r1));
}

void peek() {
    if (f1 == -1) printf("Stack is empty\n");
    else printf("Top: %d\n", q1[f1]);
}

void display() {
    if (f1 == -1) printf("Stack is empty\n");
    else {
        for (int i = f1; i <= r1; i++) printf("%d ", q1[i]);
        printf("\n");
    }
}

int main() {
    printf("Name: Shourya Singh\n");
    int choice;
    while(1) {
        printf("\n1.Push 2.Pop 3.Peek 4.Display 5.Exit: ");
        scanf("%d", &choice);
        if(choice == 1) push();
        else if(choice == 2) pop();
        else if(choice == 3) peek();
        else if(choice == 4) display();
        else break;
    }
    return 0;
}
