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

int checkanagram(char *str1,int strlength1,char *str2,int strlength2)
{
    if(strlength1!=strlength2)
    {
        return 0;
    }
    int hashmap[26]={0};
    int position=0;
    for(int index=0;index<strlength1;index++)
    {
        position=str1[index]-'a';
        hashmap[position]++;
        position=str2[index]-'a';
        hashmap[position]--;
    }
    for(int i=0;i<26;i++)
    {
        if(hashmap[i]!=0)
        return 0;
    }
    return 1;

}

int main()
{
    char *str1=NULL,*str2=NULL;
    int strlength1=0,strlength2=0;
    int hashmap[26];
    int ans=0;
    str1=dynamicinputgenerator(str1,&strlength1);
    str2=dynamicinputgenerator(str2,&strlength2);
    ans=checkanagram(str1,strlength1,str2,strlength2);
    if(ans==0)
   {
    printf("given strings are not anagrams of each other");
   }
   else
   {
    printf("given strings are anagrams of each other");
   }
    
}