#include <stdio.h>
// Function to find GCD
int gcd(int a, int b) {
 if (b == 0)
 return a;
 return gcd(b, a % b);
}
// Function to compute (base^exp) % mod
long long power(long long base, long long exp, long long mod) {
 long long result = 1;
 while (exp > 0) {
 result = (result * base) % mod;
 exp--;
 }
 return result;
}
int main() {
 int p, q, n, phi, e, d = 0;
 long long msg, cipher, decrypted;
 // Input primes
 printf("Enter prime number p: ");
 scanf("%d", &p);
 printf("Enter prime number q: ");
 scanf("%d", &q);
 // Show calculation of n
 n = p * q;
 printf("\nCalculation of n:\n");
 printf("n = p * q\n");
 printf("n = %d * %d = %d\n\n", p, q, n);
 // Show calculation of phi
 phi = (p - 1) * (q - 1);
 printf("Calculation of phi:\n");
 printf("phi = (p - 1) * (q - 1)\n");
 printf("phi = (%d - 1) * (%d - 1)\n", p, q);
 printf("phi = %d\n\n", phi);
 // Input e
 printf("Enter value of e (1 < e < %d and gcd(e, %d) = 1): ", phi,phi);
 scanf("%d", &e);
 // Validate e
 if (e <= 1 || e >= phi || gcd(e, phi) != 1) {
 printf("Invalid value of e! It must be co-prime with %d.\n",phi);
 return 0;
 }
 // Calculate d
 for (int i = 1; i < phi; i++) {
 if ((e * i) % phi == 1) {
 d = i;
 break;
 }
 }
 printf("\nPublic Key (e, n): (%d, %d)\n", e, n);
 printf("Private Key (d, n): (%d, %d)\n", d, n);
 // Input message
 printf("\nEnter message (integer < %d): ", n);
 scanf("%lld", &msg);
 // Encryption
 printf("\nEncryption Process:\n");
 printf("Cipher = (Message^e) mod n\n");
 printf("Cipher = (%lld^%d) mod %d\n", msg, e, n);
 cipher = power(msg, e, n);
 printf("Cipher = %lld\n", cipher);
 // Decryption
 printf("\nDecryption Process:\n");
 printf("Message = (Cipher^d) mod n\n");
 printf("Message = (%lld^%d) mod %d\n", cipher, d, n);
 decrypted = power(cipher, d, n);
 printf("Decrypted Message = %lld\n", decrypted);
 return 0;
}