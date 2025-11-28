#include <iostream>
using namespace std;

// Function to add two numbers using divide-and-conquer (bitwise
// recursion)
int binarySum(int a, int b) {
    // Base case: if there is no carry, return the sum
    if (b == 0)
        return a;

    // sum without carry
    int sum = a ^ b;

    // carry, shifted left
    int carry = (a & b) << 1;

    // recursive call with sum and carry
    return binarySum(sum, carry);
}

int main() {
    int num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    int result = binarySum(num1, num2);
    cout << "Binary sum of " << num1 << " and " << num2 << " is: " <<
    result << endl;

    return 0;
}
