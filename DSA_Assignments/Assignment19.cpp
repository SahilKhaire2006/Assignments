#include <iostream>
using namespace std;

struct Node_sak {
    int data_sak;
    Node_sak *next_sak;
    Node_sak *prev_sak;
};

Node_sak* createDLL_sak() {
    return NULL;
}

Node_sak* insertAtBeginning_sak(Node_sak* head_sak, int data_sak) {
    Node_sak* newnode_sak = new Node_sak;
    newnode_sak->data_sak = data_sak;
    newnode_sak->prev_sak = NULL;
    newnode_sak->next_sak = head_sak;
    if (head_sak != NULL)
        head_sak->prev_sak = newnode_sak;
    head_sak = newnode_sak;
    return head_sak;
}

Node_sak* insertAtEnd_sak(Node_sak* head_sak, int data_sak) {
    Node_sak* newnode_sak = new Node_sak;
    newnode_sak->data_sak = data_sak;
    newnode_sak->next_sak = NULL;
    if (head_sak == NULL) {
        newnode_sak->prev_sak = NULL;
        return newnode_sak;
    }
    Node_sak* temp_sak = head_sak;
    while (temp_sak->next_sak != NULL)
        temp_sak = temp_sak->next_sak;
    temp_sak->next_sak = newnode_sak;
    newnode_sak->prev_sak = temp_sak;
    return head_sak;
}

Node_sak* insertAtPosition_sak(Node_sak* head_sak, int data_sak, int pos_sak) {
    if (pos_sak == 1)
        return insertAtBeginning_sak(head_sak, data_sak);

    Node_sak* newnode_sak = new Node_sak;
    newnode_sak->data_sak = data_sak;
    Node_sak* temp_sak = head_sak;
    for (int i_sak = 1; i_sak < pos_sak - 1 && temp_sak != NULL; i_sak++)
        temp_sak = temp_sak->next_sak;
    if (temp_sak == NULL)
        return head_sak;
    newnode_sak->next_sak = temp_sak->next_sak;
    newnode_sak->prev_sak = temp_sak;
    if (temp_sak->next_sak != NULL)
        temp_sak->next_sak->prev_sak = newnode_sak;
    temp_sak->next_sak = newnode_sak;
    return head_sak;
}

Node_sak* deleteAtBeginning_sak(Node_sak* head_sak) {
    if (head_sak == NULL)
        return NULL;
    Node_sak* temp_sak = head_sak;
    head_sak = head_sak->next_sak;
    if (head_sak != NULL)
        head_sak->prev_sak = NULL;
    delete temp_sak;
    return head_sak;
}

Node_sak* deleteAtEnd_sak(Node_sak* head_sak) {
    if (head_sak == NULL)
        return NULL;
    if (head_sak->next_sak == NULL) {
        delete head_sak;
        return NULL;
    }
    Node_sak* temp_sak = head_sak;
    while (temp_sak->next_sak != NULL)
        temp_sak = temp_sak->next_sak;
    temp_sak->prev_sak->next_sak = NULL;
    delete temp_sak;
    return head_sak;
}

Node_sak* deleteAtPosition_sak(Node_sak* head_sak, int pos_sak) {
    if (head_sak == NULL)
        return NULL;
    if (pos_sak == 1)
        return deleteAtBeginning_sak(head_sak);
    Node_sak* temp_sak = head_sak;
    for (int i_sak = 1; i_sak < pos_sak && temp_sak != NULL; i_sak++)
        temp_sak = temp_sak->next_sak;
    if (temp_sak == NULL)
        return head_sak;
    if (temp_sak->next_sak != NULL)
        temp_sak->next_sak->prev_sak = temp_sak->prev_sak;
    if (temp_sak->prev_sak != NULL)
        temp_sak->prev_sak->next_sak = temp_sak->next_sak;
    delete temp_sak;
    return head_sak;
}

void displayDLL_sak(Node_sak* head_sak) {
    Node_sak* temp_sak = head_sak;
    while (temp_sak != NULL) {
        cout << temp_sak->data_sak << " ";
        temp_sak = temp_sak->next_sak;
    }
    cout << endl;
}

int main() {
    Node_sak* head_sak = NULL;
    int choice_sak, data_sak, pos_sak;

    do {
        cout << "\n1.Insert at Beginning\n2.Insert at End\n3.Insert at Position\n4.Delete at Beginning\n5.Delete at End\n6.Delete at Position\n7.Display\n0.Exit\nEnter choice: ";
        cin >> choice_sak;
        switch(choice_sak) {
            case 1:
                cout << "Enter data: ";
                cin >> data_sak;
                head_sak = insertAtBeginning_sak(head_sak, data_sak);
                break;
            case 2:
                cout << "Enter data: ";
                cin >> data_sak;
                head_sak = insertAtEnd_sak(head_sak, data_sak);
                break;
            case 3:
                cout << "Enter data and position: ";
                cin >> data_sak >> pos_sak;
                head_sak = insertAtPosition_sak(head_sak, data_sak, pos_sak);
                break;
            case 4:
                head_sak = deleteAtBeginning_sak(head_sak);
                break;
            case 5:
                head_sak = deleteAtEnd_sak(head_sak);
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> pos_sak;
                head_sak = deleteAtPosition_sak(head_sak, pos_sak);
                break;
            case 7:
                displayDLL_sak(head_sak);
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice!";
        }
    } while(choice_sak != 0);

    return 0;
}