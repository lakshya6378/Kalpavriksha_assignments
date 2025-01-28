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
int remcharcounter(char *str,int strlength,char remchar)
{
    int remcharcount=0;
    for(int index=0;index<strlength;index++)
    {
        if(str[index]==remchar)
        remcharcount++;
    }
    return remcharcount;
}

char *removespecificchar(char *str,int strlength,char remchar)
{
    int remcharcount=remcharcounter(str,strlength,remchar);
    char *remcharstring=(char *)malloc(sizeof(char)*(strlength-remcharcount+1));
    int ansstrindex=0;
    for(int index=0;index<strlength;index++)
    {
        if(str[index]!=remchar)
        {
            remcharstring[ansstrindex++]=str[index];
        }
    }
remcharstring[ansstrindex]='\0';
return remcharstring;

}
int main()
{
    char *str=NULL;
    int strlength=0;
    char remchar;
    char *ansstring=NULL;
    str=dynamicinputgenerator(str,&strlength);
    
    
    if(str!=NULL)
    {
        printf("enter the character to be removed from string  ");
    scanf("%c",&remchar);
    ansstring=removespecificchar(str,strlength,remchar);
    printf("\n%s\n",ansstring);
    free(str);
    free(ansstring);
    }
}
