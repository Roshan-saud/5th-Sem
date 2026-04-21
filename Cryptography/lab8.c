#include <stdio.h>

/*
    Function to compute T = b^m mod n efficiently
    b13= b8 × b4 × b1
*/
long long modPower(long long base, long long exp, long long mod)
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


/*
    Miller-Rabin Test Function
    n = given integer
    b = base value
*/
int millerRabin(long long n, long long b)
{
    if (n <= 1 || n == 4)
        return 0;   // Composite

    if (n <= 3)
        return 1;   // Prime


    /*
        Step 1:
        Write n − 1 = m × 2^k
        where m is odd
    */
    long long m = n - 1;
    int k = 0;

    while (m % 2 == 0)
    {
        m = m / 2;
        k++;
    }


    /*
        Step 2:
        Compute T = b^m mod n
    */
    long long T = modPower(b, m, n);


    /*
        Step 3:
        Check first condition
    */
    if (T == 1 || T == n - 1)
        return 1;   // Probably Prime


    /*
        Step 4:
        Repeat squaring T up to k−1 times
    */
    for (int i = 1; i < k; i++)
    {
        T = (T * T) % n;

        if (T == n - 1)
            return 1;   // Probably Prime
    }


    /*
        If none satisfied → Composite
    */
    return 0;
}


int main()
{
    long long n, b;

    printf("Enter the integer (n): ");
    scanf("%lld", &n);

    printf("Enter the base value (b): ");
    scanf("%lld", &b);

    if (b <= 1 || b >= n)
    {
        printf("Invalid base value!\n");
        return 0;
    }

    if (millerRabin(n, b))
        printf("%lld is Probably Prime.\n", n);
    else
        printf("%lld is Composite.\n", n);

    return 0;
}



// long long modPower(long long base, long long exp, long long mod)
// {
//     long long result = 1;
//     base = base % mod;

//     while (exp > 0)
//     {
//         if (exp % 2 == 1)
//             result = (result * base) % mod;

//         base = (base * base) % mod;
//         exp = exp / 2;
//     }

//     return result;
// }


// /*
//     Miller-Rabin Test Function
//     n = given integer
//     b = base value
// */
// int millerRabin(long long n, long long b)
// {
//     if (n <= 1 || n == 4)
//         return 0;   // Composite

//     if (n <= 3)
//         return 1;   // Prime


//     /*
//         Step 1:
//         Write n − 1 = m × 2^k
//         where m is odd
//     */
//     long long m = n - 1;
//     int k = 0;

//     while (m % 2 == 0)
//     {
//         m = m / 2;
//         k++;
//     }


//     /*
//         Step 2:
//         Compute T = b^m mod n
//     */
//     long long T = modPower(b, m, n);


//     /*
//         Step 3:
//         Check first condition
//     */
//     if (T == 1 || T == n - 1)
//         return 1;   // Probably Prime


//     /*
//         Step 4:
//         Repeat squaring T up to k−1 times
//     */
//     for (int i = 1; i < k; i++)
//     {
//         T = (T * T) % n;

//         if (T == n - 1)
//             return 1;   // Probably Prime
//     }


//     /*
//         If none satisfied → Composite
//     */
//     return 0;
// }


// int main()
// {
//     long long n, b;

//     printf("Enter the integer (n): ");
//     scanf("%lld", &n);

//     printf("Enter the base value (b): ");
//     scanf("%lld", &b);

//     if (b <= 1 || b >= n)
//     {
//         printf("Invalid base value!\n");
//         return 0;
//     }

//     if (millerRabin(n, b))
//         printf("%lld is Probably Prime.\n", n);
//     else
//         printf("%lld is Composite.\n", n);

//     return 0;
// } 