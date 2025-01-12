#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *dynamicinputgenerator(char *str, int *strlength)
{
    int position = 0;
    char ch;
    printf("enter the string\n");
    while ((scanf("%c", &ch)) == 1 && ch != '\n')
    {
        (*strlength)++;
        str = (char *)realloc(str, sizeof(char) * ((*strlength) + 1));
        if (ch == ' ')
            str[position] = ' ';
        else
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

int sustringinstring(char *textstring,int textlength,char *patternstring,int patternlength)
{
    
}
int main()
{
    char *textstring=NULL;
    char *patternstring=NULL;
    int textlength=0;
    int patternlength=0;
    textstring=dynamicinputgenerator(textstring,&textlength);
    patternstring = dynamicinputgenerator(patternstring, &patternlength);
    int index=substringinstring(textstring,textlength,patternstring,patternlength);
    printf("%d",index);

}