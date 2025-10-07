#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Member Node
typedef struct Node_sak {
    int prn_sak;
    char name_sak[50];
    struct Node_sak *next_sak;
} Node_sak;

// Create new member
Node_sak* createNode_sak(int prn_sak, char name_sak[]) {
    Node_sak* newnode_sak = (Node_sak*)malloc(sizeof(Node_sak));
    newnode_sak->prn_sak = prn_sak;
    strcpy(newnode_sak->name_sak, name_sak);
    newnode_sak->next_sak = NULL;
    return newnode_sak;
}

// Insert President (at beginning)
void insertPresident_sak(Node_sak** head_sak, int prn_sak, char name_sak[]) {
    Node_sak* newnode_sak = createNode_sak(prn_sak, name_sak);
    newnode_sak->next_sak = *head_sak;
    *head_sak = newnode_sak;
}

// Insert Secretary (at end)
void insertSecretary_sak(Node_sak** head_sak, int prn_sak, char name_sak[]) {
    Node_sak* newnode_sak = createNode_sak(prn_sak, name_sak);
    if (*head_sak == NULL) {
        *head_sak = newnode_sak;
        return;
    }
    Node_sak* temp_sak = *head_sak;
    while (temp_sak->next_sak != NULL)
        temp_sak = temp_sak->next_sak;
    temp_sak->next_sak = newnode_sak;
}

// Insert Member (after President, before Secretary)
void insertMember_sak(Node_sak* head_sak, int prn_sak, char name_sak[]) {
    if (head_sak == NULL) {
        printf("First add President!\n");
        return;
    }
    Node_sak* newnode_sak = createNode_sak(prn_sak, name_sak);
    newnode_sak->next_sak = head_sak->next_sak;
    head_sak->next_sak = newnode_sak;
}

// Delete President
void deletePresident_sak(Node_sak** head_sak) {
    if (*head_sak == NULL) return;
    Node_sak* temp_sak = *head_sak;
    *head_sak = (*head_sak)->next_sak;
    free(temp_sak);
}

// Delete Secretary
void deleteSecretary_sak(Node_sak* head_sak) {
    if (head_sak == NULL) return;
    if (head_sak->next_sak == NULL) {
        free(head_sak);
        head_sak = NULL;
        return;
    }
    Node_sak* prev_sak = NULL;
    Node_sak* temp_sak = head_sak;
    while (temp_sak->next_sak != NULL) {
        prev_sak = temp_sak;
        temp_sak = temp_sak->next_sak;
    }
    prev_sak->next_sak = NULL;
    free(temp_sak);
}

// Delete Member by PRN
void deleteMemberByPRN_sak(Node_sak** head_sak, int prn_sak) {
    if (*head_sak == NULL) return;
    Node_sak* temp_sak = *head_sak;
    Node_sak* prev_sak = NULL;

    while (temp_sak != NULL && temp_sak->prn_sak != prn_sak) {
        prev_sak = temp_sak;
        temp_sak = temp_sak->next_sak;
    }
    if (temp_sak == NULL) {
        printf("PRN %d not found!\n", prn_sak);
        return;
    }
    if (prev_sak == NULL) {
        *head_sak = temp_sak->next_sak;
    } else {
        prev_sak->next_sak = temp_sak->next_sak;
    }
    free(temp_sak);
}

// Count Members
int countMembers_sak(Node_sak* head_sak) {
    int count_sak = 0;
    while (head_sak != NULL) {
        count_sak++;
        head_sak = head_sak->next_sak;
    }
    return count_sak;
}

// Display Members
void displayMembers_sak(Node_sak* head_sak) {
    if (head_sak == NULL) {
        printf("No members!\n");
        return;
    }
    printf("\nClub Members:\n");
    while (head_sak != NULL) {
        printf("PRN: %d, Name: %s\n", head_sak->prn_sak, head_sak->name_sak);
        head_sak = head_sak->next_sak;
    }
}

// Concatenate two lists
Node_sak* concatenate_sak(Node_sak* head1_sak, Node_sak* head2_sak) {
    if (head1_sak == NULL) return head2_sak;
    Node_sak* temp_sak = head1_sak;
    while (temp_sak->next_sak != NULL)
        temp_sak = temp_sak->next_sak;
    temp_sak->next_sak = head2_sak;
    return head1_sak;
}

