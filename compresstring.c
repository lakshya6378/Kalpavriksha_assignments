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
char *compressstring(char *str,int strlength)
{
    char *compressedstring=NULL;
    int index=0;
    if(strlength==1)
    {
        compressedstring=(char *)malloc(sizeof(char)*3);
        compressedstring[0]=str[0];
        compressedstring[1]='1';
        compressedstring[2]='\0';
        return compressedstring;
    }
    int ansindex=0;
    while(index<strlength-1)
    {
         int count=1;
         while(index<strlength-1&&str[index]==str[index+1])
         {
            index++;
            count++;
         }
         compressedstring=(char *)realloc(compressedstring,ansindex+2);
         compressedstring[ansindex]=str[index];
         ansindex++;
         compressedstring[ansindex]=count+'0';
         ansindex++;
         index++;
    }
    if(str[index]!=str[index-1])
    {
        compressedstring=(char *)realloc(compressedstring,ansindex+3);
         compressedstring[ansindex]=str[index];
         ansindex++;
         compressedstring[ansindex]='1';
         ansindex++;
         compressedstring[ansindex]='\0';
    }
    else
    {
         compressedstring=(char *)realloc(compressedstring,ansindex+1);
         compressedstring[ansindex]='\0';
    }
    return compressedstring;
}

int main()
{
    char *str=NULL;
    char *compressedstring=NULL;
    int strlength=0;
    str=dynamicinputgenerator(str,&strlength);
    if(strlength!=0)
    {
    compressedstring=compressstring(str,strlength);
    printf("%s",compressedstring);
    }
    free(str);
}