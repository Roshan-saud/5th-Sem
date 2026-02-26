#include <stdio.h>

// Function to implement Extended Euclidean Algorithm
int extendedEuclid(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extendedEuclid(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcd;
}

int main() {
    int a, m;
    int x, y;

    printf("Enter number (a): ");
    scanf("%d", &a);

    printf("Enter modulus (m): ");
    scanf("%d", &m);

    int gcd = extendedEuclid(a, m, &x, &y);

    if (gcd != 1) {
        printf("Multiplicative inverse does not exist.\n");
    } else {
        int inverse = (x % m + m) % m;  // Make positive
        printf("Multiplicative inverse of %d mod %d is %d\n", a, m, inverse);
    }

    return 0;
}