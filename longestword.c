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


char *extractword(char *str,int strlength,int wordstart,int wordend)
{
    int wordlength=wordend-wordstart+1;
   char *word=(char *)malloc(sizeof(char)*(wordlength+1));
   for(int start=wordstart,index=0 ;start<=wordend;index++,start++)
   {
    word[index]=str[start];
   }
   word[wordlength]='\0';
   return word;

}
char *longestwordinstring(char *str,int strlength)
{
    char *longestword=NULL;
    int index=0;
    int longindex=0;
    int maxlength=0;
    while(index<strlength)
    {
        while(index<strlength&&str[index]==' ')
        index++;
    int wordstart=index;
    while(index<strlength&&str[index]!=' ')
    index++;
     int wordend=index-1;
     if((wordend-wordstart+1)>=maxlength)
     {
        free(longestword);
        longestword=NULL;
        maxlength=wordend-wordstart+1;
        longestword=extractword(str,strlength,wordstart,wordend);
     }
    }
    return longestword;
}


int main()
{
    char *str=NULL;
    int strlength=0;
    char *ans;
    str=dynamicinputgenerator(str,&strlength);
    ans=longestwordinstring(str,strlength);
    ans!=NULL?printf("%s",ans):printf("\n");
    free(ans);
    free(str);
}