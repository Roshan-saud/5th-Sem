#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

/* Function to create Playfair key matrix */
void generateMatrix(char key[]) {
    int used[26] = {0};
    int i, j, k = 0;

    for (i = 0; key[i]; i++) {
        if (key[i] == 'J') key[i] = 'I';
        if (!used[key[i] - 'A']) {
            matrix[k / 5][k % 5] = key[i];
            used[key[i] - 'A'] = 1;
            k++;
        }
    }

    for (i = 0; i < 26; i++) {
        if (i + 'A' == 'J') 
        continue;
        if (!used[i]) {
            matrix[k / 5][k % 5] = i + 'A';
            k++;
        }
    }
}

/* Find position of character in matrix */
void findPosition(char ch, int *row, int *col) {
    int i, j;
    if (ch == 'J') ch = 'I';

    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
}

/* Playfair encryption */
void encrypt(char text[]) {
    int i;
    for (i = 0; i < strlen(text); i += 2) {
        int r1, c1, r2, c2;
        findPosition(text[i], &r1, &c1);
        findPosition(text[i + 1], &r2, &c2);

        if (r1 == r2) {
            text[i]     = matrix[r1][(c1 + 1) % 5];
            text[i + 1] = matrix[r2][(c2 + 1) % 5];
        }
        else if (c1 == c2) {
            text[i]     = matrix[(r1 + 1) % 5][c1];
            text[i + 1] = matrix[(r2 + 1) % 5][c2];
        }
        else {
            text[i]     = matrix[r1][c2];
            text[i + 1] = matrix[r2][c1];
        }
    }
}

/* Playfair decryption */
void decrypt(char text[]) {
    int i;
    for (i = 0; i < strlen(text); i += 2) {
        int r1, c1, r2, c2;
        findPosition(text[i], &r1, &c1);
        findPosition(text[i + 1], &r2, &c2);

        if (r1 == r2) {
            text[i]     = matrix[r1][(c1 + 4) % 5];
            text[i + 1] = matrix[r2][(c2 + 4) % 5];
        }
        else if (c1 == c2) {
            text[i]     = matrix[(r1 + 4) % 5][c1];
            text[i + 1] = matrix[(r2 + 4) % 5][c2];
        }
        else {
            text[i]     = matrix[r1][c2];
            text[i + 1] = matrix[r2][c1];
        }
    }
}

int main() {
    char key[50], text[100];
    int i, j = 0;

    printf("Enter Key: ");
    scanf("%s", key);

    printf("Enter Message: ");
    scanf("%s", text);

    /* Convert key and text to uppercase */
    for (i = 0; key[i]; i++) key[i] = toupper(key[i]);
    for (i = 0; text[i]; i++) text[i] = toupper(text[i]);

    /* Prepare message */
    char prepared[100];
    for (i = 0; i < strlen(text); i++) {
        prepared[j++] = text[i];
        if (text[i] == text[i + 1])
            prepared[j++] = 'X';
    }
    if (j % 2 != 0)
        prepared[j++] = 'X';
    prepared[j] = '\0';

    generateMatrix(key);

    printf("\nEncrypted Text: ");
    encrypt(prepared);
    printf("%s", prepared);

    printf("\nDecrypted Text: ");
    decrypt(prepared);
    printf("%s", prepared);

    return 0;
}
