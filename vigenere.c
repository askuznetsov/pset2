#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

const int CONST_NUMBER_a = 97;
const int CONST_NUMBER_LETTERS = 26;

void fillNewArray(int* keyArray, char* str, unsigned long keyArrayLength);
string encrypt(string str, int* key, int key_len);

int main( int argc, char *argv[] )  
{
    // значение argc должно быть только 2
    if( argc != 2 )
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    //инициилизируем массив для шифрования
    int keyArray[strlen(argv[1])];
    fillNewArray(keyArray, argv[1], strlen(argv[1]));
    printf("plaintext:");
    string text = get_string();
    
    printf("ciphertext:%s\n",encrypt(text,keyArray,strlen(argv[1])));
    return 0;
}


void fillNewArray(int* keyArray, char* str, unsigned long keyArrayLength)
{
    //Проверям по элементно, буква ли это и заполняем массив
    for(int i = 0; i < keyArrayLength; i++)
    {
        if(!isalpha(str[i]))
        {
            printf("Usage: ./caesar k\n");
            exit(1);
        }
        keyArray[i] = (int)tolower(str[i]) - CONST_NUMBER_a;
        
    }
}

string encrypt(string str, int* key, int key_len) 
{
    int k = 0;
    for (int i = 0; i < strlen(str); i++) 
    {
        if(isalpha(str[i]))
        {
            if(isupper(str[i]) > 0)
            {
                str[i] = tolower(str[i]) + key[k]; 
                if(!isalpha(str[i]))
                {
                    str[i] -= CONST_NUMBER_LETTERS;
                }
                str[i] = toupper(str[i]);
            }else
            {
                str[i] = str[i] + key[k];          
                if(!isalpha(str[i]))
                {
                    str[i] -= CONST_NUMBER_LETTERS;
                }
            }
            k++;
            if(k > key_len-1)
            {
                k=0;
            }    
        }
    }

    return str;
}
