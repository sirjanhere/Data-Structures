#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 100;
int tree[MAX_SIZE];
int size = 0;

// Insert value at next position
void insert(int value) {
    if (size < MAX_SIZE) tree[size++] = value;
    else cout << "Tree is full\n";
}

// Display tree (level order)
void display() {
    cout << "Tree (Level Order): ";
    for (int i = 0; i < size; ++i) cout << tree[i] << " ";
    cout << endl;
}

// Parent of index
int parent(int i) {
    if (i == 0 || i >= size) return -1;
    return tree[(i-1)/2];
}

// Left child of i
int leftChild(int i) {
    int idx = 2*i+1;
    if (idx < size) return tree[idx];
    return -1;
}

// Right child of i
int rightChild(int i) {
    int idx = 2*i+2;
    if (idx < size) return tree[idx];
    return -1;
}

// isRoot
bool isRoot(int i) { return i == 0 && size > 0; }

// getSize
int getSize() { return size; }

// empty
bool empty() { return size <= 0; }

// isExternal (leaf check)
bool isExternal(int i) {
    if (i < 0 || i >= size) return false;
    int left = 2*i+1;
    int right = 2*i+2;
    return ((left >= size || tree[left] == -1) && (right >= size || tree[right] == -1));
}

// root value
int root() {
    if (empty()) {
        cout << "Tree is empty\n";
        return -1;
    }
    return tree[0];
}

// Height from node index i
int height(int i) {
    if (i >= size || tree[i] == -1) return -1;
    int left = 2*i+1;
    int right = 2*i+2;
    int leftHeight = height(left);
    int rightHeight = height(right);
    return 1 + max(leftHeight, rightHeight);
}

// Height of tree
int treeHeight() {
    if (empty()) return -1;
    return height(0);
}

// Depth of node at index i
int depth(int i) {
    if (i < 0 || i >= size || tree[i] == -1) {
        cout << "Invalid index\n";
        return -1;
    }
    int d = 0;
    while (i > 0) {
        i = (i-1)/2;
        d++;
    }
    return d;
}

// Depth of tree (= height if rooted at 0)
int treeDepth() { return treeHeight(); }

// Example main
int main() {
    // Fill with -1 initially
    for (int i = 0; i < MAX_SIZE; ++i) tree[i] = -1;

    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    display();

    cout << "Parent of index 2: " << parent(2) << endl;
    cout << "Children of index 1: " << leftChild(1) << ", " << rightChild(1) << endl;
    cout << "Is root(0): " << isRoot(0) << endl;
    cout << "Size: " << getSize() << endl;
    cout << "Empty: " << empty() << endl;
    cout << "Is External (3): " << isExternal(3) << endl;
    cout << "Root value: " << root() << endl;
    cout << "Node Height (1): " << height(1) << endl;
    cout << "Tree Height: " << treeHeight() << endl;
    cout << "Node Depth (3): " << depth(3) << endl;
    cout << "Tree Depth: " << treeDepth() << endl;

    return 0;
}
