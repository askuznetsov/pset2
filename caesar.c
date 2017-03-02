#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int CONST_NUMBER_LETTERS = 26;
string syphering(string str, int key);

int main(int argc, char *argv[])
{
 // значение argc должно быть только 2
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    printf("plaintext:");
    string text = get_string();
    printf("ciphertext:%s\n", syphering(text, atoi(argv[1]) % CONST_NUMBER_LETTERS));
    return 0;
}

string syphering(string str, int key)
{
    int len = strlen(str);
    for(int i = 0; i < len; i++)
    {
        if (isalpha(str[i]))
        {
            if (!isalpha(str[i] + key))
            {
                str[i] = str[i] + key - CONST_NUMBER_LETTERS;
            }
            else str[i] = str[i] + key;
        }
    }
    return str;
}
