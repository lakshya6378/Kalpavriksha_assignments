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


char *find_longest_pallindromic_substring(char *str,int strlength)
{
    int start_index=0;
    int max_length=0;
    if(strlength==1)
    {
        char *longest_pallindrome=(char *)malloc(sizeof(char)*2);
        longest_pallindrome[0]=str[0];
        longest_pallindrome[1]='\0';
         return longest_pallindrome;
    }
    for(int str_index=0;str_index<strlength;str_index++)
    {
        int left=str_index;
        int right=str_index;
        
        while(left>=0&&right<strlength&&str[left]==str[right])
        {
            left--;
            right++;
            
        }
        
        left++;
        right--;
        
        if((right-left+1)>max_length)
        {
            max_length=right-left+1;
            start_index=left;
        }
    

        left=str_index;
        right=str_index+1;
        
        while(left>=0&&right<strlength&&str[left]==str[right])
        {
            left--;
            right++;
            
        }
        
        left++;
        right--;
        
        if((right-left+1)>max_length)
        {
            max_length=right-left+1;
            start_index=left;
        }
    }
    

    char *longest_pallindrome=(char *)malloc(sizeof(char )*(max_length+1));
    for(int pallindrom_start=start_index;pallindrom_start<(start_index+max_length);pallindrom_start++)
    {
        longest_pallindrome[pallindrom_start-start_index]=str[pallindrom_start];
    }
    longest_pallindrome[max_length]='\0';
    return longest_pallindrome;
  

}
int main()
{
    char *str=NULL;
    int strlength=0;
    str=dynamicinputgenerator(str,&strlength);
    if(str)
    {
        char *longest_pallindrome=NULL;
        longest_pallindrome=find_longest_pallindromic_substring(str,strlength);
        if(longest_pallindrome)
        {
            printf("%s",longest_pallindrome);
            free(longest_pallindrome);
        }
    }
}