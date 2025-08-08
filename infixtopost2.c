#include <stdio.h>
#define MAX 100

int main() 
{
    char infix[MAX], postfix[MAX], stack[MAX];
    int top = -1;
    int i, j = 0;
    char c;

    printf("Enter infix expression (no spaces): ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++) 
    {
        c = infix[i];

        // If operand (A-Z or a-z)
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) 
        {
            postfix[j++] = c;
        }

        // If opening bracket
        else if (c == '(') 
        {
            stack[++top] = c;
        }

        // If closing bracket
        else if (c == ')') 
        {
            while (stack[top] != '(') 
            {
                postfix[j++] = stack[top--];
            }
            top--;  // remove '('
        }

        // If operator +, -, *, /
        else if (c == '+' || c == '-' || c == '*' || c == '/') 
        {
            // precedence of current operator
            int p1 = (c == '+' || c == '-') ? 1 : 2;

            while (top != -1 && (stack[top] == '+' || stack[top] == '-' || stack[top] == '*' || stack[top] == '/')) 
            {
                int p2 = (stack[top] == '+' || stack[top] == '-') ? 1 : 2;

                if (p2 >= p1) 
                {
                    postfix[j++] = stack[top--];
                } 
                else 
                {
                    break;
                }
            }

            stack[++top] = c; // push current operator
        }
    }

    // Pop remaining operators from stack
    while (top != -1) 
    {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';  // End the string

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
