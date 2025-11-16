#include <iostream>
using namespace std;

struct Node_sak {
    int data_sak;
    Node_sak *left_sak, *right_sak;
};

Node_sak* createNode_sak(int val_sak) {
    Node_sak* newNode_sak = new Node_sak;
    newNode_sak->data_sak = val_sak;
    newNode_sak->left_sak = newNode_sak->right_sak = NULL;
    return newNode_sak;
}

Node_sak* createTree_sak() {
    int val_sak;
    cout << "Enter data (-1 for no node): ";
    cin >> val_sak;
    if (val_sak == -1) return NULL;
    Node_sak* root_sak = createNode_sak(val_sak);
    cout << "Enter left child of " << val_sak << ": ";
    root_sak->left_sak = createTree_sak();
    cout << "Enter right child of " << val_sak << ": ";
    root_sak->right_sak = createTree_sak();
    return root_sak;
}

void inorder_sak(Node_sak* root_sak) {
    if (root_sak == NULL) return;
    inorder_sak(root_sak->left_sak);
    cout << root_sak->data_sak << " ";
    inorder_sak(root_sak->right_sak);
}

void preorder_sak(Node_sak* root_sak) {
    if (root_sak == NULL) return;
    cout << root_sak->data_sak << " ";
    preorder_sak(root_sak->left_sak);
    preorder_sak(root_sak->right_sak);
}

int countLeaf_sak(Node_sak* root_sak) {
    if (root_sak == NULL) return 0;
    if (root_sak->left_sak == NULL && root_sak->right_sak == NULL)
        return 1;
    return countLeaf_sak(root_sak->left_sak) + countLeaf_sak(root_sak->right_sak);
}

void mirrorTree_sak(Node_sak* root_sak) {
    if (root_sak == NULL) return;
    Node_sak* temp_sak = root_sak->left_sak;
    root_sak->left_sak = root_sak->right_sak;
    root_sak->right_sak = temp_sak;
    mirrorTree_sak(root_sak->left_sak);
    mirrorTree_sak(root_sak->right_sak);
}

int main() {
    Node_sak* root_sak = createTree_sak();
    cout << "\nInorder Traversal: ";
    inorder_sak(root_sak);
    cout << "\nPreorder Traversal: ";
    preorder_sak(root_sak);
    cout << "\nNumber of Leaf Nodes: " << countLeaf_sak(root_sak);
    mirrorTree_sak(root_sak);
    cout << "\nInorder Traversal of Mirror Tree: ";
    inorder_sak(root_sak);
    return 0;
}