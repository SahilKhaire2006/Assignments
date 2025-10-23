#include <iostream>
#include <string>
using namespace std;

struct Node_sak {
    string customer_sak;
    Node_sak* next_sak;
};

Node_sak* front_sak = NULL;
Node_sak* rear_sak = NULL;

void enqueue_sak(string customer_sak) {
    Node_sak* new_node_sak = new Node_sak();
    new_node_sak->customer_sak = customer_sak;
    new_node_sak->next_sak = NULL;

    if (rear_sak == NULL) {
        front_sak = rear_sak = new_node_sak;
    } else {
        rear_sak->next_sak = new_node_sak;
        rear_sak = new_node_sak;
    }
    cout << "\nCall from \"" << customer_sak << "\" added to queue.\n";
}

void dequeue_sak() {
    if (front_sak == NULL) {
        cout << "\nNo calls waiting.\n";
        return;
    }
    Node_sak* temp_sak = front_sak;
    cout << "\nAssisting customer: " << temp_sak->customer_sak << endl;
    front_sak = front_sak->next_sak;
    if (front_sak == NULL) rear_sak = NULL;
    delete temp_sak;
}

void display_sak() {
    if (front_sak == NULL) {
        cout << "\nNo calls in queue.\n";
        return;
    }
    cout << "\nCalls waiting:\n";
    Node_sak* temp_sak = front_sak;
    while (temp_sak != NULL) {
        cout << temp_sak->customer_sak << endl;
        temp_sak = temp_sak->next_sak;
    }
}

int main() {
    int choice_sak;
    string customer_sak;

    while (true) {
        cout << "\n1. Add Call\n2. Serve Call\n3. Display Calls\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_sak;
        cin.ignore();

        switch (choice_sak) {
            case 1:
                cout << "Enter customer name: ";
                getline(cin, customer_sak);
                enqueue_sak(customer_sak);
                break;
            case 2:
                dequeue_sak();
                break;
            case 3:
                display_sak();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
