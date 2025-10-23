#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct Node_sak {
    int data_sak;
    struct Node_sak* next_sak;
};

// Initialize top pointer
struct Node_sak* top_sak = NULL;

// Function to check if stack is empty
int is_empty_sak() {
    return top_sak == NULL;
}

// Function to record a new stock price (Push)
void record_sak(int price_sak) {
    struct Node_sak* new_node_sak = (struct Node_sak*)malloc(sizeof(struct Node_sak));
    if (new_node_sak == NULL) {
        printf("\nMemory allocation failed.");
        return;
    }
    new_node_sak->data_sak = price_sak;
    new_node_sak->next_sak = top_sak;
    top_sak = new_node_sak;
    printf("\nPrice %d recorded successfully.", price_sak);
}

// Function to remove latest stock price (Pop)
void remove_sak() {
    if (is_empty_sak()) {
        printf("\nNo prices to remove. Stack is empty.");
        return;
    }
    struct Node_sak* temp_sak = top_sak;
    printf("\nRemoved latest price: %d", temp_sak->data_sak);
    top_sak = top_sak->next_sak;
    free(temp_sak);
}

// Function to view latest stock price (Peek)
void latest_sak() {
    if (is_empty_sak()) {
        printf("\nNo prices recorded yet.");
        return;
    }
    printf("\nLatest recorded price: %d", top_sak->data_sak);
}

// Function to display all recorded stock prices
void display_sak() {
    if (is_empty_sak()) {
        printf("\nNo prices recorded yet.");
        return;
    }
    struct Node_sak* temp_sak = top_sak;
    printf("\nAll Recorded Prices (Latest to Oldest): ");
    while (temp_sak != NULL) {
        printf("%d ", temp_sak->data_sak);
        temp_sak = temp_sak->next_sak;
    }
}

// Main function
int main() {
    int choice_sak, price_sak;

    printf("\nSTOCK PRICE TRACKER USING STACK (LINKED LIST)\n");

    while (1) {
        printf("\n\n1. Record new price");
        printf("\n2. Remove latest price");
        printf("\n3. View latest price");
        printf("\n4. Display all prices");
        printf("\n5. Check if stack is empty");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice_sak);

        switch (choice_sak) {
            case 1:
                printf("Enter stock price: ");
                scanf("%d", &price_sak);
                record_sak(price_sak);
                break;

            case 2:
                remove_sak();
                break;

            case 3:
                latest_sak();
                break;

            case 4:
                display_sak();
                break;

            case 5:
                if (is_empty_sak())
                    printf("\nStack is empty.");
                else
                    printf("\nStack is not empty.");
                break;

            case 6:
                printf("\nExiting program.");
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.");
        }
    }

    return 0;
}