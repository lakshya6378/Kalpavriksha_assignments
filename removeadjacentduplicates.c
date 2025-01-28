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

char *removeduplicates(char *str,int strlength)
{
    int flag=1;
    char *solution_string=(char *)malloc(sizeof(char)*(strlength+1));
    char *comparestring=(char *)malloc(sizeof(char)*(strlength+1));
    strcpy(comparestring,str);
    while(flag)
    {
       int str_index=0; 
       int ans_string_index=0;
       while(str_index<strlength)
       {
        int count=1;
        while(str_index<strlength-1&&str[str_index]==str[str_index+1])
        {
            count++;
            str_index++;
        }
        if(count%2==0)
        {
            str_index++;
            continue;
        }
        else
        {
            solution_string[ans_string_index++]=str[str_index];
            str_index++;
        }


       }
       solution_string[ans_string_index]='\0';
       strlength=ans_string_index+1;
       if(strcmp(solution_string,str)==0)
       break;
       strcpy(str,solution_string);

    }
    return solution_string;
}

int main()
{
    char *str=NULL;
    int strlength=0;
    str=dynamicinputgenerator(str,&strlength);
    if(str)
    {
    char *modified_string=removeduplicates(str,strlength);
    if(modified_string!=NULL)
    {
        printf("%s",modified_string);
        free(modified_string);
    }
    free(str);
    }
       
}