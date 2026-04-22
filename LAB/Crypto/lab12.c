#include <stdio.h>

// Function to calculate gcd
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to check primitive root modulo p
int isPrimitiveRoot(int g, int p)
{
    if (gcd(g, p) != 1)
    {
        printf("\nSince gcd(%d, %d) != 1, g cannot be a primitive root.\n", g, p);
        return 0;
    }

    int value = 1;

    for (int i = 1; i < p; i++)
    {
        value = (value * g) % p;

        if (value == 1 && i != p - 1)
        {
            printf("\n%d^%d mod %d = 1 (appeared too early)\n", g, i, p);
            return 0;
        }
    }

    return 1;
}

// Function to compute (base^exp) % mod
long long powerMod(long long base, long long exp, long long mod)
{
    long long result = 1;

    for (long long i = 0; i < exp; i++)
    {
        result = (result * base) % mod;
    }

    return result;
}

int main()
{
    long long p, g;
    long long a, b;
    long long A, B;
    long long keyA, keyB;

    // Input prime and primitive root
    printf("Enter prime number (p): ");
    scanf("%lld", &p);

    printf("Enter primitive root candidate (g): ");
    scanf("%lld", &g);

    // Check if g is primitive root
    if (!isPrimitiveRoot(g, p))
    {
        printf("\n%lld is NOT a primitive root modulo %lld. Choose another g.\n", g, p);
        return 0;
    }
    else
    {
        printf("\n%lld is a valid primitive root modulo %lld.\n", g, p);
    }

    // Input private keys
    printf("\nEnter Alice's private key (a): ");
    scanf("%lld", &a);

    printf("Enter Bob's private key (b): ");
    scanf("%lld", &b);

    // Compute public keys
    A = powerMod(g, a, p);
    B = powerMod(g, b, p);

    printf("\nAlice's Public Key (A): %lld\n", A);
    printf("Bob's Public Key (B): %lld\n", B);

    // Compute shared secret key
    keyA = powerMod(B, a, p);
    keyB = powerMod(A, b, p);

    printf("\nShared Key computed by Alice: %lld\n", keyA);
    printf("Shared Key computed by Bob: %lld\n", keyB);

    // Verify key exchange
    if (keyA == keyB)
        printf("\nKey Exchange Successful! Both keys match.\n");
    else
        printf("\nKey Exchange Failed!\n");

    return 0;
}