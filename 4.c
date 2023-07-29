#include<stdio.h>
#include<string.h>
char infix[10],postfix[10],stack[10];
int top;
void push(char op)
{
    top++;
    stack[top]=op;
}
char pop(char op)
{
    op=stack[top];
    top--;
    return op;
}
int operator(char op)
{
    if(op =='+' || op =='-' || op =='*' || op =='/') 
        return 1;
    else
        return 0;
}
int precedence(char op)
{
    if(op == '*' || op=='/')
        return 3;
    else if(op == '+' || op=='-')
        return 2; 
    else
        return 0;
}
void conversion()
{
    int i=0;
    int j=0;
    while (infix[i]!='\0')
    {
        if (!operator(infix[i]))
        {
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else
        {
            if (precedence(infix[i])>precedence(stack[top]))
            {
                push(infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(stack[top]);
                j++;
            }
        }
    }
    while (top!=-1)
    {
        postfix[j]=pop(stack[top]);
        j++;
    }
    postfix[j]='\0';
}
int main()
{
    top=-1;
    printf("Enter Infix expression: ");
    gets(infix);
    conversion();
    printf("Final: \n");
    printf("Postfix: ");
    puts(postfix);
    printf("Stack: ");
    puts(stack);
    printf("Infix: ");
    puts(infix);
    return 0;
}

// #include<stdio.h>
// #include<string.h>
// char infix[10],postfix[10],stack[10];
// int top;
// void push(char op)
// {
//     top++;
//     stack[top]=op;
//     // postfix[top]=op;
// }
// char pop(char op)
// {
//     // stack[top]=0;
//     op=stack[top];
//     top--;
//     return op;
// }
// int operator(char op)
// {
//     if(op =='+' || op =='-' || op =='*' || op =='/') 
//         return 1;
//     else
//         return 0;
// }
// int precedence(char op)
// {
//     if(op == '*' || op=='/')
//         return 3;
//     else if(op == '+' || op=='-')
//         return 2; 
//     else
//         return 0;
// }
// void conversion()
// {
//     int i=0;
//     int j=0;
//     while (infix[i]!='\0')
//     {
//         if (!operator(infix[i]))
//         {
//             postfix[j]=infix[i];
//             i++;
//             j++;
//             printf("First If check\n");
//             printf("Postfix: ");
//             puts(postfix);
//             printf("Stack: ");
//             puts(stack);
//             printf("Infix: ");
//             puts(infix);
//         }
//         else
//         {
//             if (precedence(infix[i])>precedence(stack[top]))
//             {
//                 push(infix[i]);
//                 i++;
//                 printf("precedence check\n");
//                 printf("Postfix: ");
//                 puts(postfix);
//                 printf("Stack: ");
//                 puts(stack);
//                 printf("Infix: ");
//                 puts(infix);
//             }
//             else
//             {
//                 postfix[j] = pop(stack[top]);
//                 j++;
//                 printf("else check\n");
//                 printf("Postfix: ");
//                 puts(postfix);
//                 printf("Stack: ");
//                 puts(stack);
//                 printf("Infix: ");
//                 puts(infix);
//             }
//         }
//     }
//     while (top!=-1)
//     {
//         postfix[j]=pop(stack[top]);
//         j++;
//         printf("Last while check\n");
//         printf("Postfix: ");
//         puts(postfix);
//         printf("Stack: ");
//         puts(stack);
//         printf("Infix: ");
//         puts(infix);
//     }
//     postfix[j]='\0';
//     printf("After While check\n");
//     printf("Postfix: ");
//     puts(postfix);
//     printf("Stack: ");
//     puts(stack);
//     printf("Infix: ");
//     puts(infix);
// }
// int main()
// {
//     top=-1;
//     printf("Enter Infix expression: ");
//     gets(infix);
//     conversion();
//     printf("Final: \n");
//     printf("Postfix: ");
//     puts(postfix);
//     printf("Stack: ");
//     puts(stack);
//     printf("Infix: ");
//     puts(infix);
//     return 0;
// }