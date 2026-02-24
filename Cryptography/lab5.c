#include <stdio.h>

/* P10 and P8 permutation tables */
int P10[10] = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};
int P8[8]  = {6, 3, 7, 4, 8, 5, 10, 9};

/* Function to perform permutation */
void permute(int *key, int *perm, int size, int *output)
{
    for (int i = 0; i < size; i++)
        output[i] = key[perm[i] - 1];
}

/* Left shift function */
void leftShift(int *key, int shifts)
{
    while (shifts--)
    {
        int temp1 = key[0];
        int temp2 = key[5];

        for (int i = 0; i < 4; i++)
        {
            key[i] = key[i + 1];
            key[i + 5] = key[i + 6];
        }

        key[4] = temp1;
        key[9] = temp2;
    }
}

int main()
{
    int key[10], temp[10], K1[8], K2[8];

    printf("Enter 10-bit key (space separated): ");
    for (int i = 0; i < 10; i++)
        scanf("%d", &key[i]);

    /* Step 1: P10 permutation */
    permute(key, P10, 10, temp);

    /* Step 2: Left shift by 1 */
    leftShift(temp, 1);

    /* Step 3: Generate K1 using P8 */
    permute(temp, P8, 8, K1);

    /* Step 4: Left shift by 2 */
    leftShift(temp, 2);

    /* Step 5: Generate K2 using P8 */
    permute(temp, P8, 8, K2);

    printf("\nSubkey K1: ");
    for (int i = 0; i < 8; i++)
        printf("%d", K1[i]);

    printf("\nSubkey K2: ");
    for (int i = 0; i < 8; i++)
        printf("%d", K2[i]);

    return 0;
}
