#include <stdio.h>
#include <ctype.h>

#define MAX_SAK 100

int stack_sak[MAX_SAK];
int top_sak = -1;

void push_sak(int val_sak) {
    stack_sak[++top_sak] = val_sak;
}

int pop_sak() {
    return stack_sak[top_sak--];
}

int evaluatePostfix_sak(char expr_sak[]) {
    top_sak = -1;
    for (int i_sak = 0; expr_sak[i_sak] != '\0'; i_sak++) {
        char ch_sak = expr_sak[i_sak];

        if (isdigit(ch_sak)) {
            push_sak(ch_sak - '0');
        } else {
            int val2_sak = pop_sak();
            int val1_sak = pop_sak();
            int res_sak;

            switch (ch_sak) {
                case '+': res_sak = val1_sak + val2_sak; break;
                case '-': res_sak = val1_sak - val2_sak; break;
                case '*': res_sak = val1_sak * val2_sak; break;
                case '/': res_sak = val1_sak / val2_sak; break;
            }
            push_sak(res_sak);
        }
    }
    return pop_sak();
}

int main() {
    char expr_sak[MAX_SAK];
    printf("Enter postfix expression: ");
    scanf("%s", expr_sak);

    int result_sak = evaluatePostfix_sak(expr_sak);
    printf("Result of the expression: %d\n", result_sak);

    return 0;
}