#include <stdio.h>
// Function to compute (base^exp) % mod
long long power(long long base, long long exp, long long mod)
{
    long long result = 1;
    base = base % mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}
// Function to find modular inverse using Fermat's theorem
long long modInverse(long long a, long long p)
{
    return power(a, p - 2, p);
}
int main()
{
    long long p, g, x, y;
    long long m, k;
    long long c1, c2, s, decrypted;
    printf("Enter prime number p: ");
    scanf("%lld", &p);
    printf("Enter primitive root g: ");
    scanf("%lld", &g);
    printf("Enter private key x: ");
    scanf("%lld", &x);
    // Public key calculation
    y = power(g, x, p);
    printf("\nPublic Key Calculation:\n");
    printf("y = g^x mod p\n");
    printf("y = %lld^%lld mod %lld = %lld\n", g, x, p, y);
    printf("\nPublic Key (p, g, y) = (%lld, %lld, %lld)\n", p, g, y);
    printf("Private Key x = %lld\n", x);
    // Encryption
    printf("\nEnter message m: ");
    scanf("%lld", &m);
    printf("Enter random integer k: ");
    scanf("%lld", &k);
    c1 = power(g, k, p);
    c2 = (m * power(y, k, p)) % p;
    printf("\nEncryption Formulas:\n");
    printf("C1 = g^k mod p = %lld\n", c1);
    printf("C2 = m * y^k mod p = %lld\n", c2);
    // Decryption
    s = power(c1, x, p);
    decrypted = (c2 * modInverse(s, p)) % p;
    printf("\nDecryption Formulas:\n");
    printf("Shared Secret s = C1^x mod p = %lld\n", s);
    printf("m = C2 * s^-1 mod p = %lld\n", decrypted);
    return 0;
}