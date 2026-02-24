#include <stdio.h>
#include <string.h>

int main() {
    char msg[100];
    char state[4][4][3];   // 2 chars + '\0'
    int i, j, k = 0;

    printf("Enter message: ");
    scanf("%s", msg);

    // Fill the state array column-wise
    for (j = 0; j < 4; j++) {
        for (i = 0; i < 4; i++) {
            if (k + 1 < strlen(msg)) {
                state[i][j][0] = msg[k++];
                state[i][j][1] = msg[k++];
            } else {
                state[i][j][0] = 'X';
                state[i][j][1] = 'X';
            }
            state[i][j][2] = '\0';
        }
    }

    // Display the matrix using pipes
    printf("\nState Matrix:\n");
    for (i = 0; i < 4; i++) {
        printf("| ");
        for (j = 0; j < 4; j++) {
            printf("%s | ", state[i][j]);
        }
        printf("\n");
    }

    return 0;
}
