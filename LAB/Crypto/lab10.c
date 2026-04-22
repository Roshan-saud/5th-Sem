// primitive root

#include <stdio.h>   


// -------------------- GCD FUNCTION --------------------
int gcd(int a, int b) {

    // Repeat until b becomes 0
    while (b != 0) {
        int temp = b;      
        b = a % b;         
        a = temp;          
    }
    return a;
}


// -------------------- POWER FUNCTION --------------------
// This function calculates (base^exp) % mod
int power(int base, int exp, int m) {

    int result = 1;   // Initialize result as 1

    // Multiply base 'exp' times
    for(int i = 0; i < exp; i++) {
        result = (result * base) % m;  
        // Take mod each time to keep number small
    }

    return result;    // Return final result
}


// -------------------- MAIN FUNCTION --------------------
int main() {

    int g, n;      // g = possible primitive root
                   // n = prime number
    int flag = 1;  // assume primitive root initially


    printf("Enter value of g (possible primitive root): ");
    scanf("%d", &g);

    printf("Enter value of n (prime number): ");
    scanf("%d", &n);


    // ---------- STEP 1: CHECK GCD CONDITION ----------
    // A primitive root must be coprime with n
    // So gcd(g, n) must be 1

    if(gcd(g, n) != 1) {
        printf("%d is NOT a primitive root of %d\n", g, n);
        return 0;   // Stop program if condition fails
    }


    // ---------- STEP 2: CHECK POWERS ----------
    // We check g^i mod n, for i=1 to n-1

    for(int i = 1; i < n; i++) {

    int val = power(g, i, n);   // calculate g^i mod n

    printf(" %d^%d mod %d =  %d\n",g, i,n, val);   // print trace table

    if(val == 1 && i < n - 1) {
        flag = 0;
        break;
    }
}

    // ---------- FINAL RESULT ----------
    if(flag)
        printf("%d is a primitive root of %d\n", g, n);
    else
        printf("%d is NOT a primitive root of %d\n", g, n);

    return 0;  
}













// Because modular powers always form a cycle:

// If some number repeats early, the cycle length is less than p-1

// That automatically makes 1 appear before i = p-1

// So checking 1 early = automatically handles repetition of other numbers.

// i = 3 → 4^3 mod 7 = 1

// i < n-1 → early 1 detected → flag = 0 → not primitive root

// Because the cycle is shorter than 6 (n-1), numbers like 4 repeated → the code detects it implicitly through early 1.

// So the cycle repeats.





// So if 1 comes at i = k < n-1, it must repeat in cycles.
// It will not "disappear later".
// You asked:
// What if 1 comes earlier but doesn't come later?
// Actually, this situation is mathematically impossible.