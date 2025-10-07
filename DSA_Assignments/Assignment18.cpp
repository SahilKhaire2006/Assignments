#include <iostream>
using namespace std;

struct Node_sak {
    int data_sak;
    Node_sak *next_sak;
    Node_sak *prev_sak;
};

Node_sak* createDLL_sak(int n_sak) {
    Node_sak *head_sak = NULL, *temp_sak = NULL;
    for (int i_sak = 0; i_sak < n_sak; i_sak++) {
        Node_sak *newnode_sak = new Node_sak;
        cout << "Enter data: ";
        cin >> newnode_sak->data_sak;
        newnode_sak->next_sak = NULL;
        newnode_sak->prev_sak = NULL;

        if (head_sak == NULL)
            head_sak = newnode_sak;
        else {
            temp_sak->next_sak = newnode_sak;
            newnode_sak->prev_sak = temp_sak;
        }
        temp_sak = newnode_sak;
    }
    return head_sak;
}

void displayDLL_sak(Node_sak *head_sak) {
    Node_sak *temp_sak = head_sak;
    while (temp_sak != NULL) {
        cout << temp_sak->data_sak << " ";
        temp_sak = temp_sak->next_sak;
    }
    cout << endl;
}

void bubbleSortDLL_sak(Node_sak *head_sak) {
    int swapped_sak;
    Node_sak *ptr1_sak;
    Node_sak *lptr_sak = NULL;

    if (head_sak == NULL)
        return;

    do {
        swapped_sak = 0;
        ptr1_sak = head_sak;

        while (ptr1_sak->next_sak != lptr_sak) {
            if (ptr1_sak->data_sak > ptr1_sak->next_sak->data_sak) {
                int temp_sak = ptr1_sak->data_sak;
                ptr1_sak->data_sak = ptr1_sak->next_sak->data_sak;
                ptr1_sak->next_sak->data_sak = temp_sak;
                swapped_sak = 1;
            }
            ptr1_sak = ptr1_sak->next_sak;
        }
        lptr_sak = ptr1_sak;
    } while (swapped_sak);
}

int main() {
    int n_sak;
    cout << "Enter number of nodes: ";
    cin >> n_sak;

    Node_sak *head_sak = createDLL_sak(n_sak);

    cout << "\nOriginal List: ";
    displayDLL_sak(head_sak);

    bubbleSortDLL_sak(head_sak);

    cout << "Sorted List: ";
    displayDLL_sak(head_sak);

    return 0;
}