#include <iostream>
using namespace std;

#define MAX_SAK 50

int queue_sak[MAX_SAK];
int front_sak[2] = {-1, -1};
int rear_sak[2] = {-1, -1};
int size_sak = MAX_SAK / 2;

void enqueue_sak(int queue_no_sak, int val_sak) {
    int start_sak = queue_no_sak * size_sak;
    if (rear_sak[queue_no_sak] == size_sak - 1) {
        cout << "\nQueue Overflow in Queue " << queue_no_sak + 1 << "\n";
        return;
    }
    rear_sak[queue_no_sak]++;
    queue_sak[start_sak + rear_sak[queue_no_sak]] = val_sak;
    if (front_sak[queue_no_sak] == -1) front_sak[queue_no_sak] = 0;
    cout << "\nInserted " << val_sak << " into Queue " << queue_no_sak + 1 << "\n";
}

void dequeue_sak(int queue_no_sak) {
    int start_sak = queue_no_sak * size_sak;
    if (front_sak[queue_no_sak] == -1 || front_sak[queue_no_sak] > rear_sak[queue_no_sak]) {
        cout << "\nQueue Underflow in Queue " << queue_no_sak + 1 << "\n";
        return;
    }
    cout << "\nDeleted " << queue_sak[start_sak + front_sak[queue_no_sak]] << " from Queue " << queue_no_sak + 1 << "\n";
    front_sak[queue_no_sak]++;
    if (front_sak[queue_no_sak] > rear_sak[queue_no_sak]) front_sak[queue_no_sak] = rear_sak[queue_no_sak] = -1;
}

void display_sak(int queue_no_sak) {
    int start_sak = queue_no_sak * size_sak;
    if (front_sak[queue_no_sak] == -1) {
        cout << "\nQueue " << queue_no_sak + 1 << " is empty\n";
        return;
    }
    cout << "\nQueue " << queue_no_sak + 1 << " elements:\n";
    for (int i_sak = front_sak[queue_no_sak]; i_sak <= rear_sak[queue_no_sak]; i_sak++) {
        cout << queue_sak[start_sak + i_sak] << " ";
    }
    cout << "\n";
}

int main() {
    int choice_sak, queue_no_sak, val_sak;

    while (true) {
        cout << "\n1. Add Queue\n2. Delete from Queue\n3. Display Queue\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_sak;

        switch (choice_sak) {
            case 1:
                cout << "Select Queue (1 or 2): ";
                cin >> queue_no_sak;
                queue_no_sak--;
                cout << "Enter value to insert: ";
                cin >> val_sak;
                enqueue_sak(queue_no_sak, val_sak);
                break;
            case 2:
                cout << "Select Queue (1 or 2): ";
                cin >> queue_no_sak;
                queue_no_sak--;
                dequeue_sak(queue_no_sak);
                break;
            case 3:
                cout << "Select Queue (1 or 2): ";
                cin >> queue_no_sak;
                queue_no_sak--;
                display_sak(queue_no_sak);
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}