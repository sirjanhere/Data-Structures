#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right, *parent;
};

Node* createNode(int value, Node *parent = NULL) {
    Node* node = new Node;
    node->data = value;
    node->left = node->right = NULL;
    node->parent = parent;
    return node;
}

// Insert using user choice for left/right
Node* insert(Node* root, int value) {
    if (root == NULL) return createNode(value);
    char choice;
    cout << "Current Node: " << root->data << ". Insert left (l) or right (r)? ";
    cin >> choice;
    if (choice == 'l' || choice == 'L') {
        if (!root->left) root->left = createNode(value, root);
        else insert(root->left, value);
    } else if (choice == 'r' || choice == 'R') {
        if (!root->right) root->right = createNode(value, root);
        else insert(root->right, value);
    } else {
        cout << "Invalid choice! Please enter 'l' or 'r'.\n";
        insert(root, value);
    }
    return root;
}

// Traversals
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
void preorder(Node* root) {
    if (root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

// Height and Depth
int height(Node* root) {
    if (!root) return -1;
    return 1 + max(height(root->left), height(root->right));
}
int depth(Node* root, Node* p) {
    if (!p) return -1;
    if (p == root) return 0;
    return 1 + depth(root, p->parent);
}

// Size
int getSize(Node* root) {
    if (!root) return 0;
    return 1 + getSize(root->left) + getSize(root->right);
}

// Utility: Empty?
bool empty(Node* root) { return root == NULL; }

// Utility: Root data
void rootData(Node* root) {
    if (!root) cout << "Tree is empty\n";
    else cout << "Root: " << root->data << endl;
}

// isRoot and isExternal(leaf)
void isRoot(Node* p) {
    if (!p) cout << "Invalid node\n";
    else if (!p->parent) cout << "Yes, it is ROOT\n";
    else cout << "No, not root\n";
}
void isExternal(Node* p) {
    if (!p) cout << "Invalid node\n";
    else if (!p->left && !p->right) cout << "Leaf node\n";
    else cout << "Not a leaf\n";
}

// Print parent, left, right child
void printParent(Node* p) {
    if (!p) cout << "Invalid node\n";
    else if (p->parent) cout << "Parent of " << p->data << " is " << p->parent->data << endl;
    else cout << p->data << " is the root.\n";
}
void printLeft(Node* p) {
    if (!p) cout << "Invalid node\n";
    else if (p->left) cout << "Left child of " << p->data << " is " << p->left->data << endl;
    else cout << "No left child\n";
}
void printRight(Node* p) {
    if (!p) cout << "Invalid node\n";
    else if (p->right) cout << "Right child of " << p->data << " is " << p->right->data << endl;
    else cout << "No right child\n";
}

// Leaves and Non-leaves counter
void countLen(Node* root, int &leaves, int &nonleaves) {
    if (!root) return;
    if (!root->left && !root->right) leaves++;
    else nonleaves++;
    countLen(root->left, leaves, nonleaves);
    countLen(root->right, leaves, nonleaves);
}

// MAIN: User input driven tree
int main() {
    Node* root = NULL;
    int n, val;
    cout << "How many nodes to insert? ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Enter value for node " << i+1 << ": ";
        cin >> val;
        root = insert(root, val);
    }

    cout << "\nInorder: "; inorder(root); cout << endl;
    cout << "Preorder: "; preorder(root); cout << endl;
    cout << "Postorder: "; postorder(root); cout << endl;

    if (root && root->left) printParent(root->left);
    if (root) printLeft(root);
    if (root) printRight(root);
    if (root) isRoot(root);
    if (root && root->left) isRoot(root->left);
    if (root && root->right) isExternal(root->right);
    cout << "Size: " << getSize(root) << endl;
    cout << "Empty: " << empty(root) << endl;
    rootData(root);
    cout << "Height of tree: " << height(root) << endl;
    if (root && root->left) cout << "Depth of root->left: " << depth(root, root->left) << endl;
    int leaves = 0, nonleaves = 0;
    countLen(root, leaves, nonleaves);
    cout << "Leaves: " << leaves << ", Non-leaves: " << nonleaves << endl;
    return 0;
}
