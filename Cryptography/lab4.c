#include <stdio.h>
#include <string.h>

void printMatrix(char mat[][100], int rail, int len) {
    int i, j;

    printf("\nRail Fence Matrix:\n");
    for (j = 0; j < len; j++) printf("----");
    printf("-\n");

    for (i = 0; i < rail; i++) {
        printf("|");
        for (j = 0; j < len; j++) {
            if (mat[i][j] == '\0')
                printf("   |");
            else
                printf(" %c |", mat[i][j]);
        }
        printf("\n");
        for (j = 0; j < len; j++) printf("----");
        printf("-\n");
    }
}

void encrypt(char text[], int rail, char cipher[]) {
    char mat[rail][100];
    int i, j, k = 0;
    int row = 0, dir = 1;
    int len = strlen(text);

    for (i = 0; i < rail; i++)
        for (j = 0; j < 100; j++)
            mat[i][j] = '\0';

  
    for (i = 0; i < len; i++) {
        mat[row][i] = text[i];
        row += dir;
        if (row == rail - 1 || row == 0)
            dir = -dir;
    }

    int col = len;
    while (row != 0 && row != rail - 1) {
        mat[row][col++] = 'X';
        row += dir;
    }

    int totalCols = col;

    printMatrix(mat, rail, totalCols);

    for (i = 0; i < rail; i++)
        for (j = 0; j < totalCols; j++)
            if (mat[i][j] != '\0')
                cipher[k++] = mat[i][j];

    cipher[k] = '\0';
}

void decrypt(char cipher[], int rail, char plain[]) {
    char mat[rail][100];
    int i, j, k = 0;
    int row = 0, dir = 1;
    int len = strlen(cipher);

    for (i = 0; i < rail; i++)
        for (j = 0; j < len; j++)
            mat[i][j] = '\0';

    for (i = 0; i < len; i++) {
        mat[row][i] = '*';
        row += dir;
        if (row == rail - 1 || row == 0)
            dir = -dir;
    }

    for (i = 0; i < rail; i++)
        for (j = 0; j < len; j++)
            if (mat[i][j] == '*')
                mat[i][j] = cipher[k++];

    row = 0; dir = 1;
    for (i = 0; i < len; i++) {
        plain[i] = mat[row][i];
        row += dir;
        if (row == rail - 1 || row == 0)
            dir = -dir;
    }
    plain[i] = '\0';
}

int main() {
    char text[100], cipher[100], plain[100];
    int rail;

    printf("Enter message: ");
    scanf("%s", text);

    printf("Enter number of rails: ");
    scanf("%d", &rail);

    encrypt(text, rail, cipher);
    printf("\nEncrypted Text: %s\n", cipher);

    decrypt(cipher, rail, plain);
    printf("Decrypted Text: %s\n", plain);

    return 0;
}
