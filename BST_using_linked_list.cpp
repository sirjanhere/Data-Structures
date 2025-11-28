#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

// Create a new node
Node* createNode(int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// INSERTION
Node* insert(Node *root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// ITERATIVE SEARCH
bool search(Node* root, int k) {
    while (root) {
        if (root->data == k)
            return true;
        else if (k < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}

// RECURSIVE SEARCH
Node* searchRec(Node* root, int k) {
    if (root == NULL || root->data == k)
        return root;
    if (k < root->data)
        return searchRec(root->left, k);
    else
        return searchRec(root->right, k);
}

// DELETE BY COPYING
Node* delete_copy(Node *root, int k) {
    if (root == NULL)
        return NULL;

    if (k < root->data)
        root->left = delete_copy(root->left, k);
    else if (k > root->data)
        root->right = delete_copy(root->right, k);
    else {
        Node* temp = root;

        // Case 1: Only right child
        if (root->left == NULL)
            root = root->right;

        // Case 2: Only left child
        else if (root->right == NULL)
            root = root->left;

        // Case 3: Two children ? copy from inorder predecessor (max of left subtree)
        else {
            Node* prev = root;
            temp = root->left;
            while (temp->right != NULL) {
                prev = temp;
                temp = temp->right;
            }

            // Copy predecessor’s data
            root->data = temp->data;

            // Fix parent link
            if (prev == root)
                prev->left = temp->left;
            else
                prev->right = temp->left;

            delete temp;
            return root;
        }

        delete temp;
    }
    return root;
}

// COUNT LEAVES
int count_leave(Node *root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return count_leave(root->left) + count_leave(root->right);
}

// COUNT NON-LEAVES
int count_nonleave(Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    return 1 + count_nonleave(root->left) + count_nonleave(root->right);
}

// HEIGHT OF TREE
int height(Node *root) {
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

// MIN VALUE
int min(Node *root) {
    while (root && root->left)
        root = root->left;
    return root ? root->data : -1;
}

// MAX VALUE
int max(Node *root) {
    while (root && root->right)
        root = root->right;
    return root ? root->data : -1;
}

// COUNT TOTAL NODES
int count_nodes(Node *root) {
    if (root == NULL)
        return 0;
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

// SUM OF ALL NODES
int sum_nodes(Node* root) {
    if (root == NULL)
        return 0;
    return root->data + sum_nodes(root->left) + sum_nodes(root->right);
}

// RECURSIVE TRAVERSALS
void inorder(Node *root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
void preorder(Node *root) {
    if (root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node *root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

// ITERATIVE INORDER
void inorder_iterative(Node* root) {
    stack<Node*> s;
    Node* cur = root;
    while (cur || !s.empty()) {
        while (cur) {
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top();
        s.pop();
        cout << cur->data << " ";
        cur = cur->right;
    }
}

// ITERATIVE PREORDER
void preorder_iterative(Node* root) {
    if (!root) return;
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        Node* node = s.top();
        s.pop();
        cout << node->data << " ";
        if (node->right) s.push(node->right);
        if (node->left) s.push(node->left);
    }
}

// ITERATIVE POSTORDER
void postorder_iterative(Node* root) {
    if (!root) return;
    stack<Node*> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        Node* node = s1.top();
        s1.pop();
        s2.push(node);
        if (node->left) s1.push(node->left);
        if (node->right) s1.push(node->right);
    }
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

// LEVEL ORDER (Breadth-first)
void levelorder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        cout << node->data << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

// MAIN MENU DRIVER
int main() {
    Node* root = NULL;
    int choice, val;

    cout << "BST Menu:\n";
    do {
        cout << "\n1. Insert"
                "\n2. Search (Iterative)"
                "\n3. Search (Recursive)"
                "\n4. Delete by Copying"
                "\n5. Count Leaves"
                "\n6. Count Non-Leaves"
                "\n7. Height"
                "\n8. Min Value"
                "\n9. Max Value"
                "\n10. Count Nodes"
                "\n11. Inorder (Recursive)"
                "\n12. Preorder (Recursive)"
                "\n13. Postorder (Recursive)"
                "\n14. Inorder (Iterative)"
                "\n15. Preorder (Iterative)"
                "\n16. Postorder (Iterative)"
                "\n17. Level Order (BFS)"
                "\n18. Sum of All Nodes"
                "\n0. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                root = insert(root, val);
                break;

            case 2:
                cout << "Enter value to search: ";
                cin >> val;
                cout << (search(root, val) ? "Found" : "Not Found") << endl;
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> val;
                cout << (searchRec(root, val) ? "Found" : "Not Found") << endl;
                break;

            case 4:
                cout << "Enter value to delete: ";
                cin >> val;
                root = delete_copy(root, val);
                break;

            case 5:
                cout << "Leaves: " << count_leave(root) << endl;
                break;

            case 6:
                cout << "Non-Leaves: " << count_nonleave(root) << endl;
                break;

            case 7:
                cout << "Height: " << height(root) << endl;
                break;

            case 8:
                cout << "Min: " << min(root) << endl;
                break;

            case 9:
                cout << "Max: " << max(root) << endl;
                break;

            case 10:
                cout << "Total Nodes: " << count_nodes(root) << endl;
                break;

            case 11:
                cout << "Inorder: ";
                inorder(root);
                cout << endl;
                break;

            case 12:
                cout << "Preorder: ";
                preorder(root);
                cout << endl;
                break;

            case 13:
                cout << "Postorder: ";
                postorder(root);
                cout << endl;
                break;

            case 14:
                cout << "Inorder (Iterative): ";
                inorder_iterative(root);
                cout << endl;
                break;

            case 15:
                cout << "Preorder (Iterative): ";
                preorder_iterative(root);
                cout << endl;
                break;

            case 16:
                cout << "Postorder (Iterative): ";
                postorder_iterative(root);
                cout << endl;
                break;

            case 17:
                cout << "Level Order: ";
                levelorder(root);
                cout << endl;
                break;

            case 18:
                cout << "Sum of All Nodes: " << sum_nodes(root) << endl;
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
