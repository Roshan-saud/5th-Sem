//Euler totient function

#include <stdio.h>

// Function to compute Euler Totient Function using prime factorization
int phi(int n) {
    int result = n;

    for (int p = 2; p * p <= n; p++) {

        // If p is a prime factor of n
        if (n % p == 0) {

            // Remove all multiples of p from n
            while (n % p == 0) {
                n = n/ p;  
            }

            // Apply formula: result = result * (1 - 1/p)
            result = result * (p - 1) / p;
        }
    }

    // If n is still greater than 1, then it is prime
    if (n > 1) {
        result = result * (n - 1) / n;
    }

    return result;
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Totient is not defined for this input.\n");
        return 0;
    }

    printf("Euler Totient Function φ(%d) = %d\n", n, phi(n));

    return 0;
}