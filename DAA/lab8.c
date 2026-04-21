#include <stdio.h>

int main()
{
    int i, w;
    int n = 4;              // number of items
    int W = 7;              // knapsack capacity
    int wt[] = {1,3,4,5};   // weights
    int val[] = {1,4,5,7};  // values

    int K[n+1][W+1];        // DP table

    // Build DP table
    for(i = 0; i <= n; i++){
        for(w = 0; w <= W; w++){
            if(i == 0 || w == 0)
                K[i][w] = 0;   // base case
            else if(wt[i-1] <= w){
                // max(include item, exclude item)
                if(val[i-1] + K[i-1][w-wt[i-1]] > K[i-1][w])
                    K[i][w] = val[i-1] + K[i-1][w-wt[i-1]];
                else
                    K[i][w] = K[i-1][w];
            }
            else
                K[i][w] = K[i-1][w]; // cannot include item
        }
    }

    printf("Maximum Profit = %d\n", K[n][W]);

    // Backtracking to find selected items
    printf("Selected items: ");

    i = n;
    w = W;

    while(i > 0 && w > 0){
        if(K[i][w] != K[i-1][w]){  // item included
            printf("%d ", i);
            w = w - wt[i-1];       // reduce capacity
        }
        i--;
    }

    return 0;
}