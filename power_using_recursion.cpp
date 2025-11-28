#include <iostream>
using namespace std;

// Recursive function to calculate x^n
double power(double x, int n) {
    if (n == 0)        // Base case: any number to the power 0 is 1
        return 1;
    else if (n > 0)    // Positive exponent
        return x * power(x, n - 1);
    else               // Negative exponent
        return 1 / power(x, -n);
}

int main() {
    double x;
    int n;

    cout << "Enter the base (x): ";
    cin >> x;
    cout << "Enter the exponent (n): ";
    cin >> n;

    double result = power(x, n);
    cout << x << " raised to the power " << n << " is: " << result <<
    endl;

    return 0;
}
