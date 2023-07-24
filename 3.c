#include<stdio.h>
int stack[5],top;
void push()
{
    if (top==4)
    {
        printf("Stack overflow.\n");
    }
    else
    {
        top++;
        printf("Enter digit: ");
        scanf("%d",&stack[top]);
        printf("Remaining entries left : %d.\n",4-top);
    }
}
void pop()
{
    if (top==-1)
    {
        printf("Stack underflow.\n");
    }
    else
    {
        printf("\n%d is popped.\n",stack[top]);
        stack[top]=0;
        top--;
        printf("Remaining elements in stack : %d.\n",top+1);
    }
}
void peep()
{
    if (top==-1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("\n%d is on top of the stack at index %d.\n",stack[top],top);
    }
}
void change ()
{
    if (top==-1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Enter new value for %d: ",top);
        scanf("%d",&stack[top]);
    }
}
void display()
{
    if (top==-1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        for (int i = 0; i <=top; i++)
        {
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
}
int main()
{
    int choice;
    top = -1;
    restart:
    printf("\nPress 1 to Push\n");
    printf("Press 2 to Pop\n");
    printf("Press 3 to Peep\n");
    printf("Press 4 to Change\n");
    printf("Press 5 to Display\n");
    printf("Press 6 to Exit\n\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    printf("\n");
    switch (choice)
    {
    case 1:
        push();
        goto restart;
        break;
    case 2:
        pop();
        goto restart;
        break;
    case 3:
        peep();
        goto restart;
        break;
    case 4:
        change();
        goto restart;
        break;
    case 5:
        display();
        goto restart;
        break;
    case 6:
        printf("Exit.\n");
        break;
    default:
        printf("Wrong Choice\n");
        goto restart;
        break;
    }
    return 0;
}
