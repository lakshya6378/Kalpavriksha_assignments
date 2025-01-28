#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char * dynamicinputgenerator(char *str,int *strlength)
{
    int position = 0;
    char ch;
    printf("enter the string\n");
    while ((scanf("%c", &ch)) == 1 && ch != '\n')
    {
        (*strlength)++;
        str = (char *)realloc(str, sizeof(char) * ((*strlength) + 1));
        if(ch==' ')
        str[position]=' ';
        else
        str[position] = ch;
        position++;
    }
    if(position==0)
     {

     printf("\nno input string is provided\n");
    return NULL;
     }
    str[position] = '\0';
    return str;
}
int countwords(char *str,int strlength)
{
    int position=0;
    int wordcount=0;
    while(position<strlength)
    {
    while(position<strlength&&str[position]==' ')
        position++;
    while (position < strlength && str[position] != ' ')
        position++;
        wordcount++;
    while (position < strlength && str[position] == ' ')
        position++;
    }
    return wordcount;
}
int main()
{
  
  char *str=NULL;
  int strlength=0;
  str=dynamicinputgenerator(str,&strlength);
  if(strlength!=0)
  {
  int ans=countwords(str,strlength);
  printf("%d",ans);
  }


}