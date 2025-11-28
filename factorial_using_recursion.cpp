#include <iostream>
using namespace std;

// Recursive function to compute factorial
long long factorial(int n) {
    if (n <= 1)  // base case
        return 1;

    return n * factorial(n - 1);  // recursive step
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (n < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        cout << "Factorial of " << n << " is: " << factorial(n) << endl;
    }

    return 0;
}
