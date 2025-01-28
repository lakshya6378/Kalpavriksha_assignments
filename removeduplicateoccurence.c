// Write a program to remove all duplicate characters from a given string.The resulting string
// should retain the order of first appearance of characters and should not contain any duplicate
// letters.Sample Input and Output : 
// 1. Input : "programming" Output : "progamin" 
// 2. Input : "banana" Output : "ban" 
// 3. Input : "abacabad" Output : "abcd"


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_LENGTH 1000
void createHash(char *str,int strlength,int *hashmap,int *newstringlength)
{
    int hashposition = 0;
    for (int index = 0; index < strlength; index++)
    {
        hashposition = str[index];
        if (hashmap[hashposition] == 0 || str[index] == ' ')
            *newstringlength++;
        hashmap[hashposition]++;
    }
}
char *removeduplicates(char *str,int strlength)
{
    int hashmap[256]={0}; //for special characters and capital and small both type alphabets;
    int hashposition=0;
    int newstringlength=0;
    char *ans=NULL;
    int indexposition = 0;
    createHash(str,strlength,hashmap,&newstringlength);
    ans=(char *)malloc(sizeof(char)*(newstringlength+1));
    for(int index=0;index<strlength;index++)
    {
        if(str[index]==' ')
        ans[indexposition++]=' ';
        else
        {
            hashposition=str[index];
            if(hashmap[hashposition]>=1)
            {
                hashmap[hashposition]=-1;
                ans[indexposition++]=str[index];
            }
        }
    }
    ans[indexposition]='\0';

return ans;

}
int main()
{
    char str[MAX_LENGTH];
    str[0]='\0';
    char *ans;
    printf("enter the string : ");
    scanf("%[^\n]s",str);
    int stringlength=strlen(str);
    if(stringlength!=0)
    {
    ans=removeduplicates(str,stringlength);
    printf("\n string after removing duplicates is \n");
    printf("%s",ans);
    free(ans);
    }
    else
    {
        printf("\nno string provided\n");
    }
    return 0;

}