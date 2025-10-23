#include <iostream>
#include <string>
using namespace std;

#define MAX_SAK 5

string queue_sak[MAX_SAK];
int front_sak = -1;
int rear_sak = -1;

void enqueue_sak(string order_sak) {
    if ((rear_sak + 1) % MAX_SAK == front_sak) {
        cout << "\nOrder queue is full. Cannot place order.\n";
        return;
    }
    rear_sak = (rear_sak + 1) % MAX_SAK;
    queue_sak[rear_sak] = order_sak;
    if (front_sak == -1) front_sak = 0;
    cout << "\nOrder \"" << order_sak << "\" placed.\n";
}

void dequeue_sak() {
    if (front_sak == -1) {
        cout << "\nNo orders to serve.\n";
        return;
    }
    cout << "\nServing order \"" << queue_sak[front_sak] << "\"\n";
    if (front_sak == rear_sak) {
        front_sak = rear_sak = -1;
    } else {
        front_sak = (front_sak + 1) % MAX_SAK;
    }
}

void display_sak() {
    if (front_sak == -1) {
        cout << "\nNo pending orders.\n";
        return;
    }
    cout << "\nPending Orders:\n";
    int i_sak = front_sak;
    while (true) {
        cout << queue_sak[i_sak] << endl;
        if (i_sak == rear_sak) break;
        i_sak = (i_sak + 1) % MAX_SAK;
    }
}

int main() {
    int choice_sak;
    string order_sak;

    while (true) {
        cout << "\n1. Place Order\n2. Serve Order\n3. Display Orders\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_sak;
        cin.ignore();

        switch (choice_sak) {
            case 1:
                cout << "Enter order name: ";
                getline(cin, order_sak);
                enqueue_sak(order_sak);
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