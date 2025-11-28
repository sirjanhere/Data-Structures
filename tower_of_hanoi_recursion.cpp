#include <iostream>
using namespace std;

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char source, char auxiliary, char target) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << target << endl;
        return;
    }

    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, target, auxiliary);

    // Move the nth disk from source to target
    cout << "Move disk " << n << " from " << source << " to " << target << endl;

    // Move n-1 disks from auxiliary to target
    towerOfHanoi(n - 1, auxiliary, source, target);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    cout << "Sequence of moves:\n";
    towerOfHanoi(n, 'A', 'B', 'C'); // A=source, B=auxiliary, C=target

    return 0;
}
