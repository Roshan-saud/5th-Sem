#include <stdio.h>
#include <ctype.h>

void encrypt(char text[], int key) {
	int i;
    for (i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (isupper(ch)) {
            text[i] = (ch - 'A' + key) % 26 + 'A';
        }
        else if (islower(ch)) {
            text[i] = (ch - 'a' + key) % 26 + 'a';
        }
    }
}

void decrypt(char text[], int key) {
	int i;
    for (i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        if (isupper(ch)) {
            text[i] = (ch - 'A' - key + 26) % 26 + 'A';
        }
        else if (islower(ch)) {
            text[i] = (ch - 'a' - key + 26) % 26 + 'a';
        }
    }
}

int main() {
    char message[100];
    int key1, key2;

    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the key to encrypt: ");
    scanf("%d", &key1);
    encrypt(message, key1);
    printf("Encrypted Message: %s", message);

	int i=0;
	while(i!=3){
	printf("\nEnter the key to decrypt: ");
    scanf("%d", &key2);
    if(key1==key2){
    decrypt(message, key2);
    printf("Decrypted Message: %s", message);
    return 0;
	}
	else{
		printf("Sorry, Key doesn't match");
		i++;
	}	
	}
	
    return 0;
}