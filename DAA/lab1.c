// 24th Dec, 09/09 | Deadline: 16

/*
## Title

## Objective

## Theory:
 - Name
 - Algorithm
 - Trace (not for lab1 but for other)
 - Time and space complexity

## Code: Handwritten

## Output:

## Conclusion
*/

/*
Title: Iterative Algorithms Implementation

Objective:
 - To implement GCD using Iteration
 - To implement Fibonacci series using Iteration
 - To implement Factorial using Iteration
 - To implement Linear Search using Iteration
*/

#include <stdio.h>
#include <stdlib.h>

#define size 5

int arr[size], i, j, opr, result, a, b, n, c;

/* Function to find GCD using iteration */
int GCD(int a, int b)
{
    int r;
    while (1)
    {
        if (a == 0)
            return b;
        else if (b == 0)
            return a;

        r = a % b;
        a = b;
        b = r;
    }
}

/* Function to calculate factorial using iteration */
int fact(int n)
{
    int ft = 1;

    if (n == 0 || n == 1)
        return 1;

    for (i = 1; i <= n; i++)
    {
        ft = ft * i;
    }
    return ft;
}

/* Function for linear search */
int linearSearch(int arr[size], int searchVal)
{
    for (i = 0; i < size; i++)
    {
        if (arr[i] == searchVal)
            return i;
    }
    return -1;
}

/* Function to print Fibonacci series */
void fibonacci(int n)
{
    a = 0;
    b = 1;
    c = 0;

    for (i = 1; i <= n; i++)
    {
        printf("%d ", c);
        a = b;
        b = c;
        c = a + b;
    }
}

/* Main Function */
int main()
{
    do
    {
        printf("\n\nEnter 1 for GCD\n");
        printf("Enter 2 for Factorial\n");
        printf("Enter 3 for Linear Search\n");
        printf("Enter 4 for Fibonacci Series\n");
        printf("Enter 5 for Exit\n");
        printf("Enter a number (1-5): ");
        scanf("%d", &opr);
        switch (opr)
        {

        case 1:
            printf("Enter value of a and b:\n");
            scanf("%d %d", &a, &b);
            printf("The value of GCD(%d, %d) is: %d", a, b, GCD(a, b));
            break;

        case 2:
            printf("Enter a number for factorial: ");
            scanf("%d", &n);
            printf("The factorial value of %d! is %d", n, fact(n));
            break;

        case 3:
            printf("Enter an array of size 5:\n");
            for (i = 0; i < size; i++)
            {
                scanf("%d", &arr[i]);
            }

            printf("Enter a number to search: ");
            scanf("%d", &a);

            int pos = linearSearch(arr, a);
            if (pos == -1)
                printf("Element not found\n");
            else
                printf("Element found at index: %d\n", pos);

            break;
        

        case 4:
            printf("Enter the number of terms to print: ");
            scanf("%d", &a);
            fibonacci(a);
            break;

        case 5:
            printf("Exit successfully\n");
            break;

        default:
            printf("Enter a valid choice.\n");
            break;
        }
    } while (opr != 5);

    return 0;
}
