#include <stdio.h>

// Function to find the GCD using recursion
int findGCD(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return findGCD(b, a % b);
    }
}

int main() {
    int num1, num2;

    // Get user input
    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    // Validate input
    if (num1 < 0 || num2 < 0) {
        printf("Please enter non-negative numbers.\n");
        return 1;  // Exit with an error code
    }

    // Find and display the GCD
    int gcd = findGCD(num1, num2);
    printf("The GCD of %d and %d is: %d\n", num1, num2, gcd);

    return 0;  // Exit successfully
}
