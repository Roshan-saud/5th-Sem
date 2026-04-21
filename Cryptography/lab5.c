#include <stdio.h>

/* P10 permutation table */
int P10[10] = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};

/* Function to perform permutation */
void permute(int *key, int *perm, int size, int *output)
{
    for (int i = 0; i < size; i++)
        output[i] = key[perm[i] - 1];
}

/* Left circular shift for two halves */
void leftShift(int *key)
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

int main()
{
    int key[10], temp[10];
    int subkeys[16][10];

    printf("Enter 10-bit key (space separated): ");
    for (int i = 0; i < 10; i++)
        scanf("%d", &key[i]);

    /* Step 1: Apply P10 permutation */
    permute(key, P10, 10, temp);

    /* Step 2: Generate 16 subkeys */
    for (int round = 0; round < 16; round++)
    {
        leftShift(temp);  // shift each round

        for (int i = 0; i < 10; i++)
            subkeys[round][i] = temp[i];
    }

    /* Print 16 subkeys */
    printf("\nGenerated Subkeys:\n");
    for (int i = 0; i < 16; i++)
    {
        printf("K%d: ", i + 1);
        for (int j = 0; j < 10; j++)
            printf("%d", subkeys[i][j]);
        printf("\n");
    }

    return 0;
}
