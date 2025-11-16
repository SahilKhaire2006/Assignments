#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Manual Stack implementation
struct Stack {
    Node* arr[50];
    int top;
    Stack() { top = -1; }
    void push(Node* n) { arr[++top] = n; }
    Node* pop() { return arr[top--]; }
    bool isEmpty() { return top == -1; }
};

// Simple queue structure for tree creation
struct Queue {
    Node* arr[50];
    int front, rear;
    Queue() { front = rear = -1; }
    void enqueue(Node* n) {
        if (rear == 49) return;
        if (front == -1) front = 0;
        arr[++rear] = n;
    }
    Node* dequeue() {
        if (front == -1 || front > rear) return NULL;
        return arr[front++];
    }
    bool isEmpty() { return (front == -1 || front > rear); }
};

// Create tree level-wise from user input
Node* createTree() {
    int val;
    cout << "Enter data for root (-1 for no node): ";
    cin >> val;
    if (val == -1) return NULL;

    Node* root = createNode(val);
    Queue q;
    q.enqueue(root);

    while (!q.isEmpty()) {
        Node* current = q.dequeue();
        cout << "Enter left child of " << current->data << " (-1 for no node): ";
        cin >> val;
        if (val != -1) {
            current->left = createNode(val);
            q.enqueue(current->left);
        }
        cout << "Enter right child of " << current->data << " (-1 for no node): ";
        cin >> val;
        if (val != -1) {
            current->right = createNode(val);
            q.enqueue(current->right);
        }
    }
    return root;
}

void inorderNonRecursive(Node* root) {
    Stack s;
    Node* curr = root;
    while (curr != NULL || !s.isEmpty()) {
        while (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

void preorderNonRecursive(Node* root) {
    if (root == NULL) return;
    Stack s;
    s.push(root);
    while (!s.isEmpty()) {
        Node* node = s.pop();
        cout << node->data << " ";
        if (node->right) s.push(node->right);
        if (node->left) s.push(node->left);
    }
}

int countLeafNodes(Node* root) {
    if (root == NULL) return 0;
    int count = 0;
    Stack s;
    s.push(root);
    while (!s.isEmpty()) {
        Node* node = s.pop();
        if (node->left == NULL && node->right == NULL)
            count++;
        if (node->right) s.push(node->right);
        if (node->left) s.push(node->left);
    }
    return count;
}

void mirrorTree(Node* root) {
    if (root == NULL) return;
    Stack s;
    s.push(root);
    while (!s.isEmpty()) {
        Node* node = s.pop();
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;
        if (node->left) s.push(node->left);
        if (node->right) s.push(node->right);
    }
}

int main() {
    Node* root = createTree();

    cout << "\nInorder Traversal: ";
    inorderNonRecursive(root);
    cout << "\nPreorder Traversal: ";
    preorderNonRecursive(root);
    cout << "\nNumber of Leaf Nodes: " << countLeafNodes(root);
    mirrorTree(root);
    cout << "\nInorder of Mirror Tree: ";
    inorderNonRecursive(root);
    return 0;
}
