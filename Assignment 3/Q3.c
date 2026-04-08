#include <stdio.h>
#include <string.h>

#define MAX 100
char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int main() {
    char str[] = "GitHub";
    int n = strlen(str);

    for (int i = 0; i < n; i++) push(str[i]);
    
    printf("Original: %s\n", str);
    printf("Reversed: ");
    for (int i = 0; i < n; i++) printf("%c", pop());
    printf("\n");

    return 0;
}
