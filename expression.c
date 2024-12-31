#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int calculate_ans(int B,int N,int M)
{
    if(M==0)
    {
        printf("error:Modulus cant be zero");
        return 0;
    }
    if(N==0)
    return 1;
    if(N==1)
    return B%M;
    int result=calculate_ans(B,N/2,M)%M;
    if(N%2==0)
    return (result*result)%M;
    return (B % M * result * result % M) % M;
}
int main()
{
    int B,N,M;
    int ans=0;
    printf("enter the base of the expression");
    scanf("%d",&B);
    printf("enter the exponent number");
    scanf("%d",&N);
    printf("enter the modulus number");
    scanf("%d",&M);
    ans=calculate_ans(B,N,M);
    printf("%d",ans);
    
    return 0;
}