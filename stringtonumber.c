#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
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
int customstoi(char *str,int strlength)
{
    long ans=0;
    int sign=1;
    if(((strlength>1)&&(str[0]=='-')&&(!(str[1]>='0'&&str[1]<='9')))||(!(str[0]>='0'&&str[0]<='9')&&(str[0]!='-'))||(strlength==1&&(str[0]=='-')))
    {
        return 0;
    }

        for(int index=0;index<strlength;index++)
        {
            if(index>0&&(!(str[index]>='0'&&str[index]<='9')))
            {
            break;
            }
            if(str[index]=='-')
            {
                sign=-1;
                continue;
            }
            int value=str[index]-'0';
            ans=ans*10+value;
            if(ans>INT_MAX)
            {
                printf("error:out_of_range");
                return 0;
            }

        }
        return sign==1?ans:(~ans+1);
    
}

int main()
{
    char *str=NULL;
    int strlength=0;
    str=dynamicinputgenerator(str,&strlength);
    if(str!=NULL)
    {
        int integer=customstoi(str,strlength);
        printf("%d",integer);
        free(str);
    }
}