// Reverse list
void reverseList_sak(Node_sak** head_sak) {
    Node_sak* prev_sak = NULL;
    Node_sak* curr_sak = *head_sak;
    Node_sak* next_sak = NULL;
    while (curr_sak != NULL) {
        next_sak = curr_sak->next_sak;
        curr_sak->next_sak = prev_sak;
        prev_sak = curr_sak;
        curr_sak = next_sak;
    }
    *head_sak = prev_sak;
}

// Search by PRN
void searchByPRN_sak(Node_sak* head_sak, int prn_sak) {
    while (head_sak != NULL) {
        if (head_sak->prn_sak == prn_sak) {
            printf("Found Member: PRN: %d, Name: %s\n", head_sak->prn_sak, head_sak->name_sak);
            return;
        }
        head_sak = head_sak->next_sak;
    }
    printf("PRN %d not found!\n", prn_sak);
}

// Sort by PRN (Bubble Sort)
void sortByPRN_sak(Node_sak* head_sak) {
    if (head_sak == NULL) return;
    Node_sak* i_sak;
    Node_sak* j_sak;
    int tempPRN_sak;
    char tempName_sak[50];

    for (i_sak = head_sak; i_sak != NULL; i_sak = i_sak->next_sak) {
        for (j_sak = i_sak->next_sak; j_sak != NULL; j_sak = j_sak->next_sak) {
            if (i_sak->prn_sak > j_sak->prn_sak) {
                tempPRN_sak = i_sak->prn_sak;
                i_sak->prn_sak = j_sak->prn_sak;
                j_sak->prn_sak = tempPRN_sak;

                strcpy(tempName_sak, i_sak->name_sak);
                strcpy(i_sak->name_sak, j_sak->name_sak);
                strcpy(j_sak->name_sak, tempName_sak);
            }
        }
    }
}

// Main Menu
int main() {
    Node_sak* head1_sak = NULL;
    Node_sak* head2_sak = NULL;
    int choice_sak, prn_sak;
    char name_sak[50];

    while (1) {
        printf("\n===== Vertex Club Menu =====\n");
        printf("1. Add President\n2. Add Secretary\n3. Add Member\n4. Delete President\n5. Delete Secretary\n6. Delete Member by PRN\n7. Count Members\n8. Display Members\n9. Concatenate Two Divisions\n10. Reverse List\n11. Search by PRN\n12. Sort by PRN\n0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice_sak);

        switch (choice_sak) {
            case 1:
                printf("Enter PRN & Name: ");
                scanf("%d %s", &prn_sak, name_sak);
                insertPresident_sak(&head1_sak, prn_sak, name_sak);
                break;
            case 2:
                printf("Enter PRN & Name: ");
                scanf("%d %s", &prn_sak, name_sak);
                insertSecretary_sak(&head1_sak, prn_sak, name_sak);
                break;
            case 3:
                printf("Enter PRN & Name: ");
                scanf("%d %s", &prn_sak, name_sak);
                insertMember_sak(head1_sak, prn_sak, name_sak);
                break;
            case 4:
                deletePresident_sak(&head1_sak);
                break;
            case 5:
                deleteSecretary_sak(head1_sak);
                break;
            case 6:
                printf("Enter PRN to delete: ");
                scanf("%d", &prn_sak);
                deleteMemberByPRN_sak(&head1_sak, prn_sak);
                break;
            case 7:
                printf("Total Members: %d\n", countMembers_sak(head1_sak));
                break;
            case 8:
                displayMembers_sak(head1_sak);
                break;
            case 9:
                printf("Creating Division 2 list...\n");
                insertPresident_sak(&head2_sak, 2001, "Div2Pres");
                insertSecretary_sak(&head2_sak, 2002, "Div2Sec");
                head1_sak = concatenate_sak(head1_sak, head2_sak);
                printf("Lists concatenated!\n");
                break;
            case 10:
                reverseList_sak(&head1_sak);
                printf("List reversed!\n");
                break;
            case 11:
                printf("Enter PRN to search: ");
                scanf("%d", &prn_sak);
                searchByPRN_sak(head1_sak, prn_sak);
                break;
            case 12:
                sortByPRN_sak(head1_sak);
                printf("List sorted by PRN!\n");
                break;
            case 0:
                exit(0);
        }
    }
    return 0;
}
