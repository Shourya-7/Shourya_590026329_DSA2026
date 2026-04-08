#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void infixToPostfix(char* infix) {
    for (int i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) printf("%c", infix[i]);
        else if (infix[i] == '(') push('(');
        else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') printf("%c", pop());
            pop();
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) printf("%c", pop());
            push(infix[i]);
        }
    }
    while (top != -1) printf("%c", pop());
}

int main() {
    char infix[] = "A+B*(C^D-E)^(F+G*H)-I";
    printf("Postfix: ");
    infixToPostfix(infix);
    printf("\n");
    return 0;
}
