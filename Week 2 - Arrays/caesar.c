#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// write a program that enables you to encrypt messages using Caesar’s cipher.
// At the time the user executes the program, they should decide, by providing a command-line argument, what the key should be in the secret message they’ll provide at runtime.
// We shouldn’t necessarily assume that the user’s key is going to be a number; though you may assume that, if it is a number, it will be a positive integer.

int main(int argc, string argv[])
{
    // Allow only one command-line argument. Argc has to equal 2.
    if(argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Ensure every character in argv[1] is a digit
    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: key must be digits only\n");
            return 1;
        }
    }

    // Convert argv[1] from a string to an int
    int k = atoi(argv[1]);

    // Prompt user for a plaintext
    string plaintext = get_string("Plaintext: ");

    // Print ciphertext and check for each character in the plaintext:
    printf("Ciphertext: ");

    for(int j = 0, len = strlen(plaintext); j < len; j++)
    {
        // If goes over 26 (letters in alphabet), loop back to 0 + 65 so text stays A-Z (ASCII A = 65). 26 % 26 = 0. Same with lowercase at ASCII 97.
        if (isupper(plaintext[j]))
        {
            // printf("%c", (plaintext[j] - 'A' + k) % 26 + 65);
            printf("%c", (plaintext[j] - 65 + k) % 26 + 65);
        }
        else if (islower(plaintext[j]))
        {
            printf("%c", (plaintext[j] - 97 + k) % 26 + 97);
        }
        else
        {
            printf("%c", plaintext[j]);
        }
    }
    printf("\n");

}
