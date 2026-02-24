#include <stdio.h>
#include <stdlib.h>

// Simple function to calculate (a^(p-1)) % n  |  a^(p-1) = 1 (mod p)      
long long simple_power(long long base, long long power, long long n) {
    long long result = 1;
    long long i;

    for (i = 0; i < power; i++) {
        result = (result * base) % n;
    }

    return result;
}

// Fermat Test
int fermat_test(long long n, long long a) {

    if (n <= 1)
        return 0;


    int i;

     if (simple_power(a, n - 1, n) != 1)
        return 0;
    

    return 1;   // Probably prime
}

int main() {

    long long n,a;

    printf("Enter a number: ");
    scanf("%lld", &n);
	printf("Enter a base: ");
    scanf("%lld", &a);


    if (fermat_test(n,a)){
    	printf("Since  %lld^(%lld-1) = 1(mod %d)  is true\n",a,n,n);
        printf("Hence, %lld is probably prime.\n", n);	
	}

    else{
    printf("Since  %lld^(%lld-1) = 1(mod %d)  is not true\n",a,n,n);
        printf("Hence, %lld is not prime.\n", n);	
	}
    return 0;
}