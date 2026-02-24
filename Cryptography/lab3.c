#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

// Function to generate Playfair matrix
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
        if (i + 'A' == 'J') continue;
        if (!used[i]) {
            matrix[k / 5][k % 5] = i + 'A';
            k++;
        }
    }
}

// Function to print matrix
void printMatrix() {
    int i, j;
    printf("\nPlayfair Matrix:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++)
            printf("%c ", matrix[i][j]);
        printf("\n");
    }
}

// Find position of a character
void findPosition(char ch, int *row, int *col) {
    int i, j;
    if (ch == 'J') ch = 'I';
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
            }
}

// Encrypt or Decrypt
void playfair(char text[], int mode) {
    int i, r1, c1, r2, c2;
    for (i = 0; i < strlen(text); i += 2) {
        findPosition(text[i], &r1, &c1);
        findPosition(text[i + 1], &r2, &c2);

        if (r1 == r2) {
            text[i] = matrix[r1][(c1 + mode + 5) % 5];
            text[i + 1] = matrix[r2][(c2 + mode + 5) % 5];
        } else if (c1 == c2) {
            text[i] = matrix[(r1 + mode + 5) % 5][c1];
            text[i + 1] = matrix[(r2 + mode + 5) % 5][c2];
        } else {
            text[i] = matrix[r1][c2];
            text[i + 1] = matrix[r2][c1];
        }
    }
}

int main() {
    char key1[100],key2[100], message[100];
    int i,j, len;

    printf("Enter key: ");
    scanf("%s", key1);

    printf("Enter message: ");
    scanf("%s", message);

    // Convert to uppercase
    for (i = 0; key1[i]; i++) key1[i] = toupper(key1[i]);
    for (i = 0; message[i]; i++) message[i] = toupper(message[i]);

    // Prepare message
    len = strlen(message);
    for (i = 0; i < len; i += 2) {
        if (message[i] == message[i + 1]) {
            for ( j = len; j > i + 1; j--)
                message[j] = message[j - 1];
            message[i + 1] = 'X';
            len++;
        }
    }
    if (len % 2 != 0) {
        message[len++] = 'X';
        message[len] = '\0';
    }

    generateMatrix(key1);
    printMatrix();

    playfair(message, 1);
    printf("\nEncrypted Text: %s", message);

   
    i=0;
    while(i!=3){
    printf("\nEnter key: ");
    scanf("%s", key2);
    
    for (j = 0; key2[j]; j++)
    key2[j] = toupper(key2[j]);
    
    if(strcmp(key1,key2)==0){
    playfair(message, -1);
    printf("Decrypted Text: %s\n", message);
	return 0;	
	}
	else{
		printf("Please, enter correct key.\n");
		i++;
	}
	}
   
    return 0;
}



