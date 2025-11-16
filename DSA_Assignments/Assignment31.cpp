#include <iostream>
using namespace std;

struct Node_sak {
    int data_sak;
    Node_sak *left_sak, *right_sak;
};

Node_sak* createNode_sak(int data_sak) {
    Node_sak* newNode_sak = new Node_sak();
    newNode_sak->data_sak = data_sak;
    newNode_sak->left_sak = newNode_sak->right_sak = NULL;
    return newNode_sak;
}

Node_sak* insertNode_sak(Node_sak* root_sak, int data_sak) {
    if (root_sak == NULL)
        return createNode_sak(data_sak);
    if (data_sak < root_sak->data_sak)
        root_sak->left_sak = insertNode_sak(root_sak->left_sak, data_sak);
    else if (data_sak > root_sak->data_sak)
        root_sak->right_sak = insertNode_sak(root_sak->right_sak, data_sak);
    return root_sak;
}

Node_sak* minValueNode_sak(Node_sak* node_sak) {
    Node_sak* current_sak = node_sak;
    while (current_sak && current_sak->left_sak != NULL)
        current_sak = current_sak->left_sak;
    return current_sak;
}

Node_sak* deleteNode_sak(Node_sak* root_sak, int key_sak) {
    if (root_sak == NULL)
        return root_sak;
    if (key_sak < root_sak->data_sak)
        root_sak->left_sak = deleteNode_sak(root_sak->left_sak, key_sak);
    else if (key_sak > root_sak->data_sak)
        root_sak->right_sak = deleteNode_sak(root_sak->right_sak, key_sak);
    else {
        if (root_sak->left_sak == NULL) {
            Node_sak* temp_sak = root_sak->right_sak;
            delete root_sak;
            return temp_sak;
        } else if (root_sak->right_sak == NULL) {
            Node_sak* temp_sak = root_sak->left_sak;
            delete root_sak;
            return temp_sak;
        }
        Node_sak* temp_sak = minValueNode_sak(root_sak->right_sak);
        root_sak->data_sak = temp_sak->data_sak;
        root_sak->right_sak = deleteNode_sak(root_sak->right_sak, temp_sak->data_sak);
    }
    return root_sak;
}

void levelOrder_sak(Node_sak* root_sak) {
    if (root_sak == NULL) {
        cout << "Tree is empty\n";
        return;
    }

    Node_sak* queue_sak[100];
    int front_sak = 0, rear_sak = 0;
    queue_sak[rear_sak++] = root_sak;

    cout << "Levelwise Display: ";
    while (front_sak < rear_sak) {
        Node_sak* current_sak = queue_sak[front_sak++];
        cout << current_sak->data_sak << " ";
        if (current_sak->left_sak)
            queue_sak[rear_sak++] = current_sak->left_sak;
        if (current_sak->right_sak)
            queue_sak[rear_sak++] = current_sak->right_sak;
    }
    cout << endl;
}

int main() {
    Node_sak* root_sak = NULL;
    int choice_sak, value_sak;
    while (true) {
        cout << "\n1. Insert Node\n2. Delete Node\n3. Levelwise Display\n4. Exit\nEnter choice: ";
        cin >> choice_sak;
        switch (choice_sak) {
            case 1:
                cout << "Enter value: ";
                cin >> value_sak;
                root_sak = insertNode_sak(root_sak, value_sak);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value_sak;
                root_sak = deleteNode_sak(root_sak, value_sak);
                break;
            case 3:
                levelOrder_sak(root_sak);
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}
