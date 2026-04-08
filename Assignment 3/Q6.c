#include <stdio.h>
#include <ctype.h>

int stack[100];
int top = -1;

void push(int n) { stack[++top] = n; }
int pop() { return stack[top--]; }

int main() {
    char exp[100];
    printf("Enter postfix expression (e.g., 23*54*+9-): ");
    scanf("%s", exp);

    for (int i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i])) push(exp[i] - '0');
        else {
            int v2 = pop();
            int v1 = pop();
            if (exp[i] == '+') push(v1 + v2);
            else if (exp[i] == '-') push(v1 - v2);
            else if (exp[i] == '*') push(v1 * v2);
            else if (exp[i] == '/') push(v1 / v2);
        }
    }
    printf("Result = %d\n", pop());
    return 0;
}
