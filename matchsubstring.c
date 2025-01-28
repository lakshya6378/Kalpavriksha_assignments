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

int *generateLPS(char *patternstring,int patternlength)
{
     int *LPS=(int *)malloc(sizeof(int)*(patternlength+1));
    LPS[0]=0;
    int len=0;
    int i=1;
    while(i<patternlength)
    {
        if(patternstring[i]==patternstring[len])
        {
            len++;
            LPS[i]=len;
            i++;
        }
        else if(len!=0)
        {
            len=LPS[len-1];
        }
        else
        {
            LPS[i]=0;
            i++;
        }
    }
    return LPS;
   
}

int substringinstring(char *textstring,int textlength,char *patternstring,int patternlength)
{
    int *LPS=NULL;
    LPS=generateLPS(patternstring,patternlength);
    if(LPS==NULL)
    printf("Lps is not working correctly");
    int i=0;
    int j=0;
    int index=-1;
    while(i<textlength)
    {
        if(textstring[i]==patternstring[j])
        {
            i++;
            j++;
            if(j==patternlength)
            {
                index= i-j;
                break;
            }
            
        }
        else
        {
            if(j!=0)
            j=LPS[j-1];
            else
            i++;
        }
    }
    free(LPS);
    return index;

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