#include <stdio.h>
#define MAX_SAK 30
#define NUM_STACKS_SAK 3

int stack_sak[MAX_SAK];
int top_sak[NUM_STACKS_SAK];
int size_sak;

void initialize_sak() {
    for (int i = 0; i < NUM_STACKS_SAK; i++) {
        top_sak[i] = -1;
    }
    size_sak = MAX_SAK / NUM_STACKS_SAK;
}

void push_sak(int stk_no_sak, int val_sak) {
    int base_sak = stk_no_sak * size_sak;
    if (top_sak[stk_no_sak] == size_sak - 1) {
        printf("\nStack Overflow in Stack %d\n", stk_no_sak + 1);
        return;
    }
    top_sak[stk_no_sak]++;
    stack_sak[base_sak + top_sak[stk_no_sak]] = val_sak;
    printf("\nPushed %d into Stack %d\n", val_sak, stk_no_sak + 1);
}

void pop_sak(int stk_no_sak) {
    int base_sak = stk_no_sak * size_sak;
    if (top_sak[stk_no_sak] == -1) {
        printf("\nStack Underflow in Stack %d\n", stk_no_sak + 1);
        return;
    }
    int val_sak = stack_sak[base_sak + top_sak[stk_no_sak]];
    top_sak[stk_no_sak]--;
    printf("\nPopped %d from Stack %d\n", val_sak, stk_no_sak + 1);
}

void display_sak(int stk_no_sak) {
    int base_sak = stk_no_sak * size_sak;
    if (top_sak[stk_no_sak] == -1) {
        printf("\nStack %d is Empty\n", stk_no_sak + 1);
        return;
    }
    printf("\nStack %d elements are:\n", stk_no_sak + 1);
    for (int i = 0; i <= top_sak[stk_no_sak]; i++) {
        printf("%d ", stack_sak[base_sak + i]);
    }
    printf("\n");
}

int main() {
    int choice_sak, stk_no_sak, val_sak;
    initialize_sak();

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice_sak);

        switch (choice_sak) {
            case 1:
                printf("Enter stack number (0-%d): ", NUM_STACKS_SAK - 1);
                scanf("%d", &stk_no_sak);
                if (stk_no_sak < 0 || stk_no_sak >= NUM_STACKS_SAK) {
                    printf("Invalid stack number.\n");
                    break;
                }
                printf("Enter value: ");
                scanf("%d", &val_sak);
                push_sak(stk_no_sak, val_sak);
                break;

            case 2:
                printf("Enter stack number (0-%d): ", NUM_STACKS_SAK - 1);
                scanf("%d", &stk_no_sak);
                if (stk_no_sak < 0 || stk_no_sak >= NUM_STACKS_SAK) {
                    printf("Invalid stack number.\n");
                    break;
                }
                pop_sak(stk_no_sak);
                break;

            case 3:
                printf("Enter stack number (0-%d): ", NUM_STACKS_SAK - 1);
                scanf("%d", &stk_no_sak);
                if (stk_no_sak < 0 || stk_no_sak >= NUM_STACKS_SAK) {
                    printf("Invalid stack number.\n");
                    break;
                }
                display_sak(stk_no_sak);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}
