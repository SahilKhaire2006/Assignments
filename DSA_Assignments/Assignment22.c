#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE_SAK 50

// Stack structure
struct Stack_sak {
    char arr_sak[SIZE_SAK];
    int top_sak;
};

// Initialize stack
void init_stack_sak(struct Stack_sak *stack_sak) {
    stack_sak->top_sak = -1;
}

// Check if stack is empty
int is_empty_sak(struct Stack_sak *stack_sak) {
    return stack_sak->top_sak == -1;
}

// Push an element to stack
void push_sak(struct Stack_sak *stack_sak, char item_sak) {
    if (stack_sak->top_sak == SIZE_SAK - 1) {
        printf("\nStack overflow.");
        return;
    }
    stack_sak->arr_sak[++stack_sak->top_sak] = item_sak;
}

// Pop an element from stack
char pop_sak(struct Stack_sak *stack_sak) {
    if (is_empty_sak(stack_sak)) {
        return '\0';
    }
    return stack_sak->arr_sak[stack_sak->top_sak--];
}

// Peek top of stack
char peek_sak(struct Stack_sak *stack_sak) {
    if (is_empty_sak(stack_sak))
        return '\0';
    return stack_sak->arr_sak[stack_sak->top_sak];
}

// Function to check operator precedence
int precedence_sak(char op_sak) {
    switch (op_sak) {
        case '^': return 3;
        case '*':
        case '/':
        case '%': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

// Function to convert infix to postfix
void infix_to_postfix_sak(char infix_sak[], char postfix_sak[]) {
    struct Stack_sak stack_sak;
    init_stack_sak(&stack_sak);
    int i_sak = 0, j_sak = 0;
    char ch_sak;

    while ((ch_sak = infix_sak[i_sak++]) != '\0') {
        if (isalnum(ch_sak)) {
            postfix_sak[j_sak++] = ch_sak;
        }
        else if (ch_sak == '(') {
            push_sak(&stack_sak, ch_sak);
        }
        else if (ch_sak == ')') {
            while (!is_empty_sak(&stack_sak) && peek_sak(&stack_sak) != '(')
                postfix_sak[j_sak++] = pop_sak(&stack_sak);
            pop_sak(&stack_sak); // remove '('
        }
        else { // operator
            while (!is_empty_sak(&stack_sak) && precedence_sak(peek_sak(&stack_sak)) >= precedence_sak(ch_sak))
                postfix_sak[j_sak++] = pop_sak(&stack_sak);
            push_sak(&stack_sak, ch_sak);
        }
    }

    while (!is_empty_sak(&stack_sak))
        postfix_sak[j_sak++] = pop_sak(&stack_sak);

    postfix_sak[j_sak] = '\0';
}

int main() {
    char infix_sak[SIZE_SAK], postfix_sak[SIZE_SAK];

    printf("Enter an infix expression: ");
    scanf("%s", infix_sak);

    infix_to_postfix_sak(infix_sak, postfix_sak);

    printf("\nEquivalent Postfix Expression: %s\n", postfix_sak);

    return 0;
}