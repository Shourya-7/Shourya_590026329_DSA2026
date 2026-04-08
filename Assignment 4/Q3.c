#include <stdio.h>
#include <string.h>

#define MAX 100
char queue[MAX];
int front = -1, rear = -1;

void enqueue(char c) {
    if (front == -1) front = 0;
    queue[++rear] = c;
}

char dequeue() {
    return queue[front++];
}

int main() {
    printf("Name: Shourya Singh\n");
    char str[MAX];
    printf("Enter string: ");
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++) enqueue(str[i]);
    int flag = 1;
    for (int i = 0; i < len; i++) {
        if (str[i] != dequeue()) {
            flag = 0;
            break;
        }
    }
    if (flag) printf("Palindrome\n");
    else printf("Not a Palindrome\n");
    return 0;
}
