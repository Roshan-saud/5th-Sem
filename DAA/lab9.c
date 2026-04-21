#include <stdio.h>

// function to check subset sum using recursion
int subsetSum(int set[], int n, int sum)
{
    // if sum becomes 0, subset is found
    if(sum == 0)
        return 1;

    // if no elements left but sum not 0
    if(n == 0)
        return 0;

    // if last element is greater than sum, ignore it
    if(set[n-1] > sum)
        return subsetSum(set, n-1, sum);

    // check two cases: include or exclude element
    return subsetSum(set, n-1, sum) ||
           subsetSum(set, n-1, sum - set[n-1]);
}

int main()
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = 6;

    if(subsetSum(set, n, sum))
        printf("Subset with given sum exists");
    else
        printf("No subset with given sum");

    return 0;
}