#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct user{
    char uniqueid[100];
    char name[100];
    int age;
};

void CreateUser(struct user *u)
{
    FILE *fp;
    fp=fopen("users.txt","a");
    if(fp==NULL)
    {
        printf("Unable to open the file. Please try again");
        return;
    }
    fprintf(fp,"%s|%s|%d\n",u->uniqueid,u->name,u->age);
    printf("user inserted successfully");
    fclose(fp);
}

void readUser()
{
    FILE *fp;
    struct user u;
    fp = fopen("users.txt", "r");
    if (fp == NULL)
    {
        printf("Unable to open the file. Please try again");
        return;
    }
    int i=1;
    while (fscanf(fp, "%[^|]|%[^|]|%d\n", u.uniqueid, u.name, &u.age) != EOF)
    {
        printf("user %d:\n",i++);
        printf("User's UniqueId:  %s\n",u.uniqueid);
        printf("UserName:  %s\n",u.name);
        printf("User's Age:  %d",u.age);
        printf("\n");
    }
}

void updateUser(char *changableUser)
{
    FILE *fp, *temp;
    struct user u;
    int found = 0;

    fp = fopen("users.txt", "r");
    temp = fopen("temp.txt", "w");
    if (fp == NULL || temp == NULL)
    {
        printf("Unable to open the file. Please try again.\n");
        return;
    }

        while (fscanf(fp, "%[^|]|%[^|]|%d\n", u.uniqueid, u.name, &u.age) != EOF)
    {
        if (strcmp(u.uniqueid, changableUser) == 0)
        {
            
            printf("\nEnter the new ID of the user: ");
            scanf("%s", u.uniqueid);

            printf("\nEnter the new age of the user: ");
            scanf("%d", &u.age);

            getchar(); 
            printf("\nEnter the new name of the user: ");
            scanf("%[^\n]%*c", u.name);

            found = 1;
        }
        fprintf(temp, "%s %s %d\n", u.uniqueid, u.name, u.age);
    }

    fclose(fp);
    fclose(temp);

    if (found)
    {
        remove("users.txt");
        rename("temp.txt", "users.txt");
        printf("User data updated successfully.\n");
    }
    else
    {
        remove("temp.txt");
        printf("User not found.\n");
    }
}

void deleteuser(char *deluser)
{
    FILE *fp, *temp;
    struct user u;
    int found = 0;

    fp = fopen("users.txt", "r");
    temp = fopen("temp.txt", "w");
    if (fp == NULL || temp == NULL)
    {
        printf("Unable to open the file. Please try again.\n");
        return;
    }
    while (fscanf(fp, "%[^|]|%[^|]|%d\n", u.uniqueid, u.name, &u.age) != EOF)
    {
        if (strcmp(u.uniqueid, deluser) == 0)
        {
            found = 1;
            continue;
        }
        fprintf(temp, "%s|%s|%d\n", u.uniqueid, u.name, u.age);
    }

    fclose(fp);
    fclose(temp);

    if (found)
    {
        remove("users.txt");
        rename("temp.txt", "users.txt");
        printf("User deleted successfully.\n");
    }
    else
    {
        remove("temp.txt");
        printf("User not found.\n");
    }
}
int main()
{
    int n=0;
   do
    {
   printf("\n\nselect a operation from below list:\n");
   printf("1.Enter 1 for create a new user \n 2.Enter 2 for display all users data \n 3.Enter 3 for update user data \n 4.Enter 4 for delete user data.\n 5.enter 0 for exit \n");
   scanf("%d",&n);
   switch(n)
   {
    case 0:
    break;
    case 1:
    struct user u;
    printf("enter the unique id for user:  ");
    scanf("%s",u.uniqueid);
    printf("enter the age of user:  ");
    scanf("%d", &u.age);
    getchar();
    printf("enter the name of user:  ");
    scanf("%[^\n]%*c",u.name);
    CreateUser(&u);
    break;
    case 2:
    readUser();
    break;
    case 3:
    char changeableUser[100];
    printf("enter the user's uniqueid for modification:  ");
    scanf("%s",changeableUser);
    updateUser(changeableUser);
    break;
    case 4:
    char deluser[100];
    printf("enter the unique id for delete user");
    scanf("%s",deluser);
    deleteuser(deluser);
    break;
    default:
    printf("please enter a valid option:\n");
    break;
   }
    }
    while(n);
   
}