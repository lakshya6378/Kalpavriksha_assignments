#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *dynamicinputgenerator(char *str, int *strlength)
{
    int position = 0;
    char ch;
    printf("enter the string\n");
    while ((scanf("%c", &ch)) == 1 && ch != '\n')
    {
        (*strlength)++;
        str = (char *)realloc(str, sizeof(char) * ((*strlength) + 1));
        str[position] = ch;
        position++;
    }
    if (position == 0)
    {
        printf("\nno input string is provided\n");
        return NULL;
    }
    str[position] = '\0';
    return str;
}

int *generateLPS(char *patternstring, int patternlength)
{
    int *LPS = (int *)malloc(sizeof(int) * (patternlength + 1));
    LPS[0] = 0;
    int len = 0;
    int i = 1;
    while (i < patternlength)
    {
        if (patternstring[i] == patternstring[len])
        {
            len++;
            LPS[i] = len;
            i++;
        }
        else if (len != 0)
        {
            len = LPS[len - 1];
        }
        else
        {
            LPS[i] = 0;
            i++;
        }
    }
    return LPS;
}

int substringinstring(char *textstring, int textlength, char *patternstring, int patternlength)
{
    int *LPS = NULL;
    LPS = generateLPS(patternstring, patternlength);
    if (LPS == NULL)
        printf("Lps is not working correctly");
    int i = 0;
    int j = 0;
    int index = -1;
    while (i < textlength)
    {
        if (textstring[i] == patternstring[j])
        {
            i++;
            j++;
            if (j == patternlength)
            {
                index = i - j;
                break;
            }
        }
        else
        {
            if (j != 0)
                j = LPS[j - 1];
            else
                i++;
        }
    }
    free(LPS);
    return index;
}

char * concatestring(char *str1,int *str1length,char *str2,int str2length)
{
    if(str2length==0)
    return str1;
    str1=(char *)realloc(str1,sizeof(char)*((*str1length)+str2length+1));
    int newlength=(*str1length)+str2length;
    int j=0;
    for(int i=*str1length;i<newlength;i++)
    {
        str1[i]=str2[j];
        j++;
    }
    *str1length=newlength;
    return str1;
}
int main()
{
    char *textstring = NULL;
    char *rotatedstring = NULL;
    int textlength = 0;
    int rotatedstrlength = 0;
    textstring = dynamicinputgenerator(textstring, &textlength);
    rotatedstring = dynamicinputgenerator(rotatedstring, &rotatedstrlength);
    if (!textlength || !rotatedstrlength)
    {
        printf("text or rotated string cant be empty");
        return 0;
    }
   textstring=concatestring(textstring,&textlength,textstring,textlength);
    int index = substringinstring(textstring, textlength, rotatedstring, rotatedstrlength);
    if(index>=0)
    printf("true");
    else
    printf("false");
}