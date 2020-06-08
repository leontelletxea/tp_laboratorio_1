#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validations.h"

int getInt(char message[],char messageError[], int min, int max)
{

    int integerValue;

    printf("%s", message);
    scanf("%d", &integerValue);

    while(integerValue <  min || integerValue > max)
    {
        printf("%s", messageError);
        scanf("%d", &integerValue);
    }

    return integerValue;
}

float getFloat(char message[],char messageError[], float min, float max)
{

    float decimalValue;

    printf("%s", message);
    scanf("%f", &decimalValue);

    while(decimalValue <  min || decimalValue > max)
    {
        printf("%s", messageError);
        scanf("%f", &decimalValue);
    }

    return decimalValue;
}

char getChar(char message[],char messageError[], char answer1, char answer2)
{
    char letterValue;

    printf("%s", message);
    fflush(stdin);
    scanf("%c", &letterValue);
    fflush(stdin);

    while(letterValue!=answer1 && letterValue!=answer2)
    {
        printf("%s", messageError);
        fflush(stdin);
        scanf("%c", &letterValue);
    }

    return letterValue;
}

void getWord(char wordValue[], char message[])
{
    int len;
    int i;
    int flag=0;

    do
    {
        printf("%s", message);
        fflush(stdin);
        fgets(wordValue, 51, stdin);

        len=strlen(wordValue);
        wordValue[len-1]='\0';

        for(i=0; i<len; i++)
        {
            if(wordValue[i] <65 && wordValue[i] >122)
            {
                flag=1;
            }
        }
    }while(flag==1);

}
