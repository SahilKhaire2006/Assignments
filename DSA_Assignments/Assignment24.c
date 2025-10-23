#include <stdio.h>
#include <string.h>

#define MAX_SAK 100

char stack_sak[MAX_SAK];
int top_sak = -1;

void push_sak(char ch_sak) {
    if (top_sak < MAX_SAK - 1) {
        stack_sak[++top_sak] = ch_sak;
    }
}

char pop_sak() {
    if (top_sak == -1) return '\0';
    return stack_sak[top_sak--];
}

int isBalanced_sak(char str_sak[]) {
    top_sak = -1;
    for (int i_sak = 0; str_sak[i_sak] != '\0'; i_sak++) {
        char ch_sak = str_sak[i_sak];

        if (ch_sak == '(' || ch_sak == '{' || ch_sak == '[') {
            push_sak(ch_sak);
        } else if (ch_sak == ')' || ch_sak == '}' || ch_sak == ']') {
            if (top_sak == -1) return 0;
            char top_ch_sak = pop_sak();
            if ((ch_sak == ')' && top_ch_sak != '(') ||
                (ch_sak == '}' && top_ch_sak != '{') ||
                (ch_sak == ']' && top_ch_sak != '[')) {
                return 0;
            }
        }
    }
    return top_sak == -1;
}

int main() {
    char str_sak[MAX_SAK];
    printf("Enter the string: ");
    scanf("%s", str_sak);

    if (isBalanced_sak(str_sak))
        printf("The string is balanced.\n");
    else
        printf("The string is not balanced.\n");

    return 0;
}