#include <stdio.h>
#include <string.h>

// Function to encrypt the message using Caesar Cipher
void encrypt(char message[], int key)
{
    for (int i = 0; message[i] != '\0'; i++)
    {
        char ch = message[i];
        if (ch >= 'a' && ch <= 'z')
        {
            message[i] = ((ch - 'a' + key) % 26) + 'a';
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            message[i] = ((ch - 'A' + key) % 26) + 'A';
        }
    }
}

// Function to decrypt the message using Caesar Cipher
void decrypt(char message[], int key)
{
    for (int i = 0; message[i] != '\0'; i++)
    {
        char ch = message[i];
        if (ch >= 'a' && ch <= 'z')
        {
            message[i] = ((ch - 'a' - key + 26) % 26) + 'a';
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            message[i] = ((ch - 'A' - key + 26) % 26) + 'A';
        }
    }
}

int main()
{
    char message[100];
    int key;

    printf("\t****NISHAN DHAKAL****\n      ****Caesar Cipher****\n\n");
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove newline character from input

    printf("Enter key: ");
    scanf("%d", &key);

    // Encrypt the message
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}