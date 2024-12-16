#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stack
{
    long *st;
    int size;
    int top;
};

void push(struct stack *stk, long ch)
{
    if (stk->top == stk->size - 1)
    {
        printf("memory failure please try again.");
        return;
    }
        
    stk->top++;
    stk->st[stk->top] = ch;
}

void pop(struct stack *stk)
{
    if (stk->top == -1)
        return;
    stk->top--;
}

long top(struct stack *stk)
{
    if (stk->top == -1)
        return '\0';
    return stk->st[stk->top];
}

int isempty(struct stack *stk)
{
    return stk->top == -1;
}

int priority(char c)
{
    if (c == '+' || c == '-')
        return 1;
    return 2; 
}

int isoperand(char c)
{
    return c >= '0' && c <= '9';
}

int isoperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

char *postfixconversion(char str2[])
{
    int l = strlen(str2);
    char *str = (char *)malloc(sizeof(char) * (2 * l + 1)); 
    struct stack s;
    s.top = -1;
    s.size = l;
    s.st = (long *)malloc(sizeof(long) * l);
    int k = 0;

    for (int i = 0; i < l; i++)
    {
        if (isoperand(str2[i]))
        {
            
            while (i < l && isoperand(str2[i]))
            {
                str[k++] = str2[i++];
            }
            str[k++] = ' '; // Add a space to separate numbers
            i--;            // Adjust loop index
        }
        else if (str2[i] == ' ')
        {
            continue; // Ignore spaces
        }
        else
        {
            while (!isempty(&s) && priority(str2[i]) <= priority((char)top(&s)))
            {
                str[k++] = (char)top(&s);
                str[k++] = ' '; 
                pop(&s);
            }
            push(&s, str2[i]);
        }
    }

    while (!isempty(&s))
    {
        str[k++] = (char)top(&s);
        str[k++] = ' ';
        pop(&s);
    }

    str[k] = '\0'; 
    free(s.st);
    return str;
}

long evaluateans(char str2[])
{
    char *str = postfixconversion(str2); 
    int l = strlen(str);
    struct stack s;
    s.size = l;
    s.top = -1;
    s.st = (long *)malloc(sizeof(long) * l);
    int a, b;
    int num = 0;
    int isReadingNum = 0; 

    for (int i = 0; i < l; i++)
    {
        if (isoperand(str[i]))
        {
            num = num * 10 + (str[i] - '0');
            isReadingNum = 1;
        }
        else if (str[i] == ' ')
        {
            if (isReadingNum)
            {
                push(&s, num); 
                num = 0;      
                isReadingNum = 0;
            }
        }
        else
        {
            b = top(&s);
            pop(&s);
            a = top(&s);
            pop(&s);
            switch (str[i])
            {
            case '+':
                push(&s, a + b);
                break;
            case '-':
                push(&s, a - b);
                break;
            case '*':
                push(&s, a * b);
                break;
            case '/':
                if (b == 0)
                {
                    printf("Error: Division by zero.\n");
                    free(s.st);
                    free(str);
                    return __INT32_MAX__;
                }
                push(&s, a / b);
                break;
            }
        }
    }

    long ans = top(&s);
    free(s.st);
    free(str);
    return ans;
}

int main()
{
    char str[100], str2[100];
    printf("Enter the Expression:");
    scanf("%[^\n]s", str);

    int l = strlen(str), k = 0;

    for (int i = 0; i < l; i++)
    {
        if (!isoperand(str[i]) && !isoperator(str[i]) && str[i] != ' ')
        {
            printf("Error: Invalid expression.");
            exit(0);
        }
        else if (isoperator(str[i]))
        {
            if ((i + 1 < l && isoperator(str[i + 1])) ||
                (i + 2 < l && str[i + 1] == ' ' && isoperator(str[i + 2])))
            {
                printf("Error: Invalid expression. ");
                exit(0);
            }
        }
        {
            str2[k++]=str[i];
        }
        
    }

    str2[k] = '\0';

    long ans = evaluateans(str2);
    if (ans != __INT32_MAX__)
        printf("Result: %ld\n", ans);
    return 0;
}
