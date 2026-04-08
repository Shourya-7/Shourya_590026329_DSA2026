#include <stdio.h>
#include <ctype.h>

int stack[100];
int top = -1;

void push(int n) { stack[++top] = n; }
int pop() { return stack[top--]; }

int main() {
    char exp[] = "23*54*+9-";
    for (int i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i])) push(exp[i] - '0');
        else {
            int val2 = pop();
            int val1 = pop();
            switch (exp[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }
    printf("Result = %d\n", pop());
    return 0;
}
