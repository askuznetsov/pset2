#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include <cs50.h> 

void initialising(string input);

int main(void)
{
    string name = GetString();
    //Чек на NULL
    if (name != NULL)
    {
        initialising(name);
    }
    return 0;
}

void initialising(string input)
{
    int i = 0;
    int len = 0;
    //Проверяем пробелы и берем первую букву
    while (input[i] == ' ')
    {
        i++;
    }
    printf("%c",toupper(input[i]));
    len = strlen(input);
    i++;
    //Идём ко конца имени
    for (; i < len; i++)
    {
        //Берём букву после пробела
        while (input[i] == ' ')
        {
            i++;
            //И печатаем только, если следующий символ не пробел
            if (i < len && input[i] != ' ')
            {
                printf("%c", toupper(input[i]));
            }
        }
    }
    //печатаем новую строку
    printf("\n");
}
