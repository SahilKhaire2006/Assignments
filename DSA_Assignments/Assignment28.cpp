#include <iostream>
#include <string>
using namespace std;

#define MAX_SAK 50

string queue_sak[MAX_SAK];
int front_sak = -1;
int rear_sak = -1;

void enqueue_sak(string passenger_sak) {
    if (rear_sak == MAX_SAK - 1) {
        cout << "\nQueue Overflow. Cannot add passenger.\n";
        return;
    }
    rear_sak++;
    queue_sak[rear_sak] = passenger_sak;
    if (front_sak == -1) front_sak = 0;
    cout << "\nPassenger \"" << passenger_sak << "\" added to queue.\n";
}

void dequeue_sak() {
    if (front_sak == -1) {
        cout << "\nNo passengers waiting.\n";
        return;
    }
    cout << "\nPassenger \"" << queue_sak[front_sak] << "\" served.\n";
    front_sak++;
    if (front_sak > rear_sak) front_sak = rear_sak = -1;
}

void displayFront_sak() {
    if (front_sak == -1) {
        cout << "\nNo passengers waiting.\n";
        return;
    }
    cout << "\nPassenger at front: " << queue_sak[front_sak] << endl;
}

void displayCount_sak() {
    if (front_sak == -1) {
        cout << "\nNo passengers left in queue.\n";
        return;
    }
    cout << "\nNumber of passengers left in queue: " << (rear_sak - front_sak + 1) << endl;
}

int main() {
    int choice_sak;
    string passenger_sak;

    while (true) {
        cout << "\n1. Add Passenger\n2. Serve Passenger\n3. Display Front\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_sak;
        cin.ignore();

        switch (choice_sak) {
            case 1:
                cout << "Enter passenger name: ";
                getline(cin, passenger_sak);
                enqueue_sak(passenger_sak);
                break;
            case 2:
                dequeue_sak();
                break;
            case 3:
                displayFront_sak();
                break;
            case 4:
                displayCount_sak();
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}