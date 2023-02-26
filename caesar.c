#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>

bool if_only_int(string text);
string encrypt_text(string plaintext, int key);

int main(int argc, string argv[])
{
    string plain_text;
    string encrypted_text;
    int key = 0;
    if (argc == 2)
    {
        if (if_only_int(argv[1]))
        {
            key = atoi(argv[1]);
            plain_text = get_string("plaintext:  ");
            encrypted_text = encrypt_text(plain_text, key);
            printf("ciphertext: %s\n", encrypted_text);

        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

bool if_only_int(string text)
{
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (text[i] < 48 || text[i] > 57)
        {
           return false;
        }
    }
        return true;
}

string encrypt_text(string plaintext, int key)
{
    int len = strlen(plaintext);
    for (int i = 0; i < len; i++)
    {
        if (isupper(plaintext[i]))
        {
            plaintext[i] = (((plaintext[i] - 65 + key) % 26)) + 65;
        }
        else if (islower(plaintext[i]))
        {
            plaintext[i] = ((plaintext[i] - 96 + key) % 26) + 96;
        }
    }
    return plaintext;
}