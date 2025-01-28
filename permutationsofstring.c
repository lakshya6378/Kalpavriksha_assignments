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


void helperpermutationgenerator(char *str,int strlength,int *visited,char *tempstring,int index)
{
    if(index==strlength)
    {
        printf("%s\n",tempstring);
        return;
    }
    for(int str_index=0;str_index<strlength;str_index++)
    {
        if(!visited[str_index])
        {
            tempstring[index]=str[str_index];
            visited[str_index]=1;
            helperpermutationgenerator(str,strlength,visited,tempstring,index+1);
            visited[str_index]=0;
        }
    }
}
void generatepermutations(char *str,int strlength)
{
    int *visited=(int *)calloc(strlength,sizeof(int));
    char *tempstring=(char *)malloc(sizeof(char)*(strlength+1));
    helperpermutationgenerator(str,strlength,visited,tempstring,0);
    
}

int main()
{
    char *str=NULL;
    int strlength=0;
    str=dynamicinputgenerator(str,&strlength);
    if(str!=NULL)
    {
        generatepermutations(str,strlength);
    }
}