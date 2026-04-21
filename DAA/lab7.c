#include <stdio.h>
#include <limits.h>

int matrixChainOrder(int p[], int n)
{
    int m[n][n];   // DP table to store minimum cost
    int i, j, k, L, q;

    // cost is zero when multiplying one matrix
    for(i = 1; i < n; i++)
        m[i][i] = 0;

    // L is chain length
    for(L = 2; L < n; L++)
    {
        for(i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;   // initialize with large value

            for(k = i; k <= j - 1; k++)
            {
                // cost formula
                q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];

                // store minimum cost
                if(q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    return m[1][n-1];   // minimum multiplication cost
}

int main()
{
    int arr[] = {10, 20, 30, 40};   // matrix dimensions
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Minimum number of multiplications: %d",
           matrixChainOrder(arr, n));

    return 0;
}