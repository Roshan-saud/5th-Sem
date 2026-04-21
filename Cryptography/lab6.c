#include <stdio.h>
#include <string.h>

int main() {
    char msg[100];
    char hex[200];
    char state[4][4][3];
    int i, j, k = 0;

    printf("Enter message: ");
    scanf("%s", msg);

    int len = strlen(msg);

    /* Convert message characters to hexadecimal */
    for (i = 0; i < len; i++) {
        sprintf(hex + (i * 2), "%02x", msg[i]);
    }

    printf("\nHex representation: %s\n", hex);

    int hexLen = strlen(hex);

    /* Fill state array column-wise */
    for (j = 0; j < 4; j++) {
        for (i = 0; i < 4; i++) {

            if (k + 1 < hexLen) {
                state[i][j][0] = hex[k++];
                state[i][j][1] = hex[k++];
            } else {
                state[i][j][0] = '0';
                state[i][j][1] = '0';
            }

            state[i][j][2] = '\0';
        }
    }

    /* Display state matrix */
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
