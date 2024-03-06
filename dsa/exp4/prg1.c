#include <ctype.h>
#include <stdio.h>
#define SIZE 50 /* Size of Stack */
char s[SIZE];   /* Global declarations */
int top = -1;
void push(char elem) /* Function for PUSH operation */
{
    s[++top] = elem;
}
char pop() /* Function for POP operation */
{
    return (s[top--]);
}
int pr(char elem) /* Function for precedence */
{
    switch (elem)
    {
    case '#':
        return 0;
    case '(':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
    case '%':
        return 3;
    case '^':
        return 4;
    }
}
void main() /* Main Program */
{
    char infx[50], pofx[50], ch, elem;
    int i = 0, k = 0;
    printf("\n\n enter the Infix Expression : ");
    gets(infx);
    push('#');
    while ((ch = infx[i++]) != '\0')
    {
        if (ch == '(')
            push(ch);
        else if (isalnum(ch))
            pofx[k++] = ch;
        else if (ch == ')')
        {
            while (s[top] != '(')
                pofx[k++] = pop();
            elem = pop(); /* Remove ( */
        }
        else /* Operator */
        {
            while (pr(s[top]) >= pr(ch))
                pofx[k++] = pop();
            push(ch);
        }
    }
    while (s[top] != '#') /* Pop from stack till empty */
        pofx[k++] = pop();
    pofx[k] = '\0'; /* Make pofx as valid string */
    printf("\n\n Given Infix Expn is: %s\n The Postfix Expn is:%s\n", infx, pofx);
}