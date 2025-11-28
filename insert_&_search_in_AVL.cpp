#include <iostream>
using namespace std;

// Node structure for AVL Tree
struct Node {
    int key;
    Node *left;
    Node *right;
    int height;
    Node(int k) {
        key = k;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

// Utility function to get the height of the node
int getHeight(Node *node) {
    if (node == NULL) return 0;
    return node->height;
}

// Utility function to get the balance factor
int getBalance(Node *node) {
    if (node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Utility function to update height
void updateHeight(Node *node) {
    if (node != NULL)
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

// Right rotation
Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;
    // Rotate
    x->right = y;
    y->left = T2;
    // Update heights
    updateHeight(y);
    updateHeight(x);
    return x;
}

// Left rotation
Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;
    // Rotate
    y->left = x;
    x->right = T2;
    // Update heights
    updateHeight(x);
    updateHeight(y);
    return y;
}

// Insert operation
Node* insert(Node* node, int key) {
    if (node == NULL)
        return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Duplicate keys not allowed

    updateHeight(node);
    int balance = getBalance(node);

    // Balancing
    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // No balancing needed
    return node;
}

// Search operation
bool search(Node* node, int key) {
    while (node != NULL) {
        if (key == node->key)
            return true;
        else if (key < node->key)
            node = node->left;
        else
            node = node->right;
    }
    return false;
}

// Preorder Traversal for verification (no range-based loops)
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    Node *root = NULL;
    int choice, val;
    cout << "AVL Tree Insert and Search Operations\n";

    while (true) {
        cout << "\n1. Insert\n2. Search\n3. Preorder Traversal\n4. Exit\nEnter your choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter value to insert: ";
            cin >> val;
            root = insert(root, val);
            cout << "Inserted " << val << " (if not a duplicate)" << endl;
        } else if (choice == 2) {
            cout << "Enter value to search: ";
            cin >> val;
            if (search(root, val))
                cout << val << " is found in the AVL tree." << endl;
            else
                cout << val << " is NOT found in the AVL tree." << endl;
        } else if (choice == 3) {
            cout << "Preorder traversal: ";
            preorder(root);
            cout << endl;
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
