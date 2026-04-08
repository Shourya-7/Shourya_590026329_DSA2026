#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main() {
    char infix[100];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    printf("Postfix expression: ");
    for (int i = 0; i < strlen(infix); i++) {
        if (isalnum(infix[i])) printf("%c", infix[i]);
        else if (infix[i] == '(') push('(');
        else if (infix[i] == ')') {
            while (stack[top] != '(') printf("%c", pop());
            pop();
        } else {
            while (top != -1 && prec(stack[top]) >= prec(infix[i])) printf("%c", pop());
            push(infix[i]);
        }
    }
    while (top != -1) printf("%c", pop());
    printf("\n");
    return 0;
}
