#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int main() 
{
    char infix[MAX], prefix[MAX], stack[MAX], temp[MAX];
    int top = -1;
    int i, j = 0;

    printf("Enter infix expression (no spaces): ");
    scanf("%s", infix);

    // Step 1: Reverse infix expression
    int len = strlen(infix);
    for (i = 0; i < len / 2; i++) 
    {
        char t = infix[i];
        infix[i] = infix[len - i - 1];
        infix[len - i - 1] = t;
    }

    // Step 2: Replace ( with ) and vice versa
    for (i = 0; i < len; i++) 
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    // Step 3: Convert to postfix
    for (i = 0; i < len; i++) 
    {
        char c = infix[i];

        if (isalnum(c)) 
        {
            temp[j++] = c;
        } 
        else if (c == '(') 
        {
            stack[++top] = c;
        } 
        else if (c == ')') 
        {
            while (top != -1 && stack[top] != '(') 
            {
                temp[j++] = stack[top--];
            }
            if (top != -1 && stack[top] == '(')
                top--;
        } 
        else 
        {
            int p1 = (c == '+' || c == '-') ? 1 : 2;
            while (top != -1) 
            {
                char op = stack[top];
                int p2 = (op == '+' || op == '-') ? 1 : 2;
                if (p2 >= p1)
                    temp[j++] = stack[top--];
                else
                    break;
            }
            stack[++top] = c;
        }
    }

    while (top != -1) 
    {
        temp[j++] = stack[top--];
    }

    temp[j] = '\0';

    // Step 4: Reverse postfix to get prefix
    int k;
    len = strlen(temp);
    for (i = 0, k = len - 1; i < len; i++, k--) 
    {
        prefix[i] = temp[k];
    }
    prefix[i] = '\0';

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
