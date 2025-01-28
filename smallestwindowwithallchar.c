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
int *createhash(char *patternstring,int patternlength,int *dist_count)
{
    int *hashmap=(int *)calloc(256,sizeof(int));
    for(int index=0;index<patternlength;index++)
    {
        int position=patternstring[index];
        if(hashmap[position]==0)
        {
        hashmap[position]=1;
       (*dist_count)++;
        }
    }
    return hashmap;
}
char *getsubstringwithallchar(char *textstring,char *patternstring,int textlength,int patternlength)
{
    int *hashmap=NULL;
    int dist_count=0;
    hashmap=createhash(patternstring,patternlength,&dist_count);
    int pat_start=0,pat_end=0;
    int text_index=0;
    int curr_count=0;
    int curr_min_start=0;
    int min_length=textlength;
    while(text_index<textlength)
    {
     int position=textstring[text_index];
     if(hashmap[position]==1)
     {
        curr_count++;
     }
      hashmap[position]--;
     if(curr_count==dist_count)
     {
        pat_end=text_index;
        while(curr_count==dist_count)
        {
             if((pat_end-pat_start+1)<min_length)
        {
            curr_min_start=pat_start;
            min_length=pat_end-pat_start+1;
        }
            int position=textstring[pat_start];
            hashmap[position]++;
            if(hashmap[position]==1)
            curr_count--;
        pat_start++;
        }
     }  
     text_index++; 
    }
    char* res_substring=(char *)malloc(sizeof(char)*(min_length+1));
    int res_index=0;
    printf("%d %d",curr_min_start,pat_end);
    for(int text_pat_st_index=curr_min_start;text_pat_st_index<curr_min_start+min_length;text_pat_st_index++)
    {
      res_substring[res_index++]=textstring[text_pat_st_index];
    }
    res_substring[res_index]='\0';
    return res_substring;
    free(hashmap);
}

int main()
{
    char *textstring=NULL;
    int textlength=0;
    char *patternstring=NULL;
    int patternlength=0;
    char *substrwithallchar=NULL;
    textstring=dynamicinputgenerator(textstring,&textlength);
    patternstring=dynamicinputgenerator(patternstring,&patternlength);
    if(textstring&&patternstring)
    {
        substrwithallchar=getsubstringwithallchar(textstring,patternstring,textlength,patternlength);
        if(substrwithallchar)
        {
            printf("%s",substrwithallchar);
            free(substrwithallchar);
        }
        free(textstring);
        free(patternstring);
    }

}