#include <stdio.h>
#include <stdlib.h>
int cqueue[10], cfront,crear;
void cenqueue()
{
    if ((crear+1)%5==cfront)
    {
        printf("\nQueue Overflow.\n");
    }
    else if (cfront&&crear==-1)
    {
        int temp;
        cfront=(cfront+1)%5;
        crear=(crear+1)%5;
        printf("Enter digit: ");
        scanf("%d",&temp);
        cqueue[cfront]=cqueue[crear]=temp;
    }
    else
    {
        crear=(crear+1)%5;
        printf("Enter digit: ");
        scanf("%d",&cqueue[crear]);
    }
}
void cdequeue()
{
    if (cfront==-1)
    {
        printf("\nQueue Underflow.\n");
    }
    else if (cfront==crear)
    {
        printf("\n%d is dequeued.\n",cqueue[cfront]);
        cfront=crear=-1;
    }
    else
    {
        printf("\n%d is dequeued.\n",cqueue[cfront]);
        cfront=(cfront+1)%5;
    }
}
void cdisplay()
{
    if (crear&&cfront==-1)
    {
        printf("\nQueue is empty.\n");
    }
    else
    {
        int i = cfront;
        do 
        {
            printf("%d ", cqueue[i]);
            i = (i + 1) % 5;
        }
        while (i != (crear + 1) % 5);
    }
}
void cmenu()
{
    int choice;
    restart:
    printf("\nPress 1 to Enqueue.\n");
    printf("Press 2 to Dequeue.\n");
    printf("Press 3 to Display.\n");
    printf("Press 4 to Exit.\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        cenqueue();
        goto restart;
        break;
    case 2:
        cdequeue();
        goto restart;
        break;
    case 3:
        cdisplay();
        goto restart;
        break;
    case 4:
        printf("Exit.\n");
        break;
    default:
        printf("Wrong Choice.\n");
        goto restart;
        break;
    }
}
int main()
{
    cfront=crear=-1;
    cmenu();
    system("PAUSE");
    return 0;
